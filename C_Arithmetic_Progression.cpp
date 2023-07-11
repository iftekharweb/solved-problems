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
        vector<ll> a(n);
        set<ll> adj_diff , st;
        for(int i=0; i<n; i++) a[i] = vin();
        sort(all(a));

        if(0)
        {
            IMPOSSIBLE : cout << -1 << endl; return 0;
            ZERO       : cout << 0 << endl; return 0;
            PRINT_SET  : cout << st.size() << endl;
                         for(auto x:st) cout << x << " "; nl;
                         return 0;
        }

        if(n==1) goto IMPOSSIBLE;

        for(int i=1; i<n; i++) {
            adj_diff.insert(a[i]-a[i-1]);
        }
        if(adj_diff.size()>2) goto ZERO;

        if(adj_diff.size()==2) {
            ll it = *(++adj_diff.begin());
            if((it&1) || (it>>1) != *(adj_diff.begin())) goto ZERO;
            else {
                bool fg = 0;
                for(int i=1; i<n; i++) {
                    if(a[i]-a[i-1]==it) {
                        if(fg) goto ZERO;
                        st.insert(a[i-1]+(it>>1));
                        fg = 1;
                    }
                }
                goto PRINT_SET;
                return 0;
            }
        }
        ll it = *(adj_diff.begin());
        if(n==2) {
            if(!(it&1)) {
                st.insert(a[0]-it);
                st.insert(a[0]+(it>>1));
                st.insert(a[1]+it);
                goto PRINT_SET;
                return 0;
            }
        }
        st.insert(a[0]-it);
        st.insert(a[n-1]+it);
        goto PRINT_SET;
        return 0;
}
int main() 
{
        FastIO;
        solve();
        return 0;
}