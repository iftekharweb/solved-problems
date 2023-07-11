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
const long long MOD = 1e9+7 , N = (1e5)+10;
const long long INF = INT_FAST64_MAX;

using namespace std;
using namespace __gnu_pbds;
template<class T> using indexed_set = tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

//          U   R  D  L
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

inline ll vin() {ll x;cin >> x;return x;}
ll POW(ll a, ll b) {ll res = 1;while(b){if(b%2)res=(res*a)%MOD;a = (a*a)%MOD; b/=2;}return res;}
vector<ll> DIGITS(ll n){vector<ll>a;while (n)a.push_back(n%10),n/=10;return a;}

ll n , k , p , e_size , o_size , remaining_odd;
vector<ll> a(N);
queue<ll> odd , even;

bool Find_impossible_case() {
        if(o_size<k-p || e_size+(o_size>>1)<p) return false;
        if(e_size<p) {
            remaining_odd = o_size-(p-e_size)*2;
        }
        if(remaining_odd<k-p) return false;
        if(((k-p)&1) && !(remaining_odd&1)) return false;
        if(!((k-p)&1) && (remaining_odd&1)) return false;
        return true;
}

void Case_No_even_portion(ll k_p) {
        ll tmp;
        k_p--;
        while(k_p) {
            cout << 1 << ' ' << odd.front() << "\n";
            odd.pop();
            k_p--;
        }
        tmp = odd.size()+even.size();
        cout << tmp << ' ';
        while(!even.empty()) {
            cout << even.front() << ' ';
            even.pop();
        }
        while(!odd.empty()) {
            cout << odd.front() << ' ';
            odd.pop();
        }
        cout << "\n";
        return;
}

void Case_No_odd_portion(ll p_copy) {
        ll tmp;
        p_copy--;
        while(p_copy && !even.empty()) {
            cout << 1 << ' ' << even.front() << "\n";
            even.pop();
            p_copy--;
        }
        while(p_copy) {
            cout << 2 << " " << odd.front() << " ";
            odd.pop();
            cout << odd.front() << "\n";
            odd.pop();
            p_copy--;
        }
        tmp = even.size()+odd.size();
        cout << tmp << ' ';
        while(!even.empty()) {
            cout << even.front() << ' ';
            even.pop();
        }
        while(!odd.empty()) {
            cout << odd.front() << ' ';
            odd.pop();
        }
        cout << "\n";
        nl;
}

void Case_Even_Odd_both(ll p_copy , ll k_p)
{
        if(p_copy && (ll)even.size()>p_copy) {
            ll tmp = (ll)(even.size())-p_copy+1;
            cout << tmp << " ";
            while(tmp--) {
                cout << even.front() << " ";
                even.pop();
            }
            cout << "\n";
            p_copy--;
        }
        while(!even.empty()) {
            cout << 1 << " " << even.front() << "\n";
            even.pop();
            p_copy--;
        }
        while(p_copy) {
            if(!odd.empty()) {
                cout << 2 << " " << odd.front() << " ";
                odd.pop();
                cout << odd.front() << "\n";
                odd.pop();
            }
            else break;
            p_copy--;
        }
        if(k_p && k_p<(ll)odd.size()) {
            ll tmp = (ll)(odd.size())-k_p+1;
            cout << tmp << " ";
            while(tmp--) {
                cout << odd.front() << " ";
                odd.pop();
            }
            cout << "\n";
            k_p--;
        }
        while(!odd.empty()) {
            cout << 1 << ' ' << odd.front() << "\n";
            odd.pop();
        }
        return;
}

void solve()
{
        n = vin() , k = vin() , p = vin();
        
        for(int i=0; i<n; i++) {
            ll x = vin();
            a[i] = x;
            if((x&1)) odd.push(x);
            else even.push(x);
        }
        o_size = (ll)odd.size() , e_size = (ll)even.size() , remaining_odd = o_size;

        if(!Find_impossible_case()) {
            cout << "NO\n";
            return;
        }
        ll p_copy = p , k_p = k-p;
        cout << "YES\n";
        if(!p) {
            Case_No_even_portion(k_p);
            return;
        }
        if(!k_p) {
            Case_No_odd_portion(p_copy);
            return;
        }
        Case_Even_Odd_both(p_copy,k_p);
        return;
}
int main() 
{
        FastIO;
        solve();
        return 0;
}