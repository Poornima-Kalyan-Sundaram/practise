//knuth morris pratt algorithm
#include<iostream>
#include<stdio.h>

using namespace std;

int prefix[10];
char substr[20];
char str[50];
int len=0;
int len1=0;
int main()
{

	//prefix table creation
	for(int i=0;i<10;i++)
	prefix[i]=0;
	cout<<"enter the string"<<endl;
	cin>>str;
	cout<<"enter the substring"<<endl;
	cin>>substr;
	
	int a=0,i;
	for(i=1;str[i]!='\0';i++);
	len1=i;
	
		
	for( i=1;substr[i]!='\0';i++)
	{
		if(substr[i]==substr[a])
		{
			cout<<"i is"<<i<<"a is"<<a<<endl;
			prefix[i]=a+1;

			a++;
			cout<<"a is"<<a<<endl;
		}
		else
		a=0;
	}	
	len=i;
	cout<<endl;
	for(int i=0;substr[i]!='\0';i++)
	{
		cout<<prefix[i]<<" "<<endl;
	}
	cout<<endl;

	//string matching
	/*
	whenever we have a mismatch , we shift the pattern by the prefix value stored
	*/
	int j=0;i=0;
	while(i<len1)
	{
		if(str[i]==substr[j])
		{
			i++;		
			j++;
			if(j==len)
			{
				cout<<"hi"<<" "<<i-len<<endl;
				break;
			}

		}
		else
		{
			if(prefix[j]>0)
			{
				//shift your substring
				j-=prefix[j];
				
	
			}
			else
			i++;
		}
	}
	return 0;
}
