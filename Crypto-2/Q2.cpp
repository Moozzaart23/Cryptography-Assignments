#include<bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define ll long long int
#define pb push_back
#define mp make_pair
const ll mod=pow(10,9)+7;
using namespace std;
map <char,string>  m {  {'0',"0000"} , {'1',"0001"},  {'2',"0010"},  {'3',"0011"},  {'4',"0100"}, {'5',"0101"}, {'6',"0110"}, {'7',"0111"}, {'8',"1000"}, 
						{'9',"1001"}, {'A',"1010"}, {'B',"1011"}, {'C',"1100"},  {'D',"1101"},  {'E',"1110"}, {'F',"1111"}};
map <string,char>  m1 {  {"0000",'0'} , {"0001",'1'},  {"0010",'2'},  {"0011",'3'},  {"0100",'4'}, {"0101",'5'}, {"0110",'6'}, {"0111",'7'}, {"1000",'8'}, 
						{"1001",'9'}, {"1010",'A'}, {"1011",'B'}, {"1100",'C'},  {"1101",'D'},  {"1110",'E'}, {"1111",'F'}};
map <string,int> m2 {  {"0000",0} , {"0001",1},  {"0010",2},  {"0011",3},  {"0100",4}, {"0101",5}, {"0110",6}, {"0111",7}, {"1000",8}, 
						{"1001",9}, {"1010",10}, {"1011",11}, {"1100",12},  {"1101",13},  {"1110",14}, {"1111",15},};
map <char,string>  m3 {  {0,"0000"} , {1,"0001"},  {2,"0010"},  {3,"0011"},  {4,"0100"}, {5,"0101"}, {6,"0110"}, {7,"0111"}, {8,"1000"}, 
						{9,"1001"}, {10,"1010"}, {11,"1011"}, {12,"1100"},  {13,"1101"},  {14,"1110"}, {15,"1111"}};					
