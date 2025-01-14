#include <iostream>
#include <stack>

int main()
{
    using namespace std;
    // o chefe falará uma sequência de números (implementa-se uma pilha)
    int totalEntradas, soma = 0;
    stack<int> numeros;
    cin >> totalEntradas;
    for (int i = 0; i < totalEntradas; i++)
    {
        int entrada;
        cin>>entrada;
         // se o chefe falar '0', o número anterior deve ser ignorado (retira da pilha)
        if(entrada==0){
            numeros.pop();     
        }else{
            numeros.push(entrada);
        }
    }
    // ao fim da chamada, soma-se a sequência obtida(soma-se elementos da pilha)
    
    while(!numeros.empty()){
        soma+=numeros.top();
        numeros.pop();
    }
    cout << soma<< "\n";
    return 0;
    
}
