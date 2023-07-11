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

string a;
ll b , s, c , cost_b, cost_s , cost_c , rubles;
unordered_map<char,ll> needed;

ll Cook_before_buying() {
        ll x = INF, y = INF, z = INF;
        if(needed['B']) {
            if(b>=needed['B']) x = b/needed['B'];
            else x = 0;
        }
        if(needed['S']) {
            if(s>=needed['S']) y = s/needed['S'];
            else y = 0;
        }
        if(needed['C']) {
            if(c>=needed['C']) z = c/needed['C'];
            else z = 0;
        }
        //pr(x); pr(y); pr(z); pr(needed['B']); pr(needed['S']); pr(needed['C']);
        x = min(x,min(y,z));
        b -= x*needed['B'];
        s -= x*needed['S'];
        c -= x*needed['C'];
        //pr(x);
        return x;
}

bool Is_possible(ll n) {
        ll need_b = max(n*needed['B']-b,0LL);
        ll need_s = max(n*needed['S']-s,0LL);
        ll need_c = max(n*needed['C']-c,0LL);
        if(cost_b*need_b + cost_s*need_s + cost_c*need_c <= rubles) return true;
        return false;
}

ll solve()
{
        cin >> a;
        cin >> b >> s >> c;
        cin >> cost_b >> cost_s >> cost_c;
        cin >> rubles;
        for(int i=0; i<a.size(); i++) needed[a[i]]++;

        ll hamburgers = Cook_before_buying();
        ll lo = 0 , hi = 1e12 , mid;
        while(hi-lo>1) {
            mid = (hi+lo)>>1;
            if(Is_possible(mid)) {
                lo = mid;
            }
            else hi = mid-1;
        }
        if(Is_possible(hi)) {
            return hamburgers+hi;
        }
        return hamburgers+lo;
}
int main() 
{
        FastIO;
        cout << solve() << "\n";
        return 0;
}