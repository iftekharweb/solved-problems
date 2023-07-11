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
const long long MOD = 1000000007;
const long long INF = INT_FAST64_MAX;

using namespace std;
using namespace __gnu_pbds;
template<class T>using indexed_set=tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>;

inline ll vin() {ll x;cin >> x;return x;}
ll POW(ll a, ll b) {ll res = 1;while(b){if(b%2)res=(res*a)%MOD;a = (a*a)%MOD; b/=2;}return res;}
vector<ll> DIGITS(ll n){vector<ll>a;while (n)a.push_back(n%10),n/=10;return a;}


void solve()
{
        ll n = vin();
        vector<ll> a(n);
        vector<ll> cnt(200001, 0);
        vector<tuple<ll,ll,ll> > vt;

        for(int i=0; i<n; i++) {
            a[i] = vin();
            cnt[a[i]]++;
        }

        if(n==1) {
            cout << 0 << endl;
            return;
        }
        if(n==2) {
            if(a[0]==a[1]) {
                cout << 0 << endl;
            }
            else if(a[0]<a[1]) {
                cout << 1 << endl;
                cout << 1 << " " << 1 << " " << 2 << endl;
            }
            else {
                cout << 1 << endl;
                cout << 2 << " " << 1 << " " << 2 << endl;
            }
            return;
        }

        ll to_equal = -1 , mx = -1;
        for(int i=1; i<n-1; i++) {
            ll x = a[i];
            //pr(cnt[x]);
            if(cnt[x]>=mx) {
                mx = cnt[x];
                to_equal = i;
            }
        }
        //pr(to_equal);
        for(int i=to_equal; i>0; i--) {
            if(a[i]!=a[i-1]) {
                if(a[i-1]<a[i]) {
                    a[i-1] = a[i];
                    vt.push_back({1,i,i+1});
                }
                else{
                    a[i-1] = a[i];
                    vt.push_back({2,i,i+1});
                }
            }
        }
        //reverse(all(vt));
        for(int i=to_equal; i<n-1; i++) {
            if(a[i]!=a[i+1]) {
                if(a[i+1]>a[i]) {
                    a[i+1] = a[i];
                    vt.push_back({2,i+2, i+1});
                }
                else {
                    a[i+1] = a[i];
                    vt.push_back({1,i+2, i+1});
                }
            }
        }
        ll res = vt.size();
        cout << res; nl;
        for(int i=0; i<res; i++) {
            cout << get<0>(vt[i]) << " " << get<1>(vt[i]) << " " << get<2>(vt[i]) << endl;
        }
        return ;
}
int main() 
{
        FastIO;
        solve();
        return 0;
}