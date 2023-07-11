/*
             ...Bismillah Hirrahman Nirrahim...
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


int main()
{
        FastIO;
        vector< string > a(200001);
        vector< vector<int> > vv;
        vector<int> ups, arSum(18,0);
        vv.push_back(arSum);
        for(int i=1; i<=200000; i++) {
                a[i] = bitset<18>(i).to_string();
                for(int j=0; j<18; j++) {
                        if(a[i][j] == '1') arSum[j]++;
                }
                vv.push_back(arSum);
        } 
        // for(int i=1; i<=8; i++) {printVector(vv[i]);}
        TestCase
        {
                ll x , y; cin >> x >> y;
                vector<int> cnt(18,0);
                for(int i=0; i<18; i++) {
                        cnt[i] = vv[y][i] - vv[x-1][i];
                }
                sort(rall(cnt));
                //cout << nn[0].first << endl;
                cout << (y-x+1)-cnt[0] << endl;
        }
        return 0;
}