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

const long long MOD = 1e9+7 , N = 1010 , INF = INT_FAST64_MAX;

//          U   R  D  L
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
inline ll vin() {ll x;cin >> x;return x;}
ll POW(ll a, ll b) {ll res = 1;while(b){if(b%2)res=(res*a)%MOD;a = (a*a)%MOD; b/=2;}return res;}
vector<ll> DIGITS(ll n){vector<ll>a;while(n)a.push_back(n%10),n/=10;return a;}

vector<string> a;
ll mark[N][N] , n , m;

bool is_valid(ll x, ll y, char ch) {
        if(x>n-1 || y>m-1 || x<0 || y<0) return false;
        if(mark[x][y]) return false;
        if(a[x][y] != ch) return false;
        return true;
}

void Grid_dfs(ll x , ll y, ll col) {
        mark[x][y] = col;
        for(int i=0; i<4; i++) {
            if(is_valid(x+dx[i], y+dy[i], a[x][y])) {
                Grid_dfs(x+dx[i], y+dy[i], col);
            }
        }
        return;
}

ll solve()
{
        n = vin() , m = vin();
        for(int i=0; i<n; i++) {
            string s;
            cin >> s;
            a.push_back(s);
        }
        ll col = 1;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(!mark[i][j]) {
                    Grid_dfs(i,j,col);
                    col++;
                }
            }
        }
        ll q = vin();
        while(q--) {
            ll x1 = vin() , y1 = vin() , x2 = vin() , y2 = vin();
            x1-- , y1-- , x2-- , y2--;
            if(mark[x1][y1] == mark[x2][y2]) 
            {
                if(a[x1][y1] == '0') cout << "binary\n";
                else cout << "decimal\n";
            }
            else {
                cout << "neither\n";
            }
        }
        return 0;
}
int main() 
{
        FastIO;
        solve();
        return 0;
}