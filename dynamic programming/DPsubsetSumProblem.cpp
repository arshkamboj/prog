//subset sum problem - dynamic programming
#include<iostream>
using namespace std;
bool subsetSum(int arr[],int n,int sum){
    bool subsum[n][sum+1];
    for(int i=0;i<n;i++)
    {
        subsum[i][0]=true;
        for(int j=1;j<=sum;j++)
        {
             if(j<arr[i])
            {
                if(i==0)
                {
                    subsum[i][j]=false;
                }
                subsum[i][j]=(subsum[i-1][j]);
            }
            else
                
                subsum[i][j]=((subsum[i-1][j]) || (subsum[i-1][j-arr[i]]) );
        }
    }
    return subsum[n-1][sum];
}

int main()
{
    int arr[]={ 3, 34, 4, 12, 5, 2 };
    int sum=1000;
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<subsetSum(arr,n,sum);
    return 0;
}
