/*
                بِسْمِ ٱللَّٰهِ ٱلرَّحْمَٰنِ ٱلرَّحِيمِ
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

#define all(a)  a.begin(),a.end()
#define rall(a)  a.rbegin(),a.rend()
#define stringToInt(a,x)   stringstream demo(a); demo >> x;
#define intToSting(x,s)   stringstream demu; demu << x; a = demu.str();

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

inline ll vin() {ll x;cin >> x;return x;}

string solve()
{
        ll n;
        string a;
        char c;
        cin >> a >> c;
        for(int i=0; i<a.size(); i++){
            if(a[i]==c && (i+1)%2) return "YES";
        }
        return "NO";
        vector<ll> b;
        for(int i=0; i<a.size(); i++)
        {
            if(a[i]==c) b.push_back(i+1);
        }
        if(!b.size()) return "NO";
        ll x = a.size()-1;
        ll y = 2;
        ll flag = 0;
        for(int i=0; i<b.size(); i++) {
            if(b[i]!=x && b[i]!=y) {
                flag = 1;
                break;
            }
        }
        printVector(b);
        if(flag) return "YES";
        return "NO";
}
int main() 
{
        FastIO;
        TestCase {
            cout << solve() << endl;
            // solve();
        }
        return 0;
}