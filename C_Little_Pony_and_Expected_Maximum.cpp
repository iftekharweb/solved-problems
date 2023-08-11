#include<iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    int m , n;
    cin >> m >> n;

    double ans = 0;
    for(int i=1; i<=m; i++) {
        ans += (double)i*(pow((double)i/m, n) - pow((double)(i-1)/m, n));
    }
    cout << fixed << setprecision(12) << ans << endl;
    return 0;
}
