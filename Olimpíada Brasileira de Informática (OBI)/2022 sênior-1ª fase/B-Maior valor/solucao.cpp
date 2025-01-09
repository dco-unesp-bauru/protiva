#include <bits/stdc++.h>

//Davi Ferreira de Souza
//09/01/2025

using namespace std;

int somaValores(int num)
{
    int soma = 0;

    while(num > 0)
    {
        soma += num % 10;
        num /= 10;
    }

    return soma;
}


int main()
{
    int n,m,s;

    cin >> n >> m >> s;

    for(int i = m; i > n; i--)
    {
        if(somaValores(i) == s)
        {
            cout << i << endl;
            return 0;
        }
        
    }

    cout << -1 << endl;

    return 0;
}