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
#define LCM(a,b)  (a*b)/__gcd(a, b)
#define TestCase   ll t;cin>>t;while(t--)
#define points(x)   fixed<<setprecision(x)
#define pr(x)  cerr << #x << " = " << x << endl;
#define nl  cout<<"\n";

const ld PI= 3.14159265358979323846264338327950288;  //2*acos(0.0);
const long long MOD = 1000000007;
const long long INF = INT_FAST64_MAX;

using namespace std;
using namespace __gnu_pbds;
template<class T>using indexed_set=tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>;

inline ll vin() {ll x;cin >> x;return x;}
ll POW(ll a, ll b) {ll res = 1;while(b){if(b%2)res=(res*a)%MOD;a = (a*a)%MOD; b/=2;}return res;}
vector<ll> DIGITS(ll n){vector<ll>a;while (n)a.push_back(n%10),n/=10;return a;}

/*
        #stringforces
        
        Possible 3 cases : 
        onetwo => remove 2  (o_et_o)
        twoone => remove 2 (t_oo_e)
        twone => remove 1  (tw_ne)
*/


vector<ll> solve()
{
        string a;
        cin >> a;
        ll n = a.size() ;
        vector<ll> res;
        for(int i=0; i<10; i++) a.push_back('#');

        for(int i=0; i<n-2; i++) {
            if(a[i]=='o' && a[i+1]=='n' && a[i+2]=='e'){
                res.push_back(i+2);
                i+=2;
            }
            else if(a[i]=='t' && a[i+1]=='w' && a[i+2]=='o' && a[i+3] == 'n' && a[i+4]=='e'){
                res.push_back(i+3);
                i+=4;
            }
            else if(a[i]=='t' && a[i+1]=='w' && a[i+2]=='o' && a[i+3] == 'o' && a[i+4]=='n' && a[i+5] == 'e'){
                res.push_back(i+3);
                res.push_back(i+4);
                i+=5;
            }
            else if(a[i]=='t' && a[i+1]=='w' && a[i+2]=='o'){
                res.push_back(i+2);
                i+=2;
            }
            else continue;
        }
        cout << res.size() << endl;
        return res;
}
int main() 
{
        FastIO;
        TestCase {
            vector<ll> res = solve();
            printVector(res);
        }
        return 0;
}