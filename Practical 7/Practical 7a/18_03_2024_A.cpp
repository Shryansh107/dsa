// Experiment 7

// I.	Write a program to implement Circular QUEUE using Array that performs following operations
// (e)	INSERT
// (f)	DELETE
// (g)	DISPLAY

#include <iostream>
#define max 10
using namespace std;

int Queue[max];
int front = -1;
int rear = -1;

void enqueue(int val)
{
  if ((rear == max - 1 && front == 0) || (front == rear + 1))
  {
    cout << "Queue is full\n";
  }
  else if (front == -1 && rear == -1)
  {
    front = rear = 0;
    Queue[rear] = val;
  }
  else
  {
    rear = (rear + 1) % max;
    Queue[rear] = val;
  }
}

void display()
{
  if (front == -1 && rear == -1)
  {
    cout << "Empty queue\n";
    return;
  }
  for (int i = front; i <= rear; i++)
  {
    cout << Queue[i] << " ";
  }
  cout << endl;
}
void dequeue()
{
  if (front == -1 && rear == -1)
    cout << "queue is empty\n";
  else if (front < rear)
  {
    front++;
  }
}

int main()
{
  enqueue(10);
  enqueue(20);
  enqueue(30);
  display();

  dequeue();
  display();
}