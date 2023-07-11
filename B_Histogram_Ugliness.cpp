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


int main()
{
        FastIO;
        TestCase
        {
                ll n, sum=0;
                cin>>n;
                vector<ll> a(n), price(n);
                for(auto &x:a) cin>>x;
                if(n==1)
                {
                        cout<< a[0] <<endl;
                        continue;
                }
                for(int i=0; i<n; i++)
                {
                        if(i==0){
                                sum+=a[i];
                                continue;
                        }   
                        if(a[i]>a[i-1]) sum+=a[i]-a[i-1];
                        else sum+=a[i-1]-a[i];
                }
                sum+=a[n-1];
                ll pp=sum;
                if(a[0]>a[1])
                {
                        ll x = a[0]-a[1];
                        a[0] = a[1];
                        pp += x;
                        pp -= (x*2);
                        price[0] = pp;
                }
                else price[0] = pp;
                for(int i=1; i<n-1; i++)
                {
                        if(a[i]>a[i+1] && a[i]>a[i-1])
                        {
                                ll big = max(a[i-1], a[i+1]);
                                ll x = a[i]-big;
                                a[i]=big;
                                pp+=x;
                                pp-=(x*2);
                                price[i]=pp;
                        }
                        else price[i] = pp;
                }
                if(a[n-1]>a[n-2])
                {
                        ll x=a[n-1]-a[n-2];
                        a[n-1]=a[n-2];
                        pp+=x;
                        pp-=(x*2);
                        price[n-1]=pp;
                }
                else price[n-1]=pp;

                sort(all(price));
                cout<< price[0] <<endl;
        }
        return 0;
}