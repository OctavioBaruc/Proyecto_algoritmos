#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <algorithm>
using namespace std;

bool dfs(int u, int c, vector<int>& color, const vector<vector<int>>& g) {
    color[u] = c;
    for (int v : g[u]) {
        if (color[v] == -1) {
            if (!dfs(v, !c, color, g)) return false;
        } else if (color[v] == c) {
            return false; // ciclo impar
        }
    }
    return true;
}

bool tieneCicloImpar(const vector<vector<int>>& g) {
    int n = g.size();
    vector<int> color(n, -1);
    for (int i = 0; i < n; i++)
        if (color[i] == -1 && !dfs(i, 0, color, g))
            return true;
    return false;
}

int main() {
    vector<vector<int>> g = {
        {1, 2},
        {0, 2},
        {0, 1} // ciclo impar (triángulo)
    };

    cout << "Ciclo impar: "
         << (tieneCicloImpar(g) ? "SI" : "NO") << endl;
}

/*El algoritmo detecta si un grafo tiene un ciclo impar usando coloreo por DFS.
Cada nodo se colorea con 0 o 1, e intenta asignar el color opuesto a sus vecinos durante el recorrido.
Si algún vecino ya coloreado tiene el mismo color, significa que hay un ciclo impar.
Se revisan todas las componentes del grafo comenzando desde nodos no visitados.
Tiempo: O(V + E), porque cada arista y cada nodo se procesa una vez.
Espacio: O(V), por el arreglo de colores y la pila implícita del DFS.*/