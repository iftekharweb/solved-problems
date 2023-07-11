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
const long long MOD = 1e9+7 , N = 1e5*2;
const long long INF = INT_FAST64_MAX;

using namespace std;
using namespace __gnu_pbds;
template<class T>using indexed_set=tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>;

//          U   R  D  L
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

inline ll vin() {ll x;cin >> x;return x;}
ll POW(ll a, ll b) {ll res = 1;while(b){if(b%2)res=(res*a)%MOD;a = (a*a)%MOD; b/=2;}return res;}
vector<ll> DIGITS(ll n){vector<ll>a;while (n)a.push_back(n%10),n/=10;return a;}


void solve()
{
        ll n = vin();
        ll u , r , d, l , uu , rr , dd, lL;
        cin >> u >> r >> d >> l;

        if(0) {
            no  : cout << "NO" << endl;
                return;
            yes : cout << "YES" << endl;
                return;
        }
        /* PUK CONDITIONS*/
        for(int i=0; i<=15; i++) {
            uu = u , rr = r , dd = d , lL = l;
            bitset<4> bit = i;
            bool ok = 0;
            for(int j=0; j<4; j++) {
                if(!j) { // UR
                    if(bit[j]) {
                        uu--;
                        rr--;
                    }
                }
                if(j==1) { // RD
                    if(bit[j]) {
                        rr--;
                        dd--;
                    }
                }
                if(j==2) { // DL
                    if(bit[j]) {
                        dd--;
                        lL--;
                    }
                }
                if(j==3) { // LU
                    if(bit[j]) {
                        lL--;
                        uu--;
                    }
                }
            }
            if(uu<0 || dd<0 || rr<0 || lL<0) ok = 1;
            if(uu>n-2 || dd>n-2 || rr>n-2 || lL>n-2) ok = 1;
            if(!ok) goto yes;
        }
        goto no;
        /* PUK CONDITIONS*/
        uu = u , rr = r , dd = d , lL = l;

        bool ur = 0 , rd = 0 , ul = 0 , dl = 0;
        if(u==n) {
            u-=2;
            ur = ul = 1;
            l--;
            r--;
        }
        else if(u==n-1) {
            u--;
            if(r>=l) {
                r--;
                ur = 1;
            }
            else {
                l--;
                ul = 1;
            }
        }

        if(r==n) {
            r-=2;
            ur = rd = 1;
            u--;
            d--;
        }
        else if(r==n-1) {
            r--;
            if(u>=d && !ur) {
                u--;
                ur = 1;
            }
            else {
                d--;
                rd = 1;
            }
        }

        if(d==n) {
            d-=2;
            dl = rd = 1;
            l--;
            r--;
        }
        else if(d==n-1) {
            d--;
            if(r>=l && !rd) {
                r--;
                rd = 1;
            }
            else {
                l--;
                dl = 1;
            }
        }

        if(l==n) {
            l-=2;
            ul = 1 , dl = 1;
            u--;
            d --;
        }
        else if(l==n-1) {
            l--;
            if(d>=u && !dl) {
                d--;
                dl = 1;
            }
            else {
                u--;
                ul = 1;
            }
        }

        if(u<0 || d <0 || r<0 || l<0) goto no;
        goto yes;
        
}
int main() 
{
        FastIO;
        TestCase {
            //cout << solve() << "\n";
            solve();
        }
        return 0;
}