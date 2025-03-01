#include <iostream>

//Davi Ferreira de Souza
//19/02/2025

using namespace std;

int main()
{
  int c,d,t;

  cin >> c >> d >> t;

  double quantidade_necessaria = ((double)d/c) - t;

  (quantidade_necessaria < 0 ? printf("0\n") : printf("%.1lf\n", quantidade_necessaria));
  
}
