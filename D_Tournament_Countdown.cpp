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
ll POW(ll a, ll b) {ll res = 1;while(b){if(b%2)res=(res*a);a = (a*a); b/=2;}return res;}
vector<ll> DIGITS(ll n){vector<ll>a;while(n)a.push_back(n%10),n/=10;return a;}


void solve()
{
        int n;
        scanf("%d",&n);
        int X = POW(2,n);
        queue<int> Q;
        for(int i=1; i<=X; i++) Q.push(i);
        while(1) {
            int a , b , c , d, x;
            
            if(Q.size()>=4) {
                a = Q.front(); Q.pop();
                b = Q.front(); Q.pop();
                c = Q.front(); Q.pop();
                d = Q.front(); Q.pop();

                printf("? %d %d\n",b,c);
                fflush(stdout);
                scanf("%d",&x);
                if(!x) {
                    printf("? %d %d\n",a,d);
                    fflush(stdout);
                    scanf("%d",&x);
                    if(x==1) Q.push(a);
                    else Q.push(d);
                }
                else if(x==1) {
                    printf("? %d %d\n",b,d);
                    fflush(stdout);
                    scanf("%d",&x);
                    if(x==1) Q.push(b);
                    else Q.push(d);
                }
                else if(x==2) {
                    printf("? %d %d\n",a,c);
                    fflush(stdout);
                    scanf("%d",&x);
                    if(x==1) Q.push(a);
                    else Q.push(c);
                }
            }
            else if(Q.size()==2) {
                a = Q.front(); Q.pop();
                b = Q.front(); Q.pop();
                printf("? %d %d\n",a,b);
                fflush(stdout);
                scanf("%d",&x);
                if(x==1) Q.push(a);
                else Q.push(b);
            }
            else if(Q.size()==1) {
                a = Q.front();
                printf("! %d\n",a);
                fflush(stdout);
                return;
            }
        }
        return;
}
int main() 
{
        // FastIO;
        int t;
        scanf("%d", &t);
        for(int i=0; i<t; i++) {
            solve();
        }
        return 0;
}