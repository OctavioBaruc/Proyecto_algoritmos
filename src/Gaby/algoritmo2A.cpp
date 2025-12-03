/* ALGORITMO 2 : COMPROBAR LAS 3 PRUEBAS PARA QUE SEA ÁRBOL (BFS + DFS POR SEPARADO)

Revisa la condición E = V - 1 como en todo árbol.
Usa BFS para comprobar que todos los nodos son alcanzables (conectividad).
Si algún nodo no se visita con BFS, no es un árbol.
Luego usa un DFS separado para detectar ciclos.
Si DFS encuentra un nodo visitado distinto del padre, hay un ciclo.
Si está conectado y sin ciclos, es un árbol.

Tiempo: O(V + E)
El BFS recorre todos los nodos y aristas ? O(V + E).
Luego el DFS recorre todos los nodos y aristas nuevamente ? O(V + E).
La suma se simplifica a O(V + E).

Espacio: O(V)
BFS usa una cola que puede almacenar hasta V elementos.
DFS recursivo usa una pila implícita que puede medir hasta V.
Los vectores visited también son de tamaño V.
Todo esto es O(V) en total.*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<bool> visited;

bool hayCiclo(int v, int parent) {
    visited[v] = true;
    for (int u : g[v]) {
        if (!visited[u]) {
            if (hayCiclo(u, v)) return true;
        } else if (u != parent) {
            return true; // ciclo encontrado
        }
    }
    return false;
}

bool conectado(int V) {
    vector<bool> vis(V, false);
    queue<int> q;
    q.push(0);
    vis[0] = true;

    while (!q.empty()) {
        int v = q.front(); q.pop();
        for (int u : g[v]) {
            if (!vis[u]) {
                vis[u] = true;
                q.push(u);
            }
        }
    }

    // ¿Todos fueron visitados?
    for (bool x : vis) if (!x) return false;
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

    if (!conectado(V)) {
        cout << "No es arbol\n";
        return 0;
    }

    // Revisar ciclos con DFS independiente
    if (hayCiclo(0, -1)) {
        cout << "No es arbol\n";
        return 0;
    }

    cout << "Es arbol\n";
}
