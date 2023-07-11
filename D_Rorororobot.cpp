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

const long long MOD = 1e9+7 , N = 2e5+10 , INF = INT_FAST64_MAX;

//          U   R  D  L
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
inline ll vin() {ll x;cin >> x;return x;}
ll POW(ll a, ll b) {ll res = 1;while(b){if(b%2)res=(res*a)%MOD;a = (a*a)%MOD; b/=2;}return res;}
vector<ll> DIGITS(ll n){vector<ll>a;while(n)a.push_back(n%10),n/=10;return a;}

ll maxArr[4*N], a[N];

ll Query(ll si, ll ss, ll se, ll li, ll ri)
{
        if(li>se || ri<ss) {
            return (-1)*MOD;
        }
        if(ss>=li && se<=ri) {
            return maxArr[si];
        }
        ll mid = (ss+se)>>1;
        ll l = Query(2*si, ss, mid, li, ri);
        ll r = Query(2*si+1, mid+1, se, li, ri);
        return max(l,r);
}

void BuildTree(ll si, ll ss, ll se) {
        if(ss==se){
            maxArr[si] = a[ss];
            return;
        }
        ll mid = ss+(se-ss)/2;
        BuildTree(2*si, ss, mid);
        BuildTree(2*si+1, mid+1, se);
        maxArr[si]= max(maxArr[2*si], maxArr[2*si+1]);
}

ll solve()
{
        ll n = vin() , m = vin();
        ll si = 1, ss = 1, se = m;
        for(int i=1; i<=m; i++) {
            a[i] = vin();
        }
        BuildTree(si, ss, se);
        ll q = vin();
        for(int i=0; i<q; i++) {
            ll x = vin() , y = vin() , xx = vin() , yy = vin(), k = vin();
            if(y>yy) {
                swap(x,xx);
                swap(y,yy);
            }
            if(x<a[y] || xx<a[yy] || abs(xx-x)%k || abs(yy-y)%k) {
                cout << "NO\n"; continue;
            }
            ll mxInRange = Query(si, ss, se, y, yy);
            //pr(mxInRange);
            ll h = (n-x)%k;
            h = n-h;
            if(mxInRange>=h) cout << "NO\n";
            else cout << "YES\n";

        }
        return 0;
}
int main() 
{
        FastIO;
        solve();
        return 0;
}