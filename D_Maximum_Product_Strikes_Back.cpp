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
const long long MOD= 1e12;

using namespace std;
using namespace __gnu_pbds;
template<class T>using indexed_set=tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>;

inline ll vin() {ll x;cin >> x;return x;}
ll POW(ll a, ll b) {ll res = 1;while(b){if(b%2)res=(res*a)%MOD;a = (a*a)%MOD; b/=2;}return res;}
vector<ll> DIGITS(ll n){vector<ll>a;while (n)a.push_back(n%10),n/=10;return a;}

void solve()
{
        ll n = vin() , cntZ = 0, unit = 1, twos = 0;
        vector<ll> a , idxZ, cntNeg(n+2,0), mul(n+2) , lZ(n+2), rZ(n+2);

        a.push_back(0);
        mul[0] = 0;
        for(int i=0; i<n; i++)
        {
            ll x = vin();
            a.push_back(x);
            if(x!=0) {
                if(abs(x-0)==2) twos++;
            }
            else {
                mul[i+1] = twos;
                twos = 0;
            }
        }
        mul[n+1] = twos;
        a.push_back(0);

        for(int i=0; i<n+2; i++) {
            if(a[i]==0) idxZ.push_back(i);
            if(a[i]<0) cntZ++;
            cntNeg[i] = cntZ;
        }

        ll zs = idxZ.size() , mx = 0;

        for(int i=0; i<zs-1; i++) {
            for(int j=idxZ[i]+1; j<idxZ[i+1]; j++) {
                if(a[j]<0) {
                    lZ[idxZ[i]] = j;
                    break;
                }
            }
        }
        for(int i=zs-1; i>0; i--) {
            for(int j=idxZ[i]-1; j>idxZ[i-1]; j--) {
                if(a[j]<0) {
                    rZ[idxZ[i]] = j;
                    break;
                }
            }
        }

        pair<ll,ll> pp = {-1,-1};
        for(int i=0; i<zs-1; i++)
        {
            ll l = idxZ[i];
            ll r = idxZ[i+1];
            if(r==l+1) continue;
            ll negs = cntNeg[r]-cntNeg[l];
            if(negs%2==0) {
                if(mul[r]>mx) {
                    mx = mul[r];
                    pp = {l,r};
                }
            }
            else
            {
                ll ck1 = 0;
                for(int j=l+1; j<= lZ[l]; j++) {
                    if(abs(a[j]-0)==2) ck1++;
                }
                if(mul[r]-ck1 > mx) {
                    mx = mul[r]-ck1;
                    pp = {lZ[l],r}; 
                }
                ck1 = 0;
                for(int j=rZ[r]; j<r; j++) {
                    if(abs(a[j]-0)==2) ck1++;
                }
                if(mul[r]-ck1 > mx) {
                    mx = mul[r]-ck1;
                    pp = {l,rZ[r]};
                }
            }
        }
        if(pp.first==-1) {
            cout << n << " " << 0 << endl;
            return;
        }
        cout << pp.first << " " << n-pp.second+1 << endl;
        return ;
}
int main() 
{
        FastIO;
        TestCase {
            //cout << solve() << endl;
            solve();
        }
        return 0;
}