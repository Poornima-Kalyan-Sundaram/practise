#include<iostream>
#include<stdio.h>

using namespace std;

int count1=3,count2=0,count3=0;

void move(int n, char src, char dest, char aux)
{
	if(n==0)
	{
		printf("move disc from %c to %c\n",src,dest);
	}
	else
	{
		move(n-1,src,aux,dest);

		//reduce the number of discs in the source and increase the number of discs in dest
		switch(src)
		{
			case 'a':count1--;
			break;
			case 'b':count2--;
			break;
			case 'c':count3--;
			break;
		}

		switch(dest)
		{

			case 'a':count1++;
			break;
			case 'b':count2++;
			break;
			case 'c':count3++;
			break;

		}
		printf("disc moved from %c to %c\n",src,dest);
		move(n-1,aux,dest,src);	
			
	}

}

int main()
{

	move(3,'a','c','b');	
	return 0;
}
