#include <bits\stdc++.h>
using namespace std;
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int vis[105];
    memset(vis,-1,sizeof(vis));
    while(m--){
        int x;
        scanf("%d",&x);
        for(int i=x;i<=n;i++){
            if(vis[i]==-1) vis[i]=x;
        }
    }
    for(int i=1;i<=n;i++) printf("%d ",vis[i]);
    return 0;
}