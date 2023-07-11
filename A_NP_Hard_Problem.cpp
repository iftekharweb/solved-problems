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

map<ll, vector<ll> > mm, ok;
map<ll, ll> mark, color;

bool dfs(ll n, ll c)
{
        mark[n]=1;
        color[n]=c;
        ok[c].push_back(n);
        for(int i=0; i<mm[n].size(); i++)
        {
                if(mark[mm[n][i]])
                {
                        if(color[mm[n][i]]==color[n]) return false;
                }
                else
                {
                        if(color[n]==1)
                        {
                                if(dfs(mm[n][i], 2)==false) return false;
                        }
                        else if(color[n]==2)
                        {
                                if(dfs(mm[n][i], 1)==false) return false;
                        }
                }
        }
        return true;
}
int main()
{
        FastIO;
        ll n, m, u , v;
        cin >> n >> m;
        while(m--)
        {
                cin>> u >> v;
                mm[u].push_back(v);
                mm[v].push_back(u);
        }
        for(int i=1; i<=n; i++)
        {
                if(!mm[i].size()) continue;
                if(!mark[i] && mm[i].size())
                {
                        bool x = dfs(i,1);
                        if(!x){
                                cout<< -1 <<endl;
                                return 0;
                        }

                }
        }
        for(int j=1; j<=2; j++)
        {
                cout<< ok[j].size() <<endl;
                for(auto x:ok[j]) cout<< x <<" ";
                nl;
        }
        return 0;
}