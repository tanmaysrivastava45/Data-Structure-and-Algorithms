#include <iostream>
using namespace std;

class Node
{
public:
  int data;
  Node *prev;
  Node *next;
  Node(int d)
  {
    this->data = d;
    this->prev = NULL;
    this->next = NULL;
  }
  ~Node() {
    int val = this -> data;
    if(next != NULL) {
        delete next;
        next = NULL;
    }
    cout << "memory free for node with data "<< val << endl;
  }
};

void print(Node *head)
{
  Node *temp = head;
  while (temp != NULL)
  {
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << endl;
}

int getlength(Node *head)
{
  Node *temp = head;
  int count = 0;
  while (temp!= NULL)
  {
    count++;
    temp = temp->next;
  }
  return count;
}
void insertathead(Node *&head,Node*&tail, int d)
{
  if (head == NULL)
  {
    Node*temp = new Node(d);
    head=temp;
    tail=temp;
  }
  else
  {
    Node *temp = new Node(d);
    temp->next = head;
    head->prev = temp;
    head = temp;
  }
}
void insertattail(Node *&tail,Node*&head, int d)
{
  if(tail==NULL)
  {
   Node* temp = new Node(d);
   tail=temp;
   head=temp;
  }else{
    Node *temp = new Node(d);
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
  }
  
}

void insertatposition(Node *&head, Node *&tail, int position, int d)
{
  if (position == 1)
  {
    insertathead(head,tail,d);
    return;
  }
  Node *temp = head;
  int count = 1;
  while (count < position - 1)
  {
    temp = temp->next;
    count++;
  }
  if (temp->next == NULL)
  {
    insertattail(tail,head, d);
    return;
  }
  Node *Nodetoinsert = new Node(d);
  Nodetoinsert->next = temp->next;
  temp->next->prev = Nodetoinsert;
  temp->next = Nodetoinsert;
  Nodetoinsert->prev = temp;
}
void deletenode(Node *&head,Node*&tail, int position)
{
  if (position == 1)
  {
    Node *temp = head;
    temp -> next -> prev = NULL;
    head = temp-> next;
    temp->next = NULL;
    delete temp;
  }
  else
  {
    Node *curr = head;
    Node *prev = NULL;
    int curr_pos = 1;
    while (curr_pos < position)
    {
      prev = curr;
      curr = curr->next;
      curr_pos++;
    }
    curr->prev=NULL;
    prev->next = curr->next;
    if (curr->next != NULL) {
      curr->next->prev = prev;  // Update the previous pointer
    }
    if(curr->next==NULL)
    {
      tail=prev;
    }
    curr->next = NULL;
    delete curr;
  }
}
int main()
{
  Node *temp = new Node(45);
  Node *head = temp;
  Node *tail = temp;
  print(head);
  cout << getlength(head) << endl;
  insertathead(head,tail, 18);
  print(head);
  insertathead(head,tail, 7);
  print(head);
  insertathead(head,tail, 5);
  print(head);

  insertattail(tail,head, 108);
  print(head);

  insertatposition(head, tail, 1, 1);
  print(head);

  insertatposition(head, tail, 7, 500);
  print(head);

  insertatposition(head, tail, 3, 300);
  print(head);
  cout<<"HEAD  "<<head->data<<endl;
  cout<<"tail  "<<tail->data<<endl;
  deletenode(head,tail,1);
  print(head);

  deletenode(head,tail,4);
  print(head);
  cout<<"HEAD  "<<head->data<<endl;
  cout<<"tail  "<<tail->data<<endl;

  deletenode(head,tail,6);
  print(head);
  cout<<"head "<<head->data<<endl;
  cout<<"tail "<<tail->data<<endl;

}