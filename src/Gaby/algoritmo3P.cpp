/*ALGORITMO 3 — Prim con listas + búsqueda lineal (sin heap)
Usa listas de adyacencia como el algoritmo 1
PERO sin priority_queue
Se busca el mínimo manualmente usando distancias
Es diferente al #2 porque NO usa matriz, y diferente al #1 porque NO usa heap.

Explicación:
Usa listas de adyacencia como Prim estándar.
Guarda el costo mínimo para conectar cada nodo usando dist.
Busca el nodo de menor costo de forma lineal (sin heap).
Lo marca como parte del MST.
Actualiza los costos de todos sus vecinos.
Es más simple que el Prim con heap, aunque menos eficiente.

Tiempo: O(V² + E) ˜ O(V²)
Búsqueda del mínimo: O(V) repetida V veces ? O(V²).
Actualizar vecinos cuesta O(E) total.

Espacio: O(V + E)
Guarda listas de adyacencia (O(E))
Vectores dist y used de tamaño O(V) */

#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
    int V, E;
    cin >> V >> E;

    vector<vector<pair<int,int>>> g(V);
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    vector<int> dist(V, INF);
    vector<bool> used(V, false);
    dist[0] = 0;

    int total = 0;

    for (int i = 0; i < V; i++) {
        int v = -1;
        for (int j = 0; j < V; j++)
            if (!used[j] && (v == -1 || dist[j] < dist[v]))
                v = j;

        used[v] = true;
        total += dist[v];

        for (auto &p : g[v]) {
            int u = p.first, w = p.second;
            if (w < dist[u])
                dist[u] = w;
        }
    }

    cout << "Peso total MST = " << total << endl;
}
