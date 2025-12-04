#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;

bool tryKuhn(int u, vector<bool>& used, vector<int>& mt, const vector<vector<int>>& g) {
    if (used[u]) return false;
    used[u] = true;

    for (int v : g[u]) {
        if (mt[v] == -1 || tryKuhn(mt[v], used, mt, g)) {
            mt[v] = u;
            return true;
        }
    }
    return false;
}

int main() {
    vector<vector<int>> g = {
        {0, 1},
        {0},
        {1}
    };

    int n = g.size();
    int m = 2; // nodos lado derecho
    vector<int> mt(m, -1);

    for (int u = 0; u < n; u++) {
        vector<bool> used(n, false);
        tryKuhn(u, used, mt, g);
    }

    cout << "Matching Kuhn:\n";
    for (int i = 0; i < m; i++)
        if (mt[i] != -1)
            cout << mt[i] << " - " << i << "\n";
}

/*
El algoritmo implementa Kuhn, un método por DFS para encontrar un emparejamiento máximo en grafos bipartitos.
Para cada nodo del lado izquierdo, intenta encontrar una ruta aumentante usando tryKuhn.
La función recorre vecinos y, si un nodo del lado derecho está libre o puede reubicarse su pareja, se forma un nuevo emparejamiento.
Cada intento reinicia el arreglo used para evitar ciclos dentro del mismo DFS.
Tiempo: O(V · E), porque se ejecuta un DFS O(E) para cada nodo del lado izquierdo.
Espacio: O(V), por el arreglo used y la lista de emparejamiento mt.
*/