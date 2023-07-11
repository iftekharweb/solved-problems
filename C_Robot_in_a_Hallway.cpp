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

bool isPossible(ll p , vector<vector<ll> >&a , ll n) {
        ll x = (n<<1)-1;
        x = p-x;
        int cng = 0 , clc = -1 , antiClc = -1 , cnt = 0;
        for(int i=0; i<n; i++) {
            if(!cng) {
                if(i+1<n) {
                    if(cnt+1 > a[1][i]-x && cnt+2 > a[1][i+1]-x) cnt += 2;
                    else if(cnt+1 > a[0][i+1]-x) {
                        cnt++;
                        clc = i+1;
                        break;
                    }
                    else return false;
                }
                else {
                    if(cnt+1 > a[1][i]-x) cnt++;
                    else return false;
                }
            }
            else {
                if(i+1<n) {
                    if(cnt+1 > a[0][i]-x && cnt+2 > a[0][i+1]-x) cnt += 2;
                    else if(cnt+1 > a[1][i+1]-x) {
                        cnt++;
                        antiClc = i+1;
                        break;
                    }
                    else return false;
                }
                else {
                    if(cnt+1 > a[0][i]-x) cnt++;
                    else return false;
                }
            }
            cng ^= 1;
        }
        if(clc != -1) {
            bool dhukse = 0;
            for(int i=clc+1; i<n; i++) {
                if(cnt+1 > a[0][i]-x) cnt++;
                else return false;
            }
            clc--;
            for(int i=n-1; i>=clc; i--) {
                if(cnt+1 > a[1][i]-x) cnt++;
                else return false;
            }
        }
        else if(antiClc != -1) {
            for(int i=antiClc+1; i<n; i++) {
                if(cnt+1 > a[1][i]-x) cnt++;
                else return false;
            }
            antiClc--;
            for(int i=n-1; i>=antiClc; i--) {
                if(cnt+1 > a[0][i]-x) cnt++;
                else return false;
            }
        }
        return true;
}

ll solve()
{
        ll n = vin();
        w++;
        vector<vector<ll> > a(2,vector<ll>(n));
        ll mx = 0;
        for(int i=0; i<2; i++) {
            for(int j=0; j<n; j++) {
                a[i][j] = vin();
                mx = max(mx,a[i][j]);
            }
        }
        ll lo = (n<<1)-1 , hi = mx+lo, mid;
        while(hi-lo > 1) {
            mid = (hi + lo) >> 1;
            if(isPossible(mid,a,n)) hi = mid;
            else lo = mid+1;
        }
        if(isPossible(lo,a,n)) return lo;
        return hi;
}
int main() 
{
        FastIO;
        TestCase {
             cout << solve() << "\n";
        }
        return 0;
}