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

bool is_valid(ll x , ll y , ll n, ll m) {
        if(x>=0 && x<n && y>=0 && y<m) return true;
        return false;
}

ll solve()
{
        ll n = vin() , m = vin();
        ll a[n][m] , fg = 1;
        for(int i=0; i<n; i++) for(int j=0; j<m; j++) a[i][j] = 0;
        for(int i=0; i<n;) {
            for(int j=0; j<m;) {
                if(!j) {
                    a[i][j] = 1;
                    if(i && is_valid(i+1,j,n,m)) a[i+1][j] = 1;
                    j+=3;
                }
                else{
                    a[i][j] = 1;
                    if(is_valid(i,j+1,n,m)) a[i][j+1] = 1;
                    if(i && is_valid(i+1,j,n,m)) a[i+1][j] = 1;
                    if(i && is_valid(i+1,j+1,n,m)) a[i+1][j+1] = 1;
                    j+=4;
                }
            }
            if(!i) i+=3;
            else i+=4;
            if(!fg) fg = 1;
            else fg = 0;
        }
        for(int i=1; i<n; i+=4) {
            for(int j=1; j<m; j+=4) {
                a[i][j] = 1;
                if(is_valid(i,j+1,n,m)) a[i][j+1] = 1;
                if(is_valid(i+1,j,n,m)) a[i+1][j] = 1;
                if(is_valid(i+1,j+1,n,m)) a[i+1][j+1] = 1;
            }
        }
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                cout << a[i][j] << " ";
            }
            nl;
        }
        return 0;
}
int main() 
{
        FastIO;
        TestCase {
            // cout << solve() << "\n";
            solve();
        }
        return 0;
}