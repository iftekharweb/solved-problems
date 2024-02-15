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

bool TryAgain(vector<ll>& a, vector<pair<ll,ll> >&vp, ll nope, ll k, ll mid) {
        bool ok = 0;
        for(int i=1; i<=nope && !ok; i++) {
            ll x = vp[i].first, y = vp[i].second;
            if(y-x+1<mid) continue;
            ll pre = a[x], sum = 0;
            for(int j=x; j<=x+mid-1; j++) {
                sum += a[j];
            }
            if(sum<=k) {
                ok = 1;
                break;
            }
            for(int j=x+mid, bad = x; j<=y; j++, bad++) {
                sum += a[j];
                sum -= a[bad];
                if(sum<=k) {
                    ok = 1;
                    break;
                }
            }
        }
        return ok;
}

void solve()
{
        ll n = vin() , k = vin();
        vector<ll> a(n), h(n), con(n,0);
        for(auto &x:a) x = vin();
        for(auto &x:h) x = vin();
        if(n == 1 && a[0]<=k) {
            cout << 1 << endl;
            return;
        } 
        ll nope = 1;
        for(int i=0; i<n-1; i++) {
            if(h[i]%h[i+1] == 0) {
                con[i] = con[i+1] = nope;
            } else {
                ++nope;
                con[i+1] = nope;
            }
        }
        vector<pair<ll,ll> > vp(nope+1);
        for(int i=1; i<=nope; i++) {
            ll itl = lower_bound(all(con),i)-con.begin();
            ll itr = upper_bound(all(con),i)-con.begin(); itr--;
            vp[i] = {itl,itr};
        }
        ll lo = 1, hi = n, mid;
        while(hi-lo>1) {
            mid = (hi+lo) >> 1;
            if(TryAgain(a,vp,nope,k,mid)) {
                lo = mid;
            } else {
                hi = mid-1;
            }
        }
        if(TryAgain(a,vp,nope,k,hi)) {
            cout << hi << endl;
        } else if(TryAgain(a,vp,nope,k,lo)) {
            cout << lo << endl;
        } else {
            cout << 0 << endl;
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