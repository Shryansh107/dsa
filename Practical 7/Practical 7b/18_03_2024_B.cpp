// Experiment 7

// II.	Write a program to implement QUEUE using Linked List that performs following operations
// (h)	INSERT
// (i)	DELETE
// (j)	DISPLAY

#include <iostream>

using namespace std;

class Node
{
public:
  int data;
  Node *next;

  Node(int value)
  {
    data = value;
    next = nullptr;
  }
};

class Queue
{
private:
  Node *front;
  Node *rear;

public:
  Queue()
  {
    front = nullptr;
    rear = nullptr;
  }

  void enqueue(int value)
  {
    Node *newNode = new Node(value);

    if (isEmpty())
    {
      front = rear = newNode;
    }
    else
    {
      rear->next = newNode;
      rear = newNode;
    }
  }

  void dequeue()
  {
    if (isEmpty())
    {
      cout << "Queue is empty" << endl;
      return;
    }

    Node *temp = front;

    if (front == rear)
    {
      front = rear = nullptr;
    }
    else
    {
      front = front->next;
    }

    delete temp;
  }

  bool isEmpty()
  {
    return front == nullptr;
  }

  void display()
  {
    if (isEmpty())
    {
      cout << "Cannot display empty queue" << endl;
    }
    else
    {
      Node *temp = front;
      while (temp != rear)
      {
        cout << temp->data << " ";
        temp = temp->next;
      }
      cout << temp->data << endl;
    }
  }
};

int main()
{
  Queue queue;

  queue.enqueue(10);
  queue.enqueue(20);
  queue.enqueue(35);
  queue.enqueue(45);
  queue.enqueue(55);

  queue.display();

  queue.dequeue();

  queue.display();

  return 0;
}
