/*
    Este programa utiliza el algoritmo DFS para recorrer un grafo y descubrir todas
    sus componentes conexas. Los nodos se almacenan en una lista de adyacencia y se
    marca cada nodo visitado para evitar ciclos o repeticiones. La función DFS se
    implementa de manera recursiva, explorando completamente un componente antes de
    continuar con el siguiente. El programa muestra un resultado esperado hecho a
    mano y luego imprime las componentes detectadas mediante DFS.

Complejidad del algoritmo DFS:
    - Tiempo: O(n + m)   (n = nodos, m = aristas)
    - Espacio: O(n)      (vector visited + profundidad de la recursion)
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

    // ----- EJEMPLO ESPECIFICO -----
    // Nodos: 0,1,2,3,4,5 (total: 6)
    // Aristas:
    // 0 1
    // 1 2
    // 3 4
    // Nodo 5 está aislado

    int n = 6;
    vector<vector<int>> graph(n);
    vector<bool> visited(n, false);

    // Definición de las aristas
    graph[0].push_back(1);
    graph[1].push_back(0);

    graph[1].push_back(2);
    graph[2].push_back(1);

    graph[3].push_back(4);
    graph[4].push_back(3);

    // -------------------------------
    //     RESULTADO ESPERADO
    // -------------------------------
    cout << "========== RESULTADO ESPERADO (teorico, hecho a mano) ==========\n";
    cout << "Componente 1: 0 1 2\n";
    cout << "Componente 2: 3 4\n";
    cout << "Componente 3: 5\n\n";

    // -------------------------------
    //     RESULTADO DEL PROGRAMA
    // -------------------------------
    cout << "========== RESULTADO DEL PROGRAMA (DFS) ==========\n";

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            cout << "Componente:\n";
            dfs(i, graph, visited);
            cout << endl;
        }
    }

    cout << "====================================================\n";

    return 0;
}
