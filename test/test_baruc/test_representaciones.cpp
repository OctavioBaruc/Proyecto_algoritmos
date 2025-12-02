#include <iostream>
#include <vector>
using namespace std;

// ============================================================================
//  CLASE COMPLETA COPIADA DENTRO DEL TEST (opción 2 solicitada)
// ============================================================================

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

}; // END CLASS


// ============================================================================
//  FUNCIONES AUXILIARES PARA MOSTRAR MATRICES Y LISTAS
// ============================================================================

void imprimirMatriz(const vector<vector<int>>& mat) {
    for (auto &fila : mat) {
        for (int x : fila) cout << x << " ";
        cout << "\n";
    }
}

void imprimirLista(const vector<vector<pair<int,int>>>& lista) {
    for (int i = 0; i < lista.size(); i++) {
        cout << i << ": ";
        for (auto &p : lista[i])
            cout << "(" << p.first << "," << p.second << ") ";
        cout << "\n";
    }
}

// ============================================================================
//  TEST COMPLETO
// ============================================================================

int main() {
    cout << "=========== TEST DE REPRESENTACIONES DE GRAFO ===========" << endl;

    // Grafo de prueba (no dirigido, ponderado)
    vector<vector<int>> edges = {
        {0, 1, 5},
        {1, 2, 3},
        {2, 0, 2}
    };

    GraphRepresentations gr(3, edges, false, true);

    // ---------------- Matriz de adyacencia ------------------
    cout << "\n--- MATRIZ DE ADYACENCIA ---\n";
    cout << "Salida esperada:\n";
    cout <<
        "0 5 2\n"
        "5 0 3\n"
        "2 3 0\n";

    cout << "\nSalida obtenida:\n";
    imprimirMatriz(gr.adjacencyMatrix());

    // ---------------- Lista de adyacencia -------------------
    cout << "\n--- LISTA DE ADYACENCIA ---\n";
    cout << "Salida esperada:\n";
    cout <<
        "0: (1,5) (2,2)\n"
        "1: (0,5) (2,3)\n"
        "2: (1,3) (0,2)\n";

    cout << "\nSalida obtenida:\n";
    imprimirLista(gr.adjacencyList());

    // ---------------- Matriz de incidencia ------------------
    cout << "\n--- MATRIZ DE INCIDENCIA ---\n";
    cout << "Salida esperada:\n";
    cout <<
        "5 0 2\n"
        "5 3 0\n"
        "0 3 2\n";

    cout << "\nSalida obtenida:\n";
    imprimirMatriz(gr.incidenceMatrix());

    cout << "\n================== FIN DEL TEST ==================\n";
    return 0;
}
