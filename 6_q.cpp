#include<iostream>
#include<stdio.h>
#include<map>
#include<vector>
using namespace std;
int main()
{
	vector<int>v;
	int size,t;
	cin>>size;
	v.resize(size);	
	map<int,int>hash_table;
	map<int,int>::iterator it;
	for(int i=0;i<size;i++)
	{
		cin>>v[i];
		hash_table[v[i]]++;
	}
	for(it=hash_table.begin();it!=hash_table.end();it++)
	{
		cout<<it->second<<" "<<it->first<<endl;
	}
	return 0;
}
