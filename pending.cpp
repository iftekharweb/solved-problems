#include <bits\stdc++.h>

using namespace std;

#define ll long long
#define mo 12345

char ch[1010];
int d[1010];
int dd[1010];
int aa[100];
ll a[130][130];
ll a1[130][130];
ll a2[130][130];
ll a3[130][130];

int main()
{
	int i,j,k,l,m,nn,tmp,n1,ans,b1,b2,b3;
	ll n;
	string s;
	char c;
	cin>>n>>m;
	nn=1;
	for (i=0;i<m;i++)
	{
		cin>>s;
		ch[i]=s[0];
		cin>>d[i];
		nn*=d[i];
	}
	if (n==0)
	{
		printf("1\n");
		return 0;
	}
	memset(a,0,sizeof(a));
	for (i=0;i<nn;i++)
	{
		tmp=i;
		for (j=0;j<m;j++)
		{
			dd[j]=tmp%d[j];
			tmp/=d[j];
		}
		for (c='A';c<='Z';c++)
		{
			b1=0;
			for (j=0;j<m;j++)
				if (ch[j]==c)
				{
					b1=1;
					dd[j]++;
					if (dd[j]==d[j]) dd[j]=0;
				}
			if (b1==1)
			{
				tmp=0;
				for (j=m-1;j>=0;j--)
				{
					tmp*=d[j];
					tmp+=dd[j];
				}
				a[i][tmp]++;
				a[i][tmp]%=mo;
			}
			for (j=0;j<m;j++)
				if (ch[j]==c)
				{
					dd[j]--;
					if (dd[j]<0) dd[j]+=d[j];
				}
		}
	}
	n1=0;
	while (n>0)
	{
		aa[n1]=n%2;
		n1++;
		n/=2;
	}
	memcpy(a1,a,sizeof(a));
	for (i=n1-2;i>=0;i--)
	{
		memset(a2,0,sizeof(a2));
		for (j=0;j<nn;j++)
			for (k=0;k<nn;k++)
			{
				for (l=0;l<nn;l++)
				{
					a2[j][k]+=a1[j][l]*a1[l][k];
				}
				a2[j][k]%=mo;
			}
		if (aa[i]==1)
		{
			memset(a1,0,sizeof(a1));
			for (j=0;j<nn;j++)
				for (k=0;k<nn;k++)
				{
					for (l=0;l<nn;l++)
					{
						a1[j][k]+=a2[j][l]*a[l][k];
					}
					a1[j][k]%=mo;
				}
		}
		else
			memcpy(a1,a2,sizeof(a2));
	}
	ans=0;
	for (i=0;i<nn;i++)
	{
		tmp=i;
		for (j=0;j<m;j++)
		{
			dd[j]=tmp%d[j];
			tmp/=d[j];
		}
		b3=1;
		for (c='A';c<='Z';c++)
		{
			b1=0;
			b2=0;
			for (j=0;j<m;j++)
			{
				if (ch[j]==c)
				{
					b1=1;
					if (dd[j]==0) b2=1;
				}
			}
			if ((b1==1)&&(b2==0)) b3=0;
		}
		if (b3==1)
		{
			ans+=a1[i][0];
			ans%=mo;
		}
	}
	printf("%d\n",ans);
	return 0;
}

