#include<iostream>
#include<vector>
#include<queue>
#include<utility>
#include<climits> 

using namespace std;

int main()
{
    int n, b, c;
    cin >> n >> b;
    vector<vector<pair<int, int> > > graf(n); // Grafo: 

    for(int k = 0; k < b; k++)
    {
        int i, j, peso;
        cin >> i >> j >> peso;
        i--; j--; 
        graf[i].push_back({j, peso}); // Vértice e peso
        graf[j].push_back({i, peso}); 
    }
    
    cin >> c;
    for(int k = 0; k < c; k++)
    {
        int x, y;
        cin >> x >> y;
        x--; y--; 

        vector<int> gargalo(n, INT_MIN);
        gargalo[x] = INT_MAX;

        // Priorizamos os vértices com os maiores gargalos
        priority_queue<pair<int, int> > dij; // -gargalo, vértice
        dij.push({-INT_MAX, x}); 

        while(!dij.empty())
        {
            int v = dij.top().second;
            int w = -dij.top().first; // Negativo para priorizar maiores gargalos
            dij.pop();

            if(w != gargalo[v])
                continue;

            for(auto edge : graf[v])
            {
                int u = edge.first;
                int peso = edge.second;

                int novoGargalo = min(gargalo[v], peso);
                if(gargalo[u] < novoGargalo)
                {
                    gargalo[u] = novoGargalo;
                    dij.push({-gargalo[u], u}); 
                }
            }
        }

        cout << gargalo[y] << endl;
        
    }
    
    return 0;
}
