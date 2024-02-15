#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <cstring>
using namespace std;

const int MAXN = 10005;

vector<int> G[MAXN];
int order[MAXN], color[MAXN];
set<int> available_colors[MAXN];

struct Compare {
    bool operator()(int u, int v) {
        return G[u].size() > G[v].size();
    }
};

void SL(int n) {
    priority_queue<int, vector<int>, Compare> pq;

    for (int i = 0; i < n; i++) {
        order[i] = i;
        pq.push(i);
    }

    for (int i = 0; i < n; i++) {
        int u = pq.top();
        pq.pop();
        int chosen_color = -1;

        for (int v : G[u]) {
            if (color[v] != -1) {
                available_colors[color[v]].erase(color[v]);
            }
        }

        for (int c = 0; c < 6; c++) {
            if (!available_colors[c].empty()) {
                chosen_color = *available_colors[c].begin();
                break;
            }
        }

        color[u] = chosen_color;
        for (int v : G[u]) {
            if (color[v] != -1) {
                available_colors[color[v]].insert(chosen_color);
            }
        }
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;
        memset(color, -1, sizeof(color));
        for (int i = 0; i < n; i++) {
            G[i].clear();
            available_colors[i].clear();
        }

        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
        }

        SL(n);

        for (int i = 0; i < n; i++) {
            cout << i << " " << color[i] + 1 << endl;
        }
    }

    return 0;
}
