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


ll CheckIt(ll l , ll r, vector<ll>& Pre, vector<ll>& a, ll n, ll k) {
        pr(l); pr(r);
        ll lo = l , hi = r-1, mid, mx = a[r];
        while(hi-lo>1) {
            mid = (hi+lo) >> 1;
            ll d = Pre[r]-(mid ? Pre[mid-1] : 0LL);
            ll dis = r-mid+1;
            ll need = dis*mx-d;
            need += (dis*(dis-1))/2;
            if(need<=k) {
                hi = mid;
            } else {
                lo = mid+1;
            }
        }
        pr(lo); pr(hi);
        ll d = Pre[r]-(lo ? Pre[lo-1] : 0LL);
        ll dis = r-lo+1;
        ll need = dis*mx-d;
        need += (dis*(dis-1))/2;
        pr(need);
        if(need<=k) {
            return mx+dis-1;
        }
        d = Pre[r]-(hi ? Pre[hi-1] : 0LL);
        dis = r-hi+1;
        need = dis*mx-d;
        need += (dis*(dis-1))/2;
        if(need<=k) {
            return mx+dis-1;
        }
        return mx;
}

void solve()
{
        ll n = vin() , k = vin();
        vector<ll> a(n), Pre(n,0);
        for(int i=0; i<n; i++) {
            a[i] = vin();
        }
        for(int i=0; i<n; i++) {
            !i ? Pre[i] = a[i] : Pre[i] = Pre[i-1]+a[i];
        }
        ll mx = a.back(), r = n-1, l = n-1, ans = a.back();
        for(int i=n-1; i>=0; i--) {
            if(a[i]>mx) {
                l = i+1;
                if(l != r) {
                    ans = max(CheckIt(l,r,Pre,a,n,k),ans);
                }
                
                mx = a[i];
                r = i;
                ans = max(ans,mx);
            }
        }
        if(r) ans = max(CheckIt(0,r,Pre,a,n,k),ans);
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