#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;


/*
	o único caso em que jogando de maneira ótima, Pedrinhos perde é se Equalizer conseguir independente de como pedrinho jogue
		Equalizer só perde se=
			tem um número cuja repetição não seja divisível por 3
				se existe um número que não se repete:
					Pedrinho escolhe esse número e vence
				se existe um número que se repete duas vezes exatamente:
					Equalizer nunca pode apagar esse número
					Pedrinho iria precisar escolher esse número para Equalizer escolher o que sobrar, porém como só aparece duas vezes sempre vai ter uma terceira opção para Pedrinho
				para todos os números se repetindo no mínimo 3 vezes:
					Se pedrinho escolhe um número, Equalizer escolhe e apaga o mesmo número. Se tiver uma repetição não divisível por 3, uma hora vai sobrar uma repetição de 1 ou de 2.
							 
	
*/





int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll N;
	cin >> N;
	vector <ll> num(N*3);
	vector <ll> dist;
	map <ll,ll> rep;
	for(ll i=0;i<(3*N);i++){
		cin >> num[i];
		if(rep[num[i]]==0){
			dist.push_back(num[i]);
		}
		rep[num[i]]++;
	}
	bool div3=true;
	for(auto a:dist){
		if(rep[a]%3!=0){
			div3=false;
			break;
		}
	}
	if(div3){
		cout << "N\n";
	}
	else{
		cout << "Y\n";
	}
	return 0;
}