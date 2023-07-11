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

void Lets_DO_It(set<ll>&zeroIdx , set<ll>&oneIdx , vector<ll>&num, string &a , ll &n , int fg , ll next, ll subs)  {
        while(1) {
            if(!fg) {
                auto it = oneIdx.lower_bound(next);
                if(it==oneIdx.end()) break;
                next = *it;
                oneIdx.erase(it);
                num[next] = subs;
            }
            else {
                auto it = zeroIdx.lower_bound(next);
                if(it==zeroIdx.end()) break;
                next = *it;
                zeroIdx.erase(it);
                num[next] = subs;
            }
            fg ^= 1;
        }
        return;
}

void solve()
{
        ll n = vin();
        vector<ll> num(n);
        string a; cin >> a;
        set<ll> zeroIdx , oneIdx;
        for(int i=0; i<n; i++) {
            if(a[i]=='1') oneIdx.insert(i);
            else zeroIdx.insert(i);
        }
        ll subs = 1;
        while(zeroIdx.size() && oneIdx.size()){
            auto it0 = zeroIdx.begin();
            auto it1 = oneIdx.begin();
            if(*it0<*it1) {
                int fg = 0;
                ll next = *it0;
                zeroIdx.erase(it0);
                num[next] = subs;
                Lets_DO_It(zeroIdx,oneIdx,num,a,n,0,next, subs);
            }
            else {
                int fg = 0;
                ll next = *it1;
                oneIdx.erase(it1);
                num[next] = subs;
                Lets_DO_It(zeroIdx,oneIdx,num,a,n,1,next,subs);
            }
            subs++;
        }
        for(auto x:zeroIdx)  num[x] = subs++;
        for(auto x:oneIdx) num[x] = subs++;
        cout << subs-1 << endl;
        for(int i=0; i<n; i++) cout << num[i] << " "; nl;
        return;
}
int main()
{
        FastIO;
        TestCase {
            solve();
        }
        return 0;
}
