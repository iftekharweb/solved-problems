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

const ld PI= 3.14159265358979323846264338327950288;  //2*acos(0.0);
const long long MOD= 1000000007;

using namespace std;
using namespace __gnu_pbds;
template<class T>using indexed_set=tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>;

vector<ll> b;

void myfunc(vector<ll>&a ,ll k, ll x, ll n)
{
        ll small=0, big=0; 
        for(int i=k; i<n; i++)
        {
            if(!small && !big && a[i]<=x)
            {
                small =1;
                x=a[i];
            }
            else if(!small && !big && a[i]>=x)
            {
                big=1;
                x=a[i];
            }
            if(small && a[i]>x)
            {
                b.pb(x);
                if(i==n-1) return;
                else {
                    myfunc(a, i, x, n);
                    break;
                }
            }
            else if(big && a[i]<x)
            {
                b.pb(x);
                if(i==n-1) return;
                else{
                    myfunc(a, i, x, n);
                    break;
                }
            }
            else x=a[i];
        }
}

int main()
{
        FastIO;
        TestCase
        {
            ll n;
            cin>>n;
            vector<ll> a(n);
            for(auto &x:a) cin>>x;
            b.pb(a[0]);
            myfunc(a,1,a[0], n);
            b.pb(a[n-1]);
            cout<<b.size()<<endl;
            printVector(b);
            b.clear();
        }
        return 0;
}