
#include <cassert>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1e9;

// --- Función MST Prim con matriz de adyacencia ---
int primMST(int V, const vector<vector<int>> &g) {
    vector<bool> used(V, false);
    vector<int> dist(V, INF);
    dist[0] = 0;

    int total = 0;

    for (int i = 0; i < V; i++) {
        int v = -1;
        for (int j = 0; j < V; j++)
            if (!used[j] && (v == -1 || dist[j] < dist[v]))
                v = j;

        used[v] = true;
        total += dist[v];

        for (int u = 0; u < V; u++)
            if (g[v][u] < dist[u])
                dist[u] = g[v][u];
    }

    return total;
}

// --- Tests básicos ---
int main() {
    int V = 4;
    vector<vector<int>> g(V, vector<int>(V, INF));

    // Definir aristas
    g[0][1] = g[1][0] = 1;
    g[0][2] = g[2][0] = 2;
    g[1][2] = g[2][1] = 3;
    g[1][3] = g[3][1] = 4;
    g[2][3] = g[3][2] = 5;

    int pesoTotal = primMST(V, g);

    // MST esperado: aristas (0-1,0-2,1-3) -> peso 1+2+4=7
    assert(pesoTotal == 7);

    return 0;
}
