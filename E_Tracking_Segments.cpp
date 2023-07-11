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

void PointUpadate(ll si, ll ss, ll se, ll qi, ll val , vector<ll>& Tree, vector<ll>& a) {
        if(ss == se) {
            Tree[si] = a[ss];
        } else {
            ll mid = (ss+se) >> 1;
            if(qi <= mid) {
                PointUpadate(2*si, ss, mid, qi, val, Tree, a);
            } else {
                PointUpadate(2*si+1, mid+1, se, qi, val, Tree, a);
            }
            Tree[si] = (Tree[2*si]+Tree[2*si+1]);
        }
        return;
}
 
ll Query(ll si, ll ss, ll se, ll li , ll ri , vector<ll>& Tree, vector<ll>& a) {
        if(li > se || ri < ss) {
            return 0;
        } else if(li <= ss && ri >= se) {
            return Tree[si];
        } else {
            ll mid = (ss+se) >> 1;
            return Query(2*si, ss, mid, li , ri , Tree, a)+Query(2*si+1, mid+1, se, li , ri , Tree, a);
        }
}
 
void Build_Tree(ll si, ll ss, ll se, vector<ll>& Tree, vector<ll>& a) {
        if(ss == se) {
            Tree[si] = a[ss];
        } else {
            ll mid = (ss+se) >> 1;
            Build_Tree(2*si, ss, mid, Tree, a);
            Build_Tree(2*si+1, mid+1, se, Tree, a);
            Tree[si] = Tree[2*si]+Tree[2*si+1] ;
        }
        return;
}

bool isPossible(ll x,ll L, ll R, vector<ll>&b, ll q ,ll r,ll  ze) {
        for(int i=1; i<=x && ze>r; i++) {
            if(b[i]>=L && b[i]<=R) {
                ze--;
            }
        }
        pr(r); pr(ze); pr(x);
        return !(ze==r);
}
 

void solve()
{
        ll n = vin() , m = vin();
        vector<ll> Tree(4*n+1,0), a(n+1,0), b = {0};
        vector<pair<ll,ll> > vp;
        for(int i=0; i<m; i++) {
            ll x = vin() , y = vin();
            vp.push_back({x,y});
        }
        ll q = vin();
        for(int i = 0; i<q; i++) {
            ll x = vin();
            b.push_back(x);
        }
        print(b);
        ll ans = INF;
        for(int i=0; i<vp.size(); i++) {
            ll l = vp[i].first , r = vp[i].second;
            ll on = Query(1,1,n,l,r,Tree,a);
            ll ze = (r-l+1)-on;

            //pr(ze);
            if((r-l+1)%2) {
                ans = min(ans,INF);
            } else if(on>ze) {
                ans = min(ans,INF);
            } else {
                ll lo = 1, hi = q, mid;
                while(hi-lo>1) {
                    mid = (hi+lo) >> 1;
                    if(isPossible(mid,l,r,b,q,(r-l+1)/2,ze)) {
                        hi = mid;
                    } else {
                        lo = mid+1;
                    }
                }
                if(isPossible(lo,l,r,b,q,(r-l+1)/2,ze)) {
                    ans = min(ans,lo);
                } else if(isPossible(hi,l,r,b,q,(r-l+1)/2,ze)) {
                    ans = min(ans,hi);
                } else {
                    ans = min(ans,INF);
                }
            }
        }
        if(ans == INF) {
            cout << -1 << endl;
        } else {
            cout << ans << endl;
        }
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