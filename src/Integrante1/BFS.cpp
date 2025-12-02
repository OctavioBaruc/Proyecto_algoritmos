#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void bfs(int inicio, vector<vector<pair<int,int>>>& grafo) {
    vector<bool> visitado(grafo.size(), false);
    queue<int> q;

    q.push(inicio);
    visitado[inicio] = true;

    while (!q.empty()) {
        int nodo = q.front();
        q.pop();
        cout << nodo << " ";

        for (auto &arista : grafo[nodo]) {
            int vecino = arista.first;   // también está disponible el peso
            // int peso = arista.second;

            if (!visitado[vecino]) {
                visitado[vecino] = true;
                q.push(vecino);
            }
        }
    }
}

int main() {
    int n = 5;
    vector<vector<pair<int,int>>> grafo(n);

    auto agregar_arista = [&](int u, int v, int w, bool dirigido){
        grafo[u].push_back({v, w});
        if (!dirigido) grafo[v].push_back({u, w});
    };

    agregar_arista(0, 1, 5, true);   // ejemplo dirigido
    agregar_arista(0, 2, 1, true);
    agregar_arista(1, 3, 2, true);
    agregar_arista(2, 4, 3, true);

    cout << "BFS desde nodo 0: ";
    bfs(0, grafo);
    return 0;
}

/*
    BFS sirve para recorrer grafos dirigidos y no dirigidos.
    También funciona con grafos ponderados aunque ignora los pesos.
    Explora los nodos por niveles usando una cola FIFO.
    Marca nodos visitados para evitar ciclos en cualquier tipo de grafo.
    Tiempo: O(V + E) procesando todos los nodos y sus aristas una vez.
    Espacio: O(V) por la cola y el vector de nodos visitados.
*/
