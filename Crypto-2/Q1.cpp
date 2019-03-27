#include<bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define ll long long int
#define pb push_back
#define mp make_pair
const ll mod=pow(10,9)+7;
using namespace std;
int main()
{
	ll n;
	ll ans=pow(10,18);
	cin>>n;
	ll c1,n1,c2,n2;
	cin>>c1>>n1;
	cin>>c2>>n2;
	ll r=n/n1; ll p=n/n2;
	int x=0;int y=0;
	for(int i=1;i<=r;i++)
	{
		for(int j=1;j<=p;j++)
		{
			if(n1*i+n2*j==n)
			{
				if(i*c1+j*c2<ans)
				{
					x=i;y=j;
					ans=i*c1+j*c2;
				}
			}
		}
	}
	if(x!=0 && y!=0)
		cout<<x<<" "<<y;
	else
		cout<<"failure";
	return 0;
}

