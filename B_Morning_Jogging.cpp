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


int main()
{
        FastIO;
        TestCase
        {
                ll n, m, x;
                cin >> n >> m;
                map<ll, vector<ll> > mp, mm;
                map<ll, queue<ll> > ok;
                map<ll,map<ll,ll> > vai;
                priority_queue<ll, vector<ll>, greater<ll> > Q;
                for(int i=1; i<=n; i++){
                        for(int j=0; j<m; j++){
                                cin >> x;
                                Q.push(x);
                                mp[i].push_back(x);
                                mm[i].push_back(0);
                                vai[i][x]++;
                        }
                }
                ll cnt = 0;
                while(!Q.empty())
                {
                        cnt++;
                        for(int i=1; i<=n; i++){
                                if(vai[i][Q.top()]) {
                                        mm[i][cnt-1] = Q.top();
                                        vai[i][Q.top()]--;
                                        break;
                                }
                        }
                        Q.pop();
                        if(cnt == m) break;
                }
                for(int i=1; i<=n; i++){
                        for(int j=0; j<m; j++){
                                if(vai[i][mp[i][j]]){
                                        ok[i].push(mp[i][j]); 
                                        vai[i][mp[i][j]]--;
                                }
                        }
                }
                for(int i=1; i<=n; i++){
                        for(int j=0; j<m; j++){
                                if(!mm[i][j]){
                                        mm[i][j] = ok[i].front();
                                        ok[i].pop();
                                }
                        }
                }
                for(int i=1; i<=n; i++){
                        for(int j=0; j<m; j++){
                                cout << mm[i][j] <<" ";
                        }
                        nl;
                }
                
        }
        return 0;
}