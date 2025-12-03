/*ALGORITMO 2 — Reverse–Kruskal con Union–Find sin compresión

Reordena todas las aristas de mayor peso a menor.
El Union–Find es básico, sin optimizaciones.
Cada arista válida se agrega al árbol de expansión máximo.
Las aristas que conectan nodos ya unidos se descartan.
Tiene el mismo resultado que el clásico pero funciona diferente.
Suma los pesos aceptados para obtener el MST máximo

Tiempo: O(E log E + E a(V)) ˜ O(E log E)
Por ordenamiento + Union–Find básico.

Espacio: O(V + E)
Aristas + vector parent.*/

#include <bits/stdc++.h>
using namespace std;

struct Edge { int u, v, w; };

vector<int> parent;

int findSet(int v) {
    while (v != parent[v]) v = parent[v]; // sin compresión
    return v;
}

bool unite(int a, int b) {
    a = findSet(a);
    b = findSet(b);
    if (a == b) return false;
    parent[b] = a; // unión simple
    return true;
}

int main() {
    int V, E;
    cin >> V >> E;

    vector<Edge> edges(E);
    for (auto &e : edges) cin >> e.u >> e.v >> e.w;

    sort(edges.begin(), edges.end(), [](auto &a, auto &b){
        return a.w > b.w;
    });

    parent.resize(V);
    for (int i = 0; i < V; i++) parent[i] = i;

    int total = 0;
    for (auto &e : edges)
        if (unite(e.u, e.v))
            total += e.w;

    cout << "Peso total MST máximo = " << total << endl;
}
