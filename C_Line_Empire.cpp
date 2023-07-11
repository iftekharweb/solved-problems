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

/*
    # mathforces :
    Let there are 4 kingdoms ,
            C1 C2 C3 C4 
    From these C1 and C2 are already conquered and the capital is in C1
    
    Capital can be moved to C2 if : cost of conquering from C1 >= moving to C2 and conquering from C2
                b(C3-C1) + b(C4-C1) >= a(C2-C1) + b(C3-C2) + b(C4-C2)
            =>  b(C3-C1) + b(C4-C1) - b(C3-C2) - b(C4-C2) >= a(C2-C1)
            =>  b(C3-C1+C4-C1-C3+C2-C4+C2) >= a(C2-C1)
            =>  b(2*C2-2*C1) >= a(C2-C1)
            =>  2*b >= a

    This 2 is the number of unconquered kingdom(C3 & C4) when capital is in C1
    Hence, capital will move if: unconquered_kingdom * cost_of_conquering >= cost_of_moving_capital
*/


ll solve()
{
        ll n = vin() , cost = 0;
        ll a = vin() , b = vin();
        vector<ll> pnt(n);

        for(int i=0; i<n; i++) pnt[i] = vin();
        
        ll cap = 0;
        for(int i=0; i<n; i++) {
            cost += b*(pnt[i]-cap);
            if((n-i-1)*b>=a) {
                cost += a*(pnt[i]-cap);
                cap = pnt[i];
            }
        }
        return cost;
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