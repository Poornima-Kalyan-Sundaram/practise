//log n program
//find the power of a number without using power function
#include<iostream>
#include<stdio.h>
using namespace std;
int num;

int power(int m,int n)
{
	int ret_val=1;
	if(n==1)
	ret_val= m;
	else if(n==2)
	ret_val= m*m;
	else
	{
		if(n%2==0)
		{
			ret_val*= (power(m,n/2)*power(m,n/2));
		}
		else
		{
			ret_val*= (power(m,n/2)*power(m,n/2+1));

		}
	}
	return ret_val;	
}

int main()
{
	cin>>num;
	cout<<power(num,10);
	return 0;
}
