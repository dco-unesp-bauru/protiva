#include <bits/stdc++.h>

//Davi Ferreira de Souza
//09/01/2025

using namespace std;



int main()
{
    int n,s,atual,cont;


    cont = 0;

    cin >> n >> s;
    
    vector<int> x(n);

    for(int i = 0; i < n; i++)
    {
        cin>>x[i];
    }

    
    int contador = 0;

    for (int i = 0; i < n; i++) 
    {
        int soma = 0;

        for (int j = i; j < n; j++) 
        {
            soma += x[j];

            if (soma == s) 
            {
                contador++;
            }
        }
    }

    cout << contador << endl;
}