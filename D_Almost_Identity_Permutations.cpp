#include<iostream>
using namespace std;

#define pr(x) cerr << "\n" << (#x) << " is " << (x) << endl;
int main()
{
    long long n, k;
    cin >> n >> k;
    long long vFor1 = 1;
    long long vFor2 = n * (n - 1) / 2;
    long long vFor3 = n * (n - 1) * (n - 2) / 6 * 2;
    long long vFor4 = n * (n - 1) * (n - 2) * (n - 3) / 24 * (6 + 3);
    
    //pr(vFor1) pr(vFor2); pr(vFor3); pr(vFor4);
    pr(n * (n - 1) * (n - 2) / 6);
    pr(n * (n - 1) * (n - 2) * (n - 3) / 24);

    long long ans = 0;
    if(k == 1) {
        ans = vFor1;
    } else if(k == 2) {
        ans = vFor1+vFor2;
    } else if(k == 3) {
        ans = vFor1+vFor2+vFor3;
    } else {
        ans = vFor1+vFor2+vFor3+vFor4;
    }
    cout << ans << endl;
    return 0;
}