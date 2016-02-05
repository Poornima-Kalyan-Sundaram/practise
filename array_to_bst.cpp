/*
Sorted array to balanced bst
-traverse the array from mid point
includes both quick sort and merge sort
*/
#include<stdlib.h>
#include<iostream>
using namespace std;
int a[10],size;


struct node
{
	int data;
	node*left;
	node*right;
	int height;
}*root=NULL,*tmp;


void merge(int left,int right,int*a)
{
	int mid=(left+right)/2;
	int c[10];
	int i=left,j=mid+1,k=0;
	while(i<=mid&&j<=right)
	{
		if(a[i]<a[j])
		{
			c[k++]=a[i];
			i++;
		}
		else
		{
			c[k++]=a[j];
			j++;
		}
	
	}

	while(i<=mid)
	{
		c[k++]=a[i];
		i++;
	}


	while(i<=mid&&j<=right)
	{
		c[k++]=a[j];
		j++;
	
	}
	for(i=left,j=0;i<=right;i++,j++)
	a[i]=c[j];

}

void merge_sort(int left,int right,int*a)
{
	if(left<right)
	{
		int mid=(left+right)/2;
		merge_sort(left,mid,a);
		merge_sort(mid+1,right,a);
		merge(left,right,a);
	}
}

node* insert(node*ptr,int obj,int h)
{
	tmp=(node*)malloc(sizeof(struct node));
	if(ptr==NULL)
	{
		ptr=tmp;
		tmp->left=NULL;
		tmp->right=NULL;
		tmp->data=obj;
		tmp->height=h;
	}
	else
	{
		if(obj<ptr->data)
		ptr->left=insert(ptr->left,obj,h+1);
		else
		ptr->right=insert(ptr->right,obj,h+1);
	}
	return ptr;
}

int max_height=-1;
void dfs(node*ptr)
{
	if(ptr==NULL)
	return;
	else
	{
		if(ptr->height>max_height)
		{
			max_height=ptr->height;
		}
		
		if(ptr->left)
		{
			dfs(ptr->left);
		}
		if(ptr->right)
		{
			dfs(ptr->right);
		}
	}
}

int partition(int left,int right,int*a)
{
	int pivot=(left+right)/2;
	int pivot_element=a[pivot];
	int leftbuf[10],rightbuf[10],leftsize=0,rightsize=0,j;
	int i=left;
	while(i<pivot)
	{
		if(a[i]<a[pivot])
		{
			leftbuf[leftsize++]=a[i];
		}
		else
		{
			rightbuf[rightsize++]=a[i];
		}
	
		i++;
	}


	i=pivot+1;
	while(i<=right)
	{
		if(a[i]<a[pivot])
		{
			leftbuf[leftsize++]=a[i];
		}
		else
		{
			rightbuf[rightsize++]=a[i];
		}
	
		i++;
	}
	
	for(i=0,j=left;i<leftsize;i++,j++)
	a[j]=leftbuf[i];

	a[j]=pivot_element;

	for(i=0,j=pivot+1;i<rightsize;i++,j++)
	a[j]=rightbuf[i];
	
	return left+leftsize;
}

void quick_sort(int left,int right,int*a)
{
	int index=partition(left,right,a);
	if(left<right)
	{
		quick_sort(left,index,a);
		quick_sort(index+1,right,a);
	}
	
}
int main()
{
	cin>>size;

	for(int i=0;i<size;i++)
	cin>>a[i];	
	
	quick_sort(0,size-1,a);


	for(int i=0;i<size;i++)
	cout<<a[i]<<" ";	

	int mid=(size)/2;
	int j=size-1;
	root=insert(root,a[mid],0);
	for(int i=0;i<mid;i++,j--)
	{
		insert(root,a[i],0);
		insert(root,a[j],0);	
	}

	dfs(root);

	cout<<endl<<max_height;
	return 0;
}
