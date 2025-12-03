
#include <cassert>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int,int> P; // (peso, nodo)

// --- Función MST Prim simplificada para test ---
int primMST(int V, const vector<vector<P>> &g) {
    vector<bool> used(V, false);
    priority_queue<P, vector<P>, greater<P>> pq;

    pq.push({0, 0});
    int total = 0;

    while (!pq.empty()) {
        auto [w, v] = pq.top(); pq.pop();
        if (used[v]) continue;
        used[v] = true;
        total += w;

        for (auto &e : g[v])
            if (!used[e.second])
                pq.push(e);
    }

    return total;
}

// --- Tests básicos ---
int main() {
    // Grafo de prueba
    int V = 4;
    vector<vector<P>> g(V);
    g[0] = {{1,1},{2,2}};
    g[1] = {{1,0},{3,3},{3,2}};
    g[2] = {{2,0},{3,1},{5,3}};
    g[3] = {{4,1},{5,2}};

    int pesoTotal = primMST(V, g);

    // MST esperado: aristas (0-1,0-2,1-3) -> peso 1+2+4=7
    assert(pesoTotal == 7);

    return 0;
}
