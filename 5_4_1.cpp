//do a left shit->check if the first bit ..
//do a right shift -> check if the last bit is a one

#include<stdio.h>
#include<bitset>
#include<iostream>
using namespace std;
int main()
{
	int x;
	int k;
	cin>>x;
	string s;
	for(int i=0;i<32;i++)
	{
		k=x>>i;

		if(k&1)
		s.push_back('1');
		else
		s.push_back('0');
	
	}

	//reverse the string
	char temp;
	int j=s.length()-1;
	for(int i=0;i<s.length()/2;i++,j--)
	{
		temp=s[i];
		s[i]=s[j];
		s[j]=temp;
	}


	bitset <32>b(s);

	int i;
	for( i=31;i>=0;i--)
	{
		if(b[i]==1)
		{break;}
	}

	int first_one;
	if(i>0)
	 first_one=i+1;
	else
	 first_one=0;

	
	cout<<b<<endl;	

	if(b[31]==1)
	{
		b<<=1;
		b[0]=1;
	}
	if(b[0]==1)
	{
		b>>=1;
		b[first_one]=1;
	}

	cout<<endl;
	cout<<b<<endl;
	return 0;
}
