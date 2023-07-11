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
#define LCM(a,b)  (a*b)/__gcd(a, b)
#define TestCase   ll t;cin>>t;while(t--)
#define points(x)   fixed<<setprecision(x)
#define pr(x)  cerr << #x << " = " << x << endl;
#define nl  cout<<"\n";

const ld PI= 3.14159265358979323846264338327950288;  //2*acos(0.0);
const long long MOD= 1000000007;

using namespace std;
using namespace __gnu_pbds;
template<class T>using indexed_set=tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>;

inline ll vin() {ll x;cin >> x;return x;}
ll POW(ll a, ll b) {ll res = 1;while(b){if(b%2)res=(res*a)%MOD;a = (a*a)%MOD; b/=2;}return res;}
vector<ll> DIGITS(ll n){vector<ll>a;while (n)a.push_back(n%10),n/=10;return a;}

void solve()
{
        ll n = vin() ,  k = vin() , edges = n-1;
        vector<ll> a(k+1), mark(n+1,0);

        for(int i=1; i<=k; i++) {
            a[i] = vin();
            mark[a[i]] = 1;
        }

        vector<ll> mm[n+1] , leaf_dis(n+1,0) , mark_leaf(n+1,0), mainLeaf, mainDis(n+1,MOD);
        while (edges--)
        {       
            ll u = vin();
            ll v = vin();
            mm[u].push_back(v);
            mm[v].push_back(u);
        }
        for(int i=2; i<=n; i++) {
            if(mm[i].size()==1 && !mark[i]) {
                mark_leaf[i] = 1;
            }
        }

        vector<ll> vis(n+1,0);
        for(int i=0;i<=n; i++) vis[i] = mark[i];
        queue<ll> Q;
        Q.push(1);
        while (!Q.empty())
        {
            ll v = Q.front();
            vis[v] = 1;
            Q.pop();
            for(auto x:mm[v]) {
                if(!vis[x]) {
                    leaf_dis[x] = leaf_dis[v]+1;
                    if(mark_leaf[x]) mainLeaf.push_back(x);
                    Q.push(x);
                }
            }
        }
        //printVector(mainLeaf);
        for(int i=0; i<mainLeaf.size(); i++) {
            ll cc = -1;
            fill(all(vis),0);
            vector<ll> tmp_dis(n+1);
            tmp_dis[mainLeaf[i]] = 0;
            queue<ll> QQ;
            QQ.push(mainLeaf[i]);
            while (!QQ.empty())
            {
                ll v = QQ.front();
                vis[v] = 1;
                QQ.pop();
                for(auto x:mm[v]) {
                    if(!vis[x]) {
                        tmp_dis[x] = tmp_dis[v]+1;
                        if(mark[x]) mainDis[mainLeaf[i]] = min(mainDis[mainLeaf[i]],tmp_dis[x]);
                        QQ.push(x);
                    }
                }
            }
        }
        for(auto x:mainLeaf) {
            if(mainDis[x]>leaf_dis[x]) {
                cout << "YES"; nl;
                return;
            }
        }
        cout << "NO"; nl;
        return;
        // -------------------
        for(int i=1; i<=k; i++) {
            ll cc = -1;
            fill(all(vis),0);
            vector<ll> tmp_dis(n+1);
            tmp_dis[a[i]] = 0;
            queue<ll> QQ;
            QQ.push(a[i]);
            while (!QQ.empty())
            {
                ll v = QQ.front();
                vis[v] = 1;
                QQ.pop();
                for(auto x:mm[v]) {
                    if(!vis[x]) {
                        tmp_dis[x] = tmp_dis[v]+1;
                        QQ.push(x);
                    }
                }
            }
            //printVector(tmp_dis);
            cc = 0;
            for(auto x:mainLeaf) {
                mainDis[x] = min(mainDis[x],tmp_dis[x]);
            }
        }
        //printVector(mainDis);
        //printVector(leaf_dis);
        for(auto x:mainLeaf) {
            if(mainDis[x]>leaf_dis[x]) {
                cout << "YES" << endl;
                return;
            }
        }
        cout << "NO" << endl;
        return ;
}
int main() 
{
        FastIO;
        TestCase {
            //cout << solve() << endl;
            solve();
        }
        return 0;
}