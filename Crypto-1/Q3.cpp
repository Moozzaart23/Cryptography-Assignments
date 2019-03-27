#include<bits/stdc++.h>
#include<bits/stdc++.h>
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define ll long long int
#define pb push_back
const ll MOD=pow(10,9)+7;
using namespace std;
char matrix[6][6];
void get(char a,char b)
{
	//cout<<a<<" "<<b<<endl;
	int x1=-1;int y1=-1;int x2=-1;int y2=-1;
	for(int i=0;i<6;i++)
	{
		for(int j=0;j<6;j++)
		{
			if(matrix[i][j]==a)
			{
				x1=i;
				y1=j;
			}
			if(matrix[i][j]==b)
			{
				x2=i;
				y2=j;
			}
		}
	}
	//cout<<x1<<" "<<y1<<endl;
	//cout<<x2<<" "<<y2<<endl;
	if(x1==x2)
	{
		y1=y1+1;
		y2=y2+1;
		if(y1>5)
			y1=0;
		if(y2>5)
			y2=0;
		cout<<matrix[x1][y1]<<matrix[x2][y2];
	}
	else if(y1==y2)
	{
		x1=x1+1;
		x2=x2+1;
		if(x1>5)
			x1=0;
		if(x2>5)
			x2=0;
		cout<<matrix[x1][y1]<<matrix[x2][y2];
	}
	else
	{
		cout<<matrix[x1][y2]<<matrix[x2][y1];
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
	for(int i=0;i<b.length();i=i+2)
	{
		if(b[i]==b[i+1])
		{
			b.insert(b.begin()+(i+1),'X');
		}
	}
	if((b.length())%2!=0)
		b+='X';
	//cout<<b;
	string c;
	cin>>c;
	int l=c.length();
	//cout<<b<<endl;
	int visited[100005]={0};
	
	for(int i=0;i<6;i++)
	{
		for(int j=0;j<6;j++)
		{
			matrix[i][j]='.';
		}
	}
	for(int i=0,k=0;i<6;i++)
	{
		for(int j=0;j<6;)
		{
			//cout<<c[k]<<" "<<visited[c[k]]<<endl;
			if(c[k]!=' ' && !visited[c[k]])
			{
				matrix[i][j]=c[k];
				visited[c[k]]=1;
				//k++;
				j++;
			}
			k++;
			if(k>=l)
				break;
		}
		if(k>=l)
			break;
	}
	char m='0';
	for(int i=0;i<6;i++)
	{
		for(int j=0;j<6;)
		{
			if(matrix[i][j]=='.')
			{
				if(!visited[m])
				{
					matrix[i][j]=m;
					j++;
				}
				m++;
			}
			else
				j++;
			if(m>'9')
				break;
		}
		if(m>'9')
			break;
		//cout<<endl;
	}
	char m1='A';
	for(int i=0;i<6;i++)
	{
		for(int j=0;j<6;)
		{
			if(matrix[i][j]=='.')
			{
				if(!visited[m1])
				{
					matrix[i][j]=m1;
					j++;
				}
				m1++;
			}
			else
				j++;
			if(m1>'Z')
				break;
		}
		if(m1>'Z')
			break;
		//cout<<endl;
	}
	for(int i=0;i<6;i++)
	{
		for(int j=0;j<6;j++)
		{
			if(matrix[i][j]=='.')
				matrix[i][j]='X';
		}
	}
	/*for(int i=0;i<6;i++)
	{
		for(int j=0;j<6;j++)
		{
			cout<<matrix[i][j]<<" ";
		}
		cout<<endl;
	}
	//COUT<<ENDL;
	cout<<endl;*/
	for(int i=0;i<b.length();i=i+2)
	{
		get(b[i],b[i+1]);
	}
}
