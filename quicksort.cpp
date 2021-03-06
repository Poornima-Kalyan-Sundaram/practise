/*
quick sort
*/
#include<iostream>
#include<stdio.h>

using namespace std;

int a[20];

int partition(int left,int right, int*a)
{
	//chose some pivot element- in this case i choose the middle one
	int pivot=(left+right)/2;
	int b[10],c[10],i=left,j=0;
	int k=0;
	int pivot_element=a[pivot];

	//b is the left side ,c is the right side
	while(i<=right)
	{
		if(a[i]!=pivot_element)
		{
			if(a[i]<a[pivot])
			{
				b[j++]=a[i];
			}
			else
			{
				c[k++]=a[i];
			}
		}		
		i++;
				
	}


	//combine
	i=left;
	cout<<"left is"<<left<<"left side"<<endl;
	for(int q=0;q<j;q++)
	{a[i++]=b[q];cout<<b[q];}
	cout<<endl;
	j=i;
	cout<<"pivot"<<pivot_element<<endl;
	a[i++]=pivot_element;

	cout<<"right is"<<right<<"right side"<<endl;

	for(int p=0;p<k;p++)
	{a[i++]=c[p];cout<<c[p];}
	cout<<endl;

	cout<<"after every sort"<<endl;
	for(int i=0;i<4;i++)
	cout<<a[i]<<" ";
	cout<<"\n================"<<endl;
	return j; //return the new position of the pivot
}


void quicksort(int left,int right,int *a)
{
	
	int index=partition(left,right,a);
	if(left<right)
	{
	quicksort(left,index,a);
	quicksort(index+1,right,a);
	}
}


int main()
{
	int size;
	cin>>size;
	for(int i=0;i<size;i++)
	cin>>a[i];

	quicksort(0,size-1,a);

	for(int i=0;i<size;i++)
	cout<<a[i]<<" ";

	return 0;
}
