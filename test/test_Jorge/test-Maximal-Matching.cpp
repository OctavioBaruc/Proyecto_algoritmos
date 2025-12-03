#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> g;
vector<int> mt;
vector<bool> used;

bool tryKuhn(int v) {
    if (used[v]) return false;
    used[v] = true;

    for (int to : g[v]) {
        if (mt[to] == -1 || tryKuhn(mt[to])) {
            mt[to] = v;
            return true;
        }
    }
    return false;
}

int main() {
    int nL = 4, nR = 4;

    g = {
        {1},        // U0 -> V1
        {0, 2},     // U1 -> V0, V2
        {2, 3},     // U2 -> V2, V3
        {3}         // U3 -> V3
    };

    mt.assign(nR, -1);
    int match = 0;

    for (int v = 0; v < nL; v++) {
        used.assign(nL, false);
        if (tryKuhn(v)) match++;
    }

    cout << "Matching encontrado (Kuhn): " << match << endl;
    for (int i = 0; i < nR; i++) {
        if (mt[i] != -1)
            cout << "U" << mt[i] << " - V" << i << endl;
    }

    return 0;
}

