#include<iostream>
#include <map>
using namespace std;

int main() {
       map<char,int> unique;4
       string str="abcd";
       //cout<<"Enter String"<<'\n';
       //cin>>str;
       for(int i=0;i<str.length();i++)
           ++unique[str[i]];
           if(unique[str[i]] > 1)
               cout<<"not unique";
           else
               cout<<"unique";
       cout<<endl<<unique['b'];
       return 0;
}

