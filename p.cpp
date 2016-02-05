
#include<iostream>
using namespace std;
int pow(int a,int b)
{
	int res = 1;
	while(b)
	{
		if (b&1)
		res *=a;
		b >>=1;
		a *=a;
	}
	return res;
}
int main()
{
	cout<<pow(3,3);
	return 0;
}
