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

struct Node {
    ll element;
    ll minElement;
};

Node Tree[4*N];
int  lazy[4*N] , a[N];

void RangeUpdate(ll si , ll ss , ll se , ll li , ll ri , ll val) {
        if(lazy[si]) {
            ll dx = lazy[si];
            lazy[si] = 0;
            Tree[si].minElement += dx;
            if(ss != se) {
                lazy[2*si + 0] += dx;
                lazy[2*si + 1] += dx;
            }
        }
        if(li>se || ri<ss) return;
        if(li<=ss && ri>=se) {
            Tree[si].minElement += val;
            if(ss != se) {
                lazy[2*si + 0] += val;
                lazy[2*si + 1] += val;
            }
            return;
        }
        ll mid = (ss + se) >> 1;
        RangeUpdate(2*si + 0, ss, mid , li , ri , val);
        RangeUpdate(2*si + 1, mid+1 , se , li , ri , val);
        Tree[si].minElement = min(Tree[2*si + 0].minElement,Tree[2*si + 1].minElement);
        return;
}

Node Query(ll si , ll ss, ll se , ll li , ll ri) {
        if(lazy[si]) {
            ll dx = lazy[si];
            lazy[si] = 0;
            Tree[si].minElement += dx;
            if(ss != se) {
                lazy[2*si + 0] += dx;
                lazy[2*si + 1] += dx;
            }
        }
        if(li>se || ri<ss) return {INF,INF};
        if(li<=ss && ri>=se) {
            return Tree[si];
        }
        ll mid = (ss + se) >> 1;
        ll y = min(Query(2*si + 0, ss , mid , li , ri).minElement , Query(2*si + 1, mid+1, se, li, ri).minElement);
        Node tmp = {0,y};
        return tmp;
}

void BuildTree(ll si , ll ss , ll se) {
        if(ss == se) {
            Tree[si].element = a[ss];
            Tree[si].minElement = a[ss];
            return;
        }
        ll mid = (ss+se)>>1;
        BuildTree(2*si + 0, ss,  mid);
        BuildTree(2*si + 1, mid + 1 , se);
        Tree[si].minElement = min(Tree[2*si + 0].minElement , Tree[2*si + 1].minElement);
        return;
}

ll solve()
{
        ll n, q , l , r , val;
        string str;
        cin >> n;
        for(ll i=1 ; i<=n ; i++) cin >> a[i];
        BuildTree(1,1,n);
        
        cin >> q;
        getline(cin, str);
        while(q--)
        {
            getline(cin, str);
		    stringstream ss(str);
		    ss >> l >> r;
            l++ , r++;
            if(ss >> val) {
                if(l>r) {
                    RangeUpdate(1,1,n,l,n,val);
                    RangeUpdate(1,1,n,1,r,val);
                }
                else {
                    RangeUpdate(1,1,n,l,r,val);
                }
            }
            else {
                if(l>r) {
                    Node x = Query(1,1,n,l,n);
                    Node y = Query(1,1,n,1,r);
                    cout << min(x.minElement,y.minElement) << "\n";
                }
                else {
                    Node x = Query(1,1,n,l,r);
                    cout << x.minElement << "\n";
                }
            }
        } 
        return 0;
}
int main() 
{
        FastIO;
        solve();
        return 0;
}