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

void myfunc(ll n, ll w)
{
        ll idx=-1, fw=(w+1)/2, sum=0, fg=0, x;
        vector< pair<ll,ll> > a;
        for(int i=1; i<=n; i++)
        {
                cin>> x;
                a.push_back( make_pair(x, i) );
        }
        sort(all(a));
        for(int i=n-1; i>=0; i--)
        {
                if(a[i].first<=w){
                        idx = i;
                        break;
                }
        }
        if(idx==-1){
                cout<< idx <<endl;
                return;
        }

        for(int i=idx; i>=0; i--)
        {
                if(a[i].first >= fw && a[i].first <= w) {
                        cout<< 1 <<endl;
                        cout<< a[i].second <<endl;
                        return;
                }
                if(a[i].first <fw)
                {
                        idx=i;
                        fg=1;
                        break;
                }
        }
        vector<ll> ok;
        for(int i=0; i<=idx; i++)
        {
                sum+= a[i].first;
                ok.pb(a[i].second);
                if(sum>=fw && sum<=w)
                {
                        cout<< ok.size() <<endl;
                        printVector(ok);
                        return;
                }
        }
        cout<< -1 <<endl;
        return;
}

int main()
{
        FastIO;
        TestCase
        {
                ll n, w, x, idx=-1, fw;
                cin >> n >> w;
                myfunc(n, w);
                continue;
        }
        return 0;
}