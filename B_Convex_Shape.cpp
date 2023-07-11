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

vector<string> a;
ll n , m;

bool Stright_right(ll y_min , ll y_max , ll x) {
        while(y_min<=y_max) {
            if(a[x][y_min]!='B') return false;
            y_min++;
        }
        return true;
}

bool Stright_up(ll x_min , ll x_max , ll y) {
        while(x_min<=x_max) {
            if(a[x_min][y]!='B') return false;
            x_min++;
        }
        return true;
}

string solve()
{
        n = vin() , m = vin();
        for(int i=0; i<n; i++) {
            string ss;
            cin >> ss;
            a.push_back(ss);
        }
        vector<pair<ll,ll> > vp;

        for(int i=0; i<n; i++) for(int j=0; j<m; j++) {
            if(a[i][j]=='B') vp.push_back({i,j});
        }
        for(int i=0; i<vp.size()-1; i++) {
            for(int j=i+1; j<vp.size(); j++) {
                ll x = vp[i].first , y = vp[i].second;
                ll p = vp[j].first , q = vp[j].second;
                if(Stright_right(min(y,q),max(y,q),min(x,p)) && Stright_up(min(x,p),max(x,p),min(y,q)))
                    continue;
                if(Stright_right(min(y,q),max(y,q),max(x,p)) && Stright_up(min(x,p),max(x,p),max(y,q)))
                    continue;
                if(Stright_right(min(y,q),max(y,q),min(x,p)) && Stright_up(min(x,p),max(x,p),max(y,q)))
                    continue;
                if(Stright_right(min(y,q),max(y,q),max(x,p)) && Stright_up(min(x,p),max(x,p),min(y,q)))
                    continue;
                //pr(x); pr(y); pr(p); pr(q);
                return "NO";
            }
        }
        return "YES";
}
int main() 
{
        FastIO;
        cout << solve() << "\n";
        return 0;
}