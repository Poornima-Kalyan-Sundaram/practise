

#include<iostream>
#include<string>
#include<map>

#include <sstream>


using namespace std;
int main()
{
	string str;
	map<char,int> hash_table;
	map<char,int>::iterator it;
	string s;

ostringstream convert;   // stream used for the conversion

	cin>>str;
	for(int i=0;i<str.length();i++)
	{
		hash_table[str[i]]++;
	}
	for(it=hash_table.begin();it!=hash_table.end();it++)
	{
		s+=(*it).first;
		convert << ((*it).second);
		s+=convert.str();
	}	
	cout<<s;
	return 0;
}

