
#include <cassert>
#include <vector>
#include <algorithm>
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

// --- Test básico MST máximo ---
int main() {
    int V = 4;
    parent.resize(V);
    rnk.assign(V, 0);
    for (int i = 0; i < V; i++) parent[i] = i;

    vector<Edge> edges = {
        {0,1,1},
        {0,2,2},
        {1,2,3},
        {1,3,4},
        {2,3,5}
    };

    // Ordenar de mayor a menor
    sort(edges.begin(), edges.end(), [](auto &a, auto &b){ return a.w > b.w; });

    int total = 0;
    for (auto &e : edges)
        if (unite(e.u, e.v))
            total += e.w;

    // MST máximo esperado: aristas (2-3,1-3,1-2) -> peso 5+4+3=12
    assert(total == 12);

    // Verificar que todos los nodos estén en un solo conjunto
    int rep = findSet(0);
    for (int i = 1; i < V; i++)
        assert(findSet(i) == rep);

    return 0;
}
