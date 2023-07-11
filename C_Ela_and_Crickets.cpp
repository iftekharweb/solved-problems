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


string solve()
{
        ll a , b , c , d , e , f, nn;
        cin >> nn;
        cin >> a >> b >> c >> d >> e >> f;
        ll p , q;
        cin >> p >> q;
        map<pair<ll,ll>,ll> mm;
        mm[{a,b}] = 1;
        mm[{c,d}] = 1;
        mm[{e,f}] = 1;
        if(mm[{1,1}] && mm[{1,2}] && mm[{2,1}]) {
            if(p == 1 || q == 1) return "YES";
            return "NO";
        }
        if(mm[{nn,nn}] && mm[{nn,nn-1}] && mm[{nn-1,nn}]) {
            if(p == nn || q == nn) return "YES";
            return "NO";
        }
        if(mm[{nn,1}] && mm[{nn,2}] && mm[{nn-1,1}]) {
            if(p == nn || q == 1) return "YES";
            return "NO";
        }
        if(mm[{1,nn}] && mm[{1,nn-1}] && mm[{2,nn}]) {
            if(p == 1 || q == nn) return "YES";
            return "NO";
        }
        
        ll n = 0 , m = 0;
        if(a == c || a == e) n = a ;
        if(c == a || c == e) n = c;
        if(e == a || e == c) n = e;

        if(b == d || b == f) m = b;
        if(d == b || d == f) m = d;
        if(f == b || f == d) m = f;

        n %= 2 , m %= 2 , p %= 2, q %=2 ;

        if(n!=p && m!=q) return "NO";
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