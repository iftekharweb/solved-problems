#include<iostream>
using namespace std;

int main() {
    string a , b, s;
    cin >> a >> b;
    if(a.size() != b.size()) {
        cout << "No" << endl;
        return 0;
    }
    if(a == b) {
        cout << "Yes" << endl;
        cout << 0 << endl;
        return 0;
    }
    int n = a.size();
    for(int i=0; i<n; i++) {
        s+= a[i];
        
    }
}