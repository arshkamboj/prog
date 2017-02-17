//find the longest palindrome subtsring o(n2) for odd length sequences
#include<iostream>
#include<string>
using namespace std;

int longestPalindrome(string str,int n){
    int *len=new int[n];
    len[0]=1;
    int j1,j2;
 for(int i=1;i<n;i++)   {
     j1=i;j2=i;
     while(j1>=0 && j2<n && str[j1-1]==str[j2+1] ){
         j1=j1-1;j2=j2+1;
     }
     len[i]=j2-j1+1;
    
 }
 int max=len[0];
 for(int i=1;i<n;i++)   {
     if(max<len[i])
     max=len[i];
 }
 return max;
}

int main()
{
    string str="forgeeksskeegfor",newstr;
    int len=str.length(),i=0,j=0,max;
    if(len%2==0)
    {
        while(j<len){
        newstr[i++]='$';
        newstr[i++]=str[j++];
        }
        newstr[i++]='$';
        max=longestPalindrome(newstr,2*len+1);
    }
    else
    max =longestPalindrome(str,len);
    
    if(len%2==0)
        cout<<"longest palindrome subtsring :"<<endl<<max/2;
    else
        cout<<"longest palindrome subtsring :"<<endl<<max;
 
    return 0;
}