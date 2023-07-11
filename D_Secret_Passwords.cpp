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

map<char, vector<char> > mm;
map<char, ll> mark;

void dfs(char ch)
{
        mark[ch]=1;
        for(int i=0; i<mm[ch].size(); i++)
        {
                if(!mark[mm[ch][i]]){
                        dfs(mm[ch][i]);
                }
        }
}

int main()
{
        FastIO;
        ll n, res=0;
        string op;
        map<char,ll> ok;
        cin>>n;
        while(n--)
        {
                string a;
                cin>>a;
                set<char> st(all(a));
                vector<char> tmp(all(st));
                if(tmp.size()==1) if(!ok[tmp[0]])
                {
                        op.push_back(tmp[0]);
                        ok[tmp[0]]=1;
                }
                for(int i=0; i<tmp.size()-1; i++)
                {
                        if(!ok[tmp[i]]){
                                op.push_back(tmp[i]);
                                ok[tmp[i]]=1;
                        }
                        if(!ok[tmp[i+1]])
                        {
                                op.push_back(tmp[i+1]);
                                ok[tmp[i+1]]=1;
                        }
                        mm[tmp[i]].push_back(tmp[i+1]);
                        mm[tmp[i+1]].push_back(tmp[i]);
                }
        }
        for(int i=0; i<=op.size(); i++)
        {
                if(!mark[op[i]])
                {
                        res++;
                        dfs(op[i]);
                }
        }
        cout<< res-1 <<endl;
        return 0;
}