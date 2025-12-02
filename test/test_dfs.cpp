#include <iostream>
#include <vector>
using namespace std;

void dfs(int nodo, vector<vector<pair<int,int>>>& grafo, vector<bool>& visitado) {
    visitado[nodo] = true;
    cout << nodo << " ";

    for (auto &arista : grafo[nodo]) {
        int vecino = arista.first;
        if (!visitado[vecino]) {
            dfs(vecino, grafo, visitado);
        }
    }
}

int main() {
    int n = 5;
    vector<vector<pair<int,int>>> grafo(n);

    // función para agregar aristas
    auto agregar_arista = [&](int u, int v, int w, bool dirigido){
        grafo[u].push_back({v, w});
        if (!dirigido) grafo[v].push_back({u, w});
    };

    // grafo de prueba
    agregar_arista(0, 1, 3, false);
    agregar_arista(0, 2, 1, false);
    agregar_arista(1, 3, 2, false);
    agregar_arista(1, 4, 4, false);

    vector<bool> visitado(n, false);

    cout << "==== TEST DFS ====\n";
    cout << "Salida esperada: 0 1 3 4 2\n";
    cout << "Salida obtenida: ";
    dfs(0, grafo, visitado);
    cout << "\n==================\n";

    return 0;
}
