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

map<ll, vector<ll> > mm;
map<ll,ll> mark;
ll res = 0, node = 0;
/*
void dfs(ll  n)
{
    mark[n] = 1;
    while(!mm[n].empty())
    {
        if(!mark[mm[n].front()]) {
            if(mm[mm[n].front()].size() == 2) {
                mm[mm[n].front()].pop();
                res++;
                dfs(mm[mm[n].front()].front());
            } 
            else {
                dfs(mm[mm[n].front()].front());
            }
        }
        mm[n].pop();
    }
    return ;
}
*/

void dfs(ll n)
{
    mark[n] = 1;
    node++;
    for(auto x : mm[n]) {
        if(!mark[x]) dfs(x);
    }
    return;
}

int main()
{
        FastIO;
        ll n , e , u , v;
        cin >> n;
        e = n - 1;
        while (e--)
        {
            cin >> u >> v;
            mm[u].push_back(v);
            mm[v].push_back(u);
        }
        if(n%2) {
            cout << -1 << "\n";
            return 0;
        }
        vector<ll> ke;
        for(int i = 1 ; i <= n; i++ ) {
            if(mm[n].size()>=3)
            {
                for(auto x : mm[n]) {
                    if(mm[x].size()%2) ke.push_back(x);
                }
                mm[n].clear();
                mm[n] = ke;
                ke.clear();
            }
        }
        dfs(1);
        cout << node/2 << "\n";
        return 0;
}