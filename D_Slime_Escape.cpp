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


string solve()
{
        ll n = vin() , k = vin();
        vector<ll> a(n+1,0), b;
        for(int i=0; i<n; i++) a[i] = vin();

        if(a[k-1] < 0) return "NO";
        if(k == n || k == 1) return "YES";

        // Construct B
        ll curr = 0 , ck = 0 , idx = -1;
        if(a[0] < 0) ck = 1;
        for(int i=0; i<n; i++) {
            if((a[i] < 0 && !ck) || (a[i] >= 0 && ck)) {
                b.push_back(curr);
                curr = 0;
                ck ^= 1;
            }
            curr += a[i];
            if(idx == -1 && i >= k-1) idx = (int)(b.size());
        }
        b.push_back(curr);
        printVector(b); pr(idx);

        // TRY TO SCAPE THROUGH 0
        ll health = b[idx] , sz = b.size(), ii = idx-1 , jj = idx+1;
        while(ii >= 0 && jj <= sz-1) 
        {
            if(-b[jj] > health && -b[ii] > health) break;
            pr(ii); pr(jj); pr(health);

            if(-b[jj] <= health && sz != jj+1 && b[jj+1] >= -b[jj]) {
                health += b[jj] + b[jj+1];
                jj += 2;
                continue;
            }
            if(-b[ii] <= health) {
                if(ii-1 >= 0) {
                    health += b[ii] + b[ii-1];
                    ii -= 2;
                }
                else return "YES";
            }
            else {
                if(-b[jj] <= health && sz != jj+1) {
                    health += b[jj] + b[jj+1];
                    jj += 2;
                }
                else if(-b[jj] <= health && sz == jj+1) return "YES";
                else break;
            }
        }
        if(ii < 0 || jj > sz-1) return "YES";

        // TRY TO SCAPE THROUGH N
        health = b[idx] , ii = idx-1 , jj = idx+1;
        while(ii >= 0 && jj <= sz-1) 
        {
            if(-b[jj] > health && -b[ii] > health) break;

            if(-b[ii] <= health && ii-1 >= 0 && b[ii-1] >= -b[ii]) {
                health += b[ii] + b[ii-1];
                ii -= 2;
                continue;
            }
            if(-b[jj] <= health) {
                if(jj+1 < sz) {
                    health += b[jj] + b[jj+1];
                    jj += 2;
                }
                else return "YES";
            }
            else {
                if(-b[ii] <= health && ii-1 >= 0) {
                    health += b[ii] + b[ii-1];
                    ii -= 2;
                }
                else if(-b[ii] <= health && ii-1 < 0) return "YES";
                else break;
            }
        }
        if(ii < 0 || jj > sz-1) return "YES";
        return "NO";
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