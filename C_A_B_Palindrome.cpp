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

string solve(ll a, ll b)
{
        string s;
        cin >> s;
        ll n = s.size()-1,  mid = s.size()/2;
        for(int i=0; i<mid; i++){
                if(s[i] != s[n-i] && (s[i] != '?' && s[n-i]!='?'))
                {
                        return "-1";
                }
                if(s[i] == '0' || s[n-i] == '0')
                {
                        if(a>=2) a -= 2;
                        else return "-1";
                        if(s[i] != '0') s[i] = '0';
                        if(s[n-i] != '0') s[n-i] = '0';
                }
                else if(s[i] == '1' || s[n-i] == '1')
                {
                        if(b>=2) b -= 2;
                        else return "-1";
                        if(s[i] != '1') s[i] = '1';
                        if(s[n-i] != '1') s[n-i] = '1';
                }
        }
        for(int i=0; i<mid ; i++){
                if(s[i] == '?')
                {
                        if(a>=2)
                        {
                                s[i] = '0';
                                s[n-i] = '0';
                                a -= 2;
                        }
                        else if(b >= 2)
                        {
                                s[i] = '1';
                                s[n-i] = '1';
                                b -= 2;
                        }
                        else return "-1";
                }
        }
        if(s.size()%2)
        {
                if(s[mid]=='?'){
                        if(a) { s[mid] = '0'; a--;}
                        else if(b) { s[mid] = '1'; b--;}
                        else return "-1";
                }
                
                else if(s[mid]=='0'){
                        if(a) a--;
                        else return "-1";
                }
                else if(s[mid]=='1'){
                        if(b) b--;
                        else return "-1";
                }
        }
        if(a || b) return "-1";
        return s;
}

int main()
{
        FastIO;
        TestCase
        {
                ll a, b;
                cin>> a >> b;
                cout << solve(a , b) <<"\n";
        }
        return 0;
}