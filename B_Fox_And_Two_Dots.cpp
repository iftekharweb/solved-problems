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

int n , m, cnt, edge;
char a[51][51];
bool vis[51][51];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
map< pair<int ,int>,int> mm;

bool is_valid(int x, int y, char ch)
{
        if(x<1 || x>n || y<1 || y>m) return false;
        if(vis[x][y] || a[x][y] != ch) return false;
        return true;
}

void myFunc(int x, int y, char ch)
{
        vis[x][y] = true;
        //cout<< x << " " << y << endl;
        cnt++;
        edge += mm[{x,y}];
        for(int i=0; i<4; i++){
                if(is_valid(x+dx[i] , y+dy[i], ch)) myFunc(x+dx[i] , y+dy[i], ch);
        }
        return;
}

void clearDone()
{
        for(int i=1; i<=n; i++) for(int j=1; j<=m; j++) vis[i][j] = false;
        return;
}

int main()
{
        FastIO;
        cin >> n >> m;
        for(int i=1; i<=n; i++) for(int j=1; j<=m; j++) cin >> a[i][j];
        for(int i=1; i<=n; i++) for(int j=1; j<=m; j++)
        {
                for(int k=0; k<4; k++){
                if(is_valid(i+dx[k] , j+dy[k], a[i][j])) mm[{i,j}]++; 
        }
        }
        for(int i=1; i<=n; i++) for(int j=1; j<=m; j++)
        {
                clearDone();
                cnt = edge = 0;
                myFunc(i, j, a[i][j]);
                //pr(cnt); pr(edge); pr(i); pr(j);
                if(cnt <= (edge/2)){
                        cout << "Yes" <<endl;
                        return 0;
                }
        }
        cout << "No" <<endl;
        return 0;
}