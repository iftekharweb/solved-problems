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


ll solve()
{
        ll n = vin() , m = vin();
        vector<ll> quantity(n) , cost(n);
        multiset<pair<ll,pair<ll,ll>>> Q;
        map<ll,ll> ck;

        for(int i=0; i<n; i++) quantity[i] = vin();
        for(int i=0; i<n; i++) cost[i] = vin();
        for(int i=0; i<n; i++) {
            Q.insert({cost[i],{i,quantity[i]}});
        }
        for(int i=0; i<m; i++) {
            ll kind = vin() , orders = vin();
            ll Customer_cost = 0;
            kind--;

            if(orders <= quantity[kind]-ck[kind]) {
                pair<ll,pair<ll,ll> > p = {cost[kind],{kind,quantity[kind]-ck[kind]}};
                Customer_cost += orders*cost[kind];
                auto it = Q.find(p);
                if(it != Q.end()) Q.erase(it);
                p.second.second -= orders;
                if(p.second.second) {
                    Q.insert(p);
                }
                ck[kind] += orders;
                orders = 0;
            }
            else {
                auto it = Q.find({cost[kind],{kind,quantity[kind]-ck[kind]}});
                if(it!=Q.end()) {
                    Customer_cost += (*it).second.second*cost[kind];
                    Q.erase(it);
                    ck[kind] += (*it).second.second;
                    orders -= (*it).second.second;
                }
                while(orders)
                {
                    if(Q.empty()) break;
                    it = Q.begin();
                    pair<ll,pair<ll,ll> > p = *it;
                    Q.erase(it);
                    if(orders <= p.second.second) {
                        Customer_cost += orders*cost[p.second.first];
                        p.second.second -= orders;
                        ck[p.second.first] += orders;
                        if(p.second.second) {
                            Q.insert(p);
                        }
                        orders = 0;
                    }
                    else {
                        Customer_cost += p.second.second * cost[p.second.first];
                        orders -= p.second.second;
                        ck[p.second.first] = quantity[p.second.first];
                    }
                }
            }
            if(orders) cout << 0 << "\n";
            else cout << Customer_cost << "\n";
        }
        return 0;
}
int main() 
{
        FastIO;
        solve();
        return 0;
}