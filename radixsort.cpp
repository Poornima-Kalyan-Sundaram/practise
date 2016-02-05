#include<iostream>
#include<stdio.h>
#include<map>
#include<utility>

using namespace std;

struct n
{
	int a;
	int num_left;
}arr[10];

int main()
{
	multimap<int,n>bucket;

	multimap<int,n>::iterator it;
	
	int size;
	cin>>size;

	int max_num_of_digits;
	cin>>max_num_of_digits;

	for(int i=0;i<size;i++)
	{
		cin>>arr[i].a;
		arr[i].num_left=arr[i].a;
	}

	int radix=0;
	while(radix<max_num_of_digits)
	{
		for(int i=0;i<size;i++)
		{
			int index=(arr[i].num_left)%10;
			arr[i].num_left=arr[i].num_left/10;
			bucket.insert(make_pair(index,arr[i]));
			cout<<arr[i].a<<" "<<arr[i].num_left<<endl;
		}
		
		int i=0;
		//transfer the contents from bucket to array 
		for(it=bucket.begin();it!=bucket.end();it++)
		{
			arr[i].a=(*it).second.a;
			arr[i].num_left=(*it).second.num_left;
			cout<<(*it).first<<" "<<(*it).second.a<<endl;
			i++;
		}
		
		bucket.clear();
		radix++;	
	}

		for(int i=0;i<size;i++)
		{
			cout<<arr[i].a;
		}

	return 0;
}
