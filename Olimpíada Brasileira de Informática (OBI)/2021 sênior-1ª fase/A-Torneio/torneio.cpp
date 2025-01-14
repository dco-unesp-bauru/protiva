#include <iostream>

int main()
{   
    using namespace std;
    //deve-se contar quantas vitórias ao total o jogador teve
    int totalVitorias = 0; 
    for (int i = 0; i <6; i++)
    {
        char resultadoJogo;
        cout << "Resultado:\n";
        cin >> resultadoJogo;
        if (resultadoJogo == 'v')
        {
            totalVitorias++;
            cout << totalVitorias;
        }
    }
    //com base no total de vitórias, ele se classifica para um grupo(1, 2 ou 3), se perder todos não se classifica(-1)
    if (totalVitorias >= 5)
    {
        cout << '1';
    }
    else if (totalVitorias >= 3)
    {
        cout << '2';
    }
    else if (totalVitorias >= 1)
    {
        cout << '3';
    }
    else
    {
        cout << "-1";
    }

    return 0;
}