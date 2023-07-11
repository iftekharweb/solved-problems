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

ll Tree[4*N] , lazy[4*N] , a[N] , given[N];

void RangeUpdate(ll si , ll ss , ll se , ll li , ll ri , ll val) {
        // Is there any pending update? 
        if(lazy[si]) {
            ll dx = lazy[si];
            lazy[si] = 0;
            Tree[si] += dx*(se-ss+1);
            if(ss != se) {
                lazy[2*si] += dx;
                lazy[2*si+1] += dx;
            }
        }
        // Do the rest..
        if(li>se || ri<ss) return;
        if(li<=ss && ri>=se) {
            ll dx = val * (se-ss+1);
            Tree[si] += dx;
            if(ss != se) {
                lazy[2*si] += val;
                lazy[2*si+1] += val;
            }
            return;
        }
        ll mid = (ss+se)>>1;
        RangeUpdate(2*si, ss, mid , li , ri , val);
        RangeUpdate(2*si+1, mid+1 , se , li , ri , val);
        Tree[si] = Tree[2*si]+Tree[2*si+1];
        return;
}

ll Query(ll si , ll ss, ll se , ll li , ll ri) {
        // Is there any pending update? 
        if(lazy[si]) {
            ll dx = lazy[si];
            lazy[si] = 0;
            Tree[si] += dx*(se-ss+1);
            if(ss != se) {
                lazy[2*si] += dx;
                lazy[2*si+1] += dx;
            }
        }
        // Do the rest..
        if(li>se || ri<ss) return 0;
        if(li<=ss && ri>=se) {
            return Tree[si];
        }
        ll mid = (ss+se)>>1;
        return Query(2*si, ss , mid , li , ri) + Query(2*si+1, mid+1, se, li, ri);
}

void BuildTree(ll si , ll ss , ll se) {
        if(ss == se) {
            Tree[si] = a[ss];
            return;
        }
        ll mid = (ss+se)>>1;
        BuildTree(2*si, ss , mid);
        BuildTree(2*si+1, mid+1 , se);
        Tree[si] = Tree[2*si]+Tree[2*si+1];
        return;
}

ll solve()
{
        ll n = vin() , m = vin();
        ll si = 1 , ss = 1 , se = n;

        vector<ll> tmp;
        vector<pair<ll,ll> > QQQ;
        for(int i=1; i<=n; i++) {
            given[i] = vin();
            tmp.push_back(given[i]);
        }
        for(int i=1; i<=m; i++) {
            ll x = vin() , y = vin();
            QQQ.push_back({x,y});
            RangeUpdate(si, ss, se, x , y , 1LL);
        }
        vector<pair<ll,ll> > vp;
        for(int i=1; i<=n; i++) {
            ll x = Query(si, ss, se , i, i);
            //pr(x);
            vp.push_back({x,i});
        }
        sort(all(vp));
        sort(all(tmp));

        while(vp.size()) {
            a[vp.back().second] = tmp.back();
            vp.pop_back();
            tmp.pop_back();
        }

        //
        //for(auto x:vp) cout << x.first << " ";nl;
        //for(auto x:vp) cout << x.second << " ";nl;
        //for(int i=1; i<=n; i++) cout << a[i] << " "; nl;
        //

        for(int i=0; i<4*N; i++) lazy[i] = Tree[i] = 0;
        BuildTree(si,ss,se);
        ll ans = 0;
        for(auto x:QQQ) {
            ll get = Query(si, ss, se, x.first, x.second);
            ans += get;
            //pr(x.first); pr(x.second); pr(get);
        }
        return ans;
}
int main() 
{
        FastIO;
        cout << solve() << "\n";
        return 0;
}