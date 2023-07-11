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

const long long MOD = 1e9+7 , N = 1e5+10 , INF = INT_FAST64_MAX;

//          U   R  D  L
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
inline ll vin() {ll x;cin >> x;return x;}
ll POW(ll a, ll b) {ll res = 1;while(b){if(b%2)res=(res*a)%MOD;a = (a*a)%MOD; b/=2;}return res;}
vector<ll> DIGITS(ll n){vector<ll>a;while(n)a.push_back(n%10),n/=10;return a;}

ll Tree[4*N] , a[N];

void Point_update(ll si , ll ss , ll se , ll qi) {
        if(ss == se) {
            Tree[si] = a[qi];
            return;
        }
        ll mid = (ss + se) >> 1;
        if(qi <= mid) Point_update(2*si + 0 , ss , mid , qi);
        else Point_update(2*si + 1 , mid+1 , se , qi);
        Tree[si] = min(Tree[2*si + 0] , Tree[2*si + 1]);
        return;
}

ll Query(ll si , ll ss , ll se , ll li , ll ri) {
        if(li>se || ri < ss) return INF;
        if(li<=ss && ri>=se) return Tree[si];
        ll mid = (ss + se) >> 1;
        return min(Query(2*si + 0 , ss , mid , li , ri) , Query(2*si + 1 , mid+1 , se , li , ri));
}

ll solve()
{
        ll n = vin() , m = vin();
        for(int i=1; i<=n; i++){
            a[i] = vin();
            Point_update(1,1,n,i);
        }
        ll mm = INF;
        set<ll> st;
        for(int i=1; i<=n; i++) {
            if(a[i]<mm) {
                mm = a[i];
                st.insert(mm);
            }
        }
        for(int i=1; i<=m; i++) {
            ll idx = vin() , d = vin();
            ll mi = Query(1,1,n,1,idx);
            a[idx] -= d;
            Point_update(1,1,n,idx);
            if(mi > a[idx]) {
                st.erase(st.lower_bound(a[idx]), st.upper_bound(mi));
                if(idx != 1) {
                    ll tmp = Query(1,1,n,1,idx-1);
                    st.insert(tmp);
                }
                st.insert(a[idx]);
            }
            cout << st.size() << " ";
        }
        nl;
        return 0;
}
int main() 
{
        FastIO;
        for(int i=0 ; i<= 4*N; i++) Tree[i] = INF;
        TestCase {
            // cout << solve() << "\n";
            solve();
        }
        return 0;
}