#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int l, c;
    int result = 0;
    vector<vector<int> > matriz;
    cin >> l >> c; 
    
    for(int i = 0; i < l; i++)
    {
        vector<int> line;
        for(int j = 0; j < c; j++)
        {
            int value;
            cin >> value;
            line.push_back(value);
        }
        matriz.push_back(line);
    }

    int numSales = 0, l2, c2; 
    cin >> numSales;
    
    for(int i = 0; i < numSales; i++)
    {
        cin >> l2;
        cin >> c2;
        
        if(matriz[l2-1][c2-1] > 0)
        {
            matriz[l2-1][c2-1]--;
            result++;
            
        }
    }
    cout << result << endl;
    
    return 0;
}
