/* ALGORITMO 2 : COMPROBAR LAS 3 PRUEBAS PARA QUE SEA ÁRBOL (BFS + DFS ITERATIVO)

Primero revisa la condición E = V - 1, necesaria en todo árbol.
Usa BFS para comprobar que todos los nodos del grafo son alcanzables desde el nodo 0.
Si algún nodo queda sin visitar, el grafo no es conectado.
Luego hace un DFS usando una pila, en lugar de recursión.
Si el DFS iterativo encuentra un vértice visitado que no es el padre, detecta un ciclo.
Si está conectado y sin ciclos, el grafo es un árbol. 

Tiempo: O(V + E)
El BFS recorre todas las aristas y nodos una vez ? O(V + E).
El DFS iterativo hace exactamente lo mismo ? O(V + E).
La suma sigue siendo O(V + E).

Espacio: O(V)
BFS usa una cola que puede guardar hasta V elementos.
DFS iterativo usa una pila que también puede guardar hasta V elementos.
Los arreglos de visitados y padres son de tamaño V.
En conjunto, todo se mantiene en O(V).*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;

// BFS para verificar conectividad
bool bfsConectado(int V) {
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

    for (bool x : vis) if (!x) return false;
    return true;
}

// DFS iterativo con pila para detectar ciclos
bool dfsCiclos(int V) {
    vector<bool> vis(V, false);
    vector<int> parent(V, -1);
    stack<int> st;

    st.push(0);
    parent[0] = -1;

    while (!st.empty()) {
        int v = st.top(); 
        st.pop();

        if (!vis[v]) vis[v] = true;

        for (int u : g[v]) {
            if (!vis[u]) {
                parent[u] = v;
                st.push(u);
            } else if (u != parent[v]) {
                return true; // ciclo detectado
            }
        }
    }
    return false;
}

int main() {
    int V, E;
    cin >> V >> E;

    if (E != V - 1) {
        cout << "No es arbol\n";
        return 0;
    }

    g.assign(V, vector<int>());

    for (int i = 0; i < E; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    if (!bfsConectado(V)) {
        cout << "No es arbol\n";
        return 0;
    }

    if (dfsCiclos(V)) {
        cout << "No es arbol\n";
        return 0;
    }

    cout << "Es arbol\n";
}
