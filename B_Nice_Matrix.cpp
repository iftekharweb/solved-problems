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
        ll n = vin() , m = vin() , res = 0;
        vector<vector<ll> > vv;

        for(int i=0; i<n; i++) {
            vector<ll> p(m);
            for(int j=0; j<m; j++) p[j] = vin();
            vv.push_back(p);
        }
        if(n==1 && n==m) return res;

        for(int i=0; i<n; i++) {
            for(int j=0; j<m ; j++)
            {
                ll p = n-i-1 , q = m-j-1;
                if(i==p && j == q) continue;
                else if(i == p) {
                    res += abs(vv[i][j]-vv[i][q]);
                    vv[i][j] = vv[i][q];
                }
                else if(j == q) {
                    res += abs(vv[i][j]-vv[p][j]);
                    vv[i][j] = vv[p][j];
                }
                else {
                    vector<ll> ga = {vv[i][j] , vv[i][q] , vv[p][j] , vv[p][q]};
                    sort(all(ga));
                    ll mi = ga[1]; // avg is the ga[1]
                    res += abs(mi-vv[i][j]) + abs(mi-vv[i][q]) + abs(mi-vv[p][j]) + abs(mi-vv[p][q]);
                    vv[i][j] = vv[i][q] = vv[p][j] = vv[p][q] = mi;
                }
            }
        }
        return res;
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