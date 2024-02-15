#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool check(string &a, string &b) {
    if(a.size()<b.size()) return true;
    if(a.size()>b.size()) return false;
    for(int i=0; i<a.size(); i++) {
        if(a[i]>b[i]) return false;
        if(a[i]<b[i]) return true;
    }
    return true;
}

void Diff(string &b, string &a, string &d) {
    d = "";
    int carry = 0;
    for(int i=(int)(b.size())-1, j=(int)(a.size())-1; i>=0; i--, j--) {
        int x = b[i]-'0';
        int y = j>=0 ? a[j]-'0' : -1;
        if(y != -1) {
            y += carry;
            carry = 0;
            if(x<y) {
                carry = 1;
                x += 10;
                d.push_back((char)(x-y));
            } else {
                d.push_back((char)(x-y));
            }
        } else {
            if(carry) {
                y = carry;
                carry = 0;
            }
            if(x<y) {
                carry = 1;
                x += 10;
                d.push_back((char)(x-y));
            } else {
                d.push_back((char)(x-y));
            }
        }
    }
    while(d.back() == '0') d.pop_back();
    reverse(d.begin(), d.end());
}

void Plus(vector<string> &num) {
    string conDiff;
    Diff(num[1],num[0],conDiff);

    for(int i=1; i<(int)(num.size())-1; i++) { 
        string &a = num[i];
        string &b = num[i+1];
        if(!check(a,b)) {
            cout << "No" << endl;
            return;
        }
        string currDiff;
        Diff(b,a,currDiff);
        if(conDiff != currDiff) {
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
    return;
}

void Minus(vector<string> &num) {
    string conDiff;
    Diff(num[0],num[1],conDiff);

    for(int i=1; i<(int)(num.size())-1; i++) { 
        string &a = num[i+1];
        string &b = num[i];
        if(!check(a,b)) {
            cout << "No" << endl;
            return;
        }
        string currDiff;
        Diff(b,a,currDiff);
        if(conDiff != currDiff) {
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
    return;
}

int main() {
    
    while(1) {
        string a;
        getline(cin,a);
        if(a == "") continue;
        else if(a == "0") break;
        else {
            vector<string> num;
            string tt = "";
            for(auto x:a) {
                if(x == ' ') {
                    if(tt != "") num.push_back(tt);
                    tt = "";
                } else {
                    tt += x;
                }
            }
            if(tt != "") num.push_back(tt);
            if(num.size() == 1) {
                cout << "Yes" << endl;
                continue;
            }
            if(check(num[0],num[1])) {
                Plus(num);
            } else {
                Minus(num);
            }
        }
    }
    return 0;
}