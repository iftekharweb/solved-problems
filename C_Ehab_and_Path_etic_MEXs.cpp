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

map< ll, vector<ll> > mm;
map< pair<ll,ll> , ll > ok;
queue<ll> Q;
map< ll , ll > mark;
ll  r ;

void cng(ll n) { r = n - 1; }

void bfs(ll n)
{
    mark[n] = 1; 
    while( !Q.empty() ) {
        ll x = Q.front();
        Q.pop();
        for(auto cc : mm[x]) {
            if(!mark[cc]) {
                Q.push(cc);
                mark[cc] = 1;
                ll mx = max(cc , x), mi = min(cc , x);
                if(!ok[make_pair(mi , mx)]) {
                    ok[make_pair(mi , mx)] = r;
                    r--;
                }
            }
        }
    }
}

int main()
{
    FastIO;
    ll e , u, v, n;
    vector< pair <ll,ll> > vect;
    cin >> n;
    cng(n);
    e = n-1;
    while( e-- )
    {
        cin >> u >> v;
        ll mx = max(u,v), mi = min(u,v);
        vect.push_back(make_pair(mi , mx));
        mm[u].push_back(v);
        mm[v].push_back(u);
    }
    ll ops = 0;
    for(ll i = 1; i <= n; i++)
    {
        if(mm[i].size()>=3)
        {
            ll p = 1 , k = 1;
            ops = 1;
            for(auto x : mm[i])
            {
                if(p>3) break;
                ll mx = max(i, x), mi = min(i, x);
                ok[make_pair(mi , mx)] = k;
                p++;
                k++;
            }
            break;
        }
    }
    Q.push(1);
    bfs(1);
    for(int i = 0; i< n-1 ; i++)
    {
        cout << ok[make_pair(vect[i].first, vect[i].second)] - 1 << "\n";
    }
    return 0;
}