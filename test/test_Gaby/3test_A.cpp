
#include <cassert>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

vector<vector<int>> g;

bool bfsConectado(int V) {
    vector<bool> vis(V, false);
    queue<int> q;
    q.push(0);
    vis[0] = true;

    while (!q.empty()) {
        int v = q.front(); q.pop();
        for (int u : g[v]) {
            if (!vis[u]) {
                vis[u] = true;
                q.push(u);
            }
        }
    }

    for (bool x : vis) if (!x) return false;
    return true;
}

bool dfsCiclos(int V) {
    vector<bool> vis(V, false);
    vector<int> parent(V, -1);
    stack<int> st;

    st.push(0);
    parent[0] = -1;

    while (!st.empty()) {
        int v = st.top(); 
        st.pop();

        if (!vis[v]) vis[v] = true;

        for (int u : g[v]) {
            if (!vis[u]) {
                parent[u] = v;
                st.push(u);
            } else if (u != parent[v]) {
                return true; // ciclo detectado
            }
        }
    }
    return false;
}

// --- Tests simples ---
int main() {
    // Test 1: un árbol simple
    g = {{1,2}, {0,3}, {0}, {1}}; // 4 nodos
    assert(bfsConectado(4) == true);
    assert(dfsCiclos(4) == false);

    // Test 2: grafo desconectado
    g = {{1}, {0}, {3}, {2}}; // 4 nodos
    assert(bfsConectado(4) == false);

    // Test 3: grafo con ciclo
    g = {{1,2}, {0,2}, {0,1}}; // triángulo
    assert(dfsCiclos(3) == true);

    return 0;
}
