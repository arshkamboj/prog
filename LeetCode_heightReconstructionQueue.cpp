#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

template<typename P> struct Cmp
{
    bool operator()(const P &p1, const P &p2)
    {
        if(p1.first > p2.first) return true;
        if(p1.first == p2.first) return p1.first < p2.first;
        return false;
    }
};

pair<int,int>* mySort(pair<int,int> height[],int l){
    stack<pair<int,int>> myStack;
    pair<int,int> *sortHeight=new pair<int,int>[l]();
    int k=0,count=0;
    sortHeight[k]=height[k];
    k++;
  
    for(int i=1;i<l;i++){
        count=0;
        for(int j=0;j<k;j++)
        {
            if(height[i].first<=sortHeight[j].first)
            count++;
        }
        if(count==height[i].second)
        {
            sortHeight[k]=height[i];
            k++;
        }
        
        if(count>height[i].second)
        {
            do{
                myStack.push(sortHeight[k-1]);
                count--;k--;
            }while(height[i].second!=count);
            
            sortHeight[k]=height[i];
            k++;
        }
        
        if(count<height[i].second)
        {
            do{
                sortHeight[k]=myStack.top();
                myStack.pop();
                k++;count++;
            }while(!myStack.empty() && height[i].second!=count);
        
         sortHeight[k]=height[i];   
         k++;
        }
        
    }
    while(!myStack.empty()){
        sortHeight[k]=myStack.top();
        myStack.pop();
        k++;
    }
    return sortHeight;
}

int main(){
    pair<int,int> sortHeight[]={std::make_pair(7,0),
                                std::make_pair(4,4),
                                std::make_pair(7,1),
                                std::make_pair(5,0),
                                std::make_pair(6,1),
                                std::make_pair(5,2),
                                }; 
    pair<int,int> *sortHeightAns;                             
    int l=sizeof(sortHeight)/sizeof(sortHeight[0]);
    
    std::vector<pair<int,int>> v(sortHeight, sortHeight+l);
    std::sort(v.begin(), v.end(), Cmp<pair<int, int> >());
    std::copy(v.begin(), v.end(), sortHeight);
    
    cout<<endl<<"sorted input is: \n";
    for(int i=0;i<l;i++)
    cout<<sortHeight[i].first<<" "<<sortHeight[i].second<<endl;
    
    sortHeightAns=mySort(sortHeight,l);
    
    cout<<endl<<"sorted queue reconstruction is: \n";
    for(int i=0;i<l;i++)
    cout<<sortHeightAns[i].first<<" "<<sortHeightAns[i].second<<endl;
    return 0;
}