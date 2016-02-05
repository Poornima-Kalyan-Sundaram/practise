#include<iostream>
#include<stdio.h>
#include<bitset>
#include<string>

using namespace std;

int main()
{
	string s1="11";
	bitset<2>b(s1);
	string s;
	int k;
	
	int x=3;
	for(int i=0;i<2;i++)
	{	
		k=x>>i;
		if(k&1)
		s.push_back('1');
		else
		s.push_back('0');
	}
	
	bitset<2>b1(s);
	//b1<<=1;
	
	for(int i=0;i<2;i++)
	{	
		cout<<b1[i];
	}
	
	
	return 0;
}
