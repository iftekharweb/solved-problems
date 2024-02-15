#include <bits/stdc++.h>

using ll = long long;
using ld = long double;
#define all(a)  a.begin(),a.end()
#define rall(a)  a.rbegin(),a.rend()
#define LCM(a,b)  (a*b)/__gcd(a, b)
#define endl "\n"

using namespace std;
template<class T> void print(T& a) { for(auto x:a)cout<<x<<" "; cout<<"\n";}

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
}; 
// unordered_map<ll,int,custom_hash> cm;

//         U   R  D  L
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
int dxx[] = {0,1,0,-1,1,1,-1,-1};
int dyy[] = {1,0,-1,0,1,-1,1,-1};

const long long MOD = 1e9+7 , N = 2e5+10 , INF = INT_FAST64_MAX;
const long double PI= 3.14159265358979323846264338327950288;

inline ll vin() {ll x;cin >> x;return x;}
ll POW(ll a, ll b) {ll res = 1; while(b){ if(b%2) res = (res*a)%MOD; a = (a*a)%MOD; b /= 2;} return res;}
vector<ll> DIGITS(ll n){vector<ll>a;while(n)a.push_back(n%10),n/=10;return a;}

//  #define cerr if(false)cerr
#define pr(x) cerr << "\n" << (#x) << " is " << (x) << endl;

long double manual_sqrt(long double x, long double epsilon = 1e-9) {
    if (x < 0) {
        // Handle negative input (NaN)
        return std::numeric_limits<long double>::quiet_NaN();
    }

    long double guess = x;
    long double prevGuess = 0.0;

    while (std::abs(guess - prevGuess) > epsilon) {
        prevGuess = guess;
        guess = 0.5L * (guess + x / guess); // Newton-Raphson formula
    }

    return guess;
}

ld dis(ld a, ld b, ld c, ld d) {
    ld x = (a-c)*(a-c)+(b-d)*(b-d);
    x = manual_sqrt(x);
    return x;
}

void solve()
{
        ld px , py , ax , ay, bx, by;
        cin >> px >> py >> ax >> ay >> bx >> by;
        ld ans = 100000000000000000.00;

        ld AB = dis(ax,ay,bx,by);
        ld r = AB/2.0;

        ld A_00 = dis(ax,ay,0.0,0.0);
        ld B_00 = dis(bx,by,0.0,0.0);
        ld A_P = dis(ax,ay,px,py);
        ld B_P = dis(bx,by,px,py);
        //pr(A_00); pr(B_00); pr(A_P); pr(B_P);

        // (0,0) in A and (px, py) in B
        if(A_00 <= r && B_P <= r) {
            ans = r;
        }
        // (0,0) in B and (px, py) in A
        if(B_00 <= r && A_P <= r) {
            ans = r;
        }

        /* Both points are in A */
        // A_P is the radius
        if(A_P >= A_00 || (B_00 <= A_P && r<=A_P)) {
            ans = min(ans,A_P);
        }
        // A_00 is the radius
        if(A_00 >= A_P || (B_P <= A_00 && r<=A_00)) {
            ans = min(ans,A_00);
        }

        /* Both points are in B */
        if(B_P >= B_00 || (A_00 <= B_P && r<= B_P)) {
            ans = min(ans,B_P);
        }
        if(B_00 >= B_P || (A_P <= B_00 && r <= B_00)) {
            ans = min(ans,B_00);
        }

        cout << fixed << setprecision(10) << ans << endl;
        return;
}

int main() 
{
        ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

        int T = 1, CNT = 0;  cin >> T;
        while(T--){
          //  cout << "Case " << ++CNT << ": ";
            solve();
        }
        return 0;
}