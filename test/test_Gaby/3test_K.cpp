#include <cassert>
#include <vector>
#include <numeric>
#include <algorithm>
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

// --- Tests básicos ---
int main() {
    int V = 4;
    int E = 5;

    vector<int> U = {0,0,1,1,2};
    vector<int> Vv = {1,2,2,3,3};
    vector<int> W = {1,2,3,4,5};

    // Crear vector de índices
    vector<int> idx(E);
    iota(idx.begin(), idx.end(), 0);

    // Ordenar índices por peso
    sort(idx.begin(), idx.end(), [&](int a, int b){ return W[a] < W[b]; });

    // Inicializar conjuntos
    parent.resize(V);
    rnk.assign(V, 0);
    for (int i = 0; i < V; i++) parent[i] = i;

    int pesoTotal = 0;
    for (int i : idx) {
        if (unite(U[i], Vv[i]))
            pesoTotal += W[i];
    }

    // MST esperado: aristas (0-1,0-2,1-3) -> peso 1+2+4=7
    assert(pesoTotal == 7);

    // Verificar que todos los nodos estén en un solo conjunto
    int rep = findSet(0);
    for (int i = 1; i < V; i++)
        assert(findSet(i) == rep);

    return 0;
}
