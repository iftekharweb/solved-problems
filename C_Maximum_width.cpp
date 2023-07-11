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


ll solve()
{
        ll n = vin();
        ll m = vin();
        string a, b;
        cin >> a >> b;

        ll mx_diff = 0;
        vector<ll> cnt[26] , min_i(m) , max_i(m);
        for(int i=0; i<n; i++) {
            cnt[a[i]-'a'].push_back(i);
        }
        for(int i=0; i<m ; i++) {
            if(!i) {
                min_i[i] = cnt[b[i]-'a'][0];
            }
            else {
                min_i[i] = upper_bound(all(cnt[b[i]-'a']),min_i[i-1])-cnt[b[i]-'a'].begin();
                min_i[i] = cnt[b[i]-'a'][min_i[i]];
            }
        }
        //printVector(min_i);

        for(int i=m-1; i>=0; i--) {
            if(i==m-1) {
                max_i[i] = cnt[b[i]-'a'][cnt[b[i]-'a'].size()-1];
            }
            else {
                //max_i[i] = lower_bound(all(cnt[b[i]-'a']),max_i[i+1]-1) - cnt[b[i]-'a'].begin();
                max_i[i] = MOD;
                while(max_i[i]>=max_i[i+1]) {
                    max_i[i] = cnt[b[i]-'a'][cnt[b[i]-'a'].size()-1];
                    cnt[b[i]-'a'].pop_back();
                }
            }
        }
        //printVector(max_i);

        for(int i=0; i<m-1; i++) {
            mx_diff = max(mx_diff,max_i[i+1]-min_i[i]);
        }
        
        return mx_diff;
}
int main() 
{
        FastIO;
        cout << solve() << "\n";
        return 0;
}