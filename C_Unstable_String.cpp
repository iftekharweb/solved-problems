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
const long long MOD = 1e9+7 , N = 1e5*2;
const long long INF = INT_FAST64_MAX;

using namespace std;
using namespace __gnu_pbds;
template<class T>using indexed_set=tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>;

//          U   R  D  L
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

inline ll vin() {ll x;cin >> x;return x;}
ll POW(ll a, ll b) {ll res = 1;while(b){if(b%2)res=(res*a)%MOD;a = (a*a)%MOD; b/=2;}return res;}
vector<ll> DIGITS(ll n){vector<ll>a;while (n)a.push_back(n%10),n/=10;return a;}


/*
        0?10 = 8
        => 0 | 0? |-0?1 |-0?10 
        => ? | ?1 | ?10 |
        => 1 | 10 |
        => 0 |

        0??1 = b
        0???1 != b
        0??0 != b
        0???0 = b

*/

ll solve()
{
        string a , tmp1 , tmp2;
        cin >> a;
        tmp1 = tmp2 = a;
        ll n = a.size(), res = 0, flag = 0;
        vector<ll> nopee, idx;
        for(int i=0; i<n; i++)
        {
            if(a[i]!='?') flag = 1;
            if(i==0 && tmp1[i]=='?') continue;
            if(tmp1[i]=='?')
            {
                if(tmp1[i-1]=='0') tmp1[i] = '1';
                else if(tmp1[i-1]=='1') tmp1[i] = '0';
            }
        }
        if(!flag) 
        {
            res += ((n*(n+1))/2);
            return res;
        }
        tmp1.push_back(tmp1[n-1]);
        tmp2.push_back('1');
        for(int i=0; i<n; i++)
        {
            if(tmp1[i]==tmp1[i+1] && tmp1[i]!='?') nopee.push_back(i+1);
        }
        sort(all(nopee));
        for(int i=0; i<n; i++)
        {
            if(tmp2[i]=='?' && tmp2[i+1]!='?') idx.push_back(i+1);
        }
        idx.push_back(n);
        sort(all(idx));

        for(int i=0; i<n; i++)
        {
            if(a[i]!='?')
            {
                auto it = lower_bound(all(nopee), i+1);
                ll pos = *it;
                pos = pos-i;
                res+=pos;
            }
            else
            {
                auto itid = lower_bound(all(idx), i+1);
                ll id = *itid;
                auto it = lower_bound(all(nopee), id+1);
                ll pos = *it;
                if(it == nopee.end()) pos = n;
                pos = pos-i;
                res+=pos;
            }
        }
        return res;
}

int main()
{
        FastIO;
        TestCase
        {
            cout<< solve() << "\n";
        }
        return 0;
}