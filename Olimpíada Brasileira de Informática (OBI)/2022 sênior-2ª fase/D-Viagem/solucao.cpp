#include <iostream>
#include <vector>
#include <queue>
#include <limits>

// Davi Ferreira de Souza
// 01/03/2025

using namespace std;

struct Aresta {
    int destino, tempo, custo;
};

struct Estado {
    int ilha, tempo, custo;
    bool operator>(const Estado &outro) const {
        return tempo > outro.tempo;
    }
};

int menor_tempo(int V, int N, int M, vector<vector<Aresta> > &grafo, int X, int Y) {
    vector<vector<int> > dist(N + 1, vector<int>(V + 1, numeric_limits<int>::max()));
    priority_queue<Estado, vector<Estado>, greater<Estado> > pq;
    
    dist[X][0] = 0;
    pq.push({X, 0, 0});
    
    while (!pq.empty()) {
        Estado atual = pq.top();
        pq.pop();
        
        int ilha = atual.ilha, tempo = atual.tempo, custo = atual.custo;
        
        if (ilha == Y) return tempo;
        
        if (tempo > dist[ilha][custo]) continue;
        
        for (const Aresta &vizinho : grafo[ilha]) {
            int nova_ilha = vizinho.destino;
            int novo_tempo = tempo + vizinho.tempo;
            int novo_custo = custo + vizinho.custo;
            
            if (novo_custo <= V && novo_tempo < dist[nova_ilha][novo_custo]) {
                dist[nova_ilha][novo_custo] = novo_tempo;
                pq.push({nova_ilha, novo_tempo, novo_custo});
            }
        }
    }
    return -1;
}

int main() {
    int V, N, M;
    cin >> V >> N >> M;
    
    vector<vector<Aresta>> grafo(N + 1);
    
    for (int i = 0; i < M; i++) {
        int A, B, T, P;
        cin >> A >> B >> T >> P;
        grafo[A].push_back({B, T, P});
        grafo[B].push_back({A, T, P});
    }
    
    int X, Y;
    cin >> X >> Y;
    
    cout << menor_tempo(V, N, M, grafo, X, Y) << endl;
    
    return 0;
}
