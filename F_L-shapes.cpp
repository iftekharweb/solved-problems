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

int dxx[] = {-1, 0, 1, 0 , 1 , 1 ,-1 ,-1};
int dyy[] = {0, 1, 0, -1 , 1 ,-1 , 1, -1};

inline ll vin() {ll x;cin >> x;return x;}
ll POW(ll a, ll b) {ll res = 1;while(b){if(b%2)res=(res*a)%MOD;a = (a*a)%MOD; b/=2;}return res;}
vector<ll> DIGITS(ll n){vector<ll>a;while(n)a.push_back(n%10),n/=10;return a;}

vector<pair<int,int> > ck;

bool round_check(ll x , ll y , ll n , ll m) {
        if(x<0 || y<0 || x>n-1 || y>m-1) return false;
        return true;
}

bool is_valid(ll x , ll y , vector<string> &a , vector<vector<int> > &vis , ll n , ll m) {
        if(x<0 || y<0 || x>n-1 || y>m-1) return false;
        if(vis[x][y] || a[x][y] != '*') return false;
        return true;
}

void dfs(int x , int y , vector<string> &a , vector<vector<int> > &vis , ll n , ll m) {
        vis[x][y] = 1;
        ck.push_back({x,y});
        for(int i=0; i<4; i++) {
            if(is_valid(x+dx[i],y+dy[i],a,vis,n,m)) {
                dfs(x+dx[i],y+dy[i],a,vis,n,m);
            }
        }
        return;
}

bool Impossible_case(vector<string> &a , vector<vector<int> > &vis , ll &n , ll &m) {
        if(ck.size() != 3) return true;

        if(ck[0].first == ck[1].first && ck[1].first == ck[2].first) return true;
        if(ck[0].second == ck[1].second && ck[1].second == ck[2].second) return true;

        for(auto x:ck) {
            int i = x.first , j = x.second;
            for(int l=0; l<8; l++)  {
                if(round_check(i+dxx[l],j+dyy[l],n,m) ) {
                    if(a[i+dxx[l]][j+dyy[l]] == '*') {
                        bool fg = 0;
                        for(auto pp:ck) {
                            if(i+dxx[l] == pp.first && j+dyy[l] == pp.second) {
                                fg = 1;
                                break;
                            }
                        }
                        if(!fg) return true;
                    }
                }
            }
        }
        return false;
}

string solve()
{
        ll n = vin() , m = vin();
        ck.clear();
        vector<string> a(n);
        for(int i=0; i<n; i++) {
            cin >> a[i];
        }
        vector<vector<int> > vis(n,vector<int>(m,0));
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(a[i][j] == '*' && !vis[i][j]) {
                    dfs(i,j,a,vis,n,m);
                    if(Impossible_case(a,vis,n,m)) return "NO";
                    ck.clear();
                }
            }
        }
        return "YES";
}
int main() 
{
        FastIO;
        TestCase {
            cout << solve() << "\n";
        }
        return 0;
}