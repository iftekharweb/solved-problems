
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ll  long long
#define ld  long double
#define printSet(a)  for(auto Data:a) cout<<Data<<" ";cout<<"\n";
#define printVector(a)  for(auto Data:a)cout<<Data<<" ";cout<<"\n";
#define printQueue(Q)  while(!Q.empty())cout<< Q.front()<<" ",Q.pop(); cout<<"\n";

#define all(a)  a.begin(),a.end()
#define rall(a)  a.rbegin(),a.rend()
#define stringToInt(a,x)   stringstream demo(a); demo >> x;
#define intToSting(x,s)   stringstream demu; demu << x; a = demu.str();

#define TxtIO   freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#define FastIO   ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
#define LCM(a,b)  (a*b)/__gcd(a, b)
#define TestCase   ll t;cin>>t;while(t--)
#define points(x)   fixed<<setprecision(x)
#define pr(x)  cerr << #x << " = " << x << endl;
#define nl  cout<<"\n";
const ld PI= 3.14159265358979323846264338327950288;

using namespace std;
using namespace __gnu_pbds;
template<class T> using indexed_set = tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

const long long MOD = 1e9+7 , N = 2e5+10 , INF = INT_FAST64_MAX;

//          U   R  D  L
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
inline ll vin() {ll x;cin >> x;return x;}
ll POW(ll a, ll b) {ll res = 1;while(b){if(b%2)res=(res*a)%MOD;a = (a*a)%MOD; b/=2;}return res;}
vector<ll> DIGITS(ll n){vector<ll>a;while(n)a.push_back(n%10),n/=10;return a;}

map<ll,int> vis;
set<ll> uv[N];
ll mi = 0;
bool fg = 0;

void DFS(ll n , set<ll> &st) {
        if(n!=mi+1 || fg) {
            fg = 1;
            return;
        }
        vis[n] = 1;
        st.insert(n);
        mi++;
        pr(n);
        for(auto x:uv[n]) {
            if(vis[x]!=1) {
                if(x==mi+1) DFS(x,st);
                else {
                    fg = 1;
                    return;
                }
            }
        }
        fg = 1;
        return;
}

ll solve()
{
        ll n = vin(), m = vin();
        for(int i=0; i<m; i++) {
            ll u = vin() , v =vin();
            uv[u].insert(v);
            uv[v].insert(u);
        }
        for(int i=1; i<=n; i++) {cout << i << " = ";printSet(uv[i]);}
        ll q = vin();
        while(q--) {
            
            ll t , x, y;
            cin >> t;
            if(t==1) {
                x = vin() , y = vin();
                uv[x].insert(y);
                uv[y].insert(x);
            }
            else if(t==2) {
                x = vin() , y = vin();
                uv[x].erase(uv[x].find(y));
                uv[y].erase(uv[y].find(x));
            }
            else {
                ll idx = 1, cnt = 0;;
                while(1) {
                    vis[idx] = 1; 
                    if(uv[idx].size()==1) break;
                    else {
                        bool tt = 0;
                        pr(idx);
                        for(auto p:uv[idx]) {
                            if(vis[p] != 1) {
                                cnt++;
                                idx++;
                                tt = 1;
                                break;
                            }
                        }
                        pr(tt);
                        if(!tt) break;
                    }
                }
                vis.clear();
                cout << n-cnt << "\n";
            }
        }
        return 0;

}
int main() 
{
        FastIO;
        solve();
        //TestCase{solve();}
        return 0;
}