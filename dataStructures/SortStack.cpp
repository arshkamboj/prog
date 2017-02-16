//Sort the stack without extra memory
#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

int main(){
  stack<int> stack1,stack2;
  int curr;
  stack1.push(1);
  stack1.push(9);
  stack1.push(2);
  stack1.push(8);
  stack1.push(4);
  int i=0;
  cout<<stack1.empty();
  while(!stack1.empty()){
      curr=stack1.top();
      stack1.pop();
      if(stack2.empty()){
          stack2.push(curr);
      }
      else{
          while(!stack2.empty() && stack2.top()>curr ){
              stack1.push(stack2.top());
              stack2.pop();
              i++;
          }
          stack2.push(curr);
          while(i>0){
              stack2.push(stack1.top());
              stack1.pop();
              i--;
          }
          
      }
  }
  cout<<"sorted stack\n";
  while(!stack2.empty()){
      cout<<stack2.top()<<endl;
      stack2.pop();
  }
  return 0;
}