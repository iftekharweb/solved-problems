/*
                IftekharMd.Shishir
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

#define pb(x)  push_back(x)
#define all(a)  a.begin(),a.end()
#define rall(a)  a.rbegin(),a.rend()
#define stringToInt(str,x)   stringstream demo(str); demo >> x;
#define intToSting(x,get)   stringstream demu; demu << x; get = demu.str();

#define TxtIO   freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#define TxtTest   freopen("C:/Users/Iftekhar/Documents/what/input.txt", "r", stdin);
#define FastIO   ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
#define TestCase   ll t;cin>>t;while(t--)
#define points(x)   fixed<<setprecision(x)
#define pr(x) cerr << #x << " = " << x << endl;
#define nl cout<< "\n";

const ld PI= 3.14159265358979323846264338327950288;  //2*acos(0.0);
const long long MOD= 1000000007;

using namespace std;
using namespace __gnu_pbds;
template<class T>using indexed_set=tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>;

vector<ll> mm[1000001];
ll mark[1000001], cc[1000001];

void using_dfs(ll n, ll i)
{
    mark[n] = 1;
    cc[n] = i;
    for(auto x:mm[n]) {
        if(!mark[x]) {
            using_dfs(x, i);
        }
    }
}

int main()
{
        FastIO;
        TestCase {
            ll n , m, u, v;
            string STR;
            vector< pair<ll,ll> > V;
            cin >> n >> m;
            for(int i = 1 ; i <= n ; i++) {
                mm[i].clear();
                mark[i] = 0;
            }
            while(m--) {
                cin >> u >> STR >> v;
                if(STR == "=") {
                    mm[u].push_back(v);
                    mm[v].push_back(u);
                }
                else {
                    V.push_back(make_pair(u , v));
                }
            }
            for(int i = 1; i <= n;  i++) {
                if(!mark[i]) {
                    using_dfs(i, i);
                }
            }
            bool flag = false;
            for(int i = 0; i < V.size(); i++) {
                ll p = V[i].first , q = V[i].second ;
                if(cc[p] == cc[q]) flag = true;
            }
            if(flag) cout << "NO" << "\n";
            else cout << "YES" << "\n";
        }
        return 0;
}