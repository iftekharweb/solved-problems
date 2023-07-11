/*
                بِسْمِ ٱللَّٰهِ ٱلرَّحْمَٰنِ ٱلرَّحِيمِ                
                Iftekhar Md. Shishir
                Dept. of Information and Communication Engineering
                University of Rajshahi
*/

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

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
const long long MOD= 1000000007;

using namespace std;
using namespace __gnu_pbds;
template<class T>using indexed_set=tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>;

inline ll vin() {ll x;cin >> x;return x;}
ll POW(ll a, ll b) {ll res = 1;while(b){if(b%2)res=(res*a)%MOD;a = (a*a)%MOD; b/=2;}return res;}
vector<ll> DIGITS(ll n){vector<ll>a;while (n)a.push_back(n%10),n/=10;return a;}

ll solve()
{
        ll n = vin(), k = vin() , res = 0;
        ll l = 1  , r = n ;

        // 1,2,...,n-1,n
        while (l<=r) {
            ll mid = l+(r-l)/2;
            ll val = (mid*(mid+1))/2;
            if(val==k){
                return mid;
            }
            if(r==l) break;
            if(val<k) l = mid+1;
            if(val>k) r = mid-1;
        }
        if(r<n) {
            ll val = (r*(r-1))/2;
            if(val>=k) {
                return r-1;
            }
            val = (r*(r+1))/2;
            if(val>=k) {
                return r;
            }
            val = ((r+1)*(r+2))/2;
            if(val>=k) {
                return r+1;
            }
        }
        ll val = (r*(r+1))/2;
        if(val>=k) return r;

        // n-1,n-2,....,2,1
        ll store = k;
        res += r;
        k = k-val; 
        ll cal = ((n-1)*n)/2;
        l = 1;
        r = n-1;

        // 5 4 3 2 1
        while (l<=r) {
            ll mid = l+(r-l)/2;
            ll val = (mid*(mid+1))/2;
            if(cal-val==k) {
                return res+(n-1)-mid;
            }
            if(l==r) break;
            if(cal-val<k) r = mid-1;
            if(cal-val>k) l = mid+1;
        }
        if(val+(cal-((r+1)*(r+2))/2) >= store) {
            return res+(n-1)-r-1;
        }
        else if(val+(cal-(r*(r+1))/2) >= store){
            return res+(n-1)-r;
        }
        else if(val+(cal-(r*(r-1))/2) >= store){
            return res+(n-1)-r+1;
        }
        else {
            if(n==1) return n;
            else return 2*n-1;
        }
}
int main() 
{
        FastIO;
        TestCase {
            cout << solve() << endl;
            //solve();
        }
        return 0;
}