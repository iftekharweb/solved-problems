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



ll query(ll si, ll ss, ll se, ll li, ll ri, vector<ll>& Tree, vector<ll>& a) {
        if(li>se || ri<ss){
            return 0;
        }
        if(ss>=li && se<=ri){
            return Tree[si];
        }
        ll mid = (ss+se)/2;
        ll l = query(2*si, ss, mid, li, ri,Tree,a);
        ll r = query(2*si+1, mid+1, se, li, ri,Tree,a);
        return l+r;
}

void buildTree(ll si, ll ss, ll se,vector<ll>& Tree, vector<ll>& a) 
{
        if(ss==se){
            Tree[si] = a[ss];
            return;
        }
        ll mid = ss+(se-ss)/2;
        buildTree(2*si, ss, mid,Tree,a);
        buildTree(2*si+1, mid+1, se,Tree,a);
        Tree[si]=(Tree[2*si] +Tree[2*si+1]);
}

void solve()
{
        ll n = vin() , m = vin();
        string a;
        cin >> a;
        vector<ll> Tree(4*n+1,0), b(n+1);
        vector<vector<ll> > idx(2);
        for(int i=0; i<n; i++) {
            b[i+1] = (a[i] == '1' ? 1 : 0);
            idx[a[i]-'0'].push_back(i+1);
        }
        buildTree(1,1,n,Tree,b);
        vector<set<ll> > vst(n+1);
        ll base = 0;
        for(int i=0; i<m; i++) {
            ll x = vin() , y = vin();
            ll cnt = query(1,1,n,x,y,Tree,b);
            if(!cnt) {
                base = 1;
                continue;
            }
            ll it = lower_bound(all(idx[1]),x)-idx[1].begin();
            ll id1 = idx[1][it];
            ll ii = lower_bound(all(idx[0]),id1)-idx[0].begin();
            
            ll id0 = ii<idx[0].size() ? idx[0][ii] : n+1;
            if(id0<=y && id1<id0) {
                ll ii0 = lower_bound(all(idx[0]),y+1)-idx[0].begin();
                id0 = ii0<idx[0].size() ? idx[0][ii0]-1 : n;
                vst[id0].insert(cnt+id0-y);
            } else {
                base = 1;
            }
        }
        ll ans = base;
        for(int i=1; i<=n; i++) ans += vst[i].size();
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