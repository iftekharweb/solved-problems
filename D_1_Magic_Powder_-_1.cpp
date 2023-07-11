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
const long long MOD = 1e9+7 , N = 1e5+5;
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

vector<ll> need(N) , have(N) , magic(N);
ll n , k;

bool canWeMake(ll h) {
        for(int i=0; i<n; i++) {
            if(h*need[i]>have[i]) return false;
        }
        return true;
}

bool isPossible(ll h) {
        ll powder = k;
        for(int i=0; i<n; i++) {
            if(h*need[i]>have[i]) {
                ll x = h*need[i]-have[i];
                if(powder>=x) {
                    powder -= x;
                }
                else return false;
            }
        }
        return true;
}

ll solve()
{
        n = vin() , k = vin();
        ll res = 0;
        for(int i=0; i<n; i++) need[i] = vin();
        for(int i=0; i<n; i++) have[i] = vin();

        // BEFORE APPLING MAGIC
        ll lo = 1 , hi = 1e9 , mid;
        while(hi-lo>1) {
            mid = lo+(hi-lo)/2;
            if(canWeMake(mid)) {
                lo = mid;
            }else{
                hi = mid-1;
            }
        }
        if(canWeMake(hi)) {
            res += hi;
            for(int i=0; i<n; i++) {
                have[i] -= hi*need[i];
            }
        } else if(canWeMake(lo)) {
            res += lo;
            for(int i=0; i<n; i++) {
                have[i] -= lo*need[i];
            }
        }

        // APPLY MAGIC
        lo = 1 , hi = 1e9;
        while(hi-lo>1) {
            mid = lo+(hi-lo)/2;
            if(isPossible(mid)) {
                lo = mid;
            }else{
                hi = mid-1;
            }
        }
        if(isPossible(hi)) {
            res += hi;
        } else if(isPossible(lo)) {
            res += lo;
        }
        return res;
}

int main() 
{
        FastIO;
        cout << solve() << "\n";
        return 0;
}