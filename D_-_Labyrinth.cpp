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

int n , m , cnt = 0;
vector<string> a;
bool vis[1001][1001] , stop = false;
string ans;
 
bool is_valid(int x, int y) {
        if(x<0 || x>n-1 || y<0 || y>m-1) return false;
        if(vis[x][y] || a[x][y] == '#') return false;
        return true;
}
 
void GridDFS(int x, int y, char ch)
{
        vis[x][y] = true;
        if(a[x][y] == 'B') stop = true;
        if(stop) return;
        bool fg = 0;
        for(int i=0; i<4; i++){
            if(is_valid(x+dx[i] , y+dy[i])) {
                if(!i) {
                    fg = 1;
                    ans.push_back('U');
                    GridDFS(x+dx[i] , y+dy[i], 'U');
                }
                if(i == 1) {
                    fg = 1;
                    ans.push_back('R');
                    GridDFS(x+dx[i] , y+dy[i], 'R');
                }
                if(i == 2) {
                    fg = 1;
                    ans.push_back('D');
                    GridDFS(x+dx[i] , y+dy[i], 'D');
                }
                if(i == 3) {
                    fg = 1;
                    ans.push_back('L');
                    GridDFS(x+dx[i] , y+dy[i], 'L');
                }
            }
        }
        ans.pop_back();
        return ;
}

ll solve()
{
        n = vin() , m = vin();
        for(int i=0; i<n; i++) {
            string ss; cin >> ss;
            a.push_back(ss);
        }
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(a[i][j] == 'A') {
                    a[i][j] = '.';
                    GridDFS(i,j, 'O');
                }
            }
        }
        if(!stop) {
            cout << "NO" << endl;
            return 0;
        }
        cout << "YES" << endl;
        cout << ans.size() << endl;
        cout << ans << endl;
        return 0;
}
int main() 
{
        FastIO;
        solve();
        return 0;
}