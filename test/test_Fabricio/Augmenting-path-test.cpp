#include <bits/stdc++.h>
using namespace std;

/* ===== TU IMPLEMENTACIÓN DE HOPCROFT–KARP AQUÍ ===== */

const int INF = 1e9;

bool bfsHK(const vector<vector<int>>& adj, vector<int>& dist,
           const vector<int>& pairU, const vector<int>& pairV) {

    queue<int> q;
    int nL = pairU.size();

    for (int u = 0; u < nL; u++) {
        if (pairU[u] == -1) {
            dist[u] = 0;
            q.push(u);
        } else {
            dist[u] = INF;
        }
    }

    bool reachableFreeNode = false;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (pairV[v] == -1) {
                reachableFreeNode = true;
            } else if (dist[pairV[v]] == INF) {
                dist[pairV[v]] = dist[u] + 1;
                q.push(pairV[v]);
            }
        }
    }

    return reachableFreeNode;
}

bool dfsHK(int u, const vector<vector<int>>& adj, vector<int>& dist,
           vector<int>& pairU, vector<int>& pairV) {

    for (int v : adj[u]) {
        if (pairV[v] == -1 ||
            (dist[pairV[v]] == dist[u] + 1 &&
             dfsHK(pairV[v], adj, dist, pairU, pairV))) {

            pairU[u] = v;
            pairV[v] = u;
            return true;
        }
    }

    dist[u] = INF;
    return false;
}

/* ================== TEST ================== */

int main() {
    // Grafo bipartito L={0,1,2}, R={0,1,2}
    vector<vector<int>> adjL = {
        {0,1},
        {1},
        {1,2}
    };

    int nL = 3, nR = 3;
    vector<int> pairU(nL, -1), pairV(nR, -1), dist(nL);

    while (bfsHK(adjL, dist, pairU, pairV)) {
        for (int u = 0; u < nL; u++)
            if (pairU[u] == -1)
                dfsHK(u, adjL, dist, pairU, pairV);
    }

    cout << "Matching Hopcroft-Karp (L -> R):\n";
    int matched = 0;
    for (int u = 0; u < nL; u++) {
        cout << "  L" << u << " -> " << pairU[u] << "\n";
        if (pairU[u] != -1) matched++;
    }

    cout << "\nTotal matched: " << matched << "\n";
    cout << (matched >= 2 ? "OK\n" : "ERROR\n");
}
