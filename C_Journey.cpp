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
#define nl cout<<endl;

const ld PI= 3.14159265358979323846264338327950288;  //2*acos(0.0);
const long long MOD= 1000000007;

using namespace std;
using namespace __gnu_pbds;
template<class T>using indexed_set=tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>;

map<ll, vector<ll> > mm;
map<ll,ll> mark, leafdis, child;
map<ll, double> probability;
vector<ll> leaf;

void dfsAgain(ll n)
{
    mark[n]  = 1;
    for(int i = 0; i < mm[n].size(); i++) {
        if(!mark[mm[n][i]]) {
            probability[mm[n][i]] = (probability[n] / (child[n] * 1.0) );
            dfsAgain(mm[n][i]);
        }
    }
}

void dfs(ll n, ll dis, ll flag)
{
    mark[n] = 1;
    dis++;
    for(int i = 0; i < mm[n].size(); i++) {
            if(!mark[mm[n][i]]) {
                child[n]++;
                flag=1;
                dfs(mm[n][i], dis, 0);
            }
    }
    if(!flag){
            leaf.push_back(n);
            leafdis[n] = dis - 1;
    }
    return;
}

int main()
{
        FastIO;
        ll n , u, v;
        cin>> n;
        ll e = n-1;
        while(e--)
        {
            cin >> u >> v;
            mm[u].push_back(v);
            mm[v].push_back(u);
        }
        probability[1]=1.0;
        dfs(1, 0, 0);


        mark.clear();
        dfsAgain(1);
        double ans = 0.0;
        for(auto x : leaf) {
            ans += probability[x]*leafdis[x];
        }

        cout << points(15) << ans << "\n";
        return 0;
}