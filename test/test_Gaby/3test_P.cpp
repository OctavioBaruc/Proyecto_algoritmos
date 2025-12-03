
#include <cassert>
#include <vector>
#include <utility>
using namespace std;

const int INF = 1e9;

// --- Función MST Prim con lista de adyacencia y selección lineal ---
int primMST(int V, const vector<vector<pair<int,int>>> &g) {
    vector<int> dist(V, INF);
    vector<bool> used(V, false);
    dist[0] = 0;

    int total = 0;

    for (int i = 0; i < V; i++) {
        int v = -1;
        for (int j = 0; j < V; j++)
            if (!used[j] && (v == -1 || dist[j] < dist[v]))
                v = j;

        used[v] = true;
        total += dist[v];

        for (auto &p : g[v]) {
            int u = p.first, w = p.second;
            if (w < dist[u])
                dist[u] = w;
        }
    }

    return total;
}

// --- Tests básicos ---
int main() {
    int V = 4;
    vector<vector<pair<int,int>>> g(V);

    // Definir aristas
    g[0] = {{1,1},{2,2}};
    g[1] = {{0,1},{2,3},{3,4}};
    g[2] = {{0,2},{1,3},{3,5}};
    g[3] = {{1,4},{2,5}};

    int pesoTotal = primMST(V, g);

    // MST esperado: aristas (0-1,0-2,1-3) -> peso 1+2+4=7
    assert(pesoTotal == 7);

    return 0;
}
