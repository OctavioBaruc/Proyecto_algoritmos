#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

vector<vector<int>> adj;   // lista de adyacencia (lado izquierdo -> indices del derecho)
vector<int> matchR;        // match del lado derecho (index -> left vertex)
vector<char> used;

bool dfs(int u) {
    for (int v : adj[u]) {
        if (used[v]) continue;
        used[v] = 1;
        if (matchR[v] == -1 || dfs(matchR[v])) {
            matchR[v] = u;
            return true;
        }
    }
    return false;
}

// nLeft: número de vértices en la parte izquierda (0..nLeft-1 en adj)
// nRight: tamaño del lado derecho (índices referenciados en adj deben ser 0..nRight-1)
bool perfectMatching(int nLeft, int nRight) {
    matchR.assign(nRight, -1);
    for (int u = 0; u < nLeft; ++u) {
        used.assign(nRight, 0);
        if (!dfs(u)) return false; // algún vértice izquierdo no pudo emparejarse
    }
    return true;
}

int main() {
    // Ejemplo: left=3 (0,1,2), right=3 (0,1,2)
    // adj[u] contiene índices del lado derecho conectados a u
    adj = vector<vector<int>>(3);
    adj[0] = {0,1}; // izquierda 0 conectado a derecha 0 y 1
    adj[1] = {1,2}; // izquierda 1 -> derecha 1 y 2
    adj[2] = {0,2}; // izquierda 2 -> derecha 0 y 2

    bool ok = perfectMatching(3, 3);
    cout << (ok ? "Existe Perfect Matching ✔️\n" : "No existe Perfect Matching ❌\n");
    return 0;
}

