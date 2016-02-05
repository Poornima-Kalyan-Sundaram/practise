/*
string permutations
*/
#include<stdio.h>
#include<iostream>
#include<stack>
#include<vector>
using namespace std;
stack<char> s[20];

void permutation(string s,string permute,int len)
{
	if(len==s.length())
	{
		cout<<permute<<endl;
		return;
	}
	for(int i=0;i<s.length();i++)
	{
		int flag=0;
		for(int j=0;j<permute.length();j++)
		{
			if(permute[j]==s[i])
			{
				flag=1; 
				break;
			}
		} //point is to add any letters which were already not present in the output string given to us
		if(flag==0)
		{
			
			permutation(s,permute+s[i],len+1);
		}
	}

}

int main()
{
	string str,s="";
	cin>>str;
	permutation(str,s,0);
	return 0;
}
