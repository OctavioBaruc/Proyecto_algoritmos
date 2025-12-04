#include <bits/stdc++.h>
using namespace std;

/* ===== TU FUNCIÓN AQUÍ ===== */

bool isBipartiteBFS(const vector<vector<int>>& adj) {
    int n = adj.size();
    vector<int> color(n, -1);
    queue<int> q;

    for (int s = 0; s < n; s++) {
        if (color[s] != -1) continue;

        color[s] = 0;
        q.push(s);

        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : adj[u]) {
                if (color[v] == -1) {
                    color[v] = 1 - color[u];
                    q.push(v);
                }
                else if (color[v] == color[u]) {
                    return false;
                }
            }
        }
    }
    return true;
}

/* ============ TEST ============ */

int main() {
    {   // Grafo bipartito
        vector<vector<int>> G = {
            {2,3},
            {3},
            {0},
            {0,1}
        };

        cout << "Test 1 (bipartito): "
             << (isBipartiteBFS(G) ? "OK" : "ERROR") << "\n";
    }

    {   // Ciclo impar: 0-1-2-0
        vector<vector<int>> G = {
            {1,2},
            {0,2},
            {0,1}
        };

        cout << "Test 2 (no bipartito): "
             << (!isBipartiteBFS(G) ? "OK" : "ERROR") << "\n";
    }
}
