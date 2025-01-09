#include <bits/stdc++.h>

//Davi Ferreira de Souza
//09/01/2025

#define max 100

using namespace std;


int main()
{
    int n;
    int quadrado[max][max];

    int posx,posy, valorcorreto;

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> quadrado[i][j];
            if(quadrado[i][j] == 0)
            {
                posx = i;
                posy = j;
            }
        }
    }

    int soma = 0;

    for(int i = 0; i < n; i++)
    {
        if(i == posx) continue;
        for(int j = 0; j < n; j++)
        {
            soma+=quadrado[i][j];
        }
        break;
    }

    int soma_errada = 0;

    for(int j = 0; j < n; j++)
    {
        soma_errada += quadrado[posx][j];
    }

    cout << soma - soma_errada << endl;
    cout << posx + 1 << endl;
    cout << posy + 1<< endl;

    return 0;


}