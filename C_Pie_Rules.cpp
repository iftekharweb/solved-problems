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


pair<ll,ll> solve()
{
        ll n = vin();
        vector<ll> a(n);
        for(int i=0; i<n; i++) {
            a[i] = vin();
        }
        sort(all(a));
        ll alice = 0 , bob = 0;
        for(int i=n-1 , j=0; i>=0; i-- , j++) {
            if(a.size()==3) {
                if(j%2) {
                    if(a[2]>=a[0]+a[1]) alice += a[2] , bob += a[0]+a[1];
                    else alice += a[1]+a[0] , bob += a[2];
                } else {
                    if(a[2]>=a[0]+a[1]) bob += a[2] , alice += a[0]+a[1];
                    else bob += a[1]+a[0] , alice += a[2];
                }
                break;
            }
            if(j%2) {
                alice += a.back();
                a.pop_back();
            }
            else {
                bob += a.back();
                a.pop_back();
            }
        }
        printVector(a);
        return {alice , bob};
}
int main() 
{
        FastIO;
        pair<ll,ll> p = solve();
        cout << p.first << " " << p.second << "\n";
        return 0;
}