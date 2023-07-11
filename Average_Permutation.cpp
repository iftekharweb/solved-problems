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


ll solve()
{
        ll n = vin();
        if(n==3) {
            cout << "1 2 3\n";
            return 0;
        }
        set<ll> st;
        for(int i=4; i<=n; i++) st.insert(i);
        vector<ll> a(n+1);
        a[1] = 3 , a[2] = 2 , a[3] = 1;
        for(int i=4; i<=n; i++) {
            bool fg = 0;
            for(auto x:st) {
                if((a[i-1]+a[i-2]+x)%3==1) {
                    fg = 1;
                    a[i] = x;
                    st.erase(st.find(x));
                    break;
                }
            }
            if(!fg) {
                for(auto x:st) {
                    if((a[i-1]+a[i-2]+x)%3==2) {
                        fg = 1;
                        a[i] = x;
                        st.erase(st.find(x));
                        break;
                    }
                }
            }
            if(!fg) {
                a[i] = *(st.begin());
                st.erase(st.begin());
            }
        }
        for(int i=1; i<=n; i++) cout << a[i] << " "; nl;
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