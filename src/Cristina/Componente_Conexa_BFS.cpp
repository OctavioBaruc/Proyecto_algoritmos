/*  Este programa usa el algoritmo BFS para recorrer un grafo no dirigido.
    Primero solicita al usuario el número de nodos y aristas.
    Luego construye la lista de adyacencia para representar el grafo.
    Utiliza un vector de visitados para evitar procesar nodos repetidos.
    Realiza BFS desde cada nodo no visitado para encontrar componentes conexas.
    Finalmente imprime cada nodo visitado dentro de cada componente encontrada.

Complejidad del algoritmo BFS:
    - Tiempo: O(n + m)     (n = nodos, m = aristas)
    - Espacio: O(n)        (cola + vector de visitados)
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Función que realiza un BFS desde un nodo inicial
void bfs(int start, vector<vector<int>>& graph, vector<bool>& visited) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    cout << "  Nodo visitado: " << start << endl;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        // Recorremos los vecinos del nodo actual
        for (int neighbor : graph[current]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
                cout << "  Nodo visitado: " << neighbor << endl;
            }
        }
    }
}

int main() {
    int n, edges;
    
    cout << "Ingresa el numero de nodos: ";
    cin >> n;
    cout << "Ingresa el numero de aristas: ";
    cin >> edges;

    vector<vector<int>> graph(n);
    vector<bool> visited(n, false);

    cout << "Ingresa las aristas (u v):" << endl;
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u); // grafo no dirigido
    }

    cout << "\nComponentes conexos encontrados:\n";

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            cout << "Componente: " << endl;
            bfs(i, graph, visited);
            cout << endl;
        }
    }

    return 0;
}
