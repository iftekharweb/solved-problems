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

void solve()
{
        ll n = vin();
        vector<ll> a(n);
        ll mi = MOD , mx = -MOD, miId, mxId;
        for(int i=0; i<n; i++) {
            a[i] = vin();
            if(a[i]<mi) {
                mi = a[i];
                miId = i;
            }
            if(a[i]>mx) {
                mx = a[i];
                mxId = i;
            }
        }
        if(mx == 0 && mi == 0) {
            cout << 0 << endl;
            return;
        }
        vector<pair<ll,ll> > ans;
        if(abs(mx-0)>=abs(mi-0) && mx>=0) {
            for(int i=0; i<n; i++) {
                if(i != mxId) {
                    a[i] += mx;
                    ans.push_back({i,mxId});
                }
            }
            ll x = a[0];
            for(int i=1; i<n; i++) {
                a[i] += x;
                x = a[i];
                ans.push_back({i,i-1});
            }
        } else {
            for(int i=0; i<n; i++) {
                if(i != miId) {
                    a[i] += mi;
                    ans.push_back({i,miId});
                }
            }
            ll x = a.back();
            for(int i=n-2; i>=0; i--) {
                a[i] += x;
                x = a[i];
                ans.push_back({i,i+1});
            }
        }
        cout << ans.size() << endl;
        for(auto x:ans) {
            cout << x.first+1 << " " << x.second+1 << endl;
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