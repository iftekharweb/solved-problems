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
string solve()
{
        ll n  = vin(), ff = 0, ss = 0;
        vector<ll> arr(n);
        vector<ll> a,b;
        for(int i=0; i<n; i++) {
            cin >> arr[i];
            if(arr[i] > 0) {
                a.push_back(arr[i]);
                ff += arr[i];
            }
            else {
                b.push_back(-1*arr[i]);
                ss += arr[i]*(-1);
            }
        }
        // printVector(a);
        // printVector(b);
        // pr(ff); pr(ss);
        if(ff != ss) {
            if(ff>ss) return "first";
            else return "second";
        }
        for(int i=0; i<min(a.size(),b.size()) ; i++) {
            if(a[i]>b[i]) return "first";
            if(a[i]<b[i]) return "second";
        }
        if(a.size() != b.size()) {
            if(a.size() > b.size()) return "first";
            else return "second";
        }
        if(arr[n-1] > 0) return "first";
        return "second";
}
int main()
{
        FastIO;
        cout << solve() << endl;
        return 0;
}