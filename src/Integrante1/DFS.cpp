#include <iostream>
#include <vector>
using namespace std;

void dfs(int nodo, vector<vector<pair<int,int>>>& grafo, vector<bool>& visitado) {
    visitado[nodo] = true;
    cout << nodo << " ";

    for (auto &arista : grafo[nodo]) {
        int vecino = arista.first;   // el peso también está disponible si se necesita
        // int peso = arista.second;

        if (!visitado[vecino]) {
            dfs(vecino, grafo, visitado);
        }
    }
}

int main() {
    int n = 5;
    vector<vector<pair<int,int>>> grafo(n);

    // Agregar aristas (ejemplo no dirigido y ponderado)
    auto agregar_arista = [&](int u, int v, int w, bool dirigido){
        grafo[u].push_back({v, w});
        if (!dirigido) grafo[v].push_back({u, w});
    };

    agregar_arista(0, 1, 3, false);
    agregar_arista(0, 2, 1, false);
    agregar_arista(1, 3, 2, false);
    agregar_arista(1, 4, 4, false);

    vector<bool> visitado(n, false);

    cout << "DFS desde nodo 0: ";
    dfs(0, grafo, visitado);
    return 0;
}

/*
    DFS funciona tanto para grafos dirigidos como no dirigidos.
    También maneja grafos ponderados porque se recorren aristas con pesos.
    Usa recursión para profundizar en cada camino desde el nodo inicial.
    Marca nodos visitados para evitar ciclos en cualquier tipo de grafo.
    Tiempo: O(V + E) recorriendo todos los nodos y aristas una sola vez.
    Espacio: O(V) por el vector visitado y el stack de recursión.
*/
