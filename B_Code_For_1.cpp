#include<iostream>
using namespace std;

int check(long long pos, long long x, long long n)
{
    if(n<2) {
        return n;
    } else if(pos+1==x+x) {
        return n%2;
    }
    n/=2, pos/=2;
    if(x>pos+1) x -= (pos+1);
    return check(pos,x,n);
}

int main() {
    long long n, l , r;
    cin >> n >> l >> r;

    long long len=1, tmp = n;
    while(tmp>1) {
        tmp/=2;
        len*=2;
    }
    len = 2*len-1;

    long long ans = 0;
    for(long long i=l; i<=r; i++) {
        ans += check(len,i,n);
    }
    cout << ans << endl;
    return 0;
}