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

const long long MOD = 1e9+7 , N = 1e6+10 , INF = INT_FAST64_MAX;

//          U   R  D  L
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
inline ll vin() {ll x;cin >> x;return x;}
ll POW(ll a, ll b) {ll res = 1;while(b){if(b%2)res=(res*a)%MOD;a = (a*a)%MOD; b/=2;}return res;}
vector<ll> DIGITS(ll n){vector<ll>a;while(n)a.push_back(n%10),n/=10;return a;}


struct Node {
    ll len , open , close;
};

Node Tree[4*N];
char a[N];

Node MargeThem(Node lt , Node rt) {
        /*
                https://youtu.be/dtFdB4lrNCAs
                https://codeforces.com/blog/entry/10363
        */
        Node ans;
        ll ready_to_combine = min(lt.open, rt.close);
        ans.len =  lt.len + rt.len + ready_to_combine;
        ans.open = lt.open + rt.open - ready_to_combine;
        ans.close = lt.close + rt.close - ready_to_combine;
        return ans;
}

Node Query(ll si , ll ss ,ll se , ll li , ll ri) {
        if(li>se || ri<ss) return {0,0,0};
        if(li<=ss && ri>= se) return Tree[si];
        ll mid = (ss + se) >> 1;
        return MargeThem(Query(2*si + 0 , ss ,mid , li, ri) , Query(2*si + 1 , mid+1 , se , li , ri));
}

void BuildTree(ll si , ll ss , ll se) {
        if(ss == se) {
            Tree[si].len = 0;
            Tree[si].open = (a[ss] == '(');
            Tree[si].close = (a[ss] == ')');
            return;
        }
        ll mid = (ss + se) >> 1;
        BuildTree(2*si + 0 , ss , mid);
        BuildTree(2*si + 1 , mid+1 , se);
        Tree[si] = MargeThem(Tree[2*si + 0] , Tree[2*si + 1]);
}

ll solve()
{
        a[0] = ' ';
        cin >> a + 1;
        ll n = strlen(a);
        BuildTree(1,1,n);

        ll m = vin();
        while(m--) {
            ll l = vin() , r = vin();
            ll ans = Query(1,1,n,l,r).len;
            cout << 2*ans << endl;
        }
        return 0;
}
int main() 
{
        FastIO;
        solve();
        return 0;
}