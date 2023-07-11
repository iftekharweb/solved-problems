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

void solve(ll n, ll a, ll b)
{
        string s;
        cin >> s;
        ll zeroSub = 0, oneSub = 0;
        s.push_back('#');
        for(int i=0; i<n; i++)
        {
                if(s[i]=='0' && (s[i+1]=='1' || s[i+1] == '#')) zeroSub++;
        }
        for(int i=0; i<n; i++)
        {
                if(s[i]=='1' && (s[i+1]=='0' || s[i+1] == '#')) oneSub++;
        }
        ll ans1 = n*(a+b);
        ll ans2 = a*n+ (min(zeroSub,oneSub)+1)*b;
        cout<< max(ans1,ans2) <<endl;
        return ;
}

int main()
{
        FastIO;
        TestCase
        {
            ll n , a , b;
            cin >> n >> a >> b;
            solve(n,a,b);
        }
        return 0;
}