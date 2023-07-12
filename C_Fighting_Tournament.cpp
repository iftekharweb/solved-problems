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

ll w = 0;
ll solve()
{
        ll n = vin(), q = vin();
        vector<ll> a(n), idx(n+1),win_pos(n+1,-1), b(n);
        for(int i=0; i<n; i++) {
            a[i] = vin();
            idx[a[i]] = i;
        }
        ll mx = max(a[0],a[1]);
        win_pos[mx] = 0;
        b[0] = mx;
        for(int i=0; i<n-1; i++) {
            if(mx<a[i+1]) {
                win_pos[a[i+1]] = i;
                mx = a[i+1];
            }
            b[i] = mx;
        }
        b[n-1] = mx;
        while(q--) {
            ll id = vin() , k = vin();
            id = a[id-1];
            if(win_pos[id] == -1) {
                cout << 0 << endl;
                continue;
            }
            else {
                if(win_pos[id]>k-1) {
                    cout << 0 << endl;
                    continue;
                }
                ll lo = win_pos[id], hi = n-1, mid , ans = 0;
                while(hi-lo>1) {
                    mid = (hi+lo)>>1;
                    if(b[mid]==id) lo = mid;
                    else hi = mid-1;
                }
                if(b[hi]!=id) hi = lo;
                if(hi>k-1) {
                    ans += (k-1)-win_pos[id]+1;
                }
                else {
                    ans += hi-win_pos[id]+1;
                    if(id == n) {
                        ll kk = k-(n-1)-1;
                        //pr(kk); pr(ans); pr(hi); pr(win_pos[id]); pr(id);
                        ans += (n-1)*(kk/(n-1));
                        ans += (kk%(n-1));
                    }
                }
                cout << ans << endl;
            }
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