/*
Este programa implementa el algoritmo Floyd-Warshall para encontrar las distancias mínimas
entre todos los pares de nodos en un grafo. Primero solicita el número de nodos y aristas.
Luego inicializa una matriz de distancias con valores infinitos. Después lee las aristas
ingresadas por el usuario y asigna sus pesos. El algoritmo actualiza la matriz considerando
todos los nodos como posibles intermedios. Finalmente imprime la matriz resultante de distancias.

Analisis de Complejidad del algoritmo Floyd-Warshall:
    - Tiempo: O(n^3)
    - Espacio: O(n^2)
*/

#include <iostream>
#include <vector>
#include <limits>

using namespace std;

const int INF = 1e9; // Representa "infinito"

// Floyd-Warshall: encuentra la distancia mínima entre todos los pares de nodos
void floydWarshall(vector<vector<int>>& dist, int n) {
    for (int k = 0; k < n; k++) {        // Nodo intermedio
        for (int i = 0; i < n; i++) {    // Nodo origen
            for (int j = 0; j < n; j++) { // Nodo destino
                if (dist[i][k] != INF && dist[k][j] != INF)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

int main() {
    int n, m;
    cout << "Ingresa el numero de nodos: ";
    cin >> n;

    cout << "Ingresa el numero de aristas: ";
    cin >> m;

    vector<vector<int>> dist(n, vector<int>(n, INF));

    // Distancia de un nodo a sí mismo = 0
    for (int i = 0; i < n; i++)
        dist[i][i] = 0;

    cout << "Ingresa aristas (origen destino peso):\n";
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        dist[u][v] = w; // Si el grafo es no dirigido, también agregar dist[v][u] = w;
    }

    floydWarshall(dist, n);

    cout << "\nMatriz de distancias minimas entre todos los pares de nodos:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INF) cout << "INF ";
            else cout << dist[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
