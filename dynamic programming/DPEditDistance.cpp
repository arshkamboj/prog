//edit distance dynamic programming
#include<iostream>
#include<string>
using namespace std;
int min(int x, int y, int z)
{
   return min(min(x, y), z);
}
 
int minEditDistance(string s1, string s2, int m, int n){
    int dis[m+1][n+1];
    
    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i==0)
            dis[i][j]=j;
            else if (j==0)
            dis[i][j]=i;
            else if(s1[i-1]==s2[j-1])
            dis[i][j]=dis[i-1][j-1];
            else
            dis[i][j]= 1+ min(dis[i-1][j],dis[i][j-1],dis[i-1][j-1]);
        }
    }
    return dis[m][n];
}



int main(){
    string s1="monday";
    string s2="sunday";
    
    cout<<minEditDistance(s1,s2, s1.length(),s2.length());
    return 0;
}
