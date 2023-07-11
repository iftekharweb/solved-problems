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
const long long MOD = 1e9+7 , N = 2*(1e5)+10;
const long long INF = INT_FAST64_MAX;

using namespace std;
using namespace __gnu_pbds;
template<class T> using indexed_set = tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

//          U   R  D  L
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

inline ll vin() {ll x;cin >> x;return x;}
ll POW(ll a, ll b) {ll res = 1;while(b){if(b%2)res=(res*a)%MOD;a = (a*a)%MOD; b/=2;}return res;}
vector<ll> DIGITS(ll n){vector<ll>a;while (n)a.push_back(n%10),n/=10;return a;}


void solve()
{
        if(0) {
            YES :   cout << "YES\n";
                    return;
            NO  :   cout << "NO\n";
                    return;
        }

        ll n = vin() , room_tmp = vin();
        vector<pair<ll,pair<ll,ll> > > data;
        pair<ll,pair<ll,ll> > curr_tmp = {0,{room_tmp,room_tmp}};
        data.push_back({0,{room_tmp,room_tmp}});

        for(int i=0; i<n; i++) {
            ll tm = vin();
            ll l = vin() , r = vin();
            data.push_back({tm,{l,r}});
        }
        for(int i=1; i<=n; i++) {
            ll tm = (data[i].first-data[i-1].first);
            ll mi_tmp = data[i].second.first-tm;
            ll mx_tmp = data[i].second.second+tm;

            if(mx_tmp<data[i-1].second.first || mi_tmp>data[i-1].second.second) {
                goto NO;
            }
            else {
                data[i-1].second.first = max(mi_tmp,data[i-1].second.first);
                data[i-1].second.second = min(mx_tmp,data[i-1].second.second);

                data[i].second.first = min(data[i].second.second,max(data[i-1].second.first-tm,data[i].second.first));
                data[i].second.second = max(data[i].second.first,min(data[i-1].second.second+tm,data[i].second.second));
            }
        }
        goto YES;
        return;
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