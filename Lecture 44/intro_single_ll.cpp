#include <iostream>
using namespace std;
class Node
{
public:
  int data = 5;
  Node *next;
  // constructor
  Node(int data)
  {
    this->data = data;
    this->next = NULL;
  }
};
void insertAtHead(Node *&head, int d)
{

  // new node create
  // also check if head is null or not ;
  if (head == NULL)
  {
    Node *temp = new Node(d);
    head = temp;
  }
  else
  {
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
  }
}

void insertAtTail(Node *&tail, int d)
{
  // new node create
  if (tail == NULL)
  {
    Node *temp = new Node(d);
    tail = temp;
  }
  else
  {
    Node *temp = new Node(d);
    tail->next = temp;
    tail = temp;
  }
}
void print(Node *&head)
{
  Node *temp = head;
  while (temp != NULL)
  {
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << endl;
}

void insertAtposition(Node *&tail, Node *&head, int position, int d)
{
  if (position == 1)
  {
    insertAtHead(head, d);
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
    insertAtTail(tail, d);
    return;
  }
  Node *Nodetoinsert = new Node(d);
  Nodetoinsert->next = temp->next;
  temp->next = Nodetoinsert;
}

void deletenode(Node *&head, int position)
{
  if (position == 1)
  {
    Node *temp = head;
    head = head->next;
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
    prev->next = curr->next;
    curr->next = NULL;
    delete curr;
  }
}

int main()
{
  Node *node1 = new Node(45);
  // cout<<node1->data<<endl;
  // cout<<node1->next<<endl;

  Node *head = node1;
  Node *tail = node1;
  //  print(head);

  //  insert(head,18);

  //  print(head);

  //  insert(head,7);
  //  print(head);
  print(head);

  insertAtTail(tail, 18);

  print(head);

  insertAtTail(tail, 7);
  print(head);

  insertAtposition(tail, head, 3, 93);
  print(head);
  //  cout<<"head : "<<head->data<<endl;
  //  cout<<"tail : "<<tail->data<<endl;
  deletenode(head, 1);
  print(head);
}