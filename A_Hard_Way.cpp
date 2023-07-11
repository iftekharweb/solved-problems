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

long double solve()
{
        vector<pair<ll,ll> > pp;
        for(int i=0; i<3; i++)
        {
            ll x , y;
            cin >> x >> y;
            pp.push_back({y,x});
        }
        sort(rall(pp));
        ll m = (pp[0].first-pp[1].first);
        if(!m)
        {
            long double res = sqrt((pp[1].first-pp[0].first)*(pp[1].first-pp[0].first)+(pp[1].second-pp[0].second)*(pp[1].second-pp[0].second));
            return res;
        }
        m = (pp[0].first-pp[2].first);
        if(!m)
        {
            long double res = sqrt((pp[2].first-pp[0].first)*(pp[2].first-pp[0].first)+(pp[2].second-pp[0].second)*(pp[2].second-pp[0].second));
            return res;
        }
        return 0.0;
        /*
        ll a,b,c,d,e,f;
        cin >> a >> b >> c >> d >> e >> f;
        ll m = (d-b);
        if(!m && b!=0)
        {
            long double res = sqrt((a-c)*(a-c)+(b-d)*(b-d));
            return res;
        }
        m = (f-b);
        if(!m && b!=0)
        {
            long double res = sqrt((a-e)*(a-e)+(b-f)*(b-f));
            return res;
        }
        m = (f-d);
        if(!m && f!=0)
        {
            long double res = sqrt((c-e)*(c-e)+(d-f)*(d-f));
            return res;
        }
        return 0.0;
        */
}
int main() 
{
        FastIO;
        TestCase {
            cout << points(10) << solve() << endl;
            // solve();
        }
        return 0;
}