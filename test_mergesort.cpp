#include<iostream>
#include<stdio.h>

using namespace std;

int a[10],c[10],size;


void merge(int *a,int low, int high)
{
	int i,j,k,c[10];
	i=low;
	k=low;
	int mid=(low+high)/2;
	j=mid+1;
		
	while(i<=mid&&j<=high)
	{
		if(a[i]<a[j])
		{
			c[k]=a[i];
			i++;
			k++;
		}
		else
		{
			c[k]=a[j];
			j++;
			k++;
		}
	}
	
	while(i<=mid)
	{
		c[k]=a[i];
		i++;
		k++;
	}
	
	while(j<=high)
	{
		c[k]=a[j];
		j++;
		k++;
	}

	for(i=low;i<k;i++)
	a[i]=c[i];
}


void merge_sort(int *a,int low, int high)
{
	if(low<high)
	{
		int mid=(low+high)/2;
		
		merge_sort(a,low,mid);
		
		merge_sort(a,mid+1,high);
		
		merge(a,low,high);
	}
	return;
}

int main()
{
	cin>>size;
	
	for(int i=0;i<size;i++)
	cin>>a[i];
	
	merge_sort(a,0,size-1);


	for(int i=0;i<size;i++)
	cout<<a[i];

	return 0;
}
