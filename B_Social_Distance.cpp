/*
                بِسْمِ ٱللَّٰهِ ٱلرَّحْمَٰنِ ٱلرَّحِيمِ                
                Iftekhar Md. Shishir
                Dept. of Information and Communication Engineering
                University of Rajshahi
*/

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

#define ll  long long
#define ull  unsigned long long
#define ld  long double
#define printSet(a)  for(auto setData:a) cout<<setData<<" ";cout<<endl;
#define printMap(a)  for(auto mapData:a) cout<<mapData.first<<" "<<mapData.second<<endl;
#define printVector(a)  for(auto vectorData:a)cout<<vectorData<<" ";cout<<endl;
#define printQueue(Q)  while(!Q.empty()) cout<< Q.front()<<" ",Q.pop(); cout<<"\n";

#define all(a)  a.begin(),a.end()
#define rall(a)  a.rbegin(),a.rend()
#define stringToInt(a,x)   stringstream demo(a); demo >> x;
#define intToSting(x,s)   stringstream demu; demu << x; a = demu.str();

#define TxtIO   freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#define TxtTest   freopen("C:/Users/Iftekhar/Documents/what/input.txt", "r", stdin);
#define FastIO   ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
#define LCM(a,b)  (a*b)/__gcd(a, b)
#define TestCase   ll t;cin>>t;while(t--)
#define points(x)   fixed<<setprecision(x)
#define pr(x)  cerr << #x << " = " << x << endl;
#define nl  cout<<"\n";

const ld PI= 3.14159265358979323846264338327950288;  //2*acos(0.0);
const long long MOD= 1000000007;

using namespace std;
using namespace __gnu_pbds;
template<class T>using indexed_set=tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>;

inline ll vin() {ll x;cin >> x;return x;}
ll POW(ll a, ll b) {ll res = 1;while(b){if(b%2)res=(res*a)%MOD;a = (a*a)%MOD; b/=2;}return res;}
vector<ll> DIGITS(ll n){vector<ll>a;while (n)a.push_back(n%10),n/=10;return a;}

string solve()
{
        ll n = vin() , m = vin(), cnt = 0 , res = 0;
        vector<ll> a(n);
        priority_queue<ll> Q;
        for(auto &x:a) {
            x = vin();
            Q.push(x);
        }
        sort(all(a));
        for(int i=n-1; i>=0; i--) {
            if(i==n-1) res += a[i]*2+1;
            else {
                if(i==0) res++;
                else res += a[i]+1;
            }
        }
        if(res <= m) return "YES";
        return "NO";
        // ll x = Q.top() , tmp = -1;
        // Q.pop();
        // res += x*2+1;
        // while (Q.size()>1) {
        //     x = Q.top();
        //     cnt++;
        //     Q.pop();
        //     if(cnt>2) cnt = 1;
        //     if(cnt==1) tmp = x;
        //     if(cnt<=2) res += x+1;
        // }
        
        // sort(rall(a));
        // for(int i=0; i<n-1; i++) {
        //     cnt+=a[i];
        // }
        // cnt*=2;
        // cnt+= a[n-1]*2;
        // pr(cnt);
        // if(cnt<=m) return "YES";
        // return "NO";
}
int main() 
{
        FastIO;
        TestCase {
            cout << solve() << endl;
            //solve();
        }
        return 0;
}