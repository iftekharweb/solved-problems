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

map<ll, set<ll> > mm;
map<ll,ll> mark; 
ll cnt=0, fg=0, tmp;
vector<ll> a;

void dfs(ll n)
{
        mark[n]=1;
        //if(!cnt) tmp = n;
        a.push_back(n);
        for(auto x:mm[n])
        {
                if(!mark[x])
                {
                        if(!cnt) tmp = n;
                        cnt++;
                        if(cnt==2)
                        {
                                cnt=0;
                                if(mm[x].find(tmp)==mm[x].end()) fg=1;
                        }
                        dfs(x);
                }
        }
        cnt=0;
        return;
}

int main()
{
        FastIO;
        ll n, m, u, v;
        cin>> n>>m;
        while(m--)
        {
                cin>>u>>v;
                mm[u].insert(v);
                mm[v].insert(u);
        }
        for(int i=1; i<=n; i++)
        {
                if(!mark[i])
                {
                        dfs(i);
                        cnt=0;
                        if(a.size()<=2)
                        {
                                a.clear();
                                continue;
                        }
                        for(auto x:a) if(mm[x].size()<2) fg=1;
                        if(fg)
                        {
                                cout<< "NO" <<endl;
                                return 0;
                        }
                        a.clear();
                }
        }
        cout<< "YES" <<endl;
        return 0;
}