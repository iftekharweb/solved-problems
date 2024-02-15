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

void cal(ll x, ll y, multiset<pair<ll,ll> > &st, bool ck) {

}

void solve()
{
        ll n = vin(), k = vin(), a = vin() , b = vin();
        vector<pair<ll,ll> > vp(n);
        map<pair<ll,ll>, bool> cm;
        for(int i=0; i<n; i++) {
            ll x = vin() , y = vin();
            vp[i] = {x,y};
            if(i<k)  {
                cm[vp[i]] = true;
            }
        }
        a--, b--;
        priority_queue<ll, vector<ll>, greater<ll> > AtoE, BtoE;
        bool fg = 0;
        (cm.find(vp[a]) != cm.end()) ? fg = 1 : fg = 0;
        if(!fg) for(int i=0; i<n; i++) {
            if(i == a) continue;
            if(cm.find(vp[i]) != cm.end()) {
                AtoE.push(abs(vp[a].first-vp[i].first)+abs(vp[a].second-vp[i].second));
            }
        }
        (cm.find(vp[b]) != cm.end()) ? fg = 1 : fg = 0;
        if(!fg) for(int i=0; i<n; i++) {
            if(i == b) continue;
            if(cm.find(vp[i]) != cm.end()) {
                BtoE.push(abs(vp[b].first-vp[i].first)+abs(vp[b].second-vp[i].second));
            }
        }
        pair<ll,ll> p = vp[a], q = vp[b];
        if(cm.find(p) != cm.end() && cm.find(q) != cm.end()) {
            cout << 0 << endl;
            return;
        }
        ll ans = abs(p.first-q.first)+abs(p.second-q.second);
        if(cm.find(p) != cm.end() && !BtoE.empty()) {
            ans = min(BtoE.top(),ans);
            cout << ans << endl;
            return;
        }
        if(cm.find(q) != cm.end() && !AtoE.empty()) {
            ans = min(AtoE.top(),ans);
            cout << ans << endl;
            return;
        }
        if(!AtoE.empty() && !BtoE.empty()) {
            ans = min(ans,AtoE.top() + BtoE.top());
        }
        cout << ans << endl;
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