//heaps
#include<iostream>
#include<stdio.h>

using namespace std;

int a[10],n,curr_size=0;
/*
	insert at the end the new element and percolate up till the root
*/
void insert(int key)
{
	
	//perolcate up
	cout<<"insert function called"<<endl;
	int prev_pos=curr_size,pos=0,temp;	
	a[curr_size++]=key;
	for(int i=curr_size-1;i>0;i/=2)
	{
		
		//cout<<"i loop "<<i<<endl;
		if(key<a[i])
		{
			cout<<"percolated up "<<i<<endl;
			pos=i;
			
			temp=a[pos];
			a[pos]=a[prev_pos];
			a[prev_pos]=temp;
		
			prev_pos=i;
			
		}
	}
	
	//now compare with root
	
	if(key<a[0])
	{
		pos=0;
		
		temp=a[pos];
		a[pos]=a[prev_pos];
		a[prev_pos]=temp;
	
			
	}

	for(int j=0;j<curr_size;j++)
	cout<<a[j]<<" ";
	cout<<endl;
}

/*

take the last element , put it in the root and percolate down

*/

int remove()
{

	//percolate down
	int return_val=a[0];
	
	int parent=0,tmp;

	a[0]=a[n-1];	
		
	cout<<a[0]<<" 0th element"<<endl;
	while(parent<n)
	{
		//compare with the left and right children
		
		int left=2*parent+1;
		int right=2*parent+2;		
		
		if(left>=n||right>=n)
		break;		

		if(a[left]<a[parent]&&left<n)
		{

			tmp=a[parent];
			a[parent]=a[left];
			a[left]=tmp;

			parent=left;
			cout<<a[left]<<" left "<<endl;

		}
		else if(right<n)
		{

			tmp=a[parent];
			a[parent]=a[right];
			a[right]=tmp;

			parent=right;
			cout<<a[right]<<" right "<<endl;

		}

		cout<<parent<<" parent"<<" left "<<left<<" right "<<right<<endl;
	}

	for(int j=0;j<curr_size;j++)
	cout<<a[j]<<" ";
	cout<<endl;


	return return_val;
}

int main()
{
	int x;
	cin>>n;
	cout<<n;
	for(int i=0;i<n;i++)
	{
		cin>>x;
		//cout<<x;
		insert(x);
	}
	cout<<"\nremove\n"<<endl;
	cout<<remove();
	return 0;
}