int PC1[56] = {
   57, 49, 41, 33, 25, 17,  9,
    1, 58, 50, 42, 34, 26, 18,
   10,  2, 59, 51, 43, 35, 27,
   19, 11,  3, 60, 52, 44, 36,
   63, 55, 47, 39, 31, 23, 15,
    7, 62, 54, 46, 38, 30, 22,
   14,  6, 61, 53, 45, 37, 29,
   21, 13,  5, 28, 20, 12,  4
  };
  int PC2[48] = {
    14, 17, 11, 24,  1,  5,
    3, 28, 15,  6, 21, 10,
    23, 19, 12,  4, 26,  8,
    16,  7, 27, 20, 13,  2,
    41, 52, 31, 37, 47, 55,
    30, 40, 51, 45, 33, 48,
    44, 49, 39, 56, 34, 53,
    46, 42, 50, 36, 29, 32
  };
  int IP[64] = {
    58, 50, 42, 34, 26, 18, 10,  2,
    60, 52, 44, 36, 28, 20, 12,  4,
    62, 54, 46, 38, 30, 22, 14,  6,
    64, 56, 48, 40, 32, 24, 16,  8,
    57, 49, 41, 33, 25, 17,  9,  1,
    59, 51, 43, 35, 27, 19, 11,  3,
    61, 53, 45, 37, 29, 21, 13,  5,
    63, 55, 47, 39, 31, 23, 15,  7};
    
    int Expansion[48] = {
    32,  1,  2,  3,  4,  5,  4,  5,
     6,  7,  8,  9,  8,  9, 10, 11,
    12, 13, 12, 13, 14, 15, 16, 17,
    16, 17, 18, 19, 20, 21, 20, 21,
    22, 23, 24, 25, 24, 25, 26, 27,
    28, 29, 28, 29, 30, 31, 32,  1};
    
    
    int SBox[8][4][16] = {
     {
     {14,  4, 13,  1,  2, 15, 11,  8,  3, 10,  6, 12,  5,  9,  0,  7},
     { 0, 15,  7,  4, 14,  2, 13,  1, 10,  6, 12, 11,  9,  5,  3,  8},
     { 4,  1, 14,  8, 13,  6,  2, 11, 15, 12,  9,  7,  3, 10,  5,  0},
     {15, 12,  8,  2,  4,  9,  1,  7,  5, 11,  3, 14, 10,  0,  6, 13},
     },
 
     {
     {15,  1,  8, 14,  6, 11,  3,  4,  9,  7,  2, 13, 12,  0,  5, 10},
     { 3, 13,  4,  7, 15,  2,  8, 14, 12,  0,  1, 10,  6,  9, 11,  5},
     { 0, 14,  7, 11, 10,  4, 13,  1,  5,  8, 12,  6,  9,  3,  2, 15},
     {13,  8, 10,  1,  3, 15,  4,  2, 11,  6,  7, 12,  0,  5, 14,  9},
     },
 
     {
     {10,  0,  9, 14,  6,  3, 15,  5,  1, 13, 12,  7, 11,  4,  2,  8},
     {13,  7,  0,  9,  3,  4,  6, 10,  2,  8,  5, 14, 12, 11, 15,  1},
     {13,  6,  4,  9,  8, 15,  3,  0, 11,  1,  2, 12,  5, 10, 14,  7},
     { 1, 10, 13,  0,  6,  9,  8,  7,  4, 15, 14,  3, 11,  5,  2, 12},
     },
 
     {
     { 7, 13, 14,  3,  0,  6,  9, 10,  1,  2,  8,  5, 11, 12,  4, 15},
     {13,  8, 11,  5,  6, 15,  0,  3,  4,  7,  2, 12,  1, 10, 14,  9},
     {10,  6,  9,  0, 12, 11,  7, 13, 15,  1,  3, 14,  5,  2,  8,  4},
     { 3, 15,  0,  6, 10,  1, 13,  8,  9,  4,  5, 11, 12,  7,  2, 14},
     },
 
     {
     { 2, 12,  4,  1,  7, 10, 11,  6,  8,  5,  3, 15, 13,  0, 14,  9},
     {14, 11,  2, 12,  4,  7, 13,  1,  5,  0, 15, 10,  3,  9,  8,  6},
     { 4,  2,  1, 11, 10, 13,  7,  8, 15,  9, 12,  5,  6,  3,  0, 14},
     {11,  8, 12,  7,  1, 14,  2, 13,  6, 15,  0,  9, 10,  4,  5,  3},
     },
 
     {
     {12,  1, 10, 15,  9,  2,  6,  8,  0, 13,  3,  4, 14,  7,  5, 11},
     {10, 15,  4,  2,  7, 12,  9,  5,  6,  1, 13, 14,  0, 11,  3,  8},
     { 9, 14, 15,  5,  2,  8, 12,  3,  7,  0,  4, 10,  1, 13, 11,  6},
     { 4,  3,  2, 12,  9,  5, 15, 10, 11, 14,  1,  7,  6,  0,  8, 13},
     },
 
     {
     { 4, 11,  2, 14, 15,  0,  8, 13,  3, 12,  9,  7,  5, 10,  6,  1},
     {13,  0, 11,  7,  4,  9,  1, 10, 14,  3,  5, 12,  2, 15,  8,  6},
     { 1,  4, 11, 13, 12,  3,  7, 14, 10, 15,  6,  8,  0,  5,  9,  2},
     { 6, 11, 13,  8,  1,  4, 10,  7,  9,  5,  0, 15, 14,  2,  3, 12},
     },
 
     {
     {13,  2,  8,  4,  6, 15, 11,  1, 10,  9,  3, 14,  5,  0, 12,  7},
     { 1, 15, 13,  8, 10,  3,  7,  4, 12,  5,  6, 11,  0, 14,  9,  2},
     { 7, 11,  4,  1,  9, 12, 14,  2,  0,  6, 10, 13, 15,  3,  5,  8},
     { 2,  1, 14,  7,  4, 10,  8, 13, 15, 12,  9,  0,  3,  5,  6, 11},
     },};
     int PBox[32] = {
      16,  7, 20, 21, 29, 12, 28, 17,
       1, 15, 23, 26,  5, 18, 31, 10,
       2,  8, 24, 14, 32, 27,  3,  9,
      19, 13, 30,  6, 22, 11,  4, 25
  };
