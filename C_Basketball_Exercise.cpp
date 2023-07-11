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

vector<ll> a(100001) , b(100001);
vector<ll> dp(100005, 0);
ll mx = -MOD;

ll ami_sesh(ll id , ll n , ll i ,ll mx1 , ll mx2) {
        if(id) {
            if(i+1>n) return b[i];
            if(i+2>n) return b[i];
        
            return mx1 += ami_sesh(0,n,i+1,mx1, mx2);
            mx2 += ami_sesh(0,n,i+2,mx1, mx2);
                pr(mx1);
            //dp[i] = max(dp[i], ami_sesh(0,n,i+1)+b[i]);
            //dp[i] = max(dp[i], ami_sesh(0,n,i+2)+b[i]);
        }
        else {
            if(i+1>n) return a[i];
            if(i+2>n) return a[i];
            mx1 += ami_sesh(1,n,i+1,mx1, mx2);
            mx2 += ami_sesh(1,n,i+2,mx1, mx2);
            //dp[i] = max(dp[i], ami_sesh(1,n,i+1)+a[i]);
            //dp[i] = max(dp[i], ami_sesh(1,n,i+2)+a[i]);
        }
        dp[i] = max(mx1,mx2);
        return dp[i];
}

void solve()
{
        ll n = vin();
        for(int i=1; i<=n; i++) a[i] = vin();
        for(int i=1; i<=n; i++) b[i] = vin();
        ami_sesh(1,n,1 , 0 , 0);
        for(int i=1; i<=n; i++) cout << dp[i] <<  " "; nl;
        // start with A

        return ;
}
int main() 
{
        FastIO;
        solve();
        return 0;
}