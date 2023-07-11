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

void solve()
{
        ll n = vin() , k = vin();
        vector<ll> Room(k) , Temp(k), Survey(n+1,0);
        vector<int> Direction(n+1,0);
        vector<pair<ll,ll> > RoomTemp(k);
        //vector<pair<ll,pair<int,int> > > Survey(n,{-1,0});
        for(int i=0; i<k; i++) Room[i] = vin();
        for(int i=0; i<k; i++) Temp[i] = vin();
        for(int i=0; i<k; i++) {
            RoomTemp[i] = {Temp[i],Room[i]};
        }
        sort(all(RoomTemp));
        set<ll> st;

        // AC-ROOMS
        for(int i=0; i<k; i++)
        {
            if(!i) {
                Survey[RoomTemp[i].second] = RoomTemp[i].first;
                st.insert(RoomTemp[i].second);
                Direction[RoomTemp[i].second] = 0;
                continue;
            }
            st.insert(RoomTemp[i].second);
            auto itl = st.lower_bound(RoomTemp[i].second);
            auto itr = st.upper_bound(RoomTemp[i].second);
            ll x = INF , y = INF;
            if(itl != st.begin()) {
                itl--;
                x = Survey[*(itl)]+(RoomTemp[i].second-*(itl));
            }
            if(itr != st.end()) {
                if(Direction[*(itr)] == -1) {
                    y = Survey[*(itr)] - (*(itr) - RoomTemp[i].second);
                }
                else {
                    y = Survey[*(itr)] + (*(itr) - RoomTemp[i].second);
                }
            }
            Survey[RoomTemp[i].second] = min(RoomTemp[i].first , min(x,y));
            if(Survey[RoomTemp[i].second] == x) {
                Direction[RoomTemp[i].second] = -1;
            }
        }

        // Non-AC ROOMS
        for(int i=1; i<=n; i++) {
            if(Survey[i]) continue;
            st.insert(i);
            auto itl = st.lower_bound(i);
            auto itr = st.upper_bound(i);
            ll x = INF , y = INF;
            if(itl != st.begin()) {
                itl--;
                x = Survey[*(itl)] + ( i - *(itl) );
            }
            if(itr != st.end()) {
                if(Direction[*(itr)] == -1) {
                    y = Survey[*(itr)] - ( *(itr) - i );
                }
                else y = Survey[*(itr)] + ( *(itr) - i );
            }
            Survey[i] = min(x,y);
        }
        for(int i=1; i<=n; i++) cout << Survey[i] << " "; nl;
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