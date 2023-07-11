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

void Change(vector<ll>&a , vector<ll> &tmp, ll &n) {
        for(int i=0; i<n; i++) tmp[i] = a[i];
}
bool Thik_Ache_Naki(vector<ll> &tmp, ll &n) {
        bool fg = 1;
        ll t = tmp[1]-tmp[0];
        for(int i=0; i<n-1; i++) {
            if(tmp[i+1]-tmp[i] != t) {
                fg = 0;
                break;
            }
        }
        return fg;
}

ll solve()
{
        ll n = vin();
        vector<ll> a(n), b;
        for(auto &x:a) x = vin();
        ll s = 0;
        if(n == 1 || n == 2) return 0;

        for(int i=0; i<n-1; i++) {
            s += a[i+1]-a[i];
            b.push_back(a[i+1]-a[i]);
        }
        bool fg = 0;
        for(int i=0; i<n-2; i++) {
            if(b[i] != b[i+1]) {
                fg = 1;
                break;
            }
        }
        if(!fg) return 0;
        if(s<0) {
            reverse(all(a));
            s *= (-1);
        }
        ll x = s/(n-1);
        ll y = x+1;
        
        vector<ll> tmp(all(a));
        ll mi = INF , ops = 0;
        fg = 0;
        // ---   1st element  +0
        for(int i=1; i<n; i++) {
            if(tmp[i]-tmp[i-1] > x) tmp[i]-- , ops++;
            else if(tmp[i]-tmp[i-1] < x) tmp[i]++, ops++;
        }
        fg = 0; if(Thik_Ache_Naki(tmp,n)) fg = 1;
        if(fg) mi = min(ops,mi);

        Change(a,tmp,n); ops = 0;
        for(int i=1; i<n; i++) {
            if(tmp[i]-tmp[i-1] > y) tmp[i]-- , ops++;
            else if(tmp[i]-tmp[i-1] < y) tmp[i]++, ops++;
        }
        fg = 0; if(Thik_Ache_Naki(tmp,n)) fg = 1;
        if(fg) mi = min(ops,mi);

        // ---   1st element  +1
        Change(a,tmp,n);
        ops = 1;
        tmp[0]++;
        for(int i=1; i<n; i++) {
            if(tmp[i]-tmp[i-1] > x) tmp[i]-- , ops++;
            else if(tmp[i]-tmp[i-1] < x) tmp[i]++, ops++;
        }
        fg = 0; if(Thik_Ache_Naki(tmp,n)) fg = 1;
        if(fg) mi = min(ops,mi);

        Change(a,tmp,n);
        ops = 1;
        tmp[0]++;
        for(int i=1; i<n; i++) {
            if(tmp[i]-tmp[i-1] > y) tmp[i]-- , ops++;
            else if(tmp[i]-tmp[i-1] < y) tmp[i]++, ops++;
        }
        fg = 0; if(Thik_Ache_Naki(tmp,n)) fg = 1;
        if(fg) mi = min(ops,mi);

        // ---   1st element  -1
        Change(a,tmp,n);
        ops = 1;
        tmp[0]--;
        for(int i=1; i<n; i++) {
            if(tmp[i]-tmp[i-1] > x) tmp[i]-- , ops++;
            else if(tmp[i]-tmp[i-1] < x) tmp[i]++, ops++;
        }
        fg = 0; if(Thik_Ache_Naki(tmp,n)) fg = 1;
        if(fg) mi = min(ops,mi);

        Change(a,tmp,n);
        ops = 1;
        tmp[0]--;
        for(int i=1; i<n; i++) {
            if(tmp[i]-tmp[i-1] > y) tmp[i]-- , ops++;
            else if(tmp[i]-tmp[i-1] < y) tmp[i]++, ops++;
        }
        fg = 0; if(Thik_Ache_Naki(tmp,n)) fg = 1;
        if(fg) mi = min(ops,mi);

        if(mi == INF) return -1;
        return mi;
}
int main() 
{
        FastIO;
        cout << solve() << "\n";
        return 0;
}