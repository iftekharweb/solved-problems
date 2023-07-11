/*
                بِسْمِ ٱللَّٰهِ ٱلرَّحْمَٰنِ ٱلرَّحِيمِ                
                Iftekhar Md. Shishir
                Dept. of Information and Communication Engineering
                University of Rajshahi
*/

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

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
const long long MOD = 1000000007;
const long long INF = INT_FAST64_MAX;

using namespace std;
using namespace __gnu_pbds;
template<class T>using indexed_set=tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>;

inline ll vin() {ll x;cin >> x;return x;}
ll POW(ll a, ll b) {ll res = 1;while(b){if(b%2)res=(res*a)%MOD;a = (a*a)%MOD; b/=2;}return res;}
vector<ll> DIGITS(ll n){vector<ll>a;while (n)a.push_back(n%10),n/=10;return a;}

ll vis[1001][1001];
ll a[1001][1001] , n , m , cnt;

//          T   R  B  L
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

//          N   E   S  W
// int dx[] = {0 , -1, 0, 1};
// int dy[] = {-1, 0 , 1, 0};

bool is_valid(int x, int y) {
        if(x<0 || x>n-1 || y<0 || y>m-1) return false;
        return true;
}
void grid_dfs(ll x, ll y) {
        vis[x][y] = 1;
        cnt++;
        //cout << a[x][y] << " ";
        for(int i=0; i<4; i++) {
            if(is_valid(x+dx[i],y+dy[i])) {
                if(vis[x+dx[i]][y+dy[i]]) continue;
                // 13 = 1101 TRBL
                bitset<4> b1 = a[x][y];
                bitset<4> b2 = a[x+dx[i]][y+dy[i]];
                if(!i && b1[3]==0 && b2[1]==0) grid_dfs(x+dx[i],y+dy[i]);
                else if(i==1 && b1[2]==0 && b2[0]==0) grid_dfs(x+dx[i],y+dy[i]);
                else if(i==2 && b1[1]==0 && b2[3]==0) grid_dfs(x+dx[i],y+dy[i]);
                else if(i==3 && b1[0]==0 && b2[2]==0) grid_dfs(x+dx[i],y+dy[i]); 
            }
        }

}

void solve()
{
        n = vin() , m = vin();
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                cin >> a[i][j];
            }
        }
        for(int i=0; i<n; i++) for(int j=0; j<m; j++) vis[i][j] = 0;
        cnt = 0;
        vector<ll> res;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(!vis[i][j]) {
                    cnt = 0;
                    grid_dfs(i,j);
                    res.push_back(cnt);
                }
            }
        }
        sort(rall(res));
        printVector(res);
        return ;
}
int main() 
{
        FastIO;
        solve();
        return 0;
}