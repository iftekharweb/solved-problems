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

ll n , m;
vector<ll> a(N), b(N,-1) , id , up , down;

void calculate(int in , int de) {
        bool bul = 0;
        ll idx = -1;
        for(int i=0; i<n-1; i++) {
            if(a[i]>a[i+1] && !de) {
                de = 1;
                in = 0;
                b[i] = 0;
                bul = 0;
                down.push_back(i);
            }
            if(a[i]<a[i+1] && !in) {
                in = 1;
                de = 0;
                b[i] = 1;
                up.push_back(i);
                if(bul) id.push_back(idx);
                bul = 0;
            }
            if(a[i]==a[i+1]) {
                if(!bul) {
                    bul = 1;
                    idx = i;
                }
            }
        }
        return;
}

void solve()
{
        n = vin() , m = vin();
        for(int i=0; i<n; i++) a[i] = vin();
        calculate(0,0);
        vector<ll> cc(n+1,0);
        ll ze = 0 , on = 0;
        for(int i=0; i<n; i++) {
            if(b[i]==1) on++;
            cc[i] = on;
        }
        for(int i=0; i<m; i++) {
            ll l = vin() , r = vin();
            if(r-l<=1) {
                cout << "Yes\n";
                continue;
            }
            ll x = cc[l-1];
            ll y = cc[r-2];

            if(y-x==0) cout << "Yes\n";
            else if(y-x>=2) cout << "No\n";
            else {
                ll it = lower_bound(all(id),l)-id.begin() , pos = -1;
                if(it-1>0) pos = id[it-1];
                if(pos == -1) {
                    cout << "No\n"; continue;
                }
                ll itup = lower_bound(all(up),l)-up.begin();
                ll itdown = lower_bound(all(down),pos)-down.begin();
                if(itdown==down.size()) {
                    cout << "Yes\n";
                }
                else if(down[itdown]>=up[itup]) {
                    cout << "Yes\n";
                }
                else cout << "No\n";
            }
        }
        return;
}
int main() 
{
        FastIO;
        solve();
        return 0;
}