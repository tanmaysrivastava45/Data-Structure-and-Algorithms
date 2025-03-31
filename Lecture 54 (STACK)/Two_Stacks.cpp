// do visit this problem in coding ninjas good for space utilization 
/*
Two Stacks :- https://www.naukri.com/code360/problems/two-stacks_983634?leftPanelTab=0%3Fsource%3Dyoutube&campaign=YouTube_CodestudioLovebabbar5thfeb&leftPanelTabValue=PROBLEM

*/
#include <iostream>
using namespace std; 
class TwoStack {

    public:
        int *arr1;
        int top1;
        int top2;
        int s;
    
        // Initialize TwoStack.
        TwoStack(int s) {
            // Write your code here.
            this->s = s;
            arr1 = new int[s];
            top1 = -1;
            top2 = s;
        }
        
        // Push in stack 1.
        void push1(int num) {
            // Write your code here.
            if(top1<s-1 && top1<top2-1){
                top1++;
                arr1[top1]=num;
            }
        }
    
        // Push in stack 2.
        void push2(int num) {
            // Write your code here.
            if(top2>top1+1){
                top2--;
                arr1[top2]=num;
            }
        }
    
        // Pop from stack 1 and return popped element.
        int pop1() {
            // Write your code here.
            if(top1>=0){
                int ele = arr1[top1];
                top1--;
                return ele;
            }else return -1;
        
        }
    
        // Pop from stack 2 and return popped element.
        int pop2() {
            // Write your code here.
          if(top2<s){
                int ele = arr1[top2];
                top2++;
                return ele;
            }else return -1;
        }
    };
    