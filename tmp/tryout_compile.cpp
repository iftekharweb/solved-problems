#include<iostream>
#include<vector>
#include<bitset>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long ll;

const ll maxn = 1e2+16, maxv = 4e4+16, md = 1e9+7, inf = 2e16;

char a[maxn][maxn];
ll lf[maxn][maxn], rt[maxn][maxn], up[maxn][maxn], dn[maxn][maxn];
ll c[maxv], o = 0;
vector<ll> adj[maxv], jda[maxv], f;
bitset<maxv> mark;

void fDFS(ll r) {
    mark[r] = true;
    for(auto i:adj[r]) {
        if(mark[i]) continue;
        fDFS(i);
    }
    f.push_back(r);
    return;
}

void cDFS(ll r){
    c[r] = o;
    for(auto i:jda[r]) {
        if(c[i] != -1) continue;
        cDFS(i);
    }
    return;
}

int main() {
    // 

    memset(c,-1,sizeof(c));
    ll n , m;
    cin >> n >> m;
    for(ll i=0; i<n; i++) {
        for(ll j=0; j<m; j++) {
            cin >> a[i][j];
        }
    }

    for(ll i=0; i<n; i++) {
        lf[i][0] = -1;
        for(ll j=1; j<m; j++) {
            if(a[i][j-1] == '#') {
                lf[i][j] = -1;
            } else if(a[i][j-1] == 'T') {
                lf[i][j] = j-1;
            } else {
                lf[i][j] = lf[i][j-1];
            }
        }
        rt[i][m-1] = -1;
        for(ll j=m-2; ~j; j--) {
            if(a[i][j+1] == '#') {
                rt[i][j] = -1;
            } else if(a[i][j+1] == 'T') {
                rt[i][j] = j+1;
            } else {
                rt[i][j] = rt[i][j+1];
            }
        }
    }

    for(ll j = 0; j<m; j++) {
        up[0][j] = -1;
        for(ll i=1; i<n; i++) {
            if(a[i-1][j] == '#') {
                up[i][j] = -1;
            } else if(a[i-1][j] == 'T') {
                up[i][j] = i-1;
            } else {
                up[i][j] = up[i-1][j];
            }
        }
        dn[n-1][j] = -1;
        for(ll i = n-2; ~i; i--) {
            if(a[i+1][j] == '#') {
                dn[i][j] = -1;
            } else if(a[i+1][j] == 'T') {
                dn[i][j] = i+1;
            } else {
                dn[i][j] = dn[i+1][j];
            }
        }
    }

    for(ll i=0; i<n; i++) {
        for(ll j=0; j<m; j++) {
            if(a[i][j] == '#' || a[i][j] == '.') continue;
            if(a[i][j] == 'T') {
                if(lf[i][j] != -1) {
                    ll u = i*m+lf[i][j]; u*=4;
                    adj[u+1].push_back(u);
                    jda[u].push_back(u+1);
                }
                if(rt[i][j] != -1) {
                    ll u = i*m+rt[i][j]; u*=4;
                    adj[u].push_back(u+1);
                    jda[u+1].push_back(u);
                }
                if(up[i][j] != -1) {
                    ll u = up[i][j]*m+j; u*=4;
                    adj[u+3].push_back(u+2);
                    jda[u+2].push_back(u+3);
                }
                if(dn[i][j] != -1) {
                    ll u = dn[i][j]*m+j; u*=4;
                    adj[u+2].push_back(u+3);
                    jda[u+3].push_back(u+2);
                }
                continue;
            }
            ll v = -1 , u = -1;
            bool vc, uc;
            if((lf[i][j] == -1)^(rt[i][j] == -1)) {
                if(lf[i][j] != -1) {
                    v = i*m+lf[i][j];
                    vc = true;
                } else {
                    v = i*m+rt[i][j];
                    vc = false;
                }
            }
            if((up[i][j] == -1)^(dn[i][j] == -1)) {
                if(up[i][j] != -1) {
                    u = up[i][j]*m+j;
                    uc = true;
                } else {
                    u = dn[i][j]*m+j;
                    uc = false;
                }
            }

            v *= 4; u *=4;
            if(u == -4) {
                if(vc) {
                    adj[v].push_back(v+1);
                    jda[v+1].push_back(v);
                } else {
                    adj[v+1].push_back(v);
                    jda[v].push_back(v+1);
                }
                continue;
            }
            if(v == -4) {
                if(uc) {
                    adj[u+2].push_back(u+3);
                    jda[u+3].push_back(u+2);
                } else {
                    adj[u+3].push_back(u+2);
                    jda[u+2].push_back(u+3);
                }
                continue;
            }
            adj[v+!vc].push_back(u+2+uc);
            adj[u+2+!uc].push_back(v+vc);
            jda[u+2+uc].push_back(v+!vc);
            jda[v+vc].push_back(u+2+!uc);
        }
    }
    ll lm = 4*n*m;
    for(ll i=0; i<lm; i++) {
        if(mark[i]) continue;
        fDFS(i);
    }
    reverse(f.begin(),f.end());
    for(auto i:f) {
        if(c[i] != -1) continue;
        cDFS(i);
        o++;
    }
    for(ll i=0; i<n; i++) {
        for(ll j = 0; j<m; j++) {
            if(a[i][j] != 'T') {
                cout << a[i][j];
                continue;
            }
            ll v = i*m+j; v *= 4;
            bool vc = (c[v+1]>c[v]), uc = (c[v+3]>c[v+2]);
            if(vc & uc) {
                a[i][j] ='2';
            }
            if(!vc & uc) {
                a[i][j] = '1';
            }
            if(vc & !uc) {
                a[i][j] = '3';
            }
            if(!vc & !uc) {
                a[i][j] = '4';
            }
            cout << a[i][j];
        }
        cout << '\n';
    }

    return 0;
}