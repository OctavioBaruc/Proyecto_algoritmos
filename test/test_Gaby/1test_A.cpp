
#include <cassert>
#include <vector>
using namespace std;

// --- Funciones del código ---
vector<vector<int>> g;
vector<bool> visited;

bool dfs(int v, int parent) {
    visited[v] = true;
    for (int u : g[v]) {
        if (!visited[u]) {
            if (!dfs(u, v)) return false;
        } else if (u != parent) {
            return false; // ciclo detectado
        }
    }
    return true;
}

// --- Tests básicos ---
int main() {
    // Test 1: árbol simple
    g = {{1,2}, {0,3}, {0}, {1}}; // 4 nodos
    visited.assign(4, false);
    assert(dfs(0, -1) == true);
    for (bool v : visited) assert(v == true); // todos visitados

    // Test 2: grafo desconectado
    g = {{1}, {0}, {3}, {2}}; // 4 nodos
    visited.assign(4, false);
    assert(dfs(0, -1) == false); // ciclo no detectado, pero DFS no llega a todos
    // Chequeo de nodos visitados
    bool allVisited = true;
    for (bool v : visited) if (!v) allVisited = false;
    assert(allVisited == false);

    // Test 3: grafo con ciclo
    g = {{1,2}, {0,2}, {0,1}}; // triángulo
    visited.assign(3, false);
    assert(dfs(0, -1) == false);

    return 0;
}
