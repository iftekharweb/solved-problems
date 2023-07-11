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

bool isPrime(ll n)
{
        if(n == 1) return false;
        for(ll i=2; i*i<=n; i++) {
                if(n%i == 0) return false;
        }
        return true;
}

void primeFact(ll n)
{
        vector<ll> factors;
        map<ll,ll> mm;
        for(ll i=2; i*i<=n; i++) {
            if(n%i == 0) {
                int cnt = 0;
                while(n%i == 0) {
                    cnt++, n/=i;
                    factors.push_back(i);
                }
                mm[i] = cnt;
            }
        }
        if(n>1) {
            factors.push_back(n);
            mm[n]++;
        }
        if(factors.size()<=1) {
            cout << 1; nl;
            cout << n; nl;
            return;
        }
        set<ll> ss(all(factors));
        vector<pair<ll,ll> > v;
        for(auto x:ss) {
            v.push_back({mm[x],x});
        }
        sort(all(v));
        ll num = 1;
        for(int i=0; i<v.size()-1; i++) {
            ll x = v[i].first;
            while (x--)
            {
                num*=v[i].second;
            }
        }
        ll p = v.size()-1;
        if(num%v[p].second==0) {
            ll x = v[p].first;
            cout << x+1; nl;
            while (x--)
            {
                cout <<v[p].second << " ";
            }
            cout << num ; nl;
            return;
        }
        cout << v[p].first; nl;
        num*=v[p].second;
        ll x = v[p].first-1;
        while (x--)
        {
            cout <<v[p].second << " ";
        }
        cout << num ; nl;
        return;
}

void solve()
{
        ll n = vin();
        primeFact(n);
        return ;
}
int main() 
{
        FastIO;
        TestCase {
            //cout << solve() << endl;
            solve();
        }
        return 0;
}