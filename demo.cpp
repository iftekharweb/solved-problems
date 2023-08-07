#include <iostream>
#include <vector>

using namespace std;

int main() 
{
        vector<int> div = {2,4,3,9,5,25,7,49,11,13,17,19,23,29,31,37,41,43,47};
        int cnt = 0;
        for(auto x:div) {
            cout << x << '\n';
            cout.flush();

            string status;
            cin >> status;

            if(status == "yes") {
                cnt++;
            }
            if(cnt>1) break;
        } 
        if(cnt>1) {
            cout << "composite\n";
        } else {
            cout << "prime\n";
        }
        cout.flush();
        return 0;
}