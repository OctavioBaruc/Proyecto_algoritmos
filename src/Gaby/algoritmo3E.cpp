/*ALGORITMO 3 — Reverse–Kruskal usando vectores separados

Se guardan u, v y w en vectores separados.
Un vector idx guarda los índices de las aristas.
Se ordenan los índices de acuerdo al peso (mayor a menor).
Luego se procesa en ese orden usando Union–Find.
Cada arista válida se agrega al MST máximo.
Es otra forma de implementar Reverse–Kruskal sin structs.

Tiempo: O(E log E)
Ordenar el vector de índices domina el costo.

Espacio: O(V + E)
Vectores U[], V[], W[] + parent[] + rank[] + idx[].*/

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
    if (rnk[a] < rnk[b]) swap(a, b);
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
        return W[a] > W[b]; // mayor a menor
    });

    parent.resize(V);
    rnk.assign(V, 0);
    for (int i = 0; i < V; i++) parent[i] = i;

    int total = 0;
    for (int i : idx)
        if (unite(U[i], Vv[i]))
            total += W[i];

    cout << "Peso total MST máximo = " << total << endl;
}
