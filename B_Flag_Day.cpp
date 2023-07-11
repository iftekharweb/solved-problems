/*
                بِسْمِ ٱللَّٰهِ ٱلرَّحْمَٰنِ ٱلرَّحِيمِ
                Iftekhar Md. Shishir
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
#define printQueue(Q)  while(!Q.empty()) cout<< Q.front()<<" ",Q.pop(); cout<<"\n";

#define all(a)  a.begin(),a.end()
#define rall(a)  a.rbegin(),a.rend()
#define stringToInt(a,x)   stringstream demo(a); demo >> x;
#define intToSting(x,s)   stringstream demu; demu << x; a = demu.str();

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

inline ll vin() {ll x;cin >> x;return x;}

map<ll,vector<ll> > bf;
map<ll,ll> mark;
map<ll,vector<ll> > mp;
ll color = 0;

void bfs(ll n)
{
        mark[n] = 1;
        queue<ll> Q;
        Q.push(n);
        while (!Q.empty())
        {
            ll x = Q.front();
            Q.pop();
            for(int i=0; i<3; i++) if(!mp[x][i]) {
                color = i+1;
                break;
            }
            for(int i=0; i<bf[x].size(); i++) {
                mp[bf[x][i]][color-1] = 1;
                if(!mark[bf[x][i]])
                {
                    Q.push(bf[x][i]);
                    mark[bf[x][i]] = 1;
                }
            }
        }
        return;
}

void solve()
{
        ll n = vin() , m = vin();
        vector<ll> mm(n+1,0);
        while (m--)
        {
            ll x, y, z;
            cin >> x >> y >> z;
            bf[x].push_back(y);
            bf[y].push_back(x);
            bf[y].push_back(z);
            bf[z].push_back(y);
            bf[x].push_back(z);
            bf[z].push_back(x);
        }
        for(int i=1; i<= n; i++) {
            for(int j=0; j<3; j++) mp[i].push_back(0);
        }
        for(int i=1; i<=n; i++) {
            if(!mark[i]) {
                color = 1;
                bfs(i);
            }
        }
        for(int i=1; i<= n; i++) {
            for(int j=0; j<3; j++) {
                if(!mp[i][j]) {
                    cout << j+1 << " ";
                }
            }
        }
        cout << endl;
        return;
}
int main()
{
        FastIO;
        solve();
        return 0;
}