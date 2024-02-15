#include <iostream>
using namespace std;

int main() {
    int T;
	cin >> T;
	int N,M;
	while(T--){
		cin >> N >> M;
        int colc = 1, bag = N-1,  mnC = 1, mnB = N-1;
        int prev, nxt;
		cin >> prev;
		for(int i=0; i<M-1; i++){
			cin >> nxt;
            int dif = nxt-prev;
			if(dif!=0) colc += dif, bag -= dif;
			else colc -= 1;
			mnC = min(mnC,colc);
			mnB = min(mnB,bag);
			prev = nxt;
        }
        if(mnC>0 && mnB>=0) cout << "1\n";
		else if(mnB<=0) cout << "-1\n";
		else {
			int use = 2-mnC, chng = mnB+mnC;
			if(use>N || chng<0) cout << "-1\n";
			else cout << use << endl;
		}
    }
    return 0;
}