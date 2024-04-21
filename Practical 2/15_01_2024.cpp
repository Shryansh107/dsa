/*
Write a program to search an ITEM (integer) in an array using binary search, if FOUND then delete that item from array and if NOT FOUND then insert that item in such a way that the resultant array must be sorted. Write individual functions for binary search, insertion and deletion.
*/

#include <iostream>
using namespace std;

int binarySearch(int array[], int size, int key)
{
  int start = 0;
  int end = size - 1;
  int mid = start + ((end - start) / 2);
  while (start <= end)
  {
    if (array[mid] == key)
    {
      return mid;
    }
    else if (key > array[mid])
    {
      start = mid + 1;
    }
    else
    {
      end = mid - 1;
    }
    mid = start + ((end - start) / 2);
  }
  return -1;
}

void bubbleSort(int arr[], int size)
{
  for (int i = 0; i < size - 1; ++i)
  {
    for (int j = 0; j < size - i - 1; ++j)
    {
      if (arr[j] > arr[j + 1])
      {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}

void delete_or_insert(int arr[], int size, int item)
{
  int index = binarySearch(arr, size, item);
  if (index == -1)
  {
    int yQ = 0;
    while (yQ < size && arr[yQ] < item)
    {
      yQ++;
    }
    size++;
    for (int i = yQ; i < size; i++)
    {
      arr[i + 1] = arr[i];
    }
    arr[yQ] = item;
  }
  else
  {
    for (int i = index; i < size - 1; i++)
    {
      arr[i] = arr[i + 1];
    }
    size--;
  }
  cout << "Array left : " << endl;
  for (int i = 0; i < size; i++)
  {
    cout << arr[i] << " ";
  }
}

int main()
{
  int key;
  int *ptr;
  ptr = new int[12];
  cout << "Enter the elements in the array :- " << endl;
  for (int i = 0; i < 10; i++)
  {
    cin >> ptr[i];
  }
  bubbleSort(ptr, 10);
  cout << "Sorted array is :- " << endl;
  for (int i = 0; i < 10; i++)
  {
    cout << ptr[i] << " ";
  }
  cout << endl;
  cout << "Enter the element to search in the array : ";
  cin >> key;
  cout << "Position of that element in the array is : "
       << " " << binarySearch(ptr, 10, key) << endl;
  delete_or_insert(ptr, 10, key);
  delete[] ptr;
}
