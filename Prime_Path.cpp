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
map<ll,ll> mark, dis;
vector<ll> primes;

void usingBFS(ll n)
{
    queue< ll > Q;
    Q.push(n);
    mark[n] = 1;
    while( !Q.empty() ) {
        ll now = Q.front();
        Q.pop();
        for( auto x : mm[now]) {
            if(mark[x] == -1) {
                dis[x] = dis[now] +1; 
                Q.push(x);
                mark[x] = 1;
            }
        }
    }
    return ;
}
bool is_valid(ll a, ll b)
{
        ll cnt = 0;
        while(a > 0) {
            if(a%10 != b%10) cnt ++;
            a /= 10;
            b /= 10;
        }
        if( cnt == 1) return true;
        else return false ;
}
bool is_prime(ll n)
{
    for( int i = 2; i*i <= n; i++) {
        if(n % i == 0) return false;
    }
    return true;
}
void build_graph()
{
        for( int i = 1000; i <= 9999; i++ ) {
                if(is_prime(i)) {
                    primes.push_back(i);
                }
        }
        for(int i = 0; i < primes.size() - 1 ; i++ ) {
            for(int j = i + 1 ; j < primes.size() ; j++) {
                ll u = primes[i], v = primes[j] ;
                if( is_valid( u , v )) {
                    mm[u].push_back(v);
                    mm[v].push_back(u);
                }
            }
        }
        return;
}

int main()
{
        FastIO;
        ll n , u , v;
        build_graph();
        cin >> n;
        for(int i = 0; i < n ; i++) {
            cin >> u >> v;
            for(int j = 1000 ; j <= 9999 ; j++) mark[j] =  -1;
            usingBFS(u);
            if(mark[v] == -1) {
                cout << "impossible" << "\n";
            }
            else cout << dis[v] << "\n";
            dis.clear();
        }
        return 0;
}