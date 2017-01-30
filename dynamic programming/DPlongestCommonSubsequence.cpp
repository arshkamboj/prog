//longest common subsequence- dynamic programming
#include<iostream>
using namespace std;
int max(int a, int b)
{
    return (a > b)? a : b;
}

int lengthLongestCommonSubsequence(string s1,string s2, int m,int n){
        int dis[m+1][n+1];
    
    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i==0)
                dis[i][j]=0;
            else if (j==0)
                dis[i][j]=0;
            
            else if(s1[i-1] !=s2[j-1])
                dis[i][j]=max(dis[i-1][j],dis[i][j-1]);
            else
                dis[i][j]= 1+ dis[i-1][j-1];
        }
    }
    return dis[m][n];

}

int main()
{
    string s1="ABCDEF";
    string s2= "ACBCF";
    cout<<lengthLongestCommonSubsequence(s1,s2,s1.length(),s2.length());
    return 0;
    
}
