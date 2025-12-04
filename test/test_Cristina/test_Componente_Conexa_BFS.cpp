/*
    Este programa utiliza el algoritmo BFS para recorrer un grafo y encontrar todas
    sus componentes conexas. Cada nodo se marca como visitado para evitar repetir
    procesamientos. El grafo se representa mediante listas de adyacencia, permitiendo
    recorrer vecinos de forma eficiente. El programa también incluye un ejemplo manual
    de componentes esperadas y luego ejecuta BFS para encontrarlas. Finalmente imprime
    cada componente detectada en el grafo.

Complejidad del algoritmo BFS:
    - Tiempo: O(n + m)   (n = nodos, m = aristas)
    - Espacio: O(n)      (cola + arreglo visited)
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Funcion que realiza un BFS desde un nodo inicial
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

    // ----- EJEMPLO ESPECIFICO -----
    // Nodos: 6 (0,1,2,3,4,5)
    // Aristas:
    // 0 1
    // 1 2
    // 3 4
    // (5 está aislado)

    int n = 6;
    vector<vector<int>> graph(n);
    vector<bool> visited(n, false);

    // Definicion de las aristas
    graph[0].push_back(1);
    graph[1].push_back(0);

    graph[1].push_back(2);
    graph[2].push_back(1);

    graph[3].push_back(4);
    graph[4].push_back(3);

    // ----- RESULTADO ESPERADO (de forma manual) -----
    cout << "========== RESULTADO ESPERADO (teorico) ==========\n";
    cout << "Componente 1: 0 1 2\n";
    cout << "Componente 2: 3 4\n";
    cout << "Componente 3: 5\n\n";

    // ----- RESULTADO OBTENIDO POR EL PROGRAMA -----
    cout << "========== RESULTADO DEL PROGRAMA ==========\n";

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            cout << "Componente:\n";
            bfs(i, graph, visited);
            cout << endl;
        }
    }

    cout << "===================================================\n";

    return 0;
}
