#include <iostream>
#include <vector>
#include <queue>

using std::cout;
using std::endl;
using std::vector;
using std::queue;
using std::pair;

vector<pair<int,int>> eliminationMatching(vector<vector<int>>& g) {
    int n = static_cast<int>(g.size());
    vector<int> degree(n,0);
    queue<int> q;
    vector<char> removed(n, 0);
    vector<pair<int,int>> matching;

    for (int i = 0; i < n; ++i) {
        degree[i] = static_cast<int>(g[i].size());
        if (degree[i] == 1) q.push(i);
    }

    while (!q.empty()) {
        int leaf = q.front(); q.pop();
        if (removed[leaf] || degree[leaf] != 1) continue;

        int neighbor = -1;
        for (int v : g[leaf]) {
            if (!removed[v]) { neighbor = v; break; }
        }
        if (neighbor == -1) continue;

        matching.push_back({leaf, neighbor});
        removed[leaf] = removed[neighbor] = 1;

        for (int v : g[neighbor]) {
            if (!removed[v]) {
                --degree[v];
                if (degree[v] == 1) q.push(v);
            }
        }
    }
    return matching;
}

int main() {
    // Ejemplo: camino de 4 nodos 0-1-2-3
    vector<vector<int>> g(4);
    g[0] = {1};
    g[1] = {0,2};
    g[2] = {1,3};
    g[3] = {2};

    auto m = eliminationMatching(g);
    cout << "Matching generado por eliminación de hojas:\n";
    for (auto &p : m) cout << p.first << " - " << p.second << "\n";
    return 0;
}
 