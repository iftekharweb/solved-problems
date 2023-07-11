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


ll getAns(string &a , ll n) {
        a.push_back('1');
        ll cnt = 0;
        ll ans = 0;
        for(int i=0; i<n; i++) {
            if(a[i] == '0' && a[i+1] == '0') cnt++;
            if(a[i] == '0' && a[i+1] == '1') {
                cnt++;
                ans += (cnt*(cnt+1))/2;
                cnt = 0;
            }
        }
        return ans;
}

ll solve()
{
        ll k = vin();
        string a;
        cin >> a;
        ll n = a.size() , ans = 0, ones = 0 , zeros = 0 , cntID = 0;
        if(!k)  {
           return  getAns(a,n);
        }
        set<ll> OneIdx;
        for(int i=0; i<n; i++) {
            if(a[i] == '1') {
                ones++ , OneIdx.insert(i);
                if(ones == k) cntID = i;
            }
            else zeros++;
        }
        if(ones < k) return 0;
        for(int i=cntID; i<n;) {
            if(i == cntID) {
                ll left = 0 , right = 0;
                auto it = OneIdx.upper_bound(i);
                ans++;
                left = *(OneIdx.begin());
                if(it != OneIdx.end()) {
                    right = (*it)-i-1;
                    ans += left + right + (left*right);
                }
                else {
                    right = n-i-1;
                    ans += left + right + (left*right);
                    break;
                }
                i = *it;
            }
            else {
                ll left = 0 , right = 0;
                ll id = *OneIdx.begin();
                OneIdx.erase(OneIdx.begin());
                left = *(OneIdx.begin())-id-1;
                
                auto it =  OneIdx.upper_bound(i);
                ans++;
                if(it != OneIdx.end()) {
                    right = (*it)-i-1;
                    ans += left + right + (left*right);
                }
                else {
                    right = n-i-1;
                    ans += left + right + (left*right);
                    break;
                }
                i = *it;
            }
        }
        return ans;
}
int main() 
{
        FastIO;
        cout << solve() << "\n";
        return 0;
}