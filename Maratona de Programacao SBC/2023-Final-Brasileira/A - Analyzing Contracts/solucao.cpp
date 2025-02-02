#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll P[200001],S[200001];						//taxa de cada produtor e dia que cada produtor começa a distribuir

struct cliente{
	ll E=0, R=0;
	ll operator()(ll i) {					//calcula rendimento dado um produtor i
		ll aux=0;
		if(E>=S[i]){							//se não começou a suprir ainda, quer dizer que todos os fabricantes de i para cima não começaram a suprir ainda
			aux=(R-P[i]) * (E-S[i]+1);		//função rendimento
			if(aux==0)
				aux=-1;						//se dá zero ou negativo por causa do preço, quer dizer que ainda não começou o fabricantes que dá algo positivo, precisa aumentar valor i
		}
			return aux;
		// return (aux)>0?aux:0;				//se menor que 0, rendimento 0
	}
};


/*
	f1 e f2: dado que R1 > R2 e E1 < E2
	se temos um fornecedor i, onde a=Pi e b=Si+1
	Qual a relação de f1 e f2 com o fabricante i?
	
	f1(i) ? f2(i)
	
	R1a + E1b ? R2a + E2b
	R1a + E1b - R2a - E2b ? 0			equivalente a 		f1(i) - f2(i) ? 0		I
	(R1-R2)a + (E1-E2)b ? 0
	Como R1 > R2, R1-R2 > 0. R = módulo de R1-R2
	Como E1 < E2, E1-E2 < 0. E = módulo de E1-E2
	Ra - Eb ? 0
	Ra ? Eb 
	Assim temos três alternativas
	Ra > Eb, onde Ra-Eb > 0, e f1(i) - f2(i) > 0	
	Ra < Eb, onde Ra-Eb < 0, e f1(i) - f2(i) < 0	
	Ra = Eb, onde Ra-Eb = 0, e f1(i) - f2(i) = 0	
	
	Para todo i, R e E são iguais, pois R = R1-R2 que são constantes em f1 e f2, seguindo a mesma lógica para E
	
	De acordo com o enunciado do exercício, para todo produtor i, Pi > Pi+1 e Si < Si+1. Ou seja, conforme i aumenta, o valor de a dimininui e o valor de b aumenta
	
	Considerando
	Ra e Eb em um produtor i, para todo produtor j>i Ra vai diminuir (R permanece igual e a diminui) e Eb vai aumentar (E permanece igual e b diminui). Isso significa que Ra-Eb vai ficar cada vez menor.
	Podemos reescrever Ra-Eb como f1(i)-f2(i) (I). Se f1-f2 diminui conforme i aumenta, f2(i)-f1(i) aumenta conforme i aumenta.
	
	Então se em i temos:
		f2(i)-f1(i) > 0 que pode ser reescrito como f2(i) > f1(i), então para todo j>i f2(j)>f1(j), pois f2(j) - f1(j) vai aumentar de valor e sempre vai continuar >0.
	Se em i temos:
		f2(i)-f1(i) < 0 que pode ser reescrito como f2(i) < f1(i), não podemos ter certeza se para todo j>i f2(j) < f1(j), pois f2(j) - f1(j) vai aumentar de valor e pode ficar >0 eventualmente.
	Se e i temos:
		f2(i)-f1(i) = 0 que pode ser reescrito como f2(i) = f1(i), para todo j>i f2(j) >= f1(j).
	
	Isso significa que se montássemos um gráfico com essas duas funções, elas iam se cruzar no máximo apenas uma vez. Para resolver esse problema rapidamente, usaremos uma árvores de Li-Chao. 
	
	
	Antes porém, temos que considerar um outro caso onde as funções não se cruzam.
	
	f3 e f4: dado que R3 >= R4 e E3 >= E4.
	se temos um fornecedor i, onde a=Pi e b=Si+1
	Qual a relação de f3 e f4 com o fabricante i?
	
	f3(i) ? f4(i)
		
	R3a + E3b ? R4a + E4b
	R3a + E3b - R4a - E4b ? 0			equivalente a 		f3(i) - f4(i) ? 0		I
	(R3-R4)a + (E3-E4)b ? 0
	Como R3 >= R4, R3-R4 > 0. R = módulo de R3-R4
	Como E3 >= E4, E3-E4 > 0. E = módulo de E3-E4
	Pelo problema dado, a>0 e b>0. Logo, o produto de dois números > 0 é > 0, e a soma de dois números > 0, é > 0.
	Então (R3-R4)a + (E3-E4)b > 0, ou seja, f3(i) - f4(i) > 0, f3(i) > f4(i). Isso para qualquer valor de i.
	
	Uma árvore de Li-Chao é usada para dado um conjunto de funções, você quer saber o maior ou menor valor dessas funções num ponto i. O que é basicamente nosso problema, já que dado todos os clientes atuais, você quer o máximo rendimento.
	
	Para o nosso problema vai funcionar basicamente assim, você vai usar uma árvore, que inicialmente está zerada (E = 0, R = 0, para todas as raízes).
	
	No problema eu usei um vetor para ser a árvore, então o indice que eu vou falar equivale ao indice do vetor que é diferente do i do produtor.
	Na árvore, você considera que cada nó equivale a um intervalo de i, e armazena a função que dá o maior valor no ponto do meio do intervalo.
	A raíz equivale ao intervalo 0 até N, que armazena a função ótima em N/2. O filho esquerdo da raiz equivale ao intervalo 0 até N/2, e filho direito equivale ao intervalo N/2 até N. E isso se mantém para todos os nós até o intervalo ser de 1.
	Como o nosso i é inteiro, eu vou armazenar até chegar nos nós folha da árvore, mas poderia se construir a árvore só a medida que se vai precisando armazenar o novo intervalo.
	
	Quando você receber uma função do cliente, você vai olhar a função já armazenada no nó (indice 0) da sua árvore e a função que quer armazenar. Primeiro, você tem que identificar se a relação da função é do tipo f1 e f2 (II), ou do tipo f3 e f4 (III).
	Também se verifica qual é f1,f2,f3 ou f4.
	
	
	Em II, você compara f2 e f1.
		Se f2(meio)>f1(meio), você coloca f2 no nó atual, pois f2 é a nova função máxima para meio. Mas não podemos descartar f1, pois num i menor, ela poderia ter sido  maior que f2. Então indo para filho esquerdo (indice=indice*2+1) e repetimos
		Se f2(meio) < f1(meio), você coloca f1 no nó atual, pois f1 é a nova função máxima para meio. Mas não podemos descartar f2, pois num i maior ela pode ficar maior que f1. Então indo para filho direito (indice=indice*2+2) e repetimos
		Se f2(meio) = f1(meio), você normalmente escolheria uma das opções de cima como >= ou <=. Pois f2 pode ficar maior com i maior,  e f1 pode ficar maior num i menor. Porém, mas abaixo explico que no nosso caso só pode considerar >=
		Se estiver num nó folha, só faz a substituição sem avançar.
		
	Em III, você coloca no nó atual f3.
		
	Quando tiver que falar o maior rendimento em i você vai percorrer a árvore e pegar o maior resultado nas funções do caminho até chegar em algum meio = a i ou num nó folha.
	
	Explicando melhor a árvore, em um exemplo. Vamos supor que i = 4 e N=10. Na árvore tem uma função c1 na raiz, uma função c2 no filho esquerdo e uma função c3 no filho direito.
	Sabemos que c1 é a maior em j=5(10/2) e sabemos que c2 é a maior j=2(5/2), mas não temos a informação de qual a maior em i=4. O que sabemos com certeza é que do intervalo de 5 até 2, ou c1 ou c2 é a maior. Se i > 5, poderia ser ou c1 ou c3 a maior.
	
	OBS: casos a parte
	Rendimento zero por preço do fabricante ser maior que cliente e rendimento zero por data de produção fabricante maior que data recebimento cliente
	
	Essas duas situações temos que dar uma observada melhor no que acontece. No exercício temos que rendimento é zero se (R-P) * (E-S+1) < 0 ou E<S. Para a equação ser < 0, R-P < 0 (IV) ou E-S+1 (V)< 0. 
	
	Podemos transformar V em E<S-1. Conforme i avança, o valor de S aumenta, logo se em algum i E<Si-1, para todo j>i E<Si-1. Ou seja, se em i, f está zerado por causa do E, para todo j>i, f estará zerado.
	Sabemos que em f2 e f1, E2>E1, logo se f2 estiver em 0 pelo dia, f1 também vai estar em zero.
	Então num caso em que f1 e f2 ambos são zero, usaria-se o critério f1=f2.
	Porém não podemos agir como se f2<f1, pois iriamos estar considerando que até aquele ponto i, f1 é o maior.
	E se passassemos f2 para o filho direito, seria o mesmo que pensar que f2 só vai ser maior que f1 em j>i, sendo que f2 só vai deixar de ser zero quando i diminuir.
	Dessa forma, o método correto é agir como se f2>f1, pois em algum ponto com i menor f1 vai ficar maior, mas ele não é naquele ponto ainda. f2 já seria considerado 'maior' no ponto em que está zerado pelos dias.
	
	Já para o preço, podemos transformar IV em R<P. Conforme i avança, o valor de P diminui, logo em algum momento pode ocorrer R>=Pi. Sabemos que em f2 e f1, R2<R1. Ou seja, nesse caso em que f2 estiver zerado, não necessariamente f1 vai estar zerado.
	E ainda, se f1 e f2 ambos são zero por causa do preço, o que aconteceria?
	Se tentássemos usar f2>=f1, colocariamos f2 como o maior, sendo que f2 ainda estaria 'menor' que f1. E além disso, diriamos que conforme o i diminui, uma hora f1 vai ser maior. Porém se i diminuir, P aumenta, logo ficaria sempre zerado.
	Nesse caso, teria que se fazer o oposto, e usar f2<=f1.
	
	Mas como diferenciar o 0 de preço e o 0 de dia. Para isso deixamos sempre que E<=S como zero, porém se R<=P deixamos negativo. Atenção, se R=P a conta daria zero, então temos que fazer um if e deixar negativo esse caso também.
	Para o dia, considereio critério f2>=f1. Já para o caso do preço, eu quero preferir usar cliente nenhum em vez de usar cliente negativo.
	Então como nossa matriz é iniciada com 0, eu vou ter um f3 (E3,R3) e f4(0,0), porém eu quero manter f4 e mover f3 para a direita, pois se i aumentar uma hora f3 deixa de ser negativo.
	Assim, nunca teremos o caso de lidar com dois rendimentos negativos, pois caso até chegar no folha não tenha conseguido ficar positivo, o zero é o que ganharia e ficaria lá.
	Para o caso de f2 negativo e f1 positivo, contaria como f1<f2 e moveria f2 para a direita onde talvez não seja mais negativo.
							 
	
*/

