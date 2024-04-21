/*
Experiment 4
Write a menu driven program to implement following operations on the singly linked list. Please make sure that all the functions are working for all the possible test cases.
(a) Insert a node at the front of the linked list.
(b) Insert a node at the end of the linked list.
(c) Insert a node at the given position in the linked list.
(d) Delete first node of the linked list.
(e) Delete last node of the list.
(f) Delete a node from specified position.
(g) Display the elements of the linked list.
*/

#include <iostream>
using namespace std;

class Node
{
public:
  int data;
  Node *next;
  // Constructor
  Node(int data)
  {
    this->data = data;
    this->next = NULL;
  }

  // Destructor
  ~Node()
  {
    int value = this->data;
    if (this->next != NULL)
    {
      delete next;
      this->next = NULL;
    }
    cout << "Memory is free for node with data " << value << endl;
  }
};

void insertAtHead(Node *&head, int d)
{
  Node *newNode = new Node(d);
  newNode->next = head;
  head = newNode;
}

void insertAtTail(Node *&tail, int d)
{
  Node *newNode = new Node(d);
  tail->next = newNode;
  tail = newNode;
}

void insertAtPosition(Node *&tail, Node *&head, int pos, int d)
{
  Node *newNode = new Node(d);
  Node *temp = head;
  int count = 1;
  if (pos == 1)
  {
    insertAtHead(head, d);
    return;
  }
  else
  {
    while (count < (pos - 1))
    {
      temp = temp->next;
      count++;
    }
    if (temp->next == NULL)
    {
      insertAtTail(tail, d);
      return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
  }
}

void deleteNode(Node *&head, int position)
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
    int count = 1;
    while (count < position)
    {
      prev = curr;
      curr = curr->next;
      count++;
    }
    prev->next = curr->next;
    curr->next = NULL;
    delete curr;
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

// TEST DATA

// insertAtTail(tail, 29);
// print(head);

// insertAtTail(tail, 15);
// print(head);

// insertAtPosition(head, 2, 56);
// print(head);

// insertAtPosition(head, 1, 88);
// print(head);
/*
int main() // CHECK newfile.cpp BEFORE INT MAIN()
{

  Node *node1 = new Node(37);
  // cout << node1->data << endl;
  // cout << node1->next << endl;

  Node *head = node1;
  Node *tail = node1;
  cout << "The Linked List before insertion is :- \n";
  // print(head);

  int pos;

  insertAtTail(tail, 15);
  // print(head);

  insertAtPosition(tail, head, 2, 56);
  print(head);

  cout << "Where do you want to insert a node ? \nEnter 1 for start, 2 for a specific position and 3 for end of the list : ";
  cin >> pos;
  int val;
  cout << "Enter the value to be inserted : ";
  cin >> val;
  switch (pos)
  {
  case 1:
  {
    insertAtHead(head, val);
    break;
  }

  case 2:
  {
    int index;
    cout << "Enter the position at which you want to insert the data : ";
    cin >> index;
    insertAtPosition(tail, head, index, val);
    break;
  }

  case 3:
  {
    insertAtTail(tail, val);
    break;
  }

  default:
  {
    cout << "Please enter a valid position to be inserted at : ";
    break;
  }
  }

  cout << "The Linked List after insertion is :- \n";
  print(head);

  return 0;
}
*/

int main()
{
  Node *node1 = new Node(10);
  Node *head = node1;
  Node *tail = node1;

  insertAtTail(tail, 20);
  insertAtTail(tail, 30);
  insertAtTail(tail, 40);
  insertAtTail(tail, 50);

  int pos;
  int val;

  cout << "The existing linked list is :-\n";
  print(head);
  cout << endl;
  cout << "Enter the position to insert at : ";
  cin >> pos;
  cout << "Enter the value to insert : ";
  cin >> val;

  insertAtPosition(tail, head, pos, val);

  cout << "\nThe new Linked List is :-\n";
  print(head);
  cout << endl
       << endl;

  cout << "Enter the node to delete : ";
  cin >> pos;
  deleteNode(node1, pos);
  print(head);

  return 0;
}
