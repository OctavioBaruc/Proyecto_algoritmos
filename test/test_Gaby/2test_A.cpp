
#include <cassert>
#include <vector>
#include <queue>
using namespace std;

// --- Funciones del código ---
vector<vector<int>> g;
vector<bool> visited;

bool hayCiclo(int v, int parent) {
    visited[v] = true;
    for (int u : g[v]) {
        if (!visited[u]) {
            if (hayCiclo(u, v)) return true;
        } else if (u != parent) {
            return true; // ciclo encontrado
        }
    }
    return false;
}

bool conectado(int V) {
    vector<bool> vis(V, false);
    queue<int> q;
    q.push(0);
    vis[0] = true;

    while (!q.empty()) {
        int v = q.front(); q.pop();
        for (int u : g[v]) {
            if (!vis[u]) vis[u] = true, q.push(u);
        }
    }

    for (bool x : vis) if (!x) return false;
    return true;
}

// --- Tests básicos ---
int main() {
    // Test 1: árbol simple
    g = {{1,2}, {0,3}, {0}, {1}}; // 4 nodos
    visited.assign(4, false);
    assert(conectado(4) == true);
    assert(hayCiclo(0, -1) == false);

    // Test 2: grafo desconectado
    g = {{1}, {0}, {3}, {2}}; // 4 nodos
    visited.assign(4, false);
    assert(conectado(4) == false);

    // Test 3: grafo con ciclo
    g = {{1,2}, {0,2}, {0,1}}; // triángulo
    visited.assign(3, false);
    assert(hayCiclo(0, -1) == true);

    return 0;
}
