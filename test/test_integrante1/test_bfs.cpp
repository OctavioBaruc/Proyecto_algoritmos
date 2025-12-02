#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(int inicio, vector<vector<pair<int,int>>>& grafo) {
    int n = grafo.size();
    vector<bool> visitado(n, false);
    queue<int> q;

    q.push(inicio);
    visitado[inicio] = true;

    while (!q.empty()) {
        int nodo = q.front(); q.pop();
        cout << nodo << " ";

        for (auto &arista : grafo[nodo]) {
            int vecino = arista.first;
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

    agregar_arista(0, 1, 3, false);
    agregar_arista(0, 2, 1, false);
    agregar_arista(1, 3, 2, false);
    agregar_arista(1, 4, 4, false);

    cout << "==== TEST BFS ====\n";
    cout << "Salida esperada: 0 1 2 3 4\n";
    cout << "Salida obtenida: ";
    bfs(0, grafo);
    cout << "\n==================\n";

    return 0;
}
