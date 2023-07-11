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
const long long MOD = 1e9+7 , N = 1e5+10;
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

vector<int> a(N), mark(N) , point;
vector<vector<int> > vst(N);

bool Is_possible(int mid, int idx) {
        int mx = point[mid];
        int mi = point[idx];
        for(int i=0; i<a.size(); i++) {
            auto it = lower_bound(all(vst[a[i]]),mi);
            if(it==vst[a[i]].end() || *(it)>mx) return false;
        }
        return true;
}
void Clear_all(int n) {
        for(int i=0; i<=N; i++) {
            mark[i] = 0;
            vst[i].clear();
        }
        point.clear();
        return;
}

ll solve()
{
        int n , k;
        cin >> n >> k;
        Clear_all(n);

        for(int i=0; i<n; i++) {
            int x;
            cin >> x;
            a[i] = x;
            for(int j=k; j>=1; j--) {
                if(!mark[(x/j)]) {
                    //pr(x/j);
                    point.push_back(x/j);
                    mark[(x/j)] = 1;
                }
                vst[x].push_back(x/j);
            }
        }
        //sort(all(point));
        if(k>a[n-1]) {
            return 0;
        }
        if(k==1) {
            return point.back()-point[0];
        }
        int p_size = point.size() , res = INT_MAX;
        //pr(p_size);
        //printVector(point);

        for(int i=0; i<p_size; i++) {
            int lo = i , hi = p_size-1 , mid;
            while(hi-lo>1) {
                mid = (lo+hi)>>1;
                if(Is_possible(mid,i)) {
                    hi = mid;
                }
                else lo = mid+1;
            }
            if(Is_possible(lo,i)) {
                res = min(res,point[lo]-point[i]);
            }
            else if(Is_possible(hi,i)) {
                res = min(res,point[hi]-point[i]);
            }
        }
        return res;
}
int main() 
{
        FastIO;
        TestCase {
            cout << solve() << "\n";
        }
        return 0;
}