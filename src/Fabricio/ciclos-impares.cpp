#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <algorithm>
using namespace std;

bool dfs(int u, int c, vector<int>& color, const vector<vector<int>>& g) {
    color[u] = c;
    for (int v : g[u]) {
        if (color[v] == -1) {
            if (!dfs(v, !c, color, g)) return false;
        } else if (color[v] == c) {
            return false; // ciclo impar
        }
    }
    return true;
}

bool tieneCicloImpar(const vector<vector<int>>& g) {
    int n = g.size();
    vector<int> color(n, -1);
    for (int i = 0; i < n; i++)
        if (color[i] == -1 && !dfs(i, 0, color, g))
            return true;
    return false;
}

int main() {
    vector<vector<int>> g = {
        {1, 2},
        {0, 2},
        {0, 1} // ciclo impar (triángulo)
    };

    cout << "Ciclo impar: "
         << (tieneCicloImpar(g) ? "SI" : "NO") << endl;
}
