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
ll POW(ll a, ll b) {ll res = 1;while(b){if(b%2)res=(res*a)%MOD;a = (a*a)%MOD; b/=2;}return res;}
vector<ll> DIGITS(ll n){vector<ll>a;while (n)a.push_back(n%10),n/=10;return a;}


ll palindrome(string b,ll n, ll idx)
{
        
        for(int i=idx+1; i<n; i++) {
            bool flag = false;
            for(int j=idx, k=i; j<=idx+(i-idx)/2; j++,k--) {
                if(b[j]!=b[k]){
                    flag = true;
                    break;
                }
            }
            if(!flag) return i;
        }
        return idx;
}

void solve()
{
        ll n = vin() , res = 0, idx = 0;
        bool flag = false;
        string a;
        cin >> a;
        if(a.size()==1) {
            cout << 0 << " " << 1 << endl;
            return;
        }
        a.push_back('#');
        for(int i=0; i<n; i++) {
            if(a[i]==a[i+1] && !flag) {
                res++;
                i++;
                idx = i+1;
                continue;
            }
            if(a[i]!=a[i+1] && a[i]=='(' && a[i+1]==')' && !flag) {
                res++;
                i++;
                idx = i+1;
                continue;
            }
            if(a[i]==')') {
                if(flag) {
                    res++;
                    flag = false;
                    idx = i+1;
                    continue;
                }
                flag = true;
            }
            if(!flag) break;
        }
        cout << res << " " << n-(idx) << endl;
        return ;
}
int main() 
{
        FastIO;
        TestCase {
            //cout << solve() << endl;
            solve();
        }
        return 0;
}