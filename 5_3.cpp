#include<stdio.h>
#include<bitset>
#include<iostream>
using namespace std;

void func(int x)
{
	string s;
	int k;
	for(int i=0;i<32;i++)
	{
		k=x>>i;
		if(k&1)
		s.push_back('1');
		else
		s.push_back('0');
	}
	
	bitset <32>b(s);

	int max_seq_len=-1,j;		
	
	for(int i=0;i<32;i++)
	{
		int zero_set=0;
		//subseq can start with a 0 or 1 
		//subseq must have a zero only once

		for(j=i;j<32;j++)
		{
			if(b[j]==0)
			{
				if(zero_set==0)
					zero_set=1;
				else
				break;
			}
		
		}
		if((j-i)>max_seq_len)
		{
			max_seq_len=j-i;
		}

	}
	
	cout<<"\n"<<max_seq_len<<endl;
}

int main()
{
	int x;
	cin>>x; 
	func(x);
	return 0;
}
