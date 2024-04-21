/*
Experiment 3
Implement following sorting algorithms to sort an array (make a dynamic array):
1.	Write a function to sort an array using Bubble sort. Use 1-bit variable FLAG to signal when no interchange take place during pass. If FLAG is 0 after any pass, then list is already sorted and there is no need to continue.
2.	Write a function to sort an array using Selection sort.
Write a menu driven program to implement above sorting.
*/

#include <iostream>
using namespace std;

void printNewArray(int arr[], int size)
{
  for (int i = 0; i < size; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
}

int bubbleSort(int arr[], int size)
{

  cout << "Bubble Sort\n";

  for (int i = 0; i < size - 1; i++)
  {
    // int flag = 0;
    for (int j = 0; j < size - i - 1; j++)
    {

      if (arr[j] > arr[j + 1])
      {
        swap(arr[j], arr[j + 1]);
        // flag = 1;
      }

      // if (flag == 0)
      // {
      //   break;
      // }
    }
  }
  printNewArray(arr, size);
}

int selectionSort(int arr[], int size)
{

  cout << "Selection Sort\n";

  for (int i = 0; i < size - 1; i++)
  {
    int minIndex = i;
    int j = i + 1;
    while (j < size)
    {

      if (arr[minIndex] > arr[j])
      {
        minIndex = j;
      }

      j++;
    }

    {
      swap(arr[minIndex], arr[i]);
    }
  }
  printNewArray(arr, size);
}

void insertionsort(int arr[], int size)
{
  cout << "Insertion Sort\n";
  for (int i = 0; i < size; i++)
  {
    int key = arr[i];
    int j = i - 1;
    while (j >= 0 && arr[j] > key)
    {
      arr[j + 1] = arr[j];
      j = j - 1;
    }
    arr[j + 1] = key;
  }
  printNewArray(arr, size);
}

int main()
{
  // TEST CASES

  // int arr[10] = {20, 10, 30, 80, 50, 40, 60, 90, 70, 100};
  // bubbleSort(arr, 10, 'a');
  // bubbleSort(arr, 10, 'a');
  // bubbleSort(arr, 10, 'A');
  // bubbleSort(arr, 10, 'd');
  // bubbleSort(arr, 10, 'D');
  // bubbleSort(arr, 10, 'x');       -------> Invalid Order
  // selectionSort(arr, 10, 'a');
  // selectionSort(arr, 10, 'A');
  // selectionSort(arr, 10, 'd');
  // selectionSort(arr, 10, 'D');
  // selectionSort(arr, 10, 'x');      -------> Invalid Order

  // TEST CASES

  int arr[100];
  int size;
  int typeOfSorting;
  cout << "Enter the size of array : ";
  cin >> size;
  cout << "Enter the " << size << " elements of the array :-\n";
  for (int i = 0; i < size; i++)
  {
    cin >> arr[i];
  }
  cout << "Enter 1 for Bubble Sort, 2 for Selection Sort and 3 for Insertion Sort : ";
  cin >> typeOfSorting;
  switch (typeOfSorting)
  {
  case 1:
    bubbleSort(arr, size);
    break;
  case 2:
    selectionSort(arr, size);
    break;
  case 3:
    insertionsort(arr, size);
    break;

  default:
    cout << "Invalid input !" << endl;
    break;
  }

  return 0;
}
