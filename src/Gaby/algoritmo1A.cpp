/* ALGORITMO 1 : COMPROBAR LAS 3 PRUEBAS PARA QUE SEA ÁRBOL (DFS RECURSIVO)

Primero revisa si el número de aristas cumple E = V - 1, condición básica de los árboles.
Luego construye una lista de adyacencia para el grafo no dirigido.
Hace un DFS desde el nodo 0, marcando cada nodo como visitado.
Si durante el DFS encuentra un nodo visitado que no es el padre, detecta un ciclo.
Al terminar, revisa si todos los nodos fueron visitados para asegurar conectividad.
Si todo lo anterior se cumple, el grafo es un árbol. 

Tiempo: O(V + E)
El DFS visita cada vértice una sola vez, y recorre cada arista una sola vez.
Revisar la condición |E| = |V| – 1 es O(1).
Por eso, el tiempo total es O(V + E).

Espacio: O(V)
Se guarda un vector visited de tamaño V.
La recursión del DFS puede llegar a tener profundidad V en el peor caso.
La suma sigue siendo O(V).*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<bool> visited;

bool dfs(int v, int parent) {
    visited[v] = true;
    for (int u : g[v]) {
        if (!visited[u]) {
            if (!dfs(u, v)) return false;
        } else if (u != parent) {
            return false; // ciclo detectado
        }
    }
    return true;
}

int main() {
    int V, E;
    cin >> V >> E;

    if (E != V - 1) {
        cout << "No es arbol\n";
        return 0;
    }

    g.assign(V, {});
    visited.assign(V, false);

    for (int i = 0; i < E; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    // Comprobar conectividad y ciclos
    if (!dfs(0, -1)) {
        cout << "No es arbol\n";
        return 0;
    }

    // Verificar que todos fueron visitados
    for (bool v : visited) {
        if (!v) {
            cout << "No es arbol\n";
            return 0;
        }
    }

    cout << "Es arbol\n";
}
