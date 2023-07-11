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


ll solve()
{
        ll n = vin();
        string a , b;
        cin >> a;
        ll sum = 0;
        set<ll> l , r;
        for(int i=0; i<n/2; i++) {
            if(a[i] == 'L') l.insert(i);
        }
        for(int i=n/2; i<n; i++) {
            if(a[i] == 'R') r.insert(i);
        }
        for(int i=0; i<n; i++) {
            if(a[i] == 'L') sum += i;
            else sum += n-1-i;
        }
        for(int i=0; i<n; i++) {
            if(l.size() && r.size()) {
                auto itr = --r.end();
                auto itl = l.begin();
                ll x = *itr;
                ll y = *itl;
                if(x>=n-1-y) {
                    sum -= n-1-x;
                    sum += x;
                    r.erase(itr);
                    cout << sum << " ";
                    continue;
                }
                else {
                    sum -= y;
                    sum += n-1-y;
                    l.erase(itl);
                    cout << sum << " ";
                    continue;
                }
            }
            else if(l.size()) {
                auto itl = l.begin();
                ll y = *itl;
                sum -= y;
                sum += n-1-y;
                l.erase(itl);
                cout << sum << " ";
                continue;
            }
            else if(r.size()) {
                auto itr = --r.end();
                ll x = *itr;
                sum -= n-1-x;
                sum += x;
                r.erase(itr);
                cout << sum << " ";
                continue;
            }
            else {
                cout << sum << " ";
            }
        }
        nl;
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