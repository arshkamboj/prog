// Count triplets with sum smaller than a given value
#include <iostream>
using namespace std;

void countTriplets(int arr[], int n, int sum)
{
    for(int i=0;i<n-2;i++)
    {
        for(int j=i+1;j<n-1;j++)
        {
            for(int k=j+1;k<n;k++)
            {
                if(sum>arr[i]+arr[j]+arr[k])
                    cout<<arr[i]<<" "<<arr[j]<<" "<<arr[k]<<endl;
            }
        }
    }
}

int main()
{
    int arr[] = {5, 1, 3, 4, 7};
    int n = sizeof arr / sizeof arr[0];
    int sum = 12;
   countTriplets(arr, n, sum) ;
    return 0;
}
