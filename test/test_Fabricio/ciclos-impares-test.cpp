#include <bits/stdc++.h>
using namespace std;

/* ===== TU FUNCIÓN AQUÍ ===== */

vector<int> findOddCycle(const vector<vector<int>>& adj) {
    int n = adj.size();
    vector<int> level(n, -1), parent(n, -1);
    queue<int> q;

    for (int s = 0; s < n; s++) {
        if (level[s] != -1) continue;
        level[s] = 0;
        q.push(s);

        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : adj[u]) {
                if (level[v] == -1) {
                    level[v] = level[u] + 1;
                    parent[v] = u;
                    q.push(v);
                }
                else if (parent[u] != v && ((level[u] - level[v]) % 2 == 0)) {
                    // Reconstruir ciclo
                    vector<int> pathU, pathV;
                    int x = u;

                    while (x != -1) {
                        pathU.push_back(x);
                        x = parent[x];
                    }

                    int y = v;
                    while (y != -1) {
                        pathV.push_back(y);
                        y = parent[y];
                    }

                    unordered_set<int> setU(pathU.begin(), pathU.end());
                    int lca = -1;

                    for (int node : pathV)
                        if (setU.count(node)) { lca = node; break; }

                    vector<int> cycle;
                    x = u;
                    while (x != lca) { cycle.push_back(x); x = parent[x]; }
                    cycle.push_back(lca);

                    vector<int> tmp;
                    y = v;
                    while (y != lca) { tmp.push_back(y); y = parent[y]; }
                    reverse(tmp.begin(), tmp.end());
                    for (int t : tmp) cycle.push_back(t);

                    cycle.push_back(u);
                    return cycle;
                }
            }
        }
    }
    return {};
}

/* ============ TEST ============ */

int main() {
    {   // Tiene ciclo impar
        vector<vector<int>> G = {
            {1,2},
            {0,2},
            {0,1}
        };

        auto cycle = findOddCycle(G);
        cout << "Test 1 (ciclo impar): " 
             << (!cycle.empty() ? "OK" : "ERROR") << "\n";
    }

    {   // No tiene ciclos
        vector<vector<int>> G = {
            {1},
            {0,2},
            {1}
        };

        auto cycle = findOddCycle(G);
        cout << "Test 2 (sin ciclo): "
             << (cycle.empty() ? "OK" : "ERROR") << "\n";
    }
}
