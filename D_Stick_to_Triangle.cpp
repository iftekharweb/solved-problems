#include<bits/stdc++.h>
using namespace std;
//if got verdict  MLE
//try int or short int
#define     pb                push_back
#define     ll                long long int
#define     ff                first
#define     ss                second
#define     inf               9999999999999999ll
#define     MOD               1000000007
#define     gcd(a, b)         __gcd(a,b)
#define     lcm(a, b)         ((a)*(b)/gcd(a,b))
#define     all(v)            v.begin(),v.end()
#define     IOS               ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define no cout << "NO" << '\n'
#define yes cout << "YES" << '\n'
#define testcase ll tt;cin>>tt;while(tt--)
void input(vector<ll>&a){
    for(ll i=0;i<a.size();i++)cin>>a[i];
}


void solve(){
    ll n;
    cin>>n;
    ll ans=0;
    for(ll i=1;i<=n;i++){
        ll x = n-i;
        ll p=(x+1)/2;
        ll q=x-p;
        if(q<i) continue;
        ll dif = p - q;
        ll xx=i-dif;
        ll cnt=1;
        ll jaitepari = q-i;
        cnt+=min(jaitepari,xx/2);
        ans+=cnt;

    }
    cout<<ans<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    testcase{
        solve();
    }
}