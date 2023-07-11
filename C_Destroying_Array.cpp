/*
                بِسْمِ ٱللَّٰهِ ٱلرَّحْمَٰنِ ٱلرَّحِيمِ                
                Iftekhar Md. Shishir
                Dept. of Information and Communication Engineering
                University of Rajshahi
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ll  long long
#define ull  unsigned long long
#define ld  long double
#define printSet(a)  for(auto setData:a) cout<<setData<<" ";cout<<endl;
#define printMap(a)  for(auto mapData:a) cout<<mapData.first<<" "<<mapData.second<<endl;
#define printVector(a)  for(auto vectorData:a)cout<<vectorData<<" ";cout<<endl;
#define printQueue(Q)  while(!Q.empty()) cout<< Q.front()<<" ",Q.pop(); cout<<"\n";

#define all(a)  a.begin(),a.end()
#define rall(a)  a.rbegin(),a.rend()
#define stringToInt(a,x)   stringstream demo(a); demo >> x;
#define intToSting(x,s)   stringstream demu; demu << x; a = demu.str();

#define TxtIO   freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#define TxtTest   freopen("C:/Users/Iftekhar/Documents/what/input.txt", "r", stdin);
#define FastIO   ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
#define LCM(a,b)  (a*b)/__gcd(a, b)
#define TestCase   ll t;cin>>t;while(t--)
#define points(x)   fixed<<setprecision(x)
#define pr(x)  cerr << #x << " = " << x << endl;
#define nl  cout<<"\n";

const ld PI= 3.14159265358979323846264338327950288;  //2*acos(0.0);
const long long MOD = 1e9+7 , N = 1e5+2;
const long long INF = INT_FAST64_MAX;

using namespace std;
using namespace __gnu_pbds;
template<class T> using indexed_set = tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

//          U   R  D  L
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

inline ll vin() {ll x;cin >> x;return x;}
ll POW(ll a, ll b) {ll res = 1;while(b){if(b%2)res=(res*a)%MOD;a = (a*a)%MOD; b/=2;}return res;}
vector<ll> DIGITS(ll n){vector<ll>a;while (n)a.push_back(n%10),n/=10;return a;}

vector<ll> parent(N) , sum(N) , mark(N) , sz(N);
ll n , m;
 
void Make(ll v) {
        parent[v] = v;
        sum[v] = 0;
        sz[v] = 1;
        return;
}
ll Find(ll v) {
        if(parent[v]==v) return v;
        return parent[v] = Find(parent[v]);
}
ll Union(ll a , ll b) {
        a = Find(a);
        b = Find(b);
        if(a!=b) {
            if(sz[b]>sz[a]) swap(a,b);
            sum[a] += sum[b];
            parent[b] = a;
            sz[a] += sz[b];
        }
        return sum[a];
}
ll solve()
{
        ll n = vin();
        vector<ll> a(n+1) , b(n+1);
        for(int i=1; i<=n; i++) a[i] = vin();
        for(int i=1; i<=n; i++) b[i] = vin();
        for(int i=1; i<=n; i++) Make(i);
        vector<ll> res;
        ll mx = 0;
        for(int i=n; i>0; i--)
        {
            res.push_back(mx);
            sum[b[i]] = a[b[i]];
            if(!mark[b[i]+1] && !mark[b[i]-1]) {
                mx = max(mx,sum[b[i]]);
            }
            else if(mark[b[i]+1] && mark[b[i]-1]) {
                ll x = Find(b[i]+1);
                mx = max(mx,Union(b[i],x));
                x = Find(b[i]);
                ll y = Find(b[i]-1);
                mx = max(mx,Union(y,x));
            }
            else if(!mark[b[i]-1] && mark[b[i]+1]) {
                ll x = Find(b[i]+1);
                mx = max(mx,Union(b[i],x));
            }
            else if(mark[b[i]-1] && !mark[b[i]+1]) {
                ll x = Find(b[i]-1);
                mx = max(mx,Union(b[i],x));
            }
            mark[b[i]] = 1;
            //for(int i=1; i<=n; i++) cout << sum[i] << " "; nl;
        }
        reverse(all(res));
        for(int i=0; i<res.size(); i++) {
            cout << res[i] << "\n";
        }
        return 0;
}
int main() 
{
        FastIO;
        solve();
        return 0;
}