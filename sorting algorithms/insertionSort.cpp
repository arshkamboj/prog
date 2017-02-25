//insertion sort algorithm
#include<iostream>
using namespace std;
void swap(int& a,int& b)
{
    int t;
    t=a;
    a=b;
    b=t;
}

void insertionSort(int arr[],int length)
{
    int sublength,valueToInsert;
    
    for(int i=1;i<length;i++)
    {
        valueToInsert=arr[i];
        
        if(valueToInsert<arr[0])
            {
                for(int k=i;k>=0;k--)
                {
                    arr[k]=arr[k-1];
                }
                arr[0]=valueToInsert;
            }
            
        for(int j=0;j<=i;j++)
        {
            if(valueToInsert>arr[j] && valueToInsert<arr[j+1])
            {
                for(int k=i;k>j;k--)
                {
                    arr[k]=arr[k-1];
                }
                arr[j+1]=valueToInsert;
            }
        }
    }
    
    for(int i=0;i<length;i++)
    cout<<arr[i]<<" ";
}
int main()
{
    int arr[]={11,38,19,5,27,12,55};
    insertionSort(arr,7);
    return 0;
}
