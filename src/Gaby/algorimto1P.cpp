/* ALGORITMO 1 — Prim con priority_queue 
Usa un min-heap (priority_queue invertida) para seleccionar la arista de menor peso.

Explicaci+on:
Se usan listas de adyacencia para almacenar el grafo.
La priority_queue selecciona siempre la arista más barata disponible.
Se empieza desde el nodo 0 y se van agregando vecinos no visitados.
Si un nodo ya fue usado, se ignora la arista.
El proceso continúa hasta incluir todos los nodos.
La suma de pesos da el MST.

Tiempo: O(E log V)
Cada arista se inserta en el heap : O(log V)
En total : O(E log V)

Espacio: O(V + E)
Se almacenan las listas de adyacencia (O(E))
Los vectores used y el heap O(V) */

#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P; // (peso, nodo)

int main() {
    int V, E;
    cin >> V >> E;

    vector<vector<P>> g(V);
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({w, v});
        g[v].push_back({w, u});
    }

    vector<bool> used(V, false);
    priority_queue<P, vector<P>, greater<P>> pq;

    pq.push({0, 0});
    int total = 0;

    while (!pq.empty()) {
        auto [w, v] = pq.top(); pq.pop();
        if (used[v]) continue;
        used[v] = true;
        total += w;

        for (auto &e : g[v])
            if (!used[e.second])
                pq.push(e);
    }

    cout << "Peso total MST = " << total << endl;
}
