#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;

// Hungarian algorithm to find the maximum weighted matching
// Returns the maximum weight of the matching
int hungarian(vector<vector<int>>& cost) {
    int N = cost.size();
    vector<int> u(N), v(N), p(N), way(N);
    vector<int> minv(N);
    vector<bool> used(N);
    int result = 0;
    for (int i = 0; i < N; ++i) {
        p[0] = i;
        int j0 = 0;
        fill(minv.begin(), minv.end(), INF);
        fill(used.begin(), used.end(), false);
        do {
            used[j0] = true;
            int i0 = p[j0], delta = INF, j1;
            for (int j = 0; j < N; ++j) {
                if (!used[j]) {
                    int cur = cost[i0][j] - u[i0] - v[j];
                    if (cur < minv[j]) {
                        minv[j] = cur;
                        way[j] = j0;
                    }
                    if (minv[j] < delta) {
                        delta = minv[j];
                        j1 = j;
                    }
                }
            }
            for (int j = 0; j < N; ++j) {
                if (used[j]) {
                    u[p[j]] += delta;
                    v[j] -= delta;
                } else {
                    minv[j] -= delta;
                }
            }
            j0 = j1;
        } while (p[j0] != 0);
        do {
            int j1 = way[j0];
            p[j0] = p[j1];
            j0 = j1;
        } while (j0 != 0);
    }
    for (int j = 1; j < N; ++j) {
        result += cost[p[j]][j];
    }
    return result;
}

int main() {
    int N;
    cin >> N;

    vector<vector<int>> cost(N, vector<int>(N, 0));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> cost[i][j];
        }
    }

    int M;
    cin >> M;
    for (int m = 0; m < M; ++m) {
        char op;
        cin >> op;

        if (op == 'C') {
            int i, j, w;
            cin >> i >> j >> w;
            cost[i][j] = w;
        } else if (op == 'X') {
            int i;
            vector<int> x(N);
            cin >> i;
            for (int j = 0; j < N; ++j) {
                cin >> x[j];
            }
            for (int j = 0; j < N; ++j) {
                cost[i][j] = x[j];
            }
        } else if (op == 'Y') {
            int i;
            vector<int> y(N);
            cin >> i;
            for (int j = 0; j < N; ++j) {
                cin >> y[j];
            }
            for (int j = 0; j < N; ++j) {
                cost[j][i] = y[j];
            }
        } else if (op == 'A') {
            N++;
            cost.resize(N, vector<int>(N, 0));
        } else if (op == 'Q') {
            int maxWeight = hungarian(cost);
            cout << maxWeight << endl;
        }
    }

    return 0;
}
