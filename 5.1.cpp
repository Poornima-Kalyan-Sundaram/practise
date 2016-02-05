#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<bitset>
#include<string>
using namespace std;


void func(bitset<11>m,bitset<5>n)
{
	
	int i,j;
	cin>>j;//j bits from the beginning (or 0)
	cin>>i;	//i bits from the end (length -i)

	for(int k=0;k<11;k++)
	cout<<m[k];


	for(int k=0;k<=j-i;k++)
	m[k+i]=n[k];
		
	cout<<endl;

	for(int k=0;k<11;k++)
	cout<<m[k];
}

int main()
{

	string s;
	
	cin>>s;

	bitset <11> m (s);

	cin>>s;
	
	bitset <5> n (s);	

	func(m,n);

	
	
	return 0;
}
