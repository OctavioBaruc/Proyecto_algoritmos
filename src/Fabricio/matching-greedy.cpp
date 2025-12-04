#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>

using namespace std;

vector<pair<int,int>> greedyMatching(vector<vector<int>>& g) {
    int n = g.size();
    vector<bool> used(n, false);
    vector<pair<int,int>> match;

    for (int u = 0; u < n; u++) {
        if (used[u]) continue;
        for (int v : g[u]) {
            if (!used[v]) {
                used[u] = used[v] = true;
                match.push_back({u, v});
                break;
            }
        }
    }
    return match;
}

int main() {
    vector<vector<int>> g = {
        {1},
        {0, 2},
        {1}
    };

    auto res = greedyMatching(g);
    cout << "Matching greedy:\n";
    for (auto& p : res)
        cout << p.first << " - " << p.second << "\n";
}