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
ll POW(ll a, ll b) {
    ll res = 1; 
    while(b){ 
        if(b&1) {
            res*=a;
            --b;
        } else {
            a *= a; 
            b >>= 1;
        }
    }
    return res;
}
vector<ll> DIGITS(ll n){vector<ll>a;while(n)a.push_back(n%10),n/=10;return a;}

//  #define cerr if(false)cerr
#define pr(x) cerr << "\n" << (#x) << " is " << (x) << endl;

ll CalMe(ll mid, ll po, ll n) {
    ll cnt = 0;
    for(int j=0; j<=po && cnt<=n; j++) {
        cnt += POW(mid,j);
    }
    return cnt<0 ? INF : cnt;
}

void solve()
{
        ll n = vin();
        for(int i=2; i<64; i++) {
            ll lo = 2 , hi = 1e9+1, mid;
            while( hi-lo > 1) {
                mid = (hi+lo) >> 1;
                ll cnt = CalMe(mid,i,n);
                if(cnt == n) {
                    cout << "YES" << endl;
                    return;
                }
                if(cnt < n) {
                    lo = mid;
                } else {
                    hi = mid-1;
                }
            }
            ll cntHi = CalMe(hi,i,n);
            ll cntLo = CalMe(lo,i,n);

            if(cntHi == n || cntLo == n) {
                cout << "YES" << endl;
                return;
            }
        }
        cout << "NO" << endl;
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