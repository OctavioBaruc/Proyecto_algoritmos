#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 1e9;

bool bfs(vector<int>& dist, vector<int>& pairU, vector<int>& pairV, const vector<vector<int>>& g) {
    queue<int> q;
    for (int u = 0; u < pairU.size(); u++) {
        if (pairU[u] == -1) {
            dist[u] = 0;
            q.push(u);
        } else dist[u] = INF;
    }

    int dmax = INF;

    while (!q.empty()) {
        int u = q.front(); q.pop();
        if (dist[u] < dmax) {
            for (int v : g[u]) {
                if (pairV[v] == -1) {
                    dmax = dist[u] + 1;
                } else if (dist[pairV[v]] == INF) {
                    dist[pairV[v]] = dist[u] + 1;
                    q.push(pairV[v]);
                }
            }
        }
    }
    return dmax != INF;
}

bool dfs(int u, vector<int>& dist, vector<int>& pairU, vector<int>& pairV, const vector<vector<int>>& g) {
    for (int v : g[u]) {
        if (pairV[v] == -1 || (dist[pairV[v]] == dist[u] + 1 && dfs(pairV[v], dist, pairU, pairV, g))) {
            pairU[u] = v;
            pairV[v] = u;
            return true;
        }
    }
    dist[u] = INF;
    return false;
}

int main() {
    vector<vector<int>> g = {
        {0},
        {0, 1},
        {1}
    };

    int n = g.size();
    int m = 2;

    vector<int> pairU(n, -1), pairV(m, -1), dist(n);

    int matching = 0;

    while (bfs(dist, pairU, pairV, g)) {
        for (int u = 0; u < n; u++)
            if (pairU[u] == -1)
                if (dfs(u, dist, pairU, pairV, g))
                    matching++;
    }

    cout << "Matching Hopcroft–Karp:\n";
    for (int v = 0; v < m; v++)
        if (pairV[v] != -1)
            cout << pairV[v] << " - " << v << "\n";
}
/*El algoritmo implementa Hopcroft–Karp, que encuentra el emparejamiento máximo en un grafo bipartito.
Primero, el BFS construye niveles y detecta si existen rutas aumentantes más cortas.
Luego, el DFS recorre esas rutas para aumentar el matching emparejando nodos U ↔ V.
Este proceso se repite hasta que ya no existan más rutas aumentantes.
Tiempo: O(√V · E), porque cada fase BFS+DFS cuesta O(E) y se repite O(√V) veces.
Espacio: O(V + E), por almacenar el grafo y los arreglos de emparejamiento y distancias.*/