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
const long long MOD = 1e9+7 , N = 2*(1e5)+10;
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

ll  n , m;
string hor , ver;
vector<vector<pair<char,char> > > a;
ll vis[21][21] , cnt;

bool isValid(ll x , ll y , char for_x , char for_y) {
    if(x<0 || x>n-1 || y<0 || y>m-1) return false;
    if(a[x][y].first!=for_x) return false;
    if(a[x][y].second!=for_y) return false;
    return true;
}

void check_grid(ll x , ll y) {
        cnt++;
        vis[x][y] = 1;
        for(int i=0; i<4; i++) {
            if(!vis[x+dx[i]][y+dy[i]] && isValid(x+dx[i], y+dy[i], a[x][y].first, a[x][y].second)) {
                check_grid(x+dx[i],y+dy[i]);
            }
        }
}

void clear_vis() {
        for(int i=0; i<n; i++) for(int j=0; j<m; j++) vis[i][j] = 0;
        return;
}

string solve()
{
        n = vin() , m = vin();
        cin >> hor >> ver;
        for(int i=0; i<n; i++) {
            vector<pair<char,char> > tmp;
            for(int j=0; j<m; j++) {
                if(hor[i]=='>')tmp.push_back({' ','>'});
                else tmp.push_back({' ','<'});
            }
            a.push_back(tmp);
        }
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(ver[i]=='^') a[j][i].first = '^';
                else a[j][i].first = 'v';
            }
        }

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                cout << a[i][j].first << " ";
            }
            nl;
        }
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                cout << a[i][j].second << " ";
            }
            nl;
        }

        ll be_cnt = n*m;
        for(int i=0; i<n; i++) for(int j=0; j<m; j++) {
            cnt = 0;
            clear_vis();
            check_grid(i,j);
            if(cnt!=be_cnt) return "NO";
        }
        return "YES";
}
int main() 
{
        FastIO;
        cout << solve() << "\n";
        return 0;
}