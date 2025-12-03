/* ALGORITMO 1 — Kruskal clásico (con Union–Find con compresión + union por rango)

Se leen todas las aristas y se ordenan de menor peso a mayor.
Se inicializa Union–Find para manejar componentes del grafo.
Se recorre cada arista en orden creciente.
Si sus extremos están en distintos conjuntos, se unen y se agrega al MST.
La compresión de caminos y unión por rango aceleran las búsquedas.
El peso final del MST es la suma de los pesos aceptados.

Tiempo: O(E log E)
Ordenar las aristas cuesta O(E log E).
Cada operación Union/Find es casi O(1) por las optimizaciones.
El total queda dominado por el ordenamiento.

Espacio: O(V + E)
Se guardan todas las aristas (O(E))
Vector parent y rank son de tamaño O(V). */

#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, w;
};

vector<int> parent, rnk;

int findSet(int v) {
    if (v == parent[v]) return v;
    return parent[v] = findSet(parent[v]); // compresión
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
        return a.w < b.w;
    });

    parent.resize(V);
    rnk.assign(V, 0);
    for (int i = 0; i < V; i++) parent[i] = i;

    int pesoTotal = 0;

    for (auto &e : edges) {
        if (unite(e.u, e.v)) {
            pesoTotal += e.w;
        }
    }

    cout << "Peso total MST = " << pesoTotal << endl;
}
