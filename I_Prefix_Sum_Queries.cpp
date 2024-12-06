#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using ll = long long;
using ld = long double;
#define all(a)  a.begin(),a.end()
#define rall(a)  a.rbegin(),a.rend()
#define LCM(a,b)  (a*b)/__gcd(a, b)
#define nl  cout<<"\n";

using namespace std;
using namespace __gnu_pbds;
template<class T> void print(T& a) { for(auto x:a)cout<<x<<" "; cout<<"\n";}
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

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
#define dbg(x) cerr << "\n" << (#x) << " is " << (x) << endl;

void Range_Update(ll si , ll ss , ll se, ll li , ll ri , ll val , vector<ll>& Tree, vector<ll>& Lazy) {
        if(Lazy[si]) {
            ll dx = Lazy[si];
            Lazy[si] = 0;
            Tree[si] += dx*(se-ss+1);
            if(ss != se) {
                Lazy[2*si] += dx;
                Lazy[2*si+1] += dx;
            }
        }
        if(li>se || ri <ss) {
            return;
        } else if(li<=ss && ri>=se) {
            ll dx = val*(se-ss+1);
            Tree[si] += dx;
            if(ss != se) {
                Lazy[2*si] += val;
                Lazy[2*si+1] += val;
            }
        } else {
            ll mid = (ss+se) >> 1;
            ll left = 2*si;
            ll right = 2*si+1;
            Range_Update(left,ss,mid,li,ri,val,Tree,Lazy);
            Range_Update(right,mid+1,se,li,ri,val,Tree,Lazy);
            Tree[si] = Tree[left]+Tree[right];
        }
        return;
}

ll Query(ll si , ll ss, ll se , ll li , ll ri , vector<ll>& Tree, vector<ll>& Lazy) {
        if(Lazy[si]) {
            ll dx = Lazy[si];
            Lazy[si]= 0;
            Tree[si] += dx*(se-ss+1);
            if(ss != se) {
                Lazy[2*si] += dx;
                Lazy[2*si+1] += dx;
            }
        }
        if(li>se || ri <ss) {
            return 0;
        } else if(li <= ss && ri >= se) {
            return Tree[si];
        } else {
            ll mid = (ss+se) >> 1;
            ll left = 2*si;
            ll right = 2*si+1;
            return Query(left,ss,mid,li,ri,Tree,Lazy)+Query(right,mid+1,se,li,ri,Tree,Lazy);
        }
}

void Build_Tree(ll si , ll ss , ll se , vector<ll>& Tree, vector<ll>& a) {
        if(ss == se) {
            Tree[si] = a[ss];
        } else {
            ll mid = (ss+se) >> 1;
            ll left = 2*si;
            ll right = 2*si+1;
            Build_Tree(left,ss,mid,Tree,a);
            Build_Tree(right,mid+1,se,Tree,a);
            Tree[si] = Tree[left]+Tree[right];
        }
        return;
}

void solve()
{
        ll n = vin() , m = vin();
        vector<ll> a(n+1,0) , Tree(4*n+10,0), Lazy(4*n+10,0);
        for(int i=0; i<n; i++) {
            a[i+1] = 0;
        }
        Build_Tree(1,1,n,Tree,a);
        while(m--) {
            ll t = vin();
            if(t == 1) {
                ll li = vin() , ri = vin(), val = vin();
                li++;
                Range_Update(1,1,n,li,ri,val,Tree,Lazy);
            } else {
                ll x = vin();
                x++;
                ll ans = Query(1,1,n,x,x,Tree,Lazy);
                cout << ans << endl;
            }
        }
        return;
}

int main() {
    
        ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

        int T = 1, CNT = 0;  //cin >> T; 

        while(T--){
          //  cout << "Case " << ++CNT << ": ";
            solve();
        }
        return 0;
} 