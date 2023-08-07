#include <bits/stdc++.h>

using ll = long long;

using namespace std;

const long long MOD = 1e9+7 , N = 2e5+5 , INF = 1e16;
const long double PI= 3.14159265358979323846264338327950288;

void solve()
{
        ll n , x;
        cin >> n >> x;
        vector<ll> L(N,0), R(N,0), C(N,0);
        vector<vector<ll> > LV(N), RV(N);
        for(int i=1; i<=n; i++) {
            cin >> L[i] >> R[i] >> C[i];
            LV[L[i]].push_back(i);
            RV[R[i]].push_back(i);
        }
        ll ans = INF;
        map<ll,ll> cm;
        for(int i=1; i<N; i++) {
            for(auto id:LV[i]) {
                ll len = R[id]-L[id]+1;
                if(cm.count(x-len)) {
                    ans = min(ans,C[id]+cm[x-len]);
                }
            }
            for(auto id:RV[i]) {
                ll len = R[id]-L[id]+1;
                if(cm.count(len) == 0) {
                    cm[len] = INF;
                }
                cm[len] = min(cm[len], C[id]);
            }
        }
        if(ans>INF/2) {
            ans = -1;
        }
        cout << ans << endl;
        return;
}

int main() 
{
        ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

        int T = 1, CNT = 0;  //cin >> T;
        while(T--){
          //  cout << "Case " << ++CNT << ": ";
            solve();
        }
        return 0;
}