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

map<ll, vector<ll> > ar;
map<ll,ll> ck, color;

bool dfs(ll n, ll c)
{
        ck[n]=1;
        color[n]=c;
        for(int i=0; i<ar[n].size(); i++)
        {
                if(ck[ar[n][i]])
                {
                        if(color[ar[n][i]]==color[n]) return false;
                }
                else 
                {
                        if(color[n]==1)
                        {
                                if(dfs(ar[n][i], 2)==false) return false;
                        }
                        else
                        {
                                if(dfs(ar[n][i], 1)==false) return false;
                        }
                }
        }
        return true;
}

int main()
{
        FastIO;
        ll I=0;
        TestCase
        {
                I++;
                ar.clear(); ck.clear(); color.clear();
                ll n, e, u, v, fg=0;
                cin>> n >> e;
                while(e--)
                {
                        cin>> u >> v;
                        ar[u].pb(v);
                        ar[v].pb(u);
                }
                for(int i=1; i<=n; i++)
                {
                        if(!ck[i])
                        {
                                if(dfs(i, 1)==false)
                                {
                                        cout<< "Scenario #" << I << ":" <<endl;
                                        cout<< "Suspicious bugs found!" <<endl;
                                        fg=1;
                                        break;
                                }
                        }
                }
                if(fg) continue;
                cout<< "Scenario #" << I << ":" <<endl;
                cout<< "No suspicious bugs found!" <<endl;
        }
        return 0;
}