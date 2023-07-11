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
const long long MOD = 1e9+7 , N = 1e5+10;
const long long INF = INT_FAST64_MAX;

using namespace std;
using namespace __gnu_pbds;
template<class T>using indexed_set=tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>;

//          U   R  D  L
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

inline ll vin() {ll x;cin >> x;return x;}
ll POW(ll a, ll b) {ll res = 1;while(b){if(b%2)res=(res*a)%MOD;a = (a*a)%MOD; b/=2;}return res;}
vector<ll> DIGITS(ll n){vector<ll>a;while (n)a.push_back(n%10),n/=10;return a;}

vector<ll> city , tower;
ll n , m;

bool canCover(ll h) {
        
        ll cnt = 0;
        // SIDE BANDS
        if(city[0]<tower[0]) {
            if(tower[0]-h>city[0]) return false;
        }
        if(city[n-1]>tower[m-1]) {
            if(tower[m-1]+h<city[n-1]) return false;
        }
        for(int i=0; i<m-1; i++)
        {
            if(tower[i+1]-tower[i]-1 <= 2*h) continue;

            ll it = lower_bound(all(city),tower[i]) - city.begin();
            if(it==city.size()) continue;
            for(int j=it; city[j]<tower[i+1]; j++) {
                if(city[j]-tower[i]>h && tower[i+1]-city[j]>h) return false;
            }
        }   
        return true;
}

ll solve()
{
        n = vin() , m = vin();
        for(int i=0; i<n; i++) {
            ll x = vin();
            city.push_back(x);
        }
        for(int i=0; i<m; i++) {
            ll x = vin();
            tower.push_back(x);
        }

        sort(all(city));
        sort(all(tower));

        ll mn = min(city[0],tower[0]);
        ll x = 1-mn;
        if(x>0) {
            for(int i=0; i<n; i++) city[i] += x;
            for(int i=0; i<m; i++) tower[i] += x;
        }

        //printVector(city);
        //printVector(tower);

        ll lo = 0 , hi = max(city[n-1],tower[m-1]) , mid;
        //pr(lo); pr(hi);
        while(hi-lo>1) {
            mid = (hi+lo)/2;
            if(canCover(mid)) {
                hi = mid;
            } else {
                lo = mid+1;
            }
        }
        if(canCover(lo)) {
            return lo;
        } else if(canCover(hi)) {
            return hi;
        }
}
int main() 
{
        FastIO;
        cout << solve() << "\n";
        return 0;
}