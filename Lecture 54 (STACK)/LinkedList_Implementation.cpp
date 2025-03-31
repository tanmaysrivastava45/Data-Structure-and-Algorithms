#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        this->next = NULL; 
    }
};

class Stack{
private:
    Node* top;
public:
    Stack(){
     top = NULL;
    }

    void push(int data){
        Node* newnode = new Node(data);
        newnode->next = top;
        top = newnode;
    }

    void pop(){
        if(top ==NULL){
            cout<<"STACK IS EMPTY"<<endl;
        }else{
            Node* nodetodel = top;
            top = top->next;
            nodetodel->next =NULL;
            delete nodetodel;
        }
    }

    int peek(){
        if(top==NULL)return -1;
        else{
            return top->data;
        }
    }

    bool isempty(){
        if(top==NULL)return 1;
        else return 0;
    }
};

int main(){

Stack S;
S.push(5);
S.push(34);
cout<<S.peek()<<endl;
cout<<S.isempty()<<endl;
S.pop();
cout<<S.peek()<<endl;
S.pop();
cout<<S.peek()<<endl;
cout<<S.isempty()<<endl;



}