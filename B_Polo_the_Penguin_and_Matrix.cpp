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
#define TestCase   ll t;cin>>t;while(t--)
#define points(x)   fixed<<setprecision(x)
#define pr(x) cerr << #x << " = " << x << endl;
#define nl cout<< "\n";

const ld PI= 3.14159265358979323846264338327950288;  //2*acos(0.0);
const long long MOD= 1000000007;

using namespace std;
using namespace __gnu_pbds;
template<class T>using indexed_set=tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>;

inline ll vin() {ll x;cin >> x;return x;}

ll calculate(ll d[][101], ll n, ll m, ll x)
{
    ll sum = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            sum += (abs(x-d[i][j]));
        }
    }
    return sum;
}

ll solve()
{
        ll n , m, k,res = MOD;
        cin >> n >> m >> k;
        set<ll> b;
        ll a[n][m], d[n][101];
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                cin >> a[i][j];
                b.insert(a[i][j]%k);
                d[i][j] = a[i][j]/k;
            }
        }
        if(b.size()>1) return -1;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                res = min(res , calculate(d,n,m,d[i][j]));
            }
        }
        return res;
}
int main()
{
        FastIO;
        cout << solve() << endl;
        return 0;
}