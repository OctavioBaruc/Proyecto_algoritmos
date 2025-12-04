#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;

bool tryKuhn(int u, vector<bool>& used, vector<int>& mt, const vector<vector<int>>& g) {
    if (used[u]) return false;
    used[u] = true;

    for (int v : g[u]) {
        if (mt[v] == -1 || tryKuhn(mt[v], used, mt, g)) {
            mt[v] = u;
            return true;
        }
    }
    return false;
}

int main() {
    vector<vector<int>> g = {
        {0, 1},
        {0},
        {1}
    };

    int n = g.size();
    int m = 2; // nodos lado derecho
    vector<int> mt(m, -1);

    for (int u = 0; u < n; u++) {
        vector<bool> used(n, false);
        tryKuhn(u, used, mt, g);
    }

    cout << "Matching Kuhn:\n";
    for (int i = 0; i < m; i++)
        if (mt[i] != -1)
            cout << mt[i] << " - " << i << "\n";
}