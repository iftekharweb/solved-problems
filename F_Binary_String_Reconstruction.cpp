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
#define nl cout<<endl;

const ld PI= 3.14159265358979323846264338327950288;  //2*acos(0.0);
const long long MOD= 1000000007;

using namespace std;
using namespace __gnu_pbds;
template<class T>using indexed_set=tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>;

string func()
{
    ll a , b , c;
    string s = "";
    cin >> a >> b >> c;
    if(a && b && c)
    {
        for(int i = 0; i < a+1 ; i++) s += "0";
        for(int i = 0; i < c+1 ; i++) s += "1";
        if(b % 2) {
            b--;
            for(int i = 1; i <= b/2 ; i++) s += "01";
        }
        else {
            b--;
            for(int i = 1; i <= b/2 ; i++) s += "01";
            s += "0";
        }
    }
    else if(a && !b && !c) {
        for(int i = 0; i < a+1 ; i++) s += "0";
    }
    else if(!a && b && !c) {
        if(b % 2) {
            s += "1";
            for(int i = 1; i <= b/2 ; i++) s += "01";
            s += "0";
        }
        else {
            s += "1";
            for(int i = 1; i <= b/2 ; i++) s += "01";
        }
    }
    else if(!a && !b && c) {
        for(int i = 0; i < c+1 ; i++) s += "1";
    }

    else if(a && b && !c) {
        for(int i = 0; i < a+1 ; i++) s += "0";
        if(b % 2) {
            s += "1";
            b--;
            for(int i = 1; i <= b/2 ; i++) s += "01";
        }
        else {
            s += "1";
            b--;
            for(int i = 1; i <= b/2 ; i++) s += "01";
            s += "0";
        }
    }
    else if(!a && b && c) {
        if(b % 2) {
            s += "0";
            for(int i = 0; i < c+1 ; i++) s += "1";
            b--;
            for(int i = 1; i <= b/2 ; i++) s += "01";
        }
        else
        {
            for(int i = 0; i < c+1 ; i++) s += "1";
            for(int i = 1; i <= b/2 ; i++) s += "01";
        }
    }
    return s;
}

int main()
{
        FastIO;
        ll n;
        cin >> n ;
        while( n-- )
        {
            cout << func() << "\n" ;
        }
        return 0;
}