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
const long long MOD = 1e9+7 , N = 1e5*2;
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

ll n , p , pos;

ll calculate(ll mid , ll x) {
        ll sum = 0;
        ll y = 0;
        if(mid>x) {
            y = mid-x;
        }
        //pr(y);

        //pr(mid); pr(x);
        sum += (mid*(mid+1))/2 - (y*(y+1))/2;
        return sum;
}

bool check(ll mid) {
        ll left = pos-1;
        ll right = n-pos;
        ll sum = n;
        mid--;
        sum += mid + calculate(mid-1, left) + calculate(mid-1,right);
        //pr(sum);
        return sum<=p;
}

ll solve()
{
        n = vin() , p = vin() , pos = vin();
        ll lo = 1 , hi = p , mid;
        while(hi-lo>1) {
            mid = (hi + lo)/2;
            //pr(mid);
            if(check(mid)) {
                //pr(lo);
                lo = mid;
            } else {
                hi = mid-1;
            }
        }
        //cout << hi << " " << lo << endl;
        if(check(hi)) {
            return hi;
        }else if(check(lo)) {
            return lo;
        } else {
            return 0;
        }
}
int main() 
{
        FastIO;
        cout << solve() << "\n";
        return 0;
}