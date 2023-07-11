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


ll GetCal(ll tmp) {
        ll zero = 0;
        while(tmp) {
            if(tmp%10 == 0) zero++;
            else break;
            tmp /= 10;
        }
        return zero;
}

ll solve()
{
        ll n = vin() , m = vin();
        //if(m<10) {
        //    if((m*n)%10 == 0) return n*m;
        //    if(m >= 5 && (5*n)%10 == 0) return n*5;
        //    if(m >= 2 && n%10 == 5) return n*2;
        //    return n*m;
        //}
        ll incase = m;
        ll k = m;
        while(m%10 != 0 && m%10 != 5) m--;

        ll ans = 0, mxZero = -1, dig = 0;

        ll zero = 0;
        for(ll i=0; i<=100; i++) {
            if(incase-i >= 1) {
                zero = GetCal((incase-i)*n);
                if(zero > mxZero) {
                    ans = (incase-i)*n;
                    mxZero = zero;
                }
                else if(zero == mxZero) {
                    ans = max(ans,(incase-i)*n);
                }
            }
        }

        ll top_dig = -1;

        while(k) {
            zero = 0;
            k /= 10;
            dig++;
            for(int i=0; i<dig-1; i++) m/=10;
            if(!k) top_dig = m-1;
            if(m%10 >= 5) {
                m/=10;
                m*=10;
                m += 5;
                for(int i=0; i<dig-1; i++) m*=10;
                zero = GetCal(m*n);
                if(zero > mxZero) {
                    ans = m*n;
                    mxZero = zero;
                }
                else if(zero == mxZero) {
                    ans = max(ans,m*n);
                }
            }
            else {
                for(int i=0; i<dig-1; i++) m*=10;
            }
            zero = 0;
            for(int i=0; i<dig; i++) m/=10;
            m*=10;
            for(int i=0; i<dig-1; i++) m*=10;
            zero = GetCal(m*n);
            if(zero > mxZero) {
                ans = m*n;
                mxZero = zero;
            }
            else if(zero == mxZero) {
                ans = max(ans,m*n);
            }
        }
        ll p = 1;
        for(int i=0; i<dig-1; i++) {
            p *= 10;
        }
        while(top_dig>=1) {
            zero = GetCal(p*top_dig);
            if(zero > mxZero) {
                ans = m*n;
                mxZero = zero;
            }
            else if(zero == mxZero) {
                ans = max(ans,m*n);
            }
            top_dig--;
        }
        return ans;
}
int main() 
{
        FastIO;
        TestCase {
            cout << solve() << "\n";
            //solve();
        }
        return 0;
}