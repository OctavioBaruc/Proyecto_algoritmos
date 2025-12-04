/*
    Este programa implementa el algoritmo Floyd–Warshall para calcular las distancias
    mínimas entre todos los pares de nodos de un grafo dirigido con posibles pesos negativos.
    La matriz 'dist' representa el costo entre cualquier par de nodos, inicialmente con valores
    infinito salvo la diagonal principal. El algoritmo verifica si usando un nodo intermedio
    (k), la distancia entre i y j puede mejorar. Finalmente, el programa imprime la matriz
    resultante y la compara con un resultado manual esperado.

Complejidad del algoritmo Floyd-Warshall:
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
    /* EJEMPLO ESPECIFICO

    Aristas (origen -> destino : peso)
                0 -> 1 : 2
                0 -> 2 : 5
                1 -> 2 : -2
                1 -> 3 : 3
                2 -> 3 : 2
                3 -> 0 : -1
    */

    int n = 4;
    vector<vector<int>> dist(n, vector<int>(n, INF));

    // Distancia de un nodo a sí mismo = 0
    for (int i = 0; i < n; i++)
        dist[i][i] = 0;

    // Agregamos aristas con pesos positivos y negativos
    dist[0][1] = 2;
    dist[0][2] = 5;
    dist[1][2] = -2;
    dist[1][3] = 3;
    dist[2][3] = 2;
    dist[3][0] = -1;

    floydWarshall(dist, n);

    cout << "Resultado manual esperado:\n";
    cout << "0 2 0 2\n";
    cout << "-1 0 -2 0\n";
    cout << "1 3 0 2\n";
    cout << "-1 1 -1 0\n\n";

    cout << "Resultado con programa:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}