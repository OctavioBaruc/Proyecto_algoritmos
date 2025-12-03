/* ALGORITMO 2 — Prim con matriz de adyacencia + búsqueda lineal
No usa priority_queue.
Selecciona el siguiente nodo buscando el mínimo manualmente.
Esta versión es común cuando el grafo es denso.

Explicación:
Se usa una matriz de adyacencia, no listas.
dist[i] guarda el costo mínimo para conectar el nodo i al MST.
Cada paso elige el nodo no usado con dist más pequeño.
Luego actualiza las distancias de sus vecinos.
El proceso se repite V veces.
Es simple, funciona bien en grafos densos.

Tiempo: O(V²)
En cada iteración se busca el mínimo recorriendo todos los nodos O(V).
Se hacen V iteraciones: O(V²).

Espacio: O(V²)
Usa una matriz completa de adyacencia (V × V). */
#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
    int V, E;
    cin >> V >> E;

    vector<vector<int>> g(V, vector<int>(V, INF));
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u][v] = g[v][u] = w;
    }

    vector<bool> used(V, false);
    vector<int> dist(V, INF);
    dist[0] = 0;

    int total = 0;

    for (int i = 0; i < V; i++) {
        int v = -1;
        for (int j = 0; j < V; j++)
            if (!used[j] && (v == -1 || dist[j] < dist[v]))
                v = j;

        used[v] = true;
        total += dist[v];

        for (int u = 0; u < V; u++)
            if (g[v][u] < dist[u])
                dist[u] = g[v][u];
    }

    cout << "Peso total MST = " << total << endl;
}
