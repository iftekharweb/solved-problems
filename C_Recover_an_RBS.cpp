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
        string a; 
        cin >> a;
        string c = a;
        int n = a.size();
        int open = 0 , close = 0 , rbs_sum = 0 , q = 0 , need_open = 0 , need_close = 0;
        for(int i=0; i<n; i++) {
            if(a[i]=='(') rbs_sum++;
            else if(a[i]==')')rbs_sum--;
            else q++;
        }
        if(!rbs_sum) {
            need_open = need_close = q/2;
        }
        else if(rbs_sum<0) {
            int tmp = abs(rbs_sum-0);
            need_open = need_close = q>>1;
            if(q%2) {
                need_open++;
                tmp--;
            }
            need_close -= tmp>>1;
            need_open += tmp>>1;
        }
        else if(rbs_sum>0) {
            int tmp = abs(rbs_sum-0);
            need_open = need_close = q>>1;
            if(q%2) {
                need_close++;
                tmp--;
            }
            need_close += tmp>>1;
            need_open -= tmp>>1;
        }
        if(!need_open || !need_close) {
            return "YES";
        }
        // Let's Try Valid Sequence
        open = need_open-1 , close = need_close-1;
        for(int i=0; i<n; i++) {
            if(!open) break;
            if(c[i]=='?') {
                c[i] = '[' , open--;
            }
        }
        for(int i=0; i<n; i++) {
            if(c[i]=='?') {
                c[i] = ']'; break;
            }
        }
        for(int i=0; i<n; i++) {
            if(c[i]=='?') {
                c[i] = '['; break;
            }
        }
        for(int i=0; i<n; i++) {
            if(c[i]=='?') c[i] = ']';
        }
        int sum = 0;
        for(int i=0; i<n; i++) {
            if(c[i]=='(' || c[i]=='[') sum++;
            else sum--;
            if(sum<0) return "YES";
        }
        if(sum!=0) return "YES";
        return "NO";;
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