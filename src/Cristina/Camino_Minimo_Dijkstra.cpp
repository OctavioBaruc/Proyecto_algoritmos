/*  Este programa implementa el algoritmo de Dijkstra para grafos.
    Lee el número de nodos y aristas desde la entrada del usuario.
    Luego, solicita los detalles de cada arista (origen, destino y peso).
    Calcula las distancias mínimas desde un nodo origen dado.
    Usa un min-heap (priority_queue) para optimizar la selección del nodo más cercano.
    Finalmente, imprime las distancias mínimas desde el nodo origen.

Complejidad del algoritmo Dijkstra:
    - Tiempo: O((n + m) * log n)  (n = numero de nodos, m = numero de aristas)
    - Espacio: O(n + m)           (vector de distancias + lista de adyacencia)
*/

#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

// Estructura para cada arista: (destino, peso)
struct Edge {
    int to;
    int weight;
};

// Dijkstra para obtener distancias minimas desde un nodo origen
vector<int> dijkstra(int start, vector<vector<Edge>>& graph) {
    int n = graph.size();
    vector<int> dist(n, numeric_limits<int>::max());
    dist[start] = 0;

    // Min-heap: (distancia, nodo)
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        auto [currentDist, node] = pq.top();
        pq.pop();

        if (currentDist > dist[node]) continue;

        for (auto& edge : graph[node]) {
            int newDist = currentDist + edge.weight;
            if (newDist < dist[edge.to]) {
                dist[edge.to] = newDist;
                pq.push({newDist, edge.to});
            }
        }
    }

    return dist;
}

int main() {
    int n, edges, start;
    cout << "Ingresa numero de nodos: ";
    cin >> n;

    cout << "Ingresa numero de aristas: ";
    cin >> edges;

    vector<vector<Edge>> graph(n);

    cout << "Ingresa aristas (u v w): \n";
    for (int i = 0; i < edges; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w}); // Si es no dirigido
    }

    cout << "Ingresa nodo origen: ";
    cin >> start;

    vector<int> dist = dijkstra(start, graph);

    cout << "\nDistancias minimas desde el nodo " << start << ":\n";
    for (int i = 0; i < n; i++) {
        cout << "Nodo " << i << ": " << dist[i] << endl;
    }

    return 0;
}
