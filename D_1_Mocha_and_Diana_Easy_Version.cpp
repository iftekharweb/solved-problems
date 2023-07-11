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


ll mocha[1001] , diana[1001] , sm[1001] , sd[1001];

void make(ll v) {
        mocha[v] = diana[v] = v;
        sm[v] = sd[v] = 1;
}
ll find(ll v, ll id) {
        if(id) {
            if(v == mocha[v]) return v;
            return mocha[v] = find(mocha[v],1LL);
        }
        else {
            if(v == diana[v]) return v;
            return diana[v] = find(diana[v],0LL);
        }
}
void Union(ll a , ll b , ll id) {
        if(id) {
            a = find(a,1LL);
            b = find(b,1LL);
            if(a!=b) {
                if(sm[a]<sm[b]) swap(a,b);
                mocha[b] = a;
                sm[a] += sm[b];
            }
        }
        else {
            a = find(a,0LL);
            b = find(b,0LL);
            if(a!=b) {
                if(sd[a]<sd[b]) swap(a,b);
                diana[b] = a;
                sd[a] += sd[b];
            }
        }
}

vector< pair<ll,ll> > solve()
{
        ll n , m1 , m2;
        cin >> n >> m1 >> m2;
        for(int i=1; i<=n; i++) make(i);
        while (m1--) {
            ll u , v;
            cin >> u >> v;
            Union(u,v,1LL);
        }
        while (m2--) {
            ll u , v;
            cin >> u >> v;
            Union(u,v,0LL);
        }

        vector<pair<ll,ll> > res;

        for(int i=1; i<=n; i++) {
            for(int j=i+1; j<=n; j++) {
                ll a = find(i,1LL);
                ll b = find(j,1LL);
                if(a==b) continue;
                a = find(i,0LL);
                b = find(j,0LL);
                if(a==b) continue;
                // pr(a); pr(b); pr(i); pr(j);
                Union(i,j,1LL);
                Union(i,j,0LL);
                res.push_back({i,j});
            }
        }
        // ll cnt = 0;
        // for(int i=1; i<=n; i++) {
        //     if(find(i,0LL) == i) cnt++;
        // }
        // cout << "= " << cnt << endl;
        return res;
}
int main() 
{
        FastIO;
        vector<pair<ll,ll> > res = solve();
        ll n = res.size();
        cout << n << endl;
        if(n) for(int i=0; i<n; i++) {
            cout << res[i].first << " " << res[i].second << endl;
        }
        return 0;
}