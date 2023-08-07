#include <iostream>
#include <vector>

using namespace std;

int main() 
{
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> F, S;
        for(int i=0; i<n; i++) {
            cin >> a[i];
            if(a[i]<0) {
                S.push_back(-a[i]);
            } else {
                F.push_back(a[i]);
            }
        }
        long long sumF = 0, sumS = 0; 
        for(auto x:F) sumF += x;
        for(auto x:S) sumS += x;
        if(sumF != sumS) {
            if(sumF>sumS) {
                cout << "first" << endl;
            } else {
                cout << "second" << endl;
            }
            return 0;
        }
        for(int i=0; i<min(F.size(), S.size()); i++) {
            if(S[i] == F[i]) {
                continue;
            } else if(F[i]>S[i]) {
                cout << "first" << endl;
                return 0;
            } else if(S[i]>F[i]) {
                cout << "second" << endl;
                return 0;
            }
        }
        if(a.back()<0) {
            cout << "second" << endl;
            return 0;
        } else {
            cout << "first" << endl;
            return 0;
        }
        return 0;
}