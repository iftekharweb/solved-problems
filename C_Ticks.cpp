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


ll n , m , k;
vector<string> a;
ll vis[11][20];

bool isValid(ll x , ll y) {
        return (x>=0 && x<n && y>=0 && y<m);
}
bool isPossible(ll x, ll y, ll l) {
        ll cc = l, p = x , q = y;
        while(cc--){
            p--,q--;
            if(isValid(p,q) && a[p][q]=='*'){
                continue;
            }else return false;
        }
        cc = l , p = x , q = y;
        while(cc--){
            p--,q++;
            if(isValid(p,q) && a[p][q]=='*'){
                continue;
            }else return false;
        }
        return true;
}
void markThem(ll x , ll y , ll l) {
        ll cc = l, p = x , q = y;
        vis[p][q] = 1;
        while(cc--){
            p--,q--;
            vis[p][q] = 1;
        }
        cc = l , p = x , q = y;
        while(cc--){
            p--,q++;
            vis[p][q] = 1;
        }
        return;
}

string solve()
{
        a.clear();
        for(int i=0; i<n; i++) for(int j=0; j<m; j++) vis[i][j] = 0;

        n = vin() , m = vin() , k = vin();
        for(int i=0; i<n; i++) {
            string b; cin >> b;
            a.push_back(b);
        }
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                //pr(a[i][j]);
                if(a[i][j]=='*')for(int l=k; ;l++) {
                    //pr(i); pr(j);
                    if(isPossible(i,j,l)) markThem(i,j,l);
                    else break;
                }
            }
        }
        // for(int i=0; i<n; i++) {
        //     for(int j=0; j<m; j++) {
        //         cout << vis[i][j];
        //     }
        //     nl;
        // }
        for(int i=0; i<n; i++) for(int j=0; j<m; j++) {
            if(a[i][j]=='*' && !vis[i][j]) return "NO";
        }
        return "YES";
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