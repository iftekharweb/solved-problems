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

/*
        10 20 30
        a b c

        a+b = 30    .....(i)
        b+c = 50    .....(ii)
        a+c = 40    .....(iii)

    now,
        b = (30-a);

    putting value o b in (ii),
        (30-a)+c = 50;
        => a-c = (-1)*(50-30);   .....(iv)

    (iii)+(iv),
        2a = 20;
        => a = 10;
*/

ll solve()
{
        ll n = vin();
        vector<ll> a(n+1) , res;

        for(int i=1; i<n; i++) {
            cout << "? " << i << " " << i+1 << "\n";
            fflush(stdout);
            a[i] = vin(); 
        }
        cout << "? " << 1 << " " << 3 << "\n";
        fflush(stdout);
        a[n] = vin();

        ll aa = a[1];
        ll bb = a[2];
        ll cc = a[n];
        ll x = aa-bb;
        x += cc;
        x/=2;

        res.push_back(x);
        for(int i=1; i<n; i++) {
            x = a[i]-x;
            res.push_back(x);
        }
        cout << "! ";
        fflush(stdout);
        for(int i=0; i<n; i++) {
            cout << res[i] << " ";
            fflush(stdout);
        }
        cout << "\n";
        fflush(stdout);
        return 0;
}
int main() 
{
        FastIO;
        solve();
        return 0;
}