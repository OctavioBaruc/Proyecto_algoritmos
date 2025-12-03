/* ALGORITMO 1 — Reverse–Kruskal clásico (struct + Union–Find optimizado)

Se leen las aristas y se ordenan de mayor a menor.
Se usa Union–Find con compresión y rango para unir componentes.
Cada arista une dos conjuntos distintos y se agrega al MST máximo.
Las aristas que forman ciclos se ignoran.
Es exactamente Kruskal, pero invertido.
El total acumulado es el peso del árbol de expansión máximo.

Tiempo: O(E log E)
El ordenamiento domina; las operaciones Union/Find son casi O(1).

Espacio: O(V + E)
Aristas + vectores parent y rank.*/
#include <bits/stdc++.h>
using namespace std;

struct Edge { int u, v, w; };

vector<int> parent, rnk;

int findSet(int v) {
    if (v == parent[v]) return v;
    return parent[v] = findSet(parent[v]);
}

bool unite(int a, int b) {
    a = findSet(a);
    b = findSet(b);
    if (a == b) return false;
    if (rnk[a] < rnk[b]) swap(a, b);
    parent[b] = a;
    if (rnk[a] == rnk[b]) rnk[a]++;
    return true;
}

int main() {
    int V, E;
    cin >> V >> E;

    vector<Edge> edges(E);
    for (auto &e : edges) cin >> e.u >> e.v >> e.w;

    sort(edges.begin(), edges.end(), [](auto &a, auto &b){
        return a.w > b.w;   // de MAYOR a menor
    });

    parent.resize(V);
    rnk.assign(V, 0);
    for (int i = 0; i < V; i++) parent[i] = i;

    int total = 0;

    for (auto &e : edges)
        if (unite(e.u, e.v))
            total += e.w;

    cout << "Peso total MST máximo = " << total << endl;
}
