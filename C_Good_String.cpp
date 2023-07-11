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


ll Do_calculation(vector<set<ll> >&vst , char preCh , char postCh , ll n) {
        ll cal = 0 , x;
        bool fg = 1;
        auto it = vst[preCh-'0'].upper_bound(-1);
        if(it!=vst[preCh-'0'].end()) x = *(it) , cal++;
        else x = -1;

        while(x!=-1) {
            if(fg) {
                it = vst[postCh-'0'].upper_bound(x);
                if(it!=vst[postCh-'0'].end()) x = *(it) , cal++;
                else x = -1;
                fg = 0;
            }
            else {
                it = vst[preCh-'0'].upper_bound(x);
                if(it!=vst[preCh-'0'].end()) x = *(it) , cal++;
                else x = -1;
                fg = 1;
            }   
        }
        if(cal%2) cal--;
        return n-cal;
}

ll solve()
{
        string a; cin >> a;
        ll n = a.size() , res = INF , mi = INF;
        vector<ll> cntDigit(10,0);
        set<char> st;
        vector<set<ll> >  vst(10);

        for(int i=0; i<n; i++) {
            cntDigit[a[i]-'0']++;
            st.insert(a[i]);
            vst[a[i]-'0'].insert(i);
        }
        for(auto x:st) mi = min(mi,n-cntDigit[x-'0']);
        res = min(res, mi);

        vector<char> vch(all(st));
        ll vchn = vch.size();
        for(int i=0; i<vchn-1; i++) {
            for(int j=i+1; j<vchn; j++) {
                res = min(res , Do_calculation(vst,vch[i],vch[j],n));
                res = min(res , Do_calculation(vst,vch[j],vch[i],n));
            }
        }
        return res;
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