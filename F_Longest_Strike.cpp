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
        ll n = vin() , k = vin();
        vector<ll> a(n);
        for(int i=0; i<n; i++) {
            a[i] = vin();
        }
        sort(all(a));
        a.push_back(-1);

        vector<pair<ll,ll> > cnt;
        vector<ll> newCnt;

        cnt.push_back({0,0});
        ll p = 0;
        for(int i=0; i<n; i++) {
            if(a[i]==a[i+1]) {
                p++;
            }
            else {
                p++;
                cnt.push_back({p,a[i]});
                p = 0;
            }
        }
        for(int i=0; i<cnt.size(); i++) {
            if(cnt[i].first<k) {
                cnt[i].first = cnt[i].second = 0;
                continue;
            }
            if(cnt[i].first) {
                newCnt.push_back(cnt[i].second);
            }
        }
        cnt.push_back({0,0});
        // for(int i=0; i<cnt.size(); i++) {
        //     swap(cnt[i].first,cnt[i].second);
        // }
        //for(int i=0; i<cnt.size(); i++) cout << cnt[i].first << " "; nl;

        if(newCnt.empty()) {
            cout << -1 << "\n";
            return;
        }
        newCnt.push_back(0);
        //printVector(newCnt);
        ll mx = -1 , l  = 0, r = 0, idx = 0;
        for(int i=0; i<newCnt.size()-1; i++) {
            if(newCnt[i]+1!=newCnt[i+1]) {
                //pr(newCnt[i]); pr(newCnt[idx]);
                //pr(i); pr(idx);
                ll x = newCnt[i] - newCnt[idx];

                if(x>mx) {
                    //pr(i); pr(idx);
                    mx = x;
                    l = newCnt[idx];
                    r = newCnt[i];
                }
                idx = i+1;
            }
        }
        cout << l << " " << r << "\n";
        return ;
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