int d[16]={1,1,2,2,2,2,2,2,1,2,2,2,2,2,2,1};
void leftrotate(string &s, int d) 
{ 
	//string s=s1;
    reverse(s.begin(), s.begin()+d); 
    reverse(s.begin()+d, s.end()); 
    reverse(s.begin(), s.end()); 
    //cout<<"rotated= "<<s<<"\n";
    //return s;
}
int main()
{
	string msg;
	string key;
	cin>>msg>>key;
	string get;
	for(int i=0;i<key.length();i++)
	{
		get.append(m[key[i]]);
	}
	//cout<<get<<"\n";
	string get2;
	string keyy;
	for(int i=0;i<56;i++)
	{
		//cout<<PC1[i]<<" ";
		//cout<<get[i];
		get2.pb(get[PC1[i]-1]);
	}
	//cout<<get2<<"\n";
	string c0=get2.substr(0,28);
	string d0=get2.substr(28,56);
	//cout<<c0<<"\n";
	for(int i=0;i<16;i++)
	{
		leftrotate(c0,d[i]);
		//cout<<c0<<"\n";
		leftrotate(d0,d[i]);
		string key1=c0+d0;
		//cout<<key1<<"\n";
		string key2;string key3;
		for(int j=0;j<48;j++)
		{
			key2.pb(key1[PC2[j]-1]);
		}
		for(int j=0;j<key2.length();j+=4)
		{
			key3+=(m1[key2.substr(j,4)]);
		}
		cout<<key3<<"\n";
		if(i==0)
			keyy=key3;
	}
	string gett;
	for(int i=0;i<key.length();i++)
	{
		gett.append(m[msg[i]]);
	}
	string gett2;
	//string key3;
	for(int i=0;i<64;i++)
	{
		//cout<<PC1[i]<<" ";
		//cout<<get[i];
		gett2.pb(gett[IP[i]-1]);
	}
	string keyyy;
	for(int i=0;i<keyy.length();i++)
	{
		keyyy+=(m[keyy[i]]);
	}
	//cout<<
	string l0=gett2.substr(0,32);
	string r0=gett2.substr(32,64);
	string l1=r0;
	string r00;
	for(int i=0;i<48;i++)
	{
		r00.pb(r0[Expansion[i]-1]);
	}
	//cout<<r00<<"\n";
	for(int i=0;i<48;i++)
	{
		//cout<<keyyy[i]<<" "<<r00[i]<<" ";
		if(keyyy[i]=='0' && r00[i]=='0')
			r00[i]='0';
		else if(keyyy[i]=='1' && r00[i]=='1')
		{
			r00[i]='0';
			//cout<<"lol\n";
		}
			//r00[i]='0';
		else if(  (keyyy[i]=='0' && r00[i]=='1')  ||  (keyyy[i]=='1' && r00[i]=='0')  )
			r00[i]='1';
		//cout<<r00[i]<<"\n";
	}
	//cout<<keyy<<"\n";
	//cout<<keyyy<<"\n";
	//cout<<r00<<"\n";
	string lol;int e=0;
	for(int i=0;i<48;i=i+6)
	{
		string m8=r00.substr(i,6);
		//cout<<m8<<"\n";
		string n=std::string()+m8[0]+m8[5];
		//cout<<m8[0]<<m8[5]<<"\n";
		//cout<<n<<"\n";
		int r=-1;int c=-1;
		if(n=="00")
			r=0;
		else if(n=="01")
			r=1;
		else if(n=="10")
			r=2;
		else if(n=="11")
			r=3;
		string r1=std::string()+m8[1]+m8[2]+m8[3]+m8[4];
		//cout<<r1<<"\n";
		c=m2[r1];
		//lol+=S[e][r][c];
		lol+=m3[SBox[e][r][c]];
		e=e+1;
	}
	//cout<<lol<<"\n";
	string lol2;
	for(int i=0;i<32;i++)
	{
		lol2+=lol[PBox[i]-1];
	}
	for(int i=0;i<lol2.length();i++)
	{
		if(lol2[i]=='0' && l0[i]=='0')
			lol2[i]='0';
		else if(lol2[i]=='1' && l0[i]=='1')
			lol2[i]='0';
		else if(  (lol2[i]=='0' && l0[i]=='1')  ||  (lol2[i]=='1' && l0[i]=='0')  )
			lol2[i]='1';
	}
	//cout<<l1.length()<<"\n";
	//cout<<l1<<"\n";
	for(int i=0;i<32;i=i+4)
	{
		string x=l1.substr(i,4);
		//cout<<x<<"\n";
		cout<<m1[x];
	}
	for(int i=0;i<32;i=i+4)
	{
		cout<<m1[lol2.substr(i,4)];
	}
	return 0;
}

