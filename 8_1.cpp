#include<iostream>
#include<stdio.h>

using namespace std;

int global_variable=0;
int n;

void opt(int i)
{
	if(i-3>0)
	{
		opt(i-3);
	}

	if(i-2>0)
	{
		opt(i-2);

	}

	if(i-1>0)
	{
		opt(i-1);

	}



	if(i-3==0)
	{

		global_variable++;
		return;

	}

	if(i-2==0)
	{
		global_variable++;
		return;

	}

	if(i-1==0)
	{
		global_variable++;
		return;

	}


	if( i-1<0 && i-2<0 && i-3<0 )
	{
		global_variable++;
		return;
	}
}

int main()
{

	cin>>n;
	opt(n);
	cout<<global_variable<<endl;
	return 0;
}
