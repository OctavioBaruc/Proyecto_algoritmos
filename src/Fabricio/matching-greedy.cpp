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

/*El algoritmo obtiene un matching greedy recorriendo los nodos en orden y emparejando cada uno con el primer vecino disponible.
Para cada nodo no usado, se busca un vecino también libre; si existe, ambos se marcan como usados y se agrega el par al matching.
El proceso continúa sin retroceder ni deshacer emparejamientos, por lo que no garantiza el matching máximo.
Es simple y rápido, ideal como aproximación inicial o heurística.
Tiempo: O(V + E), porque cada nodo y cada arista se revisa como máximo una vez.
Espacio: O(V), por el arreglo used y el vector donde se guardan los pares emparejados.*/