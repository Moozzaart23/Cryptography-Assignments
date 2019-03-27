#include<bits/stdc++.h>
#include<bits/stdc++.h>
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define ll long long int
#define pb push_back
#define mp make_pair
const ll MOD=pow(10,9)+7;
using namespace std;
string msg;
string key;
int n;
string encrypt(string msg)
{
	string c="";
	int col=key.length();
	int row=msg.length()/col;
	if(msg.length()%col)
		row+=1;
	string matrix[row];
	int o=msg.length();
	int t=0;
	
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col && (t<o);j++)
			matrix[i]+=msg[t++];
		while(matrix[i].length()<col)
			matrix[i]+='*';
	}
	string matrix2[row];
	for(int i=0;i<row;i++)
	{
		vector <pair<char,char>> vect;
		for(int j=0;j<col;j++)
		{
			vect.pb(mp(key[j],matrix[i][j]));
		}
		sort(vect.begin(),vect.end());
		for(auto it:vect)
		{
			matrix2[i]+=it.second;
		}
	}
	for(int i=0;i<col;i++)
		for(int j=0;j<row;j++)
			c+=matrix2[j][i];
	return c;
}
int main()
{
	getline(cin,msg);
	string m="";
	string msg1="";
	for(int i=0;i<msg.length();i++)
	{
		if(msg[i]!=' ')
			msg1+=msg[i];
	}
	cin>>key;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		m=encrypt(msg1);
		msg1=m;
	}
	cout<<m;
}
