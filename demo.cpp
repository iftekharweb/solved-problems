#include<iostream>
#include<vector>
using namespace std;

int main() {
    string s , t; 
    cin >> s >> t;
    int n, INF = 1000000000;
    vector<vector<int> > G(26, vector<int>(26, INF));
    for (int i = 0; i < 26; ++i) {
        G[i][i] = 0;
    }
    cin >> n;
    while(n--) {
        char a , b;
        int cost;
        cin  >> a >> b >> cost;
        G[a - 'a'][b - 'a'] = min(G[a - 'a'][b - 'a'], cost);
    }
    if(s.size() != t.size()) {
        cout << -1 << endl;
        return 0;
    } 

    int ans = 0;
    string outStr = "";
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == t[i]) {
            outStr += s[i];
            continue;
        }
        char ch = '?';
        int relax = INF;
        for (int c = 0; c < 26; ++c) {
            if (G[s[i] - 'a'][c] + G[t[i] - 'a'][c] < relax) {
                relax = G[s[i] - 'a'][c] + G[t[i] - 'a'][c];
                ch = (char)(c + 'a');
            }
        }
        if (relax == INF) {
            cout << "-1" << endl;;
            return 0;
        }
        ans += relax;
        outStr += ch;
    }
    return 0;
}