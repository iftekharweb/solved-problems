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



bool Is_possible(string &a , string &b , ll n) {
        for(int i=1; i<n; i++) {
            if(a[i] == b[i] && a[0] != b[0]) return false;
            if(a[i] != b[i] && a[0] == b[0]) return false;
        }
        return true;
}
void PrintVP(vector<pair<ll,ll> > &vp) {
        cout << vp.size() << "\n";
        for(auto x:vp) {
            cout << x.first << " " << x.second << "\n";
        }
        return;
}
void solve()
{
        ll n = vin();
        string a , b;
        cin >> a >> b;
        if(n == 1) {
            if(a.back() == b.back() && a.back() == '0') {
                cout << "YES\n0\n";
            }
            else if(a.back() == b.back() && a.back() == '1') {
                cout << "NO\n";
            }
            else if(a.back() == '0') {
                cout <<"NO\n";
            }
            else {
                cout << "YES\n1\n1 1\n";
            }
            return;
        }
        if(!Is_possible(a,b,n)) {
            cout <<"NO\n";
            return;
        }

        cout << "YES\n";
        vector<pair<ll,ll> > vp;
        string c , d;

        for(int i=0; i<n; i++) c.push_back('0') , d.push_back('1');

        if(a == d && b == c) {
            vp = {{1,n}};
            PrintVP(vp);
            return;
        }
        if(a == c && b == d) {
            vp = {{1,n},{1,1}, {2,n}};
            PrintVP(vp);
            return;
        }
        if(a == c && b == c) {
            PrintVP(vp);
            return;
        }
        if(a == d && b == d) {
            vp = {{1,1},{2,n}};
            PrintVP(vp);
            return;
        }

        int stat = 0 , i = 0;
        while(i<n) {
            if(!stat) {
                while(a[i] != '0' && i<n) i++;
                if(i<n) vp.push_back({i+1,n});
            }
            else {
                while(a[i] != '1' && i<n) i++;
                if(i<n) vp.push_back({i+1,n});
            }
            stat ^= 1;
        }
        if(b.back() == '0') {
            vp.push_back({1,n});
        }
        else {
            vp.push_back({1,1});
            vp.push_back({2,n});
        }
        PrintVP(vp);
        return;
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