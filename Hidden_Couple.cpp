#include <iostream>

using ll = long long;

using namespace std;

void solve()
{
        string a;
        cin >> a;
        ll value = 0;
        for(auto x:a) {
            value += x;
        }
        cout << value << " ";
        if(value%3 == 0) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
        return;
}

int main() 
{
        ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

        int T = 1, CNT = 0;  cin >> T;
        while(T--){
            cout << "Case " << ++CNT << ": ";
            solve();
        }
        return 0;
}