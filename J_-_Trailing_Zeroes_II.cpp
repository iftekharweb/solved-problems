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

const long long MOD = 1e9+7 , N = 1e6+1 , INF = INT_FAST64_MAX;

//          U   R  D  L
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
inline ll vin() {ll x;cin >> x;return x;}
ll POW(ll a, ll b) {ll res = 1;while(b){if(b%2)res=(res*a)%MOD;a = (a*a)%MOD; b/=2;}return res;}
vector<ll> DIGITS(ll n){vector<ll>a;while(n)a.push_back(n%10),n/=10;return a;}


vector<int> Total_2(N,0), Total_5(N,0);
vector<bool> markPrime(N,true);
vector<int> primes , minFactor(N,0);

void Seive()
{
        int maxN = N-1;
        markPrime[1] = false;
        minFactor[2] = 2;
        for(int i=4; i<=maxN; i+=2) {
            markPrime[i] = false;
            minFactor[i] = 2;
        }
        for(int i=3; i*i<=maxN; i+=2){
            if(markPrime[i]) {
                for(int j=i*i; j<=maxN; j+=i) {
                    markPrime[j] = false;
                    if(!minFactor[j]) minFactor[j] = i;
                }
            }
        }
        for(int i=1; i<=maxN; i++) {
            if(markPrime[i]) {
                primes.push_back(i);
                minFactor[i] = i;
            }
        }
        return;
}

int solve()
{
        int n = vin() , r = vin() , p = vin() , q = vin();
        int nr = n-r , cnt_2 , cnt_5 , tcnt_2 = 0, tcnt_5 = 0;
        cnt_2 = Total_2[n]-Total_2[nr];
        cnt_5 = Total_5[n]-Total_5[nr];
        while(p>1) {
            if(minFactor[p]==2) tcnt_2++;
            if(minFactor[p]==5) tcnt_5++;
            p /= minFactor[p];
        }
        tcnt_2 *= q;
        tcnt_5 *= q;
        cnt_2 += tcnt_2;
        cnt_5 += tcnt_5;
        cnt_2 -= min(cnt_2,Total_2[r]);
        cnt_5 -= min(cnt_5,Total_5[r]);
        return min(cnt_2,cnt_5);
}
int main() 
{
        FastIO;
        Seive();
        int cnt_2 = 0, cnt_5 = 0;
        for(int i=2; i<N; i++) {
            int x = i;
            while(x>1) {
                if(minFactor[x]==2) cnt_2++;
                if(minFactor[x]==5) cnt_5++;
                x /= minFactor[x];
            }
            Total_2[i] = cnt_2;
            Total_5[i] = cnt_5;
        }
        int cnt = 1;
        TestCase {
            cout << "Case " << cnt << ": " << solve() << "\n";
            cnt++;
        }
        return 0;
}