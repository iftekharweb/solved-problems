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
void solve()
{
        string a, mid;
        cin >> a;
        ll n = a.size();
        ll ii=-1, jj=-1, flag = 0;
        if(n==1){
            cout << a << endl;
            return;
        }
        for(int i=n; i>0;i--){
            ll x = a[i]+a[i-1]-(2*48);
            if(x>=10){
                stringstream demu; 
                demu << x; 
                mid = demu.str();
                ii = i;
                jj = i-1;
                break;
            }
        }
        if(ii!=-1 && jj!=-1)
        {
            for(int i=0; i<n; i++)
            {
                if(i==ii || i==jj)
                {
                    if(!flag) cout << mid, flag = 1;
                }
                else cout << a[i];
            }
            cout << endl;
            return;
        }
        ll x = a[0]+a[1]-(2*48);
        stringstream demu; 
        demu << x; 
        mid = demu.str();
        for(int i=0; i<n; i++)
        {
            if(i==0) cout << mid;
            else if(i==1) continue;
            else cout << a[i];
        }
        cout << endl;
        return ;
}
int main()
{
        FastIO;
        TestCase
        {
                // cout << solve() << endl;
                solve();
        }
        return 0;
}