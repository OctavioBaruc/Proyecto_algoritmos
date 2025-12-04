#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;

/* ===== TU FUNCIÓN AQUÍ (Alternating Path Matching) ===== */

vector<int> alternatingPathMatching(const vector<vector<int>>& adjL, int nR) {
    int nL = adjL.size();
    vector<int> matchR(nR, -1);
    vector<int> matchL(nL, -1);

    bool improved = true;
    while (improved) {
        improved = false;
        vector<int> parentL(nL, -1), parentR(nR, -1);
        queue<int> q;

        for (int u = 0; u < nL; u++) {
            if (matchL[u] == -1) {
                q.push(u);
            }
        }

        bool augFound = false;
        int endR = -1;

        while (!q.empty() && !augFound) {
            int u = q.front();
            q.pop();

            for (int v : adjL[u]) {
                if (parentR[v] != -1) continue;
                parentR[v] = u;

                if (matchR[v] == -1) {
                    augFound = true;
                    endR = v;
                    break;
                }

                int nextL = matchR[v];
                if (parentL[nextL] == -1) {
                    parentL[nextL] = v;
                    q.push(nextL);
                }
            }
        }

        if (!augFound) break;

        improved = true;
        int r = endR;
        while (r != -1) {
            int l = parentR[r];
            int nextR = matchL[l];
            matchL[l] = r;
            matchR[r] = l;
            r = nextR;
        }
    }

    return matchL;
}

/* ================== TEST ================== */

int main() {
    // Grafo bipartito L={0,1,2}, R={0,1,2}
    vector<vector<int>> adjL = {
        {0,1}, // L0 -> R0,R1
        {1},   // L1 -> R1
        {2}    // L2 -> R2
    };

    auto match = alternatingPathMatching(adjL, 3);

    cout << "Matching result (L -> R):\n";
    for (int i = 0; i < match.size(); i++) {
        cout << "  L" << i << " -> " << (match[i] == -1 ? -1 : match[i]) << "\n";
    }

    // Validación esperada: matching mínimo = 3
    int count = 0;
    for (int x : match) if (x != -1) count++;

    cout << (count == 3 ? "\nOK (matching perfecto)\n"
                        : "\nERROR (matching incompleto)\n");
}
