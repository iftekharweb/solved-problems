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


void BlockCharacter(ll si, ll ss, ll se, ll qi, vector<bool>& Tree, vector<string>& a) {
        if(ss == se) {
            Tree[si] = true;
        } else {
            ll mid = (ss+se) >> 1;
            if(qi <= mid) {
                BlockCharacter(2*si, ss, mid, qi, Tree, a);
            } else {
                BlockCharacter(2*si+1, mid+1, se, qi, Tree, a);
            }
            Tree[si] = (Tree[2*si] & Tree[2*si+1]);
        }
        return;
}

void PointUpadateOrUnblock(ll si, ll ss, ll se, ll qi, char ch1, char ch2 , vector<bool>& Tree, vector<string>& a) {
        if(ss == se) {
            a[0][ss] = ch1, a[1][ss] = ch2;
            if(a[1][ss] == a[0][ss]){
                Tree[si] = true;
            } else {
                Tree[si] = false;
            }
        } else {
            ll mid = (ss+se) >> 1;
            if(qi <= mid) {
                PointUpadateOrUnblock(2*si, ss, mid, qi, ch1, ch2, Tree, a);
            } else {
                PointUpadateOrUnblock(2*si+1, mid+1, se, qi, ch1, ch2, Tree, a);
            }
            Tree[si] = (Tree[2*si] && Tree[2*si+1]);
        }
        return;
}
 
bool Query(ll si, ll ss, ll se, ll li , ll ri , vector<bool>& Tree, vector<string>& a) {
        if(li > se || ri < ss) {
            return true;
        } else if(li <= ss && ri >= se) {
            return Tree[si];
        } else {
            ll mid = (ss+se) >> 1;
            return (Query(2*si, ss, mid, li , ri , Tree, a) && Query(2*si+1, mid+1, se, li , ri , Tree, a));
        }
}
 
void Build_Tree(ll si, ll ss, ll se, vector<bool>& Tree, vector<string>& a) {
        if(ss == se) {
            if(a[1][ss] == a[0][ss]){
                Tree[si] = true;
            } else {
                Tree[si] = false;
            }
            return;
        } else {
            ll mid = (ss+se) >> 1;
            Build_Tree(2*si, ss, mid, Tree, a);
            Build_Tree(2*si+1, mid+1, se, Tree, a);
            Tree[si] = (Tree[2*si] && Tree[2*si+1]);
        }
}
 

void solve()
{
        vector<string> a(2);
        string u , v;
        a[0] = a[1] = "#";
        cin >> u >> v;
        a[0] += u;
        a[1] += v;
        ll n = a[0].size();
        vector<bool> Tree(4*n+10, true);
        Build_Tree(1,1,n,Tree,a);

        queue<ll> Q;
        ll t = vin(), q = vin();
        for(int i=0; i<q; i++) {
            ll type = vin();
            if(type == 1) {
                ll pos = vin();
                BlockCharacter(1,1,n,pos,Tree,a);
                Q.push(pos);
            } else if(type == 2) {
                ll w = vin() , x = vin() , y = vin() , z = vin();
                swap(a[w-1][x],a[y-1][z]);
                PointUpadateOrUnblock(1,1,n,x,a[0][x],a[1][x],Tree,a);
                PointUpadateOrUnblock(1,1,n,z,a[0][z],a[1][z],Tree,a);
                Q.push(0);
            } else {
                if(Tree[1]) {
                    cout << "YES" << endl;
                } else {
                    cout << "NO" << endl;
                }
                Q.push(0);
            }

            // Unblocking
            if(Q.size()>=t) {
                if(Q.front()) {
                    PointUpadateOrUnblock(1,1,n,Q.front(),a[0][Q.front()], a[1][Q.front()],Tree,a);
                }
                Q.pop();
            }
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