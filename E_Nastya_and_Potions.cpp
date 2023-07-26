#include <bits/stdc++.h>

using ll = long long;
using ld = long double;
#define all(a)  a.begin(),a.end()
#define rall(a)  a.rbegin(),a.rend()
#define LCM(a,b)  (a*b)/__gcd(a, b)
#define endl "\n"

using namespace std;
template<class T> void print(T& a) { for(auto x:a)cout<<x<<" "; cout<<"\n";}

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
}; 
// unordered_map<ll,int,custom_hash> cm;

//         U   R  D  L
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
int dxx[] = {0,1,0,-1,1,1,-1,-1};
int dyy[] = {1,0,-1,0,1,-1,1,-1};

const long long MOD = 1e9+7 , N = 2e5+10 , INF = INT_FAST64_MAX;
const long double PI= 3.14159265358979323846264338327950288;

inline ll vin() {ll x;cin >> x;return x;}
ll POW(ll a, ll b) {ll res = 1; while(b){ if(b%2) res = (res*a)%MOD; a = (a*a)%MOD; b /= 2;} return res;}
vector<ll> DIGITS(ll n){vector<ll>a;while(n)a.push_back(n%10),n/=10;return a;}

//  #define cerr if(false)cerr
#define pr(x) cerr << "\n" << (#x) << " is " << (x) << endl;

ll GoDeep(ll n , vector<vector<ll> >& uv, vector<ll>& vis, vector<ll>& portions, vector<ll>& dp) 
{
        vis[n] = 1;
        dp[n] = portions[n];
        ll curr = 0;
        for(auto x:uv[n]) {
            if(!vis[x]) {
                curr += GoDeep(x,uv,vis,portions,dp);
            } else {
                curr += dp[x];
            }
        }
        if(uv[n].size()) {
            dp[n] = min(dp[n], (portions[n] ? curr : 0LL));
        }
        return dp[n];
}

void solve()
{
        ll n = vin() , k = vin();
        vector<ll> portions(n+1,0);
        for(int i=1; i<=n; i++) {
            portions[i] = vin();
        }
        for(int i=0; i<k; i++) {
            ll x = vin();
            portions[x] = 0;
        }
        vector< vector<ll> > uv(n+1);
        for(int i=1; i<=n; i++) {
            ll m = vin();
            for(int j=0; j<m; j++) {
                ll x = vin();
                uv[i].push_back(x);
            }
        }
        vector<ll> vis(n+1,0), dp(n+1,0), ans;
        for(int i=1; i<=n; i++) {
            if(!vis[i]) {
                ans.push_back(GoDeep(i,uv,vis,portions,dp));
            } else {
                ans.push_back(dp[i]);
            }
        }
        print(ans);
        return;
}

int main() 
{
        ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

        int T = 1, CNT = 0;  cin >> T;
        while(T--){
          //  cout << "Case " << ++CNT << ": ";
            solve();
        }
        return 0;
}