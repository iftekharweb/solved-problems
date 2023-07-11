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

const long long MOD = 1e9+7 , N = 1e5 , INF = INT_FAST64_MAX;

//          U   R  D  L
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
inline ll vin() {ll x;cin >> x;return x;}
ll POW(ll a, ll b) {ll res = 1;while(b){if(b%2)res=(res*a)%MOD;a = (a*a)%MOD; b/=2;}return res;}
vector<ll> DIGITS(ll n){vector<ll>a;while(n)a.push_back(n%10),n/=10;return a;}


bool Test_Contest(ll id , vector<ll>&a, ll n, ll iq) {
        for(int i=id; i<n; i++) {
            if(a[i]>iq && iq) iq--;
            else if(a[i]>iq && !iq) return false;
        }
        return true;
}

void Lets_print(ll id , vector<ll>&a, ll n, ll iq) {
        for(int i=0; i<n; i++) {
            if(i<id) {
                if(a[i]<=iq) cout << 1;
                else cout << 0;
            }
            else cout << 1;
        }
        cout << "\n";
        return;
}

ll solve()
{
        ll n = vin() , iq = vin();
        vector<ll> a(n) , index;
        for(int i=0; i<n; i++) {
            a[i] = vin();
            if(a[i]>iq) index.push_back(i);
        }
        if(!index.size()) {
            for(int i=0; i<n; i++) cout << 1; cout << "\n";
            return 0;
        }
        ll lo = 0, hi = index.size()-1 , mid;
        while(hi-lo>1) {
            mid = (hi+lo)>>1;
            if(Test_Contest(index[mid],a,n,iq)) hi = mid;
            else lo = mid+1;
        }
        if(Test_Contest(index[lo],a,n,iq)) {
            Lets_print(index[lo],a,n,iq);
        }
        else if(Test_Contest(index[hi],a,n,iq)) {
            Lets_print(index[hi],a,n,iq);
        }
        else {
            for(auto x:a) {
                if(x>iq) cout << 0;
                else cout << 1;
            }
            cout << "\n";
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