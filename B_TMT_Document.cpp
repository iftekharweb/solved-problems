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
                ll n, cnt=0, cntt=0, flag =0, firstM=-1, lastM=-1, cntM=0, cntT=0;
                string a;
                cin>> n >> a;
                for(int i=0; i<n; i++) {
                        if(a[i]=='T') cntT++;
                        else cntM++;
                }
                for(int i=0; i<n; i++) if(a[i]=='M'){
                        firstM=i;
                        break;
                }
                for(int i=n-1; i>=0; i--) if(a[i]=='M'){
                        lastM=i;
                        break;
                }
                if(firstM ==-1 || cntT!=2*cntM) { cout<<"NO"<<endl; continue; }
                for(int i=0; i<=lastM; i++)
                {
                        if(a[i]=='T')cnt++;
                        if(a[i]=='M') 
                        {
                                if(!cnt)
                                {
                                        flag = 1;
                                        break;
                                }
                                cnt--;
                        }
                }
                if(flag) { cout<<"NO"<<endl; continue; }
                flag=0;
                for(int i=n-1; i>=firstM; i--)
                {
                        if(a[i]=='T') cntt++;
                        if(a[i]=='M') 
                        {
                                if(!cntt)
                                {
                                        flag=1;
                                        break;
                                }
                                cntt--;
                        }
                }
                if(flag) { cout<<"NO"<<endl; continue; }
                cout<<"YES"<<endl;
        }
        return 0;
}