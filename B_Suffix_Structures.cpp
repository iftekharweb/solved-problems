/*
                Bismillah Hirrahman Nirrahim 
                Iftekhar Md. Shishir
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
#define printQueue(Q)  while(!Q.empty()) cout<< Q.front()<<" ",Q.pop(); cout<<"\n";

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

inline ll vin() {
        ll x;
        cin >> x;
        return x;
}
string solve()
{
        bool flag = false;
        string a , b;
        cin >> a >> b;
        map<char, ll> An, Bn;
        for(int i=0; i<a.size(); i++) An[a[i]]++;
        for(int i=0; i<b.size(); i++) Bn[b[i]]++;
        for(int i=0; i<b.size(); i++) {
            if(!An[b[i]] || (Bn[b[i]]>An[b[i]])) return "need tree";
        }
        if(a.size() == b.size())
        {
            for(int i=0; i<b.size(); i++) {
                if(An[b[i]]!=Bn[b[i]]) {
                    flag = true;
                    break;
                }
            }
            if(!flag) return "array";
        }
        ll cnt = 0;
        for(int i=0, j=0; i<b.size();)
        {
            if(b[i]!=a[j]) j++;
            else {
                i++;
                j++;
                cnt++;
                if(j>=a.size()) break;
            }
        }
        if(cnt==b.size()) return "automaton";
        return "both";
}
int main()
{
        FastIO;
        cout << solve() << endl;
        return 0;
}