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
        ll n = vin(), ans = 1;
        vector<string> a(2);
        cin >> a[0] >> a[1];
        ll x = 0 , y = 0;
        string lex = ""; lex.push_back(a[0][0]);
        while(x != 1 || y != n-1) {
            if(x==0) {
                if(y+1<n) {
                    //(a[x][y+1]<a[x+1][y]) ? y++ : x++;
                    if(a[x][y+1]<a[x+1][y]) {
                        y++;
                        ans = 1;
                    } else if(a[x][y+1]==a[x+1][y]) {
                        //pr(x); pr(y);
                        y++;
                        ans++;
                    } else {
                        x++;
                    }
                } else {
                    x++;
                }
            } else {
                y++;
            }
            lex.push_back(a[x][y]);
            //cout << x << " " << y << " " << ans << endl;
        }
        cout << lex << endl;
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