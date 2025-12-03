/*ALGORITMO 3 — Kruskal SIN usar struct Edge (solo vectores separados)
Es una implementación distinta:
No usa un struct
Guarda u, v, w en tres vectores
Usa un vector de índices para ordenar

Se guardan los extremos y el peso de cada arista en tres vectores separados.
Se crea un vector de índices para ordenar sin usar estructuras.
Los índices se ordenan según el peso de las aristas.
Se usan Union–Find para evitar ciclos.
Cada arista válida se suma al MST.
Es Kruskal, pero implementado de otra forma completamente distinta.

Tiempo: O(E log E)
El ordenamiento del vector de índices domina el tiempo.
Las uniones/finds tienen costo casi constante con compresión.

Espacio: O(V + E)
Se guardan los tres vectores de tamaño E.
Y los vectores parent, rank e idx, de tamaño V o E. */

#include <bits/stdc++.h>
using namespace std;

vector<int> parent, rnk;

int findSet(int v) {
    if (v == parent[v]) return v;
    return parent[v] = findSet(parent[v]);
}

bool unite(int a, int b) {
    a = findSet(a);
    b = findSet(b);
    if (a == b) return false;
    if (rnk[a] < rnk[b]) swap(a,b);
    parent[b] = a;
    if (rnk[a] == rnk[b]) rnk[a]++;
    return true;
}

int main() {
    int V, E;
    cin >> V >> E;

    vector<int> U(E), Vv(E), W(E);
    for (int i = 0; i < E; i++)
        cin >> U[i] >> Vv[i] >> W[i];

    vector<int> idx(E);
    iota(idx.begin(), idx.end(), 0);

    sort(idx.begin(), idx.end(), [&](int a, int b){
        return W[a] < W[b];
    });

    parent.resize(V);
    rnk.assign(V, 0);
    for (int i = 0; i < V; i++) parent[i] = i;

    int pesoTotal = 0;

    for (int i : idx) {
        if (unite(U[i], Vv[i]))
            pesoTotal += W[i];
    }

    cout << "Peso total MST = " << pesoTotal << endl;
}
