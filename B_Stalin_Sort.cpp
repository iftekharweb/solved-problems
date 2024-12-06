#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findLNDSLength(const vector<int>& arr) {
    int n = arr.size();
    int length = 1;
    int maxElement = arr[0];
    
    for (int i = 1; i < n; ++i) {
        if (arr[i] >= maxElement) {
            length++;
            maxElement = arr[i];
        }
    }
    return length;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        
        reverse(a.begin(), a.end());
        int lndsLength = findLNDSLength(a);
        cout << (n - lndsLength) << endl;
    }
    return 0;
}
