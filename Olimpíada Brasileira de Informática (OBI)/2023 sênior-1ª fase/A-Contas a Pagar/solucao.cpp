#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int t, aux;
    vector<int> contas; 

    cin >> t;
    for(int i = 0; i < 3; i++)
    {
        cin >> aux;
        contas.push_back(aux);
    }
    sort(contas.begin(), contas.end());
    
    int cPagas = 0;
    for(int i = 0; i < 3; i++)
    {
        if(t >= contas[i])
        {
            t -= contas[i];
            cPagas++;
        }
    }
    
    cout << cPagas << endl;
    return 0;
}
