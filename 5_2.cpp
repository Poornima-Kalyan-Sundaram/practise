#include<iostream>
#include<stdio.h>
#include<math.h>
#include<string>
using namespace std;

string convert_int_binary(int x)
{
	string s;
	int temp;
	for(int i=0;i<32;i++)
	{
		temp = x >> i;
		if(temp&1)
		{
			s.push_back('1');
		}
		else
		{
			s.push_back('0');	
		}		
	}
	
	char temp_char;
	//reverse the string
	int j=s.length()-1;
	for(int i=0;i<s.length()/2;i++,j--)
	{
		temp_char=s[i];
		s[i]=s[j];
		s[j]=temp_char;
	}

	return s;
}

string convert_double_binary(double d)
{

	string s;

	double t;
	if(d>0)
	{
		
		//iterate for 32 times
		for(int i=0;i<32;i++)
		{
			t=d*2;
			if(t>=1)
			{
				s.push_back('1');

			}
			else if(t<1&&t>0)
			{

				s.push_back('0');

			}
			else //edge case
			{
				break;
			}
			
			d=t-floor(t);
		}
	}
	else
	{
		s.push_back('0');	
	}



	char temp_char;
	//reverse the string
	int j=s.length()-1;
	for(int i=0;i<s.length()/2;i++,j--)
	{
		temp_char=s[i];
		s[i]=s[j];
		s[j]=temp_char;
	}

	
	return s;		
}

string resize_intbinary_string(string s)
{
	for(int i=0;i<s.length();i++)
	{
		if(s[i]==1)
		break;
	}
	return s.substr(i);
}

int main()
{
	double num;
	cin>>num;
	string s1=convert_double_binary(num-floor(num));
	
	if(s1.length()>32)
	{
		cout<<"cant represent"<<endl;
		return -1;
	}
	cout<<endl;


	string s2=convert_int_binary(floor(num));		


	cout<<resize_int_string(s2);

	return 0;
}
