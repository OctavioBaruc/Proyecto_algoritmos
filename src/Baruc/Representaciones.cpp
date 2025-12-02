// ============================================================================
//  Representaciones de Grafos (C++)
//  - Matriz de Adyacencia
//  - Lista de Adyacencia
//  - Matriz de Incidencia
//
//  Compatible con:
//      ✔ Grafos dirigidos y no dirigidos
//      ✔ Grafos ponderados y no ponderados
//
//  Proyecto: Grafos CCA 2025
// ============================================================================

#include <iostream>
#include <vector>
using namespace std;

class GraphRepresentations {
private:
    int n;                                   // Número de vértices
    vector<vector<int>> edges;               // Lista de aristas
    bool directed;                           // Si el grafo es dirigido
    bool weighted;                           // Si el grafo es ponderado

public:
    GraphRepresentations(int num_vertices,
                        vector<vector<int>> edges_list,
                        bool dir = false,
                        bool w = false)
        : n(num_vertices), edges(edges_list),
        directed(dir), weighted(w) {}

    // =========================================================================
    // 1. MATRIZ DE ADYACENCIA
    // =========================================================================
    vector<vector<int>> adjacencyMatrix() {
        vector<vector<int>> matrix(n, vector<int>(n, 0));

        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int w = weighted ? e[2] : 1;

            matrix[u][v] = w;
            if (!directed)
                matrix[v][u] = w;
        }
        return matrix;
    }

    // =========================================================================
    // 2. LISTA DE ADYACENCIA
    // =========================================================================
    vector<vector<pair<int,int>>> adjacencyList() {
        vector<vector<pair<int,int>>> lista(n);

        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int w = weighted ? e[2] : 1;

            lista[u].push_back({v, w});
            if (!directed)
                lista[v].push_back({u, w});
        }
        return lista;
    }

    // =========================================================================
    // 3. MATRIZ DE INCIDENCIA
    // =========================================================================
    vector<vector<int>> incidenceMatrix() {
        int m = edges.size();
        vector<vector<int>> mat(n, vector<int>(m, 0));

        for (int i = 0; i < m; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = weighted ? edges[i][2] : 1;

            if (directed) {
                // u -> v
                mat[u][i] = -w;  // sale
                mat[v][i] = +w;  // entra
            } else {
                mat[u][i] = w;
                mat[v][i] = w;
            }
        }
        return mat;
    }

}; // end class


// ============================================================================
// EJEMPLO DE USO
// ============================================================================
int main() {
    // Grafo simple no dirigido y ponderado
    vector<vector<int>> edges = {
        {0, 1, 5},
        {1, 2, 3},
        {2, 0, 2}
    };

    GraphRepresentations gr(3, edges, false, true);

    // ==============================
    // Matriz de Adyacencia
    // ==============================
    cout << "MATRIZ DE ADYACENCIA:\n";
    auto mat = gr.adjacencyMatrix();
    for (auto &fila : mat) {
        for (int x : fila)
            cout << x << " ";
        cout << "\n";
    }

    // ==============================
    // Lista de Adyacencia
    // ==============================
    cout << "\nLISTA DE ADYACENCIA:\n";
    auto lista = gr.adjacencyList();
    for (int i = 0; i < lista.size(); i++) {
        cout << i << ": ";
        for (auto &par : lista[i])
            cout << "(" << par.first << "," << par.second << ") ";
        cout << "\n";
    }

    // ==============================
    // Matriz de Incidencia
    // ==============================
    cout << "\nMATRIZ DE INCIDENCIA:\n";
    auto inc = gr.incidenceMatrix();
    for (auto &fila : inc) {
        for (int x : fila)
            cout << x << " ";
        cout << "\n";
    }

    return 0;
}
