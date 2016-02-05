#include<iostream>
#include<stdio.h>
#include<vector>
#define NEGINF -9999
using namespace std;
/*
	to find the maximum sum of a subarray in O(n) time
def max_subarray(A):
    max_ending_here = max_so_far = A[0]
    for x in A[1:]:
        max_ending_here = max(x, max_ending_here + x)
        max_so_far = max(max_so_far, max_ending_here)
    return max_so_far

*/



void kadane(vector<int>v,int size)
{
	int max_ending_here=v[0];
	int max_so_far=v[0];
	for(int i=0;i<size;i++)
	{
		max_ending_here=max(v[i],max_ending_here+v[i]);
		max_so_far=max(max_so_far,max_ending_here);
	}
	cout<<max_so_far<<endl;
}

int main()
{	
	vector<int> v;
	int size;

	cin>>size;

	int t;
	for(int i=0;i<size;i++)
	{
		cin>>t;
		v.push_back(t);
	}

	kadane(v,size);

	return 0;
}
