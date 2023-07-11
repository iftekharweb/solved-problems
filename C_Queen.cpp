/*
             ...Bismillah Hirrahman Nirrahim...
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
#define printQueue(Q)  while(!Q.empty()) cout<< Q.front()<<" ",Q.pop(); cout<<"\n";

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

vector<ll> mm[100001], del;
bool vis[100001];
ll c[100001];
ll root;

void coloBismillah(ll n)
{
        queue<ll> Q;
        Q.push(n);
        vis[n] = true;
        while(!Q.empty())
        {
                ll current = Q.front();
                Q.pop();
                ll cnt = 0, child = 0;
                for(auto x:mm[current])
                {
                        if(!vis[x])
                        {
                                Q.push(x);
                                vis[x] = true;
                                if( c[x] == 1) cnt++;
                                child++;
                        }
                }
                if(c[current] == 1 && cnt == child) del.push_back(current);
        }
        return;
}

int main()
{
        FastIO;
        ll n, x, y;
        cin >> n;
        for(int i=1; i<=n; i++)
        {
                cin >> x >> y;
                if(x == -1) root = i;
                else
                {
                        mm[i].push_back(x);
                        mm[x].push_back(i);
                }
                c[i] = y;
        }
        coloBismillah(root);
        sort(all(del));
        if(!del.size()) cout << -1 << endl;
        else printVector(del);
        return 0;
}