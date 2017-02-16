#include<stdio.h>
#include<iostream>
#include<stack> 
#include<string>
using namespace std;

bool isPair(char a,char b){
    if(a=='[' && b==']')
     return true;
    else if(a=='{' && b=='}')
     return true;
    else if(a=='(' && b==')')
     return true;
    else
    return false;
}

bool balanceParanthesis(string str){
    stack<char> c;
 for(int i=0;i<str.length();i++){
     if(str[i]=='{' ||str[i]=='[' ||str[i]=='(' )
     c.push(str[i]);
     if(str[i]=='}' ||str[i]==']' ||str[i]==')' ){
         
         if(isPair(c.top(),str[i]))
         c.pop();
         else
         return false;
     }
 }   
 if(!c.empty())
 return false;
 else
 return true;
}

int main()
{
  string str="{()}[]{";
  bool res=balanceParanthesis(str);
  if(res==true)
  cout<<"parantesis balanced";
  else
  cout<<"parantesis not balanced";
  return 0;
}