#include <bits/stdc++.h>
using namespace std;

int main() {

  int n;
  cin >> n;

  if (n % 4 == 2 || n % 4 == 3) {
    cout << "NO\n";
    return 0;
  }
  cout << "YES\n";

    for (int i = 1; i + 1 <= n; i += 2) {
        for (int j = i + 2; j + 1 <= n; j += 2) {
            cout << i << ' ' << j << '\n';
            cout << i + 1 << ' ' << j + 1 << '\n';
            cout << i + 1 << ' ' << j << '\n';
            cout << i << ' ' << j + 1 << '\n';
        }
    }

    if (n % 4 == 0) {
        for (int i = 1; i + 1 <= n; i += 2)
            cout << i << ' ' << i + 1 << '\n';
    } else {
        for (int i = 1; i + 1 <= n; i += 2) {
            cout << i << ' ' << n << '\n';
            cout << i << ' ' << i + 1 << '\n';
            cout << i + 1 << ' ' << n << '\n';
        }
    }

  return 0;
}
  		 							  		  	 		  	 	   	