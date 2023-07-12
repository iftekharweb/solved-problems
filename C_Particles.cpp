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

ll maxFrogJump(vector<ll>& values, ll index, vector<ll>& dp) {
    if (index < 0) {
        return 0;
    }
    
    if (dp[index] != -1) {
        return dp[index];
    }
    
    ll jump2 = maxFrogJump(values, index - 2, dp);
    ll jump3 = maxFrogJump(values, index - 3, dp);
    
    dp[index] = max(jump2, jump3) + values[index];
    
    return dp[index];
}

void solve()
{
        ll n = vin();
        vector<ll> a(n);
        for(int i=0; i<n; i++) {
            a[i] = vin();
        }
        vector<ll> b = {0,0,0,0,0,0,0}, dd = {0,0,0,0,0,0,0};
        stack<ll> c;
        for(int i=0; i<n-1; i++) {
            if(a[i]<0 && a[i+1]<0) continue;
            b.push_back(a[i]);
        }
        b.push_back(a[n-1]);
        //print(b);
        if(b.size() == 8) {
            cout << b.back() << endl;
            return;
        }
        for(int i=0; i<b.size(); i++) {
            if(b[i]<0) continue;
            if(b[i]>=0 && i+1<b.size() && b[i+1]<0) {
                if(i+2<b.size()) {
                    c.push(b[i]+b[i+2]);
                    dd.push_back((b[i]+b[i+2]));
                    i+=2;
                } else {
                    c.push(b[i]);
                    dd.push_back(b[i]);
                }
            } else {
                c.push(b[i]);
                dd.push_back(b[i]);
            }
        }
        b.push_back(0);
        b.push_back(0);
        b.push_back(0);
        b.push_back(0);
        b.push_back(0);
        b.push_back(0);

        ll nn = b.size();
        vector<ll> dp(nn, -1);
        
        ll maxGain = maxFrogJump(b, nn - 1, dp);
        cout << maxGain << endl;
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