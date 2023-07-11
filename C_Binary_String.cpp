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
        string a;
        cin >> a;
        ll n = a.size() , cost = 0 , ze = 0 , on = 0;
        vector<ll> idx;

        for(int i=0; i<n; i++) {
            if(a[i]=='1')idx.push_back(i) , on++;
            else ze++ , cost++;
        }

        ll cnt_0 = 0, cnt_1 = 0 , pos1 = -1 , pos2 = n , p = 0;
        for(int i=0; i<n; i++) {
            
        }

        // for(int i=0 , j = n-1; i<n; i++ , j--) {
        //     p++;
        //     if(p%2)
        //     {
        //         ll it = lower_bound(all(idx),i)-idx.begin();
        //         ze -= it-i;
        //     }
        //     else {
        //         if(ze>on) {

        //         }
        //     }
        // }


        for(int i=0; i<n; i++)
        {
            if(a[i]=='0') cnt_0++ , ze-- , pos1 = i;
            else {
                if(ze<=cnt_1) {
                    pos1 = pos1+1;
                    break;
                }
                cnt_1++ , on--;
            }
            if(cnt_0>=cnt_1) {
                pos1 = i;

                cost += cnt_1;
                cnt_0 = cnt_1 = 0;
            }
        }
        cnt_0 = 0, cnt_1 = 0;
        for(int i=n-1; i>=max(0LL,pos1); i--) {
            if(a[i]=='0') cnt_0++ , ze-- , pos2 = i;
            else {
                if(ze<=cnt_1) {
                    pos2 = pos2;
                    break;
                }
                cnt_1++ , on--;
            }
            if(cnt_0>=cnt_1) {
                pos2 = i;

                cost += cnt_1;
                cnt_0 = cnt_1 = 0;
            }
        }
        pr(pos1); pr(pos2);
        ll cc = 0;
        for(int i=pos1; i<min(pos2,n); i++) {
            if(a[i]=='0') cc++;
        }
        return max(cost,cc);
}
int main() 
{
        FastIO;
        TestCase {
            cout << solve() << "\n";
            //solve();
        }
        return 0;
}