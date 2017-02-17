//Check whether two strings are anagram of each other STL

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){
  string string1="listen",string2="silent";
  sort(string1.rbegin(),string1.rend());
  sort(string2.rbegin(),string2.rend());
  if(string1==string2)
  cout<<"strings are anagram";
  else
  cout<<"strings are not anagram";
  return 0;
}