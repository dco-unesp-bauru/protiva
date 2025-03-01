#include <iostream>
#include <string>

//Davi Ferreira de Souza
//19/02/2025

using namespace std;

int checa_palindromo(string texto)
{
  int tamanho_string = texto.size();

  for(int i = 0; i < tamanho_string / 2; i++)
  {
    if(texto[i] != texto[tamanho_string - i - 1]) return 0;
  }

  return 1;
}

int main()
{
  string C;
  int n, maior;

  cin >> n;
  cin >> C;

  maior = 1;
  
  for(int i = 0; i < n; i++)
  {
    for(int j = i + 1; j <= n; j++)
    {
      string substring = C.substr(i, j - i);
      if(checa_palindromo(substring) && substring.size() > maior) maior = substring.size();
    }
  }

  cout << maior << endl;
  




}
