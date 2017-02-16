// Given a string, print all possible palindromic partitions
#include <iostream>
#include<string>
using namespace std;
bool isPalindrome(string str, int low, int high)
{
    while (low <= high)
    {
        if (str[low] != str[high])
            return false;
        low++;
        high--;
    }
    return true;
}

void allPalPartitions(string str)
{
    for(int i=0;i<str.length();i++)
    {
        for(int j=i;j<str.length();j++)
        {
            if(isPalindrome(str,i,j))
                cout<<str.substr(i,j-i+1)<<endl;
        }
    }
}


int main()
{
    string str = "nitin";
    allPalPartitions(str);
    return 0;
}
