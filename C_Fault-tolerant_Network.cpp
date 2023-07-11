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



ll solve()
{
        ll n = vin();
        vector<ll> a(n) , b(n);
        for(int i=0; i<n; i++) a[i] = vin();
        for(int i=0; i<n; i++) b[i] = vin();

        if(n==1) return (ll)abs(a[0]-b[0]);
        if(n==2) {
                ll x = abs(a[0]-b[0])+abs(a[1]-b[1]);
                ll y = abs(a[0]-b[1])+abs(a[1]-b[0]);
                return min(x,y);
        }
        vector<ll> forMx;
        map<ll,ll> idx_a;
        ll mi1 = INF , mi2 = INF , mi3 = INF , mi4 = INF , idx1 = -1 , idx2 = -1;
        for(int i=0; i<n; i++) {
                if(abs(a[0]-b[i])<mi1) {
                        idx1 = i;
                        mi1 = abs(a[0]-b[i]);
                }
                if(abs(a[n-1]-b[i])<mi2) {
                        idx2 = i;
                        mi2 = abs(a[n-1]-b[i]);
                }
        }
        idx_a[idx1] = idx_a[idx2] = 1;
        if(idx_a[0]) mi3 = 0;
        if(idx_a[n-1]) mi4 = 0;

        for(int i=n-1; i>=0; i--) {
                if(!idx_a[0]) if(abs(b[0]-a[i])<mi3) mi3 = abs(b[0]-a[i]);
                if(!idx_a[n-1]) if(abs(b[n-1]-a[i])<mi4) mi4 = abs(b[n-1]-a[i]);
        }
        forMx.push_back(mi1+mi2+mi3+mi4);
        
        forMx.push_back(abs(a[0]-b[0]) + abs(a[n-1]-b[n-1]));
        forMx.push_back(abs(a[0]-b[n-1]) + abs(a[n-1]-b[0]));

        forMx.push_back(abs(a[0]-b[1])+abs(a[1]-b[0]) + abs(a[n-1]-b[n-2])+abs(a[n-2]-b[n-1]));
        forMx.push_back(abs(a[0]-b[0]) + abs(a[n-1]-b[n-2])+abs(a[n-2]-b[n-1]));
        forMx.push_back(abs(a[0]-b[1])+abs(a[1]-b[0]) + abs(a[n-1]-b[n-1]));

        mi1 = mi2 = mi3 = mi4 = INF;
        mi1 = abs(a[0]-b[0]);
        for(int i=0; i<n; i++) {
                mi2 = min(mi2,abs(a[n-1]-b[i]));
                mi3 = min(mi3,abs(b[n-1]-a[i]));
        }
        forMx.push_back(mi1+mi2+mi3);
        mi1 = mi2 = mi3 = mi4 = INF;
        mi1 = abs(a[n-1]-b[n-1]);
        for(int i=0; i<n; i++) {
                mi2 = min(mi2,abs(a[0]-b[i]));
                mi3 = min(mi3,abs(b[0]-a[i]));
        }
        forMx.push_back(mi1+mi2+mi3);

        mi1 = mi2 = mi3 = mi4 = INF;
        mi1 = abs(a[0]-b[n-1]);
        for(int i=0; i<n; i++) {
                mi2 = min(mi2,abs(a[n-1]-b[i]));
                mi3 = min(mi3,abs(b[0]-a[i]));
        }
        forMx.push_back(mi1+mi2+mi3);
        mi1 = mi2 = mi3 = mi4 = INF;
        mi1 = abs(a[n-1]-b[0]);
        for(int i=0; i<n; i++) {
                mi2 = min(mi2,abs(a[0]-b[i]));
                mi3 = min(mi3,abs(b[n-1]-a[i]));
        }
        forMx.push_back(mi1+mi2+mi3);
        sort(all(forMx));
        return forMx[0];
}
int main() 
{
        FastIO;
        TestCase {
            cout << solve() << "\n";
            // solve();
        }
        return 0;
}