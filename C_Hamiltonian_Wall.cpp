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
//          U   R  D  L
int px[] = {1, 0, -1, 0};
int py[] = {0, 1, 0, -1};

inline ll vin() {ll x;cin >> x;return x;}
ll POW(ll a, ll b) {ll res = 1;while(b){if(b%2)res=(res*a)%MOD;a = (a*a)%MOD; b/=2;}return res;}
vector<ll> DIGITS(ll n){vector<ll>a;while(n)a.push_back(n%10),n/=10;return a;}

vector<pair<ll,ll> > vp;
ll vis[2][N];

bool isPos(ll x ,ll y , vector<string>&a, ll n) {
        if(x<0 || x>=2 || y<0 || y >=n) return false;
        if(vis[x][y]) return false;
        if(a[x][y] == 'W') return false;
        return true;
}

void Dfs(ll x ,ll y , vector<string>&a, ll n) {
        vis[x][y] = 1;
        vp.push_back({x,y});
        for(int i=0; i<4; i++) {
            if(isPos(x+dx[i],y+dy[i],a,n)) {
                Dfs(x+dx[i],y+dy[i],a,n);
            }
        }
        return;
}

void DfsAgain(ll x ,ll y , vector<string>&a, ll n) {
        vis[x][y] = 1;
        vp.push_back({x,y});
        for(int i=0; i<4; i++) {
            if(isPos(x+px[i],y+py[i],a,n)) {
                DfsAgain(x+px[i],y+py[i],a,n);
            }
        }
        return;
}

void ClearVis(ll n) {
        for(int i=0; i<2; i++) {
            vis[0][i] = vis[1][i] = 0;
        }
        return;
}

bool CheckAns(vector<string> &a, ll n) {
        for(int i=0; i<2; i++) {
            for(int j=0; j<n; j++) {
                if(a[i][j] == 'B' && !vis[i][j]) {
                    return false;
                }
            }
        }
        for(int i=0; i<(int)(vp.size())-1; i++) {
            if(vp[i].first == vp[i+1].first) {
                if(vp[i].second+1 == vp[i+1].second) {
                    return false;
                }
            }
            else if(vp[i].second == vp[i+1].second) {
                if(vp[i].first+1 != vp[i+1].first) {
                    return false;
                }
            }
            else 
                return false;
        }
        return true;
}

string solve()
{
        ll n = vin();
        vector<string> a(2);
        vector< vector<ll> > vis(2,vector<ll>(n,0));
        for(int i=0; i<2; i++) {
            string p; cin >> p;
            a[i] = p;
        }
        //return "-";
        for(int i=0; i<n; i++) {
            bool bad = 0;
            if(a[1][i] == 'B') {
                Dfs(1,i,a,n);
                if(CheckAns(a,n)) {
                    return "YES";
                }
                vp.clear();
                ClearVis(n);

                //DfsAgain(1,i,a,vis,n);
                if(CheckAns(a,n)) {
                    return "YES";
                }
                vp.clear();
                ClearVis(n);
                bad = 1;
            }
            if(a[0][i] == 'B') {
                Dfs(0,i,a,n);
                if(CheckAns(a,n)) {
                    return "YES";
                }
                vp.clear();
                ClearVis(n);

                //DfsAgain(0,i,a,vis,n);
                if(CheckAns(a,n)) {
                    return "YES";
                }
                vp.clear();
                ClearVis(n);
                bad = 1;
            }
            if(bad) break;
        }
        return "NO";
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