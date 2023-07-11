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

void Apply_DFS(ll n, vector< vector<int> > &uv, vector<bool> &vis){
      vis[n] = true;
      for(auto x:uv[n]) {
        if(!vis[x]) Apply_DFS(x,uv,vis);
      }
      return;
}

ll solve()
{
        ll n = vin();
        n += n;
        string a; cin >> a;
        stack<int> stk;
        vector<int> reg;
        vector<bool> vis(n+1,false);
        vector< vector<int> > uv(n+1);
        for(int i=0; i<n; i++){
          if(a[i] == '(') {
            stk.push(i+1);
          }
          else {
            uv[i+1].push_back(stk.top());
            uv[stk.top()].push_back(i+1);
            stk.pop();
          }
        }
        for(int i=0; i<n-1; i++) {
            if(a[i] == ')' && a[i+1] == '(') {
                uv[i+1].push_back(i+2);
                uv[i+2].push_back(i+1);
            }
        }
        int connected = 0;
        for(int i=1; i<=n; i++){
          if(!vis[i]) {
              Apply_DFS(i,uv,vis);
            connected++;
          }
        }
        return connected;
}
int main() 
{
        FastIO;
        TestCase {
            cout << solve() << "\n";
            //solve();
        }
        return 0;
}