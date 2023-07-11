/*
                Bismillah Hirrahman Nirrahim 
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

inline ll vin() {
        ll x;
        cin >> x;
        return x;
}
void solve()
{
        ll  n , k;
        cin >> n >> k;
        vector< pair<ll,ll> > a;
        vector<vector<ll> > b(n);
        for(int i = 0; i < n ; i++) {
            ll x = vin();
            a.push_back({x , i});
        }
        sort(all(a));
        for(int i = 0; i < n; i++) {
            for(int j = 0, p = 1; j < a[i].first ; j++, p++) {
                if(p > k) p=1;
                b[a[i].second].push_back(p);
            }
        }
        ll d1 = a[0].first/k;
        ll d2 = a[n-1].first/k;
        ll r1 = a[0].first%k;
        ll r2 = a[n-1].first%k;
        if((d2 > d1+1) || ((d2 <= d1+1 && r2 > r1))) {
            cout << "NO" << endl;
            return;
        }
        cout << "YES" << endl;
        for(int i = 0; i < n; i++) {
            printVector(b[i]);
        }
        return ;
}
int main()
{
        FastIO;
        solve();
        return 0;
}