#include <bits/stdc++.h>

//Davi Ferreira de Souza
//09/01/2025

using namespace std;

int main()
{
    int d,a,n,diarias_adicionais;

    cin >> d >> a >> n;

    diarias_adicionais = n;

    if(n > 15) diarias_adicionais = 15;

    int diaria_adicional = d + (diarias_adicionais - 1) * a;

    cout << (31 - n + 1) * diaria_adicional << endl;
    
    return 0;

}