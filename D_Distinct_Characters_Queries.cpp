/*
                بِسْمِ ٱللَّٰهِ ٱلرَّحْمَٰنِ ٱلرَّحِيمِ                
                Iftekhar Md. Shishir
                Dept. of Information and Communication Engineering
                University of Rajshahi
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ll  long long
#define ld  long double
#define printSet(a)  for(auto Data:a) cout<<Data<<" ";cout<<"\n";
#define printVector(a)  for(auto Data:a)cout<<Data<<" ";cout<<"\n";
#define printQueue(Q)  while(!Q.empty())cout<< Q.front()<<" ",Q.pop(); cout<<"\n";

#define all(a)  a.begin(),a.end()
#define rall(a)  a.rbegin(),a.rend()
#define stringToInt(a,x)   stringstream demo(a); demo >> x;
#define intToSting(x,s)   stringstream demu; demu << x; a = demu.str();

#define TxtIO   freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#define FastIO   ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
#define LCM(a,b)  (a*b)/__gcd(a, b)
#define TestCase   ll t;cin>>t;while(t--)
#define points(x)   fixed<<setprecision(x)
#define pr(x)  cerr << #x << " = " << x << endl;
#define nl  cout<<"\n";
const ld PI= 3.14159265358979323846264338327950288;

using namespace std;
using namespace __gnu_pbds;
template<class T> using indexed_set = tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

const long long MOD = 1e9+7 , N = 1e5+10 , INF = INT_FAST64_MAX;

//          U   R  D  L
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
inline ll vin() {ll x;cin >> x;return x;}
ll POW(ll a, ll b) {ll res = 1;while(b){if(b%2)res=(res*a)%MOD;a = (a*a)%MOD; b/=2;}return res;}
vector<ll> DIGITS(ll n){vector<ll>a;while(n)a.push_back(n%10),n/=10;return a;}

struct Node {
    int cnt[26];
    int unique;
};

Node Tree[4*N];
char a[N];

Node MargeThem(Node lt , Node rt) {
        Node send;
        int x = 0;
        for(int i=0; i<26; i++) {
            if(lt.cnt[i]==1 || rt.cnt[i]==1) {
                x++;
                send.cnt[i] = 1;
            }
            else send.cnt[i] = 0;
        }
        send.unique = x;
        return send;
}

void BuildTree(int si , int ss , int se) {
        if(ss == se) {
            for(int i=0; i<26; i++) Tree[si].cnt[i] = 0;
            Tree[si].unique = 1;
            Tree[si].cnt[a[ss]-'a'] = 1;
            return;
        }
        int mid = (ss + se) >> 1;
        BuildTree(2*si + 0 , ss , mid);
        BuildTree(2*si + 1 , mid+1 , se);
        Tree[si] = MargeThem(Tree[2*si + 0] , Tree[2*si + 1]);
        return;
}

void PointUpdate(int si , int ss , int se , int qi) {
        if(ss == se) {
            for(int i=0; i<26; i++) Tree[si].cnt[i] = 0;
            Tree[si].unique = 1;
            Tree[si].cnt[a[ss]-'a'] = 1;
            return;
        }
        int mid = (ss + se) >> 1;
        if(qi <= mid) PointUpdate(2*si + 0 , ss ,mid , qi);
        else PointUpdate(2*si + 1 , mid+1 , se , qi);
        Tree[si] = MargeThem(Tree[2*si + 0] , Tree[2*si + 1]);
        return;
}

Node Query(int si , int ss , int se , int li , int ri) {
        if(li>se || ri<ss) {
            return {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},0};
        }
        if(li<=ss && ri>=se) {
            return Tree[si];
        }
        int mid = (ss + se) >> 1;
        return MargeThem(Query(2*si + 0 , ss , mid , li , ri), Query(2*si + 1 , mid+1 , se ,li , ri));
}

ll solve()
{
        a[0] = ' ';
        cin >> a + 1;
        int n = strlen(a);
        BuildTree(1,1,n);
        //ll kk = Tree[1].cnt[0]; cout << kk << "\n";

        int q;
        cin >> q;
        while(q--) {
            int type , idx , l , r;
            char ch;
            cin >> type;
            //pr(type);
            if(type == 1) {
                cin >> idx >> ch;
                //pr(a[idx]);
                a[idx] = ch;
                PointUpdate(1,1,n,idx);
                //cout << "OK" << endl;
            }
            else {
                cin >> l >> r;
                int ans = Query(1,1,n,l,r).unique;
                cout << ans << "\n";
                //cout << "OK" << endl;
            }
        }
        return 0;
}
int main() 
{
        FastIO;
        solve();
        return 0;
}