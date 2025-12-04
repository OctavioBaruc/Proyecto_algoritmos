#include <bits/stdc++.h>
using namespace std;

/* ===== TU FUNCIÓN AQUÍ ===== */

bool dfsColor(int u, int c, vector<int>& color, const vector<vector<int>>& adj) {
    color[u] = c;
    for (int v : adj[u]) {
        if (color[v] == -1) {
            if (!dfsColor(v, 1 - c, color, adj)) return false;
        }
        else if (color[v] == color[u]) {
            return false;
        }
    }
    return true;
}

bool isBipartiteDFS(const vector<vector<int>>& adj) {
    int n = adj.size();
    vector<int> color(n, -1);

    for (int i = 0; i < n; i++)
        if (color[i] == -1)
            if (!dfsColor(i, 0, color, adj)) return false;

    return true;
}

/* ============ TEST ============ */

int main() {
    {   // Bipartito
        vector<vector<int>> G = {
            {2,3},
            {3},
            {0},
            {0,1}
        };

        cout << "Test 1 (bipartito): "
             << (isBipartiteDFS(G) ? "OK" : "ERROR") << "\n";
    }

    {   // Ciclo impar
        vector<vector<int>> G = {
            {1,2},
            {0,2},
            {0,1}
        };

        cout << "Test 2 (no bipartito): "
             << (!isBipartiteDFS(G) ? "OK" : "ERROR") << "\n";
    }
}
