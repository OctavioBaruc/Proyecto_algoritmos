#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 1e9;
vector<vector<int>> adj;
vector<int> pairU, pairV, dist;
int nL, nR;

bool bfs() {
    queue<int> q;
    for (int u = 0; u < nL; u++) {
        if (pairU[u] == -1) dist[u] = 0, q.push(u);
        else dist[u] = INF;
    }

    int found = INF;

    while (!q.empty()) {
        int u = q.front(); q.pop();
        if (dist[u] < found) {
            for (int v : adj[u]) {
                if (pairV[v] == -1) found = dist[u] + 1;
                else if (dist[pairV[v]] == INF) {
                    dist[pairV[v]] = dist[u] + 1;
                    q.push(pairV[v]);
                }
            }
        }
    }
    return found != INF;
}

bool dfs(int u) {
    for (int v : adj[u]) {
        if (pairV[v] == -1 || (dist[pairV[v]] == dist[u] + 1 && dfs(pairV[v]))) {
            pairU[u] = v;
            pairV[v] = u;
            return true;
        }
    }
    dist[u] = INF;
    return false;
}

int hopcroftKarp() {
    pairU.assign(nL, -1);
    pairV.assign(nR, -1);
    dist.resize(nL);
    int matching = 0;

    while (bfs())
        for (int u = 0; u < nL; u++)
            if (pairU[u] == -1 && dfs(u))
                matching++;

    return matching;
}

int main() {
    nL = 4, nR = 4;

    adj = {
        {1},        // U0 -> V1
        {0, 2},     // U1 -> V0, V2
        {2, 3},     // U2 -> V2, V3
        {3}         // U3 -> V3
    };

    int result = hopcroftKarp();
    cout << "Matching encontrado (Hopcroft-Karp): " << result << endl;

    for (int i = 0; i < nL; i++)
        if (pairU[i] != -1)
            cout << "U" << i << " - V" << pairU[i] << endl;

    return 0;
}

