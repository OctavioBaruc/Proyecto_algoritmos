#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;

struct Edge { int u, v; };

vector<Edge> maximalMatching(int n, vector<Edge>& edges) {
    vector<char> used(n, 0);
    vector<Edge> matching;

    // Heurística: ordenar por suma de índices (simple). Puedes cambiar por grado si tienes esa info.
    std::sort(edges.begin(), edges.end(), [](const Edge &a, const Edge &b){
        return (a.u + a.v) < (b.u + b.v);
    });

    for (const Edge &e : edges) {
        if (!used[e.u] && !used[e.v]) {
            used[e.u] = used[e.v] = 1;
            matching.push_back(e);
        }
    }
    return matching;
}

int main() {
    int n = 6;
    vector<Edge> edges = { {0,1}, {2,3}, {1,2}, {3,4}, {4,5} };

    vector<Edge> match = maximalMatching(n, edges);
    cout << "Maximal Matching obtenido:\n";
    for (const Edge &e : match) cout << e.u << " - " << e.v << "\n";
    return 0;
}
 
/*El algoritmo construye un maximal matching seleccionando aristas sin conflicto de forma greedy.
Primero ordena las aristas según una heurística simple (suma de índices), lo que solo influye en el orden de elección.
Luego recorre cada arista y la agrega al matching si ambos extremos aún no están usados.
Los nodos de cada arista aceptada se marcan como ocupados para evitar emparejamientos múltiples.
El matching resultante es maximal (no se puede agregar más aristas sin romper la validez), aunque no necesariamente máximo.
Tiempo: O(E log E) por la ordenación y Espacio: O(V), por el vector used y el matching almacenado.*/