#include<iostream>
using namespace std;

class Stack {
  int *arr;
  int top;
  int size;

  // constructor to initialize stack 
  public:
  Stack(int size){
    this->size=size;
    arr = new int[size];
    top = -1;
  }

  // behaviour
  void push(int element){
    if(top<size-1){
        top++;
        arr[top]=element;
    }else{
        cout<<"STACK OVERFLOW"<<endl;
    }
  }
  
  void pop(){
    if(top == -1){
        cout<<"STACK UNDERFLOW"<<endl;
    }else{
        top--;
    }
  }

  int peek(){
    if(top==-1){
        cout<<"STACK IS EMPTY"<<endl;
        return -1;
    }else{
        return arr[top];
    }
  }
  
  bool isempty(){
    if(top==-1){
        return 1;
    }else{
        return 0;
    }
  }

  ~Stack(){
    delete[]arr;
  }
};

int main()
{
    Stack st(4);
    st.push(5);
    st.push(25);
    cout<<st.peek()<<endl;
    cout<<st.isempty()<<endl;
    st.pop();
    cout<<st.peek()<<endl;
    cout<<st.isempty()<<endl;
    st.pop();
    cout<<st.isempty()<<endl;
    st.pop();
}