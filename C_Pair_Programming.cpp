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

void solve(ll k, ll n, ll m)
{
        vector<ll> a(n), b(m),res;
        queue<ll> p,q;
        for(int i=0; i<n; i++){
                cin>> a[i];
                p.push(a[i]);
        }
        for(int i=0; i<m; i++){
                cin >> b[i];
                q.push(b[i]);
        }
        ll x = 0;
        while(1)
        {
                ll flag = 0;
                while(!p.empty()){
                        if(p.front() == 0){
                                res.push_back(p.front());
                                p.pop();
                                k++;
                                x++;
                                flag = 1;
                        }
                        else
                        {
                                if(p.front() <=k){
                                        res.push_back(p.front());
                                        p.pop();
                                        x++;
                                        flag = 1;
                                }
                                else break;
                        }
                }
                while(!q.empty()){
                        if(q.front() == 0){
                                res.push_back(q.front());
                                q.pop();
                                k++;
                                x++;
                                flag = 1;
                        }
                        else
                        {
                            if(q.front() <=k){
                                    res.push_back(q.front());
                                    q.pop();
                                    x++;
                                    flag = 1;
                            }
                            else break;
                        }
                }
                if(q.empty() && p.empty()) break;
                if(!flag) break;
        }
        if(x!=n+m) cout << -1;
        else printVector(res);
        return;
}

int main()
{
        FastIO;
        TestCase
        {
                ll k, n, m;
                cin >> k>> n >> m;
                solve(k, n , m);
        }
        return 0;
}