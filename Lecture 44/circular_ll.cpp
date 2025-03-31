#include<iostream>
using namespace std;
class Node
{
public:
  int data;
  Node *next;
  Node(int d)
  {
    this->data = d;
    this->next = NULL;
  }
  ~Node() {
    int val = this -> data;
    if(this->next != NULL) {
        delete next;
        next = NULL;
    }
    cout << "memory free for node with data "<< val << endl;
  }
};

void insertnode(Node* &tail,int element,int d)
{
    if(tail==NULL)
    {
        Node* temp = new Node(d);
        temp-> next = temp;
        tail = temp;
    }
    else{
        Node* temp = tail;
        while(temp->data!=element)
        {
            temp = temp -> next;
        }
        Node* newnode = new Node(d);
        newnode -> next = temp -> next;
        temp -> next = newnode;
    }
}

void print(Node* &tail)
{
    if (tail == NULL)
    {
        cout<< " LINKED LIST IS EMPTY"<<endl;
        return;
    }
    else{
    Node* temp = tail;
   // tail=tail->next;
    do {
        cout << tail -> data << " ";
        tail = tail -> next;
    } while(tail != temp);
    //cout<<tail->data<<" ";
    cout<<endl;
    }
}
void deleteNode(Node* &tail, int value) {

  //empty list
  if(tail == NULL) {
      cout << " List is empty, please check again" << endl;
      return;
  }
  else{
      //non-empty

      //assuming that "value" is present in the Linked List
      Node* prev = tail;
      Node* curr = prev -> next;

      while(curr -> data != value) {
          prev = curr;
          curr = curr -> next;
      }

      prev -> next = curr -> next;

      //1 Node Linked List
      if(curr == prev) {
          tail = NULL;
      }

      //>=2 Node linked list
      else if(tail == curr ) {
          tail = prev;
      }

      curr -> next = NULL;
      delete curr;

  }

}

int main()
{
  Node* tail = NULL;
  print(tail);

  insertnode(tail,5,3);
  print(tail);

  insertnode(tail,3,6);
  print(tail);

  insertnode(tail,6,5);
  print(tail);

  insertnode(tail,6,2);
  print(tail);

  deleteNode(tail,6);
  print(tail);
  
  deleteNode(tail,3);
  print(tail);

}