#include <iostream>
#include<vector>
#include<map>
using namespace std;

int main()
{
        int n;
        cin >> n;
        string tmp ="";
        map<string,int> mm;
        vector<string> a(n), test;
        for(char i='a'; i<='z'; i++) test.push_back(tmp+i);
        for(char i='a'; i<='z'; i++) {
            for(char j='a'; j<='z'; j++) {
                test.push_back(tmp+i+j);
            }
        }
        for(int i=0; i<n; i++) {
            cin >> a[i];
            for(auto x:a[i]) {
                mm[tmp+x] = 1;
            }
            for(int j=0; j<(int)(a[i].size())-1; j++) {
                mm[tmp+a[i][j]+a[i][j+1]] = 1;
            }
        }
        for(auto x:test) {
            if(!mm[x]) {
                cout << x << endl;
                return 0;
            }
        }
        return 0;
}