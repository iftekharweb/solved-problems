#include<bits/stdc++.h> 

# define ll long long int
using namespace std;

vector<ll> factors;
void primeFact(ll n)
{
        for(ll i=2; i<=n; i++) {
                if(n%i == 0) {
                        int cnt = 0;
                        while(n%i == 0) {
                                cnt++, n/=i;
                                factors.push_back(i);
                        }
                        cout << i << "^" << cnt << endl;
                }
        }
}

int main ()
{
    ll n;
    cin >> n;
    primeFact(n);
    return 0;
}