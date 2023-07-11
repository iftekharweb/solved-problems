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

string hh;

ll fact(ll n)
{
    if(n==0) return 1;
    else return n*fact((n-1));
}

void permutation(ll n,ll idx)
{
        if(idx==n)
        {
                cout<< hh <<endl;
                return;
        }
        for(int i=0; i<n; i++){
                hh[idx+i]='+';
                permutation(n,idx+i);
                hh[idx+i]='-';
        }
        return;
}

int main()
{
        //TxtTest;
        ll n, total=0,g=0,h=0,q=0;
        string a,b;
        cin>>a>>b;
        for(auto x:a){
                if(x=='+') total++;
                else total--;
        }
        for(auto x:b){
                if(x=='+') g++;
                else if(x=='-')g--;
                else q++;
        }
        permutation(q,0);
        for(int i=0; i<q; i++) a.pb('+');

        n= total-g;
        n=abs(n-0);
        if(abs(q-0)<abs(n-0)){
                cout<<points(12)<<0.0<<endl;
                return 0;
        }
        if(!q){
                cout<<points(12)<<1.0<<endl;
                return 0;
        }
        
        double x = fact(q)/(  (   fact(n+(q-n)/2) *  fact((q-n)/2)   ));
        //cout<< pow(2,q)<<endl;
        cout<< points(12) <<  (double)pow(2,q)/x <<endl;;
        return 0;
}