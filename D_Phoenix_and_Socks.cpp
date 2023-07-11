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
const long long MOD = 1000000007;
const long long INF = INT_FAST64_MAX;

using namespace std;
using namespace __gnu_pbds;
template<class T>using indexed_set=tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>;

inline ll vin() {ll x;cin >> x;return x;}
ll POW(ll a, ll b) {ll res = 1;while(b){if(b%2)res=(res*a)%MOD;a = (a*a)%MOD; b/=2;}return res;}
vector<ll> DIGITS(ll n){vector<ll>a;while (n)a.push_back(n%10),n/=10;return a;}

ll solve()
{
        ll n , l , r , res = 0;
        cin >> n >> l >> r;
        vector<ll> a(n) , lt, rt;
        set<ll> s_lt, s_rt , s_tt;

        for(int i=0; i<n; i++) {
            a[i] = vin();
            if(i<l) {
                lt.push_back(a[i]);
                s_lt.insert(a[i]);
                s_tt.insert(a[i]);
            }
            else {
                rt.push_back(a[i]);
                s_rt.insert(a[i]);
                s_tt.insert(a[i]);
            }
        }
        res += (n/2 - min(l,r));
        ll doit = res;

        map<ll,ll> cnt_lt , cnt_rt;
        for(int i=0; i<l; i++) cnt_lt[lt[i]]++;
        for(int i=0; i<r; i++) cnt_rt[rt[i]]++;

        // let's remove the common ones first
        for(auto y:s_tt) {
            ll x = min(cnt_lt[y], cnt_rt[y]);
            cnt_lt[y] -= x;
            cnt_rt[y] -= x;
        }

        // Banalce socks
        if(l>r) {
            for(int i=0; i<l; i++) {
                ll y = lt[i];
                if(!doit) break;
                if(cnt_rt[y]<cnt_lt[y] && cnt_lt[y] > 1) {
                    cnt_lt[y]-=2;
                    doit--;
                }
            }
            if(doit) {
                for(int i=0; i<l; i++) {
                    ll y = lt[i];
                    if(!doit) break;
                    if(cnt_lt[y] > 1) {
                        cnt_lt[y]-=2;
                        doit--;
                    }
                }
            }
            if(doit) {
                for(int i=0; i<l; i++) {
                    ll y = lt[i];
                    if(!doit) break;
                    if(cnt_lt[y]) {
                        cnt_lt[y]--;
                        cnt_rt[y]++;
                        doit--;
                    }
                }
            }
        }
        else if(r>l)
        {
            for(int i=0; i<r; i++) {
                ll y = rt[i];
                if(!doit) break;
                if(cnt_lt[y]<cnt_rt[y] && cnt_rt[y] > 1) {
                    cnt_rt[y]-=2;
                    doit--;
                }
            }
            if(doit) {
                for(int i=0; i<r; i++) {
                    ll y = rt[i];
                    if(!doit) break;
                    if(cnt_rt[y] > 1) {
                        cnt_rt[y]-=2;
                        doit--;
                    }
                }
            }
            if(doit) {
                for(int i=0; i<r; i++) {
                    ll y = rt[i];
                    if(!doit) break;
                    if(cnt_rt[y]) {
                        cnt_rt[y]--;
                        cnt_lt[y]++;
                        doit--;
                    }
                }
            }
        }

        // Now use dollar
        ll cnt = 0;
        for(auto y:s_tt) cnt += cnt_lt[y]+cnt_rt[y];
        res += cnt/2;
        return res;
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