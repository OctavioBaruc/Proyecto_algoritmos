/*
    Este programa implementa el algoritmo de Dijkstra para encontrar las distancias
    mínimas desde un nodo origen hacia todos los demás nodos del grafo. El grafo se
    representa mediante listas de adyacencia y cada arista incluye un peso positivo.
    Se utiliza un priority_queue tipo min-heap para obtener eficientemente el nodo
    con menor distancia provisional. Finalmente, el programa calcula y muestra las
    distancias esperadas y las obtenidas por el algoritmo para un ejemplo específico.

Complejidad del algoritmo Dijkstra:
    - Tiempo: O((n + m) * log n)   (n = nodos, m = aristas)
    - Espacio: O(n + m)            (listas de adyacencia + arreglo dist)
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

    /* EJEMPLO ESPECIFICO
        Nodos: 0, 1, 2, 3, 4
        Aristas (u, v, w): 
                0-1: 2
                0-2: 4
                1-2: 1
                1-3: 7
                2-4: 3
                3-4: 1
    */
   
    int n = 5; // Nodos
    vector<vector<Edge>> graph(n);

    // Agregamos las aristas
    graph[0].push_back({1, 2});
    graph[0].push_back({2, 4});
    graph[1].push_back({0, 2});
    graph[1].push_back({2, 1});
    graph[1].push_back({3, 7});
    graph[2].push_back({0, 4});
    graph[2].push_back({1, 1});
    graph[2].push_back({4, 3});
    graph[3].push_back({1, 7});
    graph[3].push_back({4, 1});
    graph[4].push_back({2, 3});
    graph[4].push_back({3, 1});

    int start = 0;

    vector<int> dist = dijkstra(start, graph);

    // Mostrar resultados
    cout << "Resultado manual esperado: [0, 2, 3, 7, 6]\n";
    cout << "Resultado con programa: [";
    for (int i = 0; i < n; i++) {
        cout << dist[i];
        if (i != n-1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}
