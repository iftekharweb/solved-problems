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



ll arr[N] , TreeMin[4*N] , TreeMax[4*N];

ll QueryForMax(ll si, ll ss, ll se, ll li, ll ri) {
        if(li>se || ri<ss) {
            return -INF;
        }
        if(ss>=li && se<=ri) {
            return TreeMax[si];
        }
        ll mid = (ss+se)>>1;
        ll l , r;
        l = QueryForMax(2*si, ss, mid, li, ri);
        r = QueryForMax(2*si+1, mid+1, se, li, ri);
        return max(l,r);
}

ll QueryForMin(ll si, ll ss, ll se, ll li, ll ri) {
        if(li>se || ri<ss) {
            return INF;
        }
        if(ss>=li && se<=ri) {
            return TreeMin[si];
        }
        ll mid = (ss+se)>>1;
        ll l , r;
        l = QueryForMin(2*si, ss, mid, li, ri);
        r = QueryForMin(2*si+1, mid+1, se, li, ri);
        return min(l,r);
}
 
void BuildTree(ll si, ll ss, ll se) {
        if(ss==se){
            TreeMin[si]= TreeMax[si] = arr[ss];
            return;
        }
        ll mid = ss+(se-ss)/2;
        BuildTree(2*si, ss, mid);
        BuildTree(2*si+1, mid+1, se);
        TreeMin[si] = min(TreeMin[2*si], TreeMin[2*si+1]);
        TreeMax[si] = max(TreeMax[2*si], TreeMax[2*si+1]);
}

ll solve()
{
        ll n = vin() , q = vin();
        string a; cin >> a;
        ll x = 0;
        for(int i=1; i<=n; i++) {
            if(a[i-1] == '-') x--;
            else x++;
            arr[i] = x;
        }
        BuildTree(0,0,n);
        while(q--) {
            ll l = vin() , r = vin() , Unique, mi , mx;
            mi = QueryForMax(0,0,n,0,l-1);
            mx = max(QueryForMin(0,0,n,0,l-1),0LL);
            if(l==1) mi = 0 , mx = 0;
            //pr(mx); pr(mi);
            Unique = mx-mi+1; 
            if(!(mi<=0 && mx>=0)) Unique++;
            if(r==n) {
                cout << Unique << "\n";
                continue;
            }
            ll Value = arr[l-1];
            if(a[r]=='-') Value--;
            else Value++;
            mx = max(mx, QueryForMax(0,0,n,r+1,n)-arr[r+1]+Value);
            mi = min(mi, QueryForMin(0,0,n,r+1,n)-arr[r+1]+Value);
            Unique = mx-mi+1; 
            cout << Unique << "\n";
        }
        return 0;
}
int main() 
{
        FastIO;
        TestCase {
            // cout << solve() << "\n";
            solve();
        }
        return 0;
}