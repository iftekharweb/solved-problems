#include <bits/stdc++.h>

using ll = long long;

using namespace std;

void solve()
{
        int n , m;
        cin >> m >> n;
        vector<vector<int> > Time(m,vector<int>(n));
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                cin >> Time[i][j];
            }
        }
        return;
}

int main() 
{
        ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

        int T = 1;
        while(T--){
            solve();
        }
        return 0;
}