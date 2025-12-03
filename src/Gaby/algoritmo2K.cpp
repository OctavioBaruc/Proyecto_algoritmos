/* ALGORITMO 2 — Kruskal con Union–Find SIN compresión de caminos

Se ordenan las aristas en orden creciente de peso.
Union–Find se hace sin compresión, lo cual es más básico.
El Find camina hacia arriba hasta la raíz sin optimizar.
Cada arista que conecta conjuntos diferentes se agrega al MST.
Es el mismo Kruskal pero con estructura más simple.
El resultado final es el mismo MST.

Tiempo: O(E log E + E a(V)) ˜ O(E log E)
Ordenar sigue costando O(E log E).
"findSet" es más lento pero sigue siendo casi lineal amortizado.

Espacio: O(V + E)
Se almacenan todas las aristas.
Un vector parent de tamaño V. */
#include <bits/stdc++.h>
using namespace std;

struct Edge { int u, v, w; };

vector<int> parent;

int findSet(int v) {
    while (v != parent[v]) v = parent[v];  // sin compresión
    return v;
}

bool unite(int a, int b) {
    a = findSet(a);
    b = findSet(b);
    if (a == b) return false;
    parent[b] = a;   // unión simple
    return true;
}

int main() {
    int V, E;
    cin >> V >> E;

    vector<Edge> edges(E);
    for (auto &e : edges) cin >> e.u >> e.v >> e.w;

    sort(edges.begin(), edges.end(), [](auto &a, auto &b){
        return a.w < b.w;
    });

    parent.resize(V);
    for (int i = 0; i < V; i++) parent[i] = i;

    int pesoTotal = 0;

    for (auto &e : edges) {
        if (unite(e.u, e.v))
            pesoTotal += e.w;
    }

    cout << "Peso total MST = " << pesoTotal << endl;
}
