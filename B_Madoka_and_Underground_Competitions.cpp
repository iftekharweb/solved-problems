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

bool is_valid(ll x , ll y , ll n) {
    if(x<0 || y<0 || x>n-1 || y>n-1) return false;
    return true;
}
void Change(ll xx , ll yy , vector<string> &a, ll n) {
        ll x = xx , y = yy;
        while(is_valid(x,y,n)) {
            a[x][y] = 'X';
            x++ , y++;
        }
        x = xx , y = yy;
        while(is_valid(x,y,n)) {
            a[x][y] = 'X';
            x-- , y--;
        }
}

ll solve()
{
        ll n = vin() , k = vin() , r = vin() , c = vin();
        vector<string> a(n);
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) a[i].push_back('.');
        }
        a[r-1][c-1] = 'X';
        //return 0;
        ll x = r-1 , y = c-1;
        while(is_valid(x,y,n)) {
            a[x][y] = 'X';
            x++ , y++;
        }
        x = r-1 , y = c-1;
        while(is_valid(x,y,n)) {
            a[x][y] = 'X';
            x-- , y--;
        }
        //return 0;
        while(1){
            bool fg = 0;
            for(int i=0; i<n && !fg; i++) {
                for(int j=0; j<n && !fg; j++) {
                    if(a[i][j] == 'X') {
                        if(is_valid(i,j+k,n) && a[i][j+k] != 'X') {
                            fg = 1;
                            Change(i,j+k,a,n);
                        }
                        if(is_valid(i,j-k,n) && a[i][j-k] != 'X') {
                            fg = 1;
                            Change(i,j-k,a,n);
                        }
                        if(is_valid(i-1,j+k-1,n) && a[i-1][j+k-1] != 'X') {
                            fg = 1;
                            Change(i-1,j+k-1,a,n);
                        }
                        if(is_valid(i+1,j-k+1,n) && a[i+1][j-k+1] != 'X') {
                            fg = 1;
                            Change(i+1,j-k+1,a,n);
                        }
                    }
                }
            }
            if(!fg) break;
        }
        for(int i=0; i<n; i++) {
            cout << a[i] << "\n";
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