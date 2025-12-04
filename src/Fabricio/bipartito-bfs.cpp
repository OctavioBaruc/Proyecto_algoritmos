#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool isBipartiteBFS(const vector<vector<pair<int,int>>>& adj){
    int n = adj.size();
    vector<int> color(n, -1);
    queue<int> q;
    for(int s=0;s<n;s++){
        if(color[s] != -1) continue;
        color[s]=0;
        q.push(s);
        while(!q.empty()){
            int u = q.front(); q.pop();
            for(auto &e : adj[u]){
                int v = e.first;
                if(color[v] == -1){
                    color[v] = 1 - color[u];
                    q.push(v);
                } else if(color[v] == color[u]) return false;
            }
        }
    }
    return true;
}
int main() {
    // Ejemplo de grafo bipartito
    vector<vector<pair<int,int>>> adj = {
        {{1,1}, {3,1}},
        {{0,1}, {2,1}},
        {{1,1}, {3,1}},
        {{0,1}, {2,1}}
    };

    if (isBipartiteBFS(adj))
        cout << "El grafo es bipartito\n";
    else
        cout << "El grafo NO es bipartito\n";

    return 0;
}

/*El algoritmo determina si un grafo es bipartito usando BFS para colorear sus nodos.
Cada componente comienza sin color, se asigna uno inicial y se propaga el color opuesto a sus vecinos.
Si durante el recorrido un nodo vecino ya tiene color y coincide con el actual, el grafo no es bipartito.
El proceso se repite para todos los nodos no visitados para cubrir componentes desconectados.
Tiempo: O(V + E), porque cada arista y cada nodo se procesa una sola vez.
Espacio: O(V), por el arreglo de colores y la cola del BFS.*/