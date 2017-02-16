// Length of the largest subarray with contiguous elements
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int arr[] = {1, 56, 58, 57, 90, 92, 94, 93, 91, 45};
    int n = sizeof(arr)/sizeof(arr[0]);int ans=0;
    sort(arr, arr + n);
    for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";
    
    for(int i=0;i<n;i++)
    {
        int len=1;
        for(int j=i;j<n;j++)
        {
            if(arr[j]==arr[j+1]-1){len++;
                continue;}
            else
                break;
        }
        if(ans<len){ans=len;}
    }
    cout << "Length of the longest contiguous subarray is "
         << ans;
    return 0;
}
