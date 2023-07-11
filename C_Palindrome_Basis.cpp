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
const long long MOD = 1e4*4+2;
const long long INF = INT_FAST64_MAX;

using namespace std;
using namespace __gnu_pbds;
template<class T>using indexed_set=tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>;

inline ll vin() {ll x;cin >> x;return x;}
ll POW(ll a, ll b) {ll res = 1;while(b){if(b%2)res=(res*a)%MOD;a = (a*a)%MOD; b/=2;}return res;}
vector<ll> DIGITS(ll n){vector<ll>a;while (n)a.push_back(n%10),n/=10;return a;}

vector<ll> pals;

void create_pal() {
        for(int i=1; i<40001; i++) {
                vector<ll> d = DIGITS(i);
                bool fg = 0;
                for(int j=0 , k = d.size()-1; j<d.size()/2; j++, k--) {
                        if(d[j]!=d[k]) {
                                fg = 1;
                                break;
                        }
                }
                if(!fg) pals.push_back(i);
        }
}

vector<ll> tmp(40001,-1);
vector<vector<ll> > dp(498,tmp);

ll WAYS(ll n,ll val) {
        if(val==1) return 1;
        if(n<0 || val<0) return 0;
        if(dp[n][val]!=-1) return dp[n][val];

        return dp[n][val] = WAYS(n,val-pals[n-1])+WAYS(n-1,val);
}

ll solve()
{
        ll val = vin();
        return dp[10][val];
}
int main() 
{
        FastIO;
        create_pal();
        ll n = pals.size();
        ll kam_nai = WAYS(n,40000);
        TestCase {
            cout << solve() << endl;
            //solve();
        }
        return 0;
}