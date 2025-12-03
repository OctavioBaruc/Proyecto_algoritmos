#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> grafo;
vector<int> matchR;
vector<bool> visited;

bool dfs(int u) {
    for (int v : grafo[u]) {
        if (!visited[v]) {
            visited[v] = true;
            if (matchR[v] == -1 || dfs(matchR[v])) {
                matchR[v] = u;
                return true;
            }
        }
    }
    return false;
}

int main() {
    int nL = 4, nR = 4; // partições izquierda y derecha

    grafo = {
        {0, 1},   // U0 -> V0, V1
        {1, 2},   // U1 -> V1, V2
        {0, 3},   // U2 -> V0, V3
        {2}       // U3 -> V2
    };

    matchR.assign(nR, -1);
    int matching = 0;

    for (int u = 0; u < nL; u++) {
        visited.assign(nR, false);
        if (dfs(u)) matching++;
    }

    cout << "Emparejamientos encontrados (DFS): " << matching << endl;
    for (int v = 0; v < nR; v++) {
        if (matchR[v] != -1)
            cout << "U" << matchR[v] << " - V" << v << endl;
    }

    return 0;
}
