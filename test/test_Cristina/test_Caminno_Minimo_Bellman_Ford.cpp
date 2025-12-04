/*
    Este programa implementa el algoritmo Bellman-Ford para encontrar las distancias
    mínimas desde un nodo origen en un grafo dirigido con posibles pesos negativos.
    Primero define un conjunto fijo de aristas como ejemplo de prueba. El algoritmo
    relaja todas las aristas n−1 veces y luego verifica si existe algún ciclo negativo.
    Si no hay ciclos negativos, devuelve el arreglo con las distancias mínimas. Finalmente,
    el programa imprime un resultado esperado y el resultado calculado por Bellman-Ford.

    Complejidad del algoritmo Bellman-Ford:
    - Tiempo: O(n * m)     (n = número de nodos, m = número de aristas)
    - Espacio: O(n)        (arreglo dist)
*/

#include <iostream>
#include <vector>
#include <limits>

using namespace std;

// Estructura para representar una arista
struct Edge {
    int from;
    int to;
    int weight;
};

// Bellman-Ford para obtener distancias mínimas desde un nodo origen
vector<int> bellmanFord(int start, int n, vector<Edge>& edges) {
    vector<int> dist(n, numeric_limits<int>::max());
    dist[start] = 0;

    // Relajamos todas las aristas n-1 veces    
    for (int i = 0; i < n - 1; i++) {
        for (auto& edge : edges) {
            if (dist[edge.from] != numeric_limits<int>::max() && dist[edge.from] + edge.weight < dist[edge.to]) {
                dist[edge.to] = dist[edge.from] + edge.weight;
            }
        }
    }

    // Verificamos si hay ciclo negativo
    for (auto& edge : edges) {
        if (dist[edge.from] != numeric_limits<int>::max() && dist[edge.from] + edge.weight < dist[edge.to]) {
            cout << "El grafo contiene un ciclo negativo.\n";
            return {};
        }
    }

    return dist;
}

int main() {
    /* EJEMPLO ESPECIFICO

        Aristas (from, to, weight):
                    0 -> 1 : 6
                    0 -> 2 : 7
                    1 -> 2 : 8
                    1 -> 3 : 5
                    1 -> 4 : -4
                    2 -> 3 : -3
                    2 -> 4 : 9
                    3 -> 1 : -2
                    4 -> 0 : 2
                    4 -> 3 : 7
    */

    int n = 5;
    vector<Edge> edges = {
        {0, 1, 6},
        {0, 2, 7},
        {1, 2, 8},
        {1, 3, 5},
        {1, 4, -4},
        {2, 3, -3},
        {2, 4, 9},
        {3, 1, -2},
        {4, 0, 2},
        {4, 3, 7}
    };

    int start = 0;

    vector<int> dist = bellmanFord(start, n, edges);

    cout << "Resultado manual esperado: [0, 2, 7, 4, -2]\n";

    cout << "Resultado con programa: [";
    for (int i = 0; i < n; i++) {
        cout << dist[i];
        if (i != n-1) cout << ", ";
    }
    cout << "]\n";

    return 0;
}
