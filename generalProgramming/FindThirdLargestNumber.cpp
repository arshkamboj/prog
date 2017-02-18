#include<iostream>
#include<stdlib.h>
#define INT_MIN -255
using namespace std;
int findThirdMax(int arr[],int n){
    int max=INT_MIN;
    int max2=INT_MIN;
    int max3=INT_MIN;
    int temp,temp2;
    for(int i=0;i<n;i++){
        if(arr[i]>max){
        temp=max;
        max=arr[i];
        
        temp2=max2;
        max2=temp;
        max3=temp2;
        }
        else if(arr[i]<max && arr[i]>max2){
            temp2=max2;
            max2=temp;
            max3=temp2;
        }
        else if(arr[i]>max3){
            max3=arr[i];
        }
    }
    
    if(max3==INT_MIN)
    return max;
    else
    return max3;
}
int main()
{
   cout << "Enter different numbers ";
   int numbers[10],max;
    
   for(int n = 0; n <10; n++)
       numbers[n]=n;
       
   max=findThirdMax(numbers,10);
   cout<<max;
  
return 0;
}