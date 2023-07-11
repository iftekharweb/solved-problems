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
#define printArray(i,a,n)  f(i,n)cout<<a[i]<<" "; cout<<endl;
#define printSet(a)  for(auto setData:a) cout<<setData<<" ";cout<<endl;
#define printMap(a)  for(auto mapData:a) cout<<mapData.first<<" "<<mapData.second<<endl;
#define printVector(a)  for(auto vectorData:a)cout<<vectorData<<" ";cout<<endl;
#define printLinkedList()  temp=head;while(temp){cout<<temp->data<<" ";temp=temp->post;} cout<<endl;

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

double binarySearch(ll h,ll c, ll t)
{
        ll lb=1, ub=10000001, mid=0;
        double n=t*1.0;
        ll ans=0, cnt=0;
        long double test;
        ub--;
        while (lb<=ub)
        {
                ll mid=lb+(ub-lb)/2;
                test = (mid*h+mid*c+h)/(mid*2.0+1.0);
                if(test<=n){
                        ub=mid-1;
                        ans=mid;
                        cnt++;
                }
                else {
                        lb=mid+1;
                        ans=mid;
                        if(!cnt) return 2;
                }
        }
        ll r,l;
        if(ans-10>0) l=ans-10;
        else l=1;
        r=ans+10;
        double mi = abs((ans*h+ans*c+h)/(ans*2.0+1.0)-n);
        double okkk = h-n;
        for(int i=l; i<r; i++){
                if(abs( (i*h+i*c+h) / (i*2.0+1.0) - n)<mi){
                        mi = abs( (i*h+i*c+h) / (i*2.0+1.0) - n);
                        ans=i;
                }
        }
        if(okkk>mi)ans=ans*2+1;
        else ans = 1;
        return ans;
}

int main()
{
        //TxtTest;
        FastIO;
        TestCase
        {
                double h,c,t;
                cin>>h>>c>>t;
                if((h+c)/2.0==t ){
                        cout<< 2 <<endl;
                        continue;
                }
                if(h==t){
                        cout<<1<<endl;
                        continue;
                }
                ll hh=h, cc=c, tt=t;
                ll ans = binarySearch(h,c,t);
                cout<< ans <<endl;
        }
        return 0;
}