void adicionarCliente(ll L,ll R, cliente c, vector<cliente>& cli, ll ind=0){						//adicionar cliente
	
	if(L>=R){																						//se nó folha
		if(c(L) > cli[ind](L)){																		//deixa maior no nó
			cli[ind] = c;
		}
			
		return;
	}
	ll meio=(L+R)/2, filhoL=ind*2+1, filhoR=ind*2+2;												//para avancar na arvore
	if((cli[ind].E >= c.E && cli[ind].R >= c.R) || (cli[ind].E<=c.E && cli[ind].R<=c.R))			//se for f3 e f4
	{
		if(c(meio) >= cli[ind](meio) && c.E>=cli[ind].E && c.R >= cli[ind].R){						//coloca f3 no nó se não estiver E se for preco não negativo
//			cout << "ADICIONANDO/TROCANDO " << c.E << " " << c.R << " em " << ind << "\n";
			swap(cli[ind],c);
		}
		else if(c(meio)<0){																			//preco negativo
			adicionarCliente(meio+1,R,c,cli,filhoR);
		}
		if(c(meio)!=cli[ind](meio))
			return;	
		if(cli[ind].E == 0 && c.E==0)
			return;															
	}
	if(cli[ind].E > c.E){																			//se c for f1 e cli[no] for f2, coloca c como f2
//		cout << "ADICIONANDO " << c.E << " " << c.R << " em " << ind << "\n";
		swap(cli[ind],c);
	}
	if(cli[ind](meio) <= c(meio)){																	//se  f2 >= f1, coloca f2 no nó e avança para filho esquerdo
//		cout << "ADICIONANDO " << c.E << " " << c.R << " em " << ind << "\n";
		swap(cli[ind],c);
		adicionarCliente(L,meio-1,c,cli,filhoL);
	}
	else{																							//se f2<f1, deixa f1 no nó e avança para filho direito
			adicionarCliente(meio+1,R,c,cli,filhoR);
		
	}
}

ll maiorRend(ll L, ll R, ll i, vector<cliente>& cli, ll ind=0){										//maior rendimento
	ll meio=(L+R)/2,filhoL=ind*2+1,filhoR=ind*2+2;													//para avancar na arvore
//	if(i==59){
//		cout << "ENTRAMOS NÓ " << meio << "\n";
//	}
//		cout << "BUSCANDO " << i << " ótimo= " << cli[ind](i) << "\n"; 
//		cout << "CLIENTE " << cli[ind].E << " " << cli[ind].R << "\n";
	if(L>=R || i == meio){
		return cli[ind](i);																			//chegou nó folha ou chegou meio de valor i
	}

	if(i<meio){																						//i está no intervalo do filho esquerdo
		return max(cli[ind](i),maiorRend(L,meio-1,i,cli,filhoL));										//sabe valor para cliente ótimo de meio, agora tem que ver se tem maior rendimento em um intervalo menor que contiver i
	}
	else																							//i está no intervalo do filho direito
		return max(cli[ind](i),maiorRend(meio+1,R,i,cli,filhoR));									//sabe valor para cliente ótimo de meio, agora tem que ver se tem maior rendimento em um intervalo menor que contiver i
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll N,Q;
	cin >> N;
	vector <cliente> cli(N*4);
	for(ll i=0;i<N;i++){
		cin >> S[i] >> P[i];
	}
	cin >> Q;
	ll R,E;
	ll tam=0;
	
	
	for(ll i=0;i<Q;i++){
		char op;
		cin >> op;
		if(op == 'c'){
			cin >> E >> R;
			cliente aux;
			aux.E=E,aux.R=R;
			adicionarCliente(0,N-1,aux,cli);
		}
		else{
			ll I;
			cin >> I;
			I--;
			cout << max((ll)0,maiorRend(0,N-1,I,cli)) << "\n";
		}
	}
	return 0;
}