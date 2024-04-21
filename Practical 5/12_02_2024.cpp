/*
Experiment 5
I.	Write a program to implement STACK using arrays/Linked List that performs following operations
(a)	PUSH
(b)	POP
(c)	PEEP
(d)	DISPLAY
*/

#include <iostream>
#include <stack>
using namespace std;

class Stack
{
public:
  int *arr;
  int top;
  int size;

  // Constructor
  Stack(int size)
  {
    this->size = size;
    arr = new int(size);
    top = -1;
  }

  void push(int element)
  {
    if ((size - top) > 1)
    {
      top++;
      arr[top] = element;
      cout << "Pushed " << element << " into the stack\n";
    }

    else
    {
      cout << "Stack overflow\n";
    }
  }

  void pop()
  {
    if (top >= 0)
    {
      // top--;
      cout << "Popped " << arr[top--] << " from the stack\n";
    }
    else
    {
      cout << "Stack underflow\n";
    }
  }

  int peek()
  {
    if (top >= 0)
    {
      return arr[top];
    }
    else
    {
      cout << "Stack is empty\n";
      return -1;
    }
  }

  // NOT POSSIBLE
  /*
  int top()
  {
    if (this->top >= 0)
    {
      return arr[this->top];
    }
    else
    {
      cout << "Stack is empty\n";
      return -1;
    }
  }
  */

  bool isEmpty()
  {
    if (top == -1)
    {
      return true;
    }
    else
    {
      return false;
    }
  }

  /*
  int display(int size)
  {
    for (int i = 0; i < size; i++)
    {
      cout << arr[i] << " ";
    }
    cout << endl;
  }
  */
};

int main()
{

  Stack st(5);
  st.push(30);
  st.push(20);
  st.push(10);
  cout << "Top = " << st.peek() << endl;
  st.pop();
  cout << "Top = " << st.peek() << endl;
  st.pop();
  cout << "Top = " << st.peek() << endl;
  st.pop();
  cout << "Top = " << st.peek() << endl;
  return 0;
}
