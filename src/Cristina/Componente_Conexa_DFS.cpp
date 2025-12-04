/*  Este programa utiliza el algoritmo DFS para recorrer un grafo no dirigido.
    Primero solicita el número de nodos y aristas al usuario.
    Después construye la lista de adyacencia del grafo según los datos ingresados.
    Usa un arreglo de visitados para evitar visitar nodos repetidos.
    Efectúa una DFS desde cada nodo no visitado para hallar componentes conexas.
    Finalmente imprime los nodos visitados dentro de cada componente encontrada.

Complejidad del algoritmo DFS:
    - Tiempo: O(n + m)     (n = número de nodos, m = número de aristas)
    - Espacio: O(n)        (vector visited + profundidad máxima de la recursión)
*/

#include <iostream>
#include <vector>

using namespace std;

// Funcion DFS recursiva
void dfs(int node, vector<vector<int>>& graph, vector<bool>& visited) {
    visited[node] = true;
    cout << "  Nodo visitado: " << node << endl;

    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, graph, visited);
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
        graph[v].push_back(u); // Grafo no dirigido
    }

    cout << "\nComponentes conexos encontrados:\n";

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            cout << "Componente:" << endl;
            dfs(i, graph, visited);
            cout << endl;
        }
    }

    return 0;
}
