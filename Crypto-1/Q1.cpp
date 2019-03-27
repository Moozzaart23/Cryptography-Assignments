#include<bits/stdc++.h>
#include<bits/stdc++.h>
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define ll long long int
#define pb push_back
//#define mp make_pair
const ll MOD=pow(10,9)+7;
using namespace std;
int main()
{
	string s;
	cin>>s;
	int n=s.length();
	n=n/2;
	n++;
	cout<<s[0];
	for(int i=1;i<n;i++)
	{
		char a=s[i];
		char b=s[i-1];
		//cin>>a>>b;
		//cout<<a<<" "<<b<<endl;
		int x,y,z;
		if(a>='a' && a<='f')	
			x=a-87;
		if(a>='0' && a<='9')
			x=a-48;
		if(b>='a' && b<='f')	
			y=b-87;
		if(b>='0' && b<='9')
			y=b-48;
		//cout<<x<<" "<<y<<endl;
		z=(x^y);
		//cout<<z<<endl;
		char c;
		if(z<10)
			c=z+48;
		else
			c=z+87;
		cout<<c;
	}
}
