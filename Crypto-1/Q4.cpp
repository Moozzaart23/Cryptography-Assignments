#include<bits/stdc++.h>
#include<bits/stdc++.h>
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define ll long long int
#define pb push_back
#define mp make_pair
const ll MOD=pow(10,9)+7;
using namespace std;
int mod(int x)
{
	if(x>=0)
		return (x%26);
	else
	{
		x*=-1;
		x=x%26;
		x=26-x;
	}
	return x;
}
int inverse(int x)
{
	for(int i=1;i<26;i++)
	{
		if((i*x)%26==1)
			return i;
	}
}
int main()
{
	string a;
	getline(cin,a);
	string b="";
	for(int i=0;i<a.length();i++)
	{
		if(a[i]!=' ')
		{
			if(islower(a[i]))
				b+=toupper(a[i]);
			else
				b+=a[i];
		}
	}
	//cout<<b<<endl;
	if((b.length())%2!=0)
		b+='Z';
	string x,y;
	cin>>x>>y;
	//cout<<x<<y<<endl;
	int plain[2][2]={4,19,19,19};
	int cipher[2][2]={x[0]-'A',x[1]-'A',y[0]-'A',y[1]-'A'};
	int ans[2][2]={0};
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
		{
			for(int k=0;k<2;k++)
			{
				ans[i][j]+=plain[i][k]*cipher[k][j];
			}
		}
	}
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
			ans[i][j]=mod(ans[i][j]);
	}
	
	int det=ans[0][0]*ans[1][1]-ans[0][1]*ans[1][0];
	det=mod(det);
	det=inverse(det);
	ans[0][1]=-ans[0][1];
	ans[1][0]=-ans[1][0];
	int temp=ans[0][0];
	ans[0][0]=ans[1][1];
	ans[1][1]=temp;
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
			ans[i][j]=mod(det*ans[i][j]);
	}
	/*for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
			cout<<ans[i][j]<<" ";
	}*/
	for(int i=0;i<b.length();i=i+2)
	{
		int x=b[i]-'A';
		int y=b[i+1]-'A';
		int u=ans[0][0]*x+ans[1][0]*y;
		int v=ans[0][1]*x+ans[1][1]*y;
		u=mod(u);
		v=mod(v);
		char e=u+'A';
		char f=v+'A';
		cout<<e<<f;
	}
}
