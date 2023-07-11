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

const long long MOD = 1e9+7 , N = 1000 , INF = INT_FAST64_MAX;

//          U   R  D  L
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
inline ll vin() {ll x;cin >> x;return x;}
ll POW(ll a, ll b) {ll res = 1;while(b){if(b%2)res=(res*a)%MOD;a = (a*a)%MOD; b/=2;}return res;}
vector<ll> DIGITS(ll n){vector<ll>a;while(n)a.push_back(n%10),n/=10;return a;}

ll Tree[4*(N+1)][4*(N+1)] , a[N+1][N+1];

ll QueryY(ll six , ll siy , ll ssy, ll sey , ll y1 , ll y2) {
        if(ssy == sey) {
            return Tree[six][siy];
        }
        else if(y1 <= ssy && sey <= y2) {
            return Tree[six][siy];
        }
        else {
            ll mid = (ssy+sey)/2;
            return QueryY(six , 2*siy + 0 , ssy, mid , y1, y2) + QueryY(six , 2*siy + 1 , mid+1, sey , y1, y2);
        }
}
ll QueryX(ll six, ll ssx, ll sex , ll x1 , ll x2 , ll y1, ll y2) {
        if(sex < x1 || x2 < ssx) return 0;
        if(ssx == sex) {
            return QueryY(six,1,1,N,y1,y2);
        } 
        else if(x1 <= ssx && sex <= x2) {
            return QueryY(six,1,1,N,y1,y2);
        } 
        else {
            ll mid = (ssx+sex) >> 1;
            return QueryX(2*six + 0,ssx, mid , x1 , x2, y1, y2) + QueryX(2*six + 1, mid+1, sex , x1 , x2, y1, y2);
        }
}

void BuildTreeY(ll six, ll ssx, ll sex, ll siy , ll ssy , ll sey) {
        if(ssy == sey) {
            if(ssx == sex) {
                Tree[six][siy] = a[ssx][ssy];
            } 
            else {
                Tree[six][siy] = Tree[2*six + 0][siy] + Tree[2*six + 1][siy];
            }
            return;
        }
        ll mid = (ssy+sey)/2;
        BuildTreeY(six, ssx, sex, 2*siy + 0, ssy , mid);
        BuildTreeY(six, ssx, sex, 2*siy + 1, mid+1 , sey);
        Tree[six][siy] = Tree[six][2*siy + 0] + Tree[six][2*siy + 1];
}
void BuildTreeX(ll six, ll ssx, ll sex) {
        if(ssx == sex) {
            BuildTreeY(six , ssx , sex, 1, 1 ,N);
            return;
        }
        ll mid = (ssx+sex)/2;
        BuildTreeX(2*six + 0, ssx , mid);
        BuildTreeX(2*six + 1,mid+1, sex);
        BuildTreeY(six , ssx , sex, 1, 1 ,N);
}

ll solve()
{
        int n = vin() , q = vin();
        for(int i=0; i<n; i++) {
            string str; cin >> str;
            for(int j=1; j<=n; j++) {
                if(str[j-1] == '*') a[i+1][j] = 1;
            }
        }
        BuildTreeX(1,1,N);
        while(q--) {
            ll hs = vin() , ws = vin() , hb = vin() , wb = vin();
            ll sum = QueryX(1,1,N,hs, hb, ws, wb);
            cout << sum << "\n";
        }
        return 0;
}
int main() 
{
        FastIO;
        solve();
        return 0;
}