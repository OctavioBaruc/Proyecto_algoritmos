#include <bits/stdc++.h>
using namespace std;

/* ===== TU FUNCIÓN AQUÍ ===== */

set<pair<int,int>> greedyMatching(const vector<vector<int>>& adj) {
    int n = adj.size();
    vector<bool> used(n, false);
    set<pair<int,int>> M;

    for (int u = 0; u < n; u++) {
        for (int v : adj[u]) {
            if (!used[u] && !used[v]) {
                used[u] = used[v] = true;
                M.insert({min(u,v), max(u,v)});
            }
        }
    }
    return M;
}

/* ============ TEST ============ */

int main() {
    // Grafo simple para matching
    vector<vector<int>> G = {
        {2,3},
        {3},
        {0},
        {0,1}
    };

    auto M = greedyMatching(G);

    cout << "Matching encontrado:\n";
    for (auto& p : M) {
        cout << "  (" << p.first << ", " << p.second << ")\n";
    }

    cout << (M.size() >= 1 ? "OK\n" : "ERROR\n");
}
