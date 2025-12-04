/*  Este programa implementa el algoritmo de Tarjan para encontrar Componentes
    Fuertemente Conexas (SCC) en un grafo dirigido. Primero solicita la cantidad de nodos
    y aristas, luego construye la lista de adyacencia. Usa arrays auxiliares para
    asignar IDs, calcular low-links y rastrear nodos en la pila. La función recursiva
    tarjan DFS procesa cada nodo y detecta cuándo se forma una SCC. Finalmente imprime
    todas las SCC detectadas en el grafo.

Complejidad del algoritmo Tarjan:
    - Tiempo: O(n + m)   (n = nodos, m = aristas)
    - Espacio: O(n)      (pila, arrays ids-low-onStack)
*/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<vector<int>> graph;
vector<int> ids;          // ID unico para cada nodo
vector<int> low;          // Low-link values
vector<bool> onStack;
stack<int> st;
int idCounter = 0;

// Funcion recursiva de Tarjan
void tarjanDFS(int at) {
    st.push(at);
    onStack[at] = true;
    ids[at] = low[at] = idCounter++; // Asignar ID e inicializar low-link

    // Visitar los vecinos
    for (int to : graph[at]) {
        if (ids[to] == -1) {
            tarjanDFS(to);
            low[at] = min(low[at], low[to]);
        }
        else if (onStack[to]) {
            low[at] = min(low[at], ids[to]);
        }
    }

    // Si un nodo es raíz de un SCC
    if (ids[at] == low[at]) {
        cout << "SCC encontrado: ";
        while (true) {
            int node = st.top();
            st.pop();
            onStack[node] = false;
            cout << node << " ";
            if (node == at) break;
        }
        cout << endl;
    }
}

int main() {
    int n, edges;
    cout << "Ingresa numero de nodos: ";
    cin >> n;

    cout << "Ingresa numero de aristas: ";
    cin >> edges;

    graph.assign(n, vector<int>());
    ids.assign(n, -1);
    low.assign(n, 0);
    onStack.assign(n, false);

    cout << "Ingresa aristas dirigidas (u v):\n";
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }

    cout << "\nComponentes Fuertemente Conexas (Tarjan):\n";
    for (int i = 0; i < n; i++) {
        if (ids[i] == -1) {
            tarjanDFS(i);
        }
    }

    return 0;
}
