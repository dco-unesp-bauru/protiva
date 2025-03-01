#include <iostream>

//Davi Ferreira de Souza
//19/02/2025

using namespace std;

int main()
{
  int n;

  cin >> n;


  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < n; j++)
    {
      int distancia_x = (j < n / 2 ? j : n - 1 - j);
      int distancia_y = (i < n / 2 ? i : n - 1 - i);

      distancia_x > distancia_y ? cout << distancia_y + 1 << " " : cout << distancia_x + 1 << " ";
    }

    printf("\n");
  }
  
}
