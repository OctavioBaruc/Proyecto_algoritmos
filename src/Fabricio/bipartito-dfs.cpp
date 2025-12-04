#include <iostream>
#include <vector>
using namespace std;

bool dfs(int u, int c, vector<int>& color, const vector<vector<int>>& g) {
    color[u] = c;
    for (int v : g[u]) {
        if (color[v] == -1) {
            if (!dfs(v, !c, color, g)) return false;
        } else if (color[v] == color[u]) {
            return false;
        }
    }
    return true;
}

bool esBipartitoDFS(const vector<vector<int>>& g) {
    int n = g.size();
    vector<int> color(n, -1);
    for (int i = 0; i < n; i++)
        if (color[i] == -1 && !dfs(i, 0, color, g))
            return false;
    return true;
}

int main() {
    vector<vector<int>> g = {
        {1, 3},
        {0, 2},
        {1, 3},
        {0, 2}
    };

    cout << "Bipartito DFS: "
         << (esBipartitoDFS(g) ? "SI" : "NO") << endl;
}