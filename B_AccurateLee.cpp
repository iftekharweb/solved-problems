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


int main()
{
        FastIO;
        TestCase
        {
                ll n, flag = 0, one=0, first0=0, first1=0;
                cin>>n;
                string a;
                cin>>a;
                for(auto ch:a)
                {
                         if(ch=='0') first0=1;
                         else if(ch=='1') first1=1;
                }
                if(!first1 || !first0)
                {
                        cout<< a <<endl;
                        continue;
                }
                first1=first0=-1;
                if(a[0]=='0') for(int i=0; i<n-1; i++){
                        if(a[i]=='0' && a[i+1]=='1') {
                                first0=i;
                                break;
                        }
                }
                if(a[n-1]=='1') for(int i=n-1; i>0; i--){
                        if(a[i]=='1' && a[i-1]=='0'){
                                first1=i;
                                break;
                        }
                }
                if(first1-first0==1)
                {
                        cout<< a <<endl;
                        continue;
                }
                if(first1==-1 && first0==-1){
                        cout<<'0'<<endl;
                        continue;
                }
                if(first0!=-1)
                {
                        for(int i=0; i<=first0; i++) cout<<"0";
                }
                for(int i=first0+1; i<n-1;i++) if(a[i]=='1' && a[i+1]=='0'){
                        cout<<'0';
                        break;
                }
                if(first1!=-1)for(int i=first1+1; i<=n; i++) cout<<"1";
                cout<< endl;
        }
        return 0;
}