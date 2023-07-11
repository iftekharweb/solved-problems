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

inline int vin() {int x;cin >> x;return x;}

vector<int> cntOperations(int n)
{
        vector<int> CNT(1001);
        for(int i=2; i<=n; i++) CNT[i] = MOD;
        CNT[1] = 0;
        CNT[2] = 1;
        for(int i=2; i<=n; i++) {
            for(int j=i; j>0; j--) {
                ll x = i+i/j;
                if(x>1000) break;
                CNT[x] = min(CNT[x],1+CNT[i]);
            }
        }
        return CNT;
}

int knapsack(int n,int k , vector<int> weight,vector<int> cost)
{
        vector<vector<int> > dp(n+1, vector<int> (k+1, 0));
        for(int i=0; i<=n; i++)
        {
            for(int j=0; j<=k; j++)
            {
                int X, Y;
                if(!i) X = 0;
                else X = dp[i-1][j];
                if(j - weight[i]<0 || !i) Y = 0;
                else Y = dp[i-1][j-weight[i]] + cost[i];

                dp[i][j] = max(X,Y);
            }
        }
        return dp[n][k];
}

int solve()
{
        int n = vin();
        int k = vin();
        vector<int> CNT = cntOperations(1000);
        vector<int> b(n+1), c(n+1), OP(n+1);
        int sum = 0;
        for(int i=1; i<=n; i++){
            cin >> b[i];
            OP[i] = CNT[b[i]];
            sum += OP[i];
        }
        for(int i=1; i<=n; i++){
            cin >> c[i];
        }
        b[0] = c[0] = OP[0] = 0 ;
        if(k>=sum) {
            sum = 0;
            for(int i=0; i<=n; i++) sum += c[i];
            return sum;
        }
        int mx = knapsack(n,k,OP,c);
        return mx;
}
int main() 
{
        FastIO;
        TestCase {
            cout << solve() << endl;
            //solve();
        }
        return 0;
}