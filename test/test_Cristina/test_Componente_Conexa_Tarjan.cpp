/*
    Este programa implementa el algoritmo de Tarjan para encontrar todas las
    componentes fuertemente conexas (SCC) en un grafo dirigido. Cada nodo recibe
    un ID único y se calcula su valor low-link recursivamente mediante DFS. Se
    usa una pila para mantener los nodos activos en el DFS y determinar los SCC.
    Al encontrar un SCC, se imprimen sus nodos. El programa incluye un ejemplo
    de grafo y muestra los resultados esperados y obtenidos.

Complejidad del algoritmo Tarjan SCC:
    - Tiempo: O(n + m)   (n = nodos, m = aristas)
    - Espacio: O(n)      (vectores ids, low, onStack + pila de recursion)
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

    /* EJEMPLO ESPECIFICO DEL GRAFO DIRIGIDO
        0 → 1
        1 → 2
        2 → 0     (SCC #1 = {0,1,2})

        1 → 3
        3 → 4
        4 → 3     (SCC #2 = {3,4})
    */

    int n = 5; // nodos 0–4
    graph.assign(n, vector<int>());
    ids.assign(n, -1);
    low.assign(n, 0);
    onStack.assign(n, false);

    // Aristas (dirigidas)
    graph[0].push_back(1);
    graph[1].push_back(2);
    graph[2].push_back(0);
    graph[1].push_back(3);
    graph[3].push_back(4);
    graph[4].push_back(3);

    // RESULTADO ESPERADO
    cout << "============== RESULTADO ESPERADO (teorico) ==============\n";
    cout << "SCC 1: 0 1 2\n";
    cout << "SCC 2: 3 4\n\n";

    // RESULTADO OBTENIDO DEL PROGRAMA
    cout << "=========== RESULTADO DEL PROGRAMA (Tarjan SCC) ==========\n";

    for (int i = 0; i < n; i++) {
        if (ids[i] == -1) {
            tarjanDFS(i);
        }
    }

    cout << "==========================================================\n";

    return 0;
}
