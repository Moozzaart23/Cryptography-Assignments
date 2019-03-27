#include<bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define ll long long int
#define pb push_back
#define mp make_pair
const ll mod=pow(10,9)+7;
using namespace std;
string xorr="0000000000000000";
void xor1(string a)
{
	int l1=xorr.length();
	int l2=a.length();
	if(l2<l1)
	{
		for(int i=0;i<(l1-l2);i++)
			a='0'+a;
	}
	//cout<<"a= "<<a<<"\n";
	for(int i=0;i<xorr.length();i++)
	{
		if(xorr[i]=='0' && a[i]=='0')
			xorr[i]='0';
		else if(xorr[i]=='1' && a[i]=='1')
			xorr[i]='0';
		else if  (  (xorr[i]=='0' && a[i]=='1')   || (xorr[i]=='1' && a[i]=='0')    )
			xorr[i]='1';
	}
	//cout<<"xor= "<<xorr<<"\n";
}
int getdegree(string a)
{
	int n=a.length();
	for(int i=0;i<n;i++)
	{
		if(a[i]=='1')
			return i;
	}
	return -1;
}
int main()
{
	string a,b,c;
	cin>>a>>b>>c;
	int deg1=c.length()-1;
	for(int i=b.length()-1;i>=0;i--)
	{
		string copy=a;
		if(b[i]=='1')
		{
			//cout<<"lol2\n"<<i<<"\n";
			for(int j=0;j<(b.length()-1-i);j++)
			{
				copy.pb('0');	
				//cout<<"lol\n";
			}
			xor1(copy);
		}
		//cout<<copy<<"\n";
		//xor1(copy);
	}
	//cout<<xorr<<"\n";
	
	
	
	
	
	
	
	
	
	
	
	
	
	int deg21=getdegree(xorr);
	int deg2=xorr.length()-1-getdegree(xorr);
	//cout<<deg2<<"\n";
	if(deg21==-1)
	{
		cout<<0;
		return 0;
	}
	if(deg2<deg1)
	{
		string ans=xorr.substr(deg21,xorr.length()-deg21);
		cout<<ans;
		return 0;
	}
	if(deg2==deg1)
	{
		//int y=getdegree2(c);
		//cout<<y<<"\n";
		xor1(c);
		int y=getdegree(xorr);
		string ans=xorr.substr(y,xorr.length()-y);
		cout<<ans;
		return 0;
	}
	//cout<<"deg1= "<<deg1<<"\n";
	//cout<<deg2<<"\n";
	while(deg2>deg1)
	{
		int x=deg2-deg1;
		//cout<<x<<"\n";
		string copy=c;
		for(int i=0;i<x;i++)
		{
			copy+='0';
		}
		//deg2=xorr.length()-1-getdegree(xorr);
		//cout<<deg2<<"\n";
		//cout<<"copy= "<<copy<<"\n";
		xor1(copy);
		//cout<<"xorr= "<<xorr<<"\n";
		deg2=xorr.length()-1-getdegree(xorr);
		//cout<<deg2<<"\n";
		if(deg2==deg1)
		{
			xor1(c);
			int y=getdegree(xorr);
			
			if(y!=-1)
			{
				string ans=xorr.substr(y,xorr.length()-y);
					cout<<ans;
			}
			
			else
				cout<<0;
			return 0;
		}
		//cout<<deg2<<"\n";
	}
	//cout<<xorr<<"\n";
	int d=getdegree(xorr);
	//cout<<d<<"\n";
	
	if(d!=-1)
	{
		string ans=xorr.substr(d,xorr.length()-d);
		cout<<ans;
	}
		
	else
		cout<<0;
	return 0;
}

