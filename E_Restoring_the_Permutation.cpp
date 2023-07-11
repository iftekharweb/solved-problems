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
        vector<ll> a(n) , lexiMin(n+1,0) , lexiMax(n+1,0);
        set<ll> st;
        for(int i=0; i<n; i++) {
            st.insert(i+1);
            a[i] = vin();
        }
        st.erase(st.find(a[0]));
        lexiMin[0] = lexiMax[0] = a[0];
        for(int i=0; i<n-1; i++) {
            if(a[i]!=a[i+1]) {
                lexiMin[i+1] = lexiMax[i+1] = a[i+1];
                st.erase(st.find(a[i+1]));
            }
        }
        ll cnt = 0;
        vector<pair<ll,ll> > keep;
        vector<ll> store[n+10] , vi(all(st));
        for(int i=0; i<n; i++) {
            if(lexiMin[i]) {
                keep.push_back({i,cnt});
                cnt = 0;
            }
            else cnt++;
            if(i==n-1) {
                keep.push_back({i+1,cnt});
            }
        }
        ll k = 0;
        for(auto x:keep) {
            for(int i=0; i<x.second; i++ , k++) {
                store[x.first].push_back(vi[k]);
            }
            sort(all(store[x.first]));
        }
        for(auto x:keep) {
            for(auto d:store[x.first]) cout << d << " ";
            if(x.first!=n) cout << a[x.first] << " ";
            reverse(all(store[x.first]));
        }
        nl;
        for(int i=0; i<keep.size()-1; i++) {
            if(keep[i].first!=n) cout << a[keep[i].first] << " ";
            if(!st.size()) continue;
            auto it = st.upper_bound(a[keep[i].first]-1);
            it--;
            cnt = keep[i+1].second;
            while(cnt--) {
                cout << *(it) << " ";
                auto tmp = it;
                it--;
                st.erase(tmp);
            }
        }
        nl;
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