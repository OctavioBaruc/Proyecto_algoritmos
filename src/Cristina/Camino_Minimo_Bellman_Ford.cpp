/*  Este programa implementa el algoritmo de Bellman-Ford para grafos.    
    Lee el número de nodos y aristas desde la entrada del usuario.
    Luego, solicita los detalles de cada arista (origen, destino y peso).
    Calcula las distancias mínimas desde un nodo origen dado.
    Detecta si existe algún ciclo negativo en el grafo.
    Finalmente, imprime las distancias mínimas o un mensaje de error.

Complejidad del algoritmo Bellman-Ford:
    - Tiempo: O(n * m)  (n = numero de nodos, m = numero de aristas)
    - Espacio: O(n)     (vector de distancias)

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
    int n, edgesCount, start;
    cout << "Ingresa numero de nodos: ";
    cin >> n;

    cout << "Ingresa numero de aristas: ";
    cin >> edgesCount;

    vector<Edge> edges(edgesCount);

    cout << "Ingresa aristas (origen destino peso):\n";
    for (int i = 0; i < edgesCount; i++) {
        cin >> edges[i].from >> edges[i].to >> edges[i].weight;
    }

    cout << "Ingresa nodo origen: ";
    cin >> start;

    vector<int> dist = bellmanFord(start, n, edges);

    if (!dist.empty()) {
        cout << "\nDistancias minimas desde el nodo " << start << ":\n";
        for (int i = 0; i < n; i++) {
            if (dist[i] == numeric_limits<int>::max())
                cout << "Nodo " << i << ": INFINITO\n";
            else
                cout << "Nodo " << i << ": " << dist[i] << endl;
        }
    }

    return 0;
}
