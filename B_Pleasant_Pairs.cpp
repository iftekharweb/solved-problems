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

vector<ll> mm[1000001];

void all_divisors(ll n)
{
    for(int i=1; i<=n; i++) {
        for(int j=i; j<=n ; j+=i) {
            mm[j].push_back(i);
        }
    }
}

int main()
{
        FastIO;
        all_divisors(100001);
        TestCase {
            ll n, ans=0;
            cin>> n;
            vector<ll> a(n);
            map<ll,ll> getVal, getIdx;
            for(int i=1; i<=n ; i++) {
                cin >> a[i];
                getVal[i] = a[i];
                getIdx[a[i]] = i; 
            }
            sort(all(a));
            for(int i = 3 ; i<= n+n-1; i++) {
                for(int j=0, k=mm[i].size()-1; j<=k; j++,k--) {
                    if(getIdx[mm[i][j]] && getIdx[mm[i][k]]) {
                        if(getIdx[mm[i][j]]+getIdx[mm[i][k]] == mm[i][j]*mm[i][k]) ans++;
                    }
                }
            }
            cout << ans <<"\n";
        }
        return 0;
}