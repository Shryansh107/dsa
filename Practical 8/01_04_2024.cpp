// Write a menu driven program to implement a binary search tree and write the function to perform following operations:
// 1.Insert an element
// 2.Preorder traversal of the tree
// 3.Inorder traversal of the tree
// 4.Postorder traversal of the tree
// 5.Delete a node(which can have no children/one children/two children)

#include <iostream>
using namespace std;

class Node
{
public:
  int data;
  Node *left;
  Node *right;

  Node(int d)
  {
    this->data = d;
    this->left = NULL;
    this->right = NULL;
  }
};

class BST
{
public:
  Node *root;

  BST()
  {
    root = NULL;
  }

  Node *insert(Node *node, int data)
  {
    if (node == NULL)
    {
      return new Node(data);
    }

    if (data < node->data)
    {
      node->left = insert(node->left, data);
    }
    else if (data > node->data)
    {
      node->right = insert(node->right, data);
    }

    return node;
  }

  void preorderTraversal(Node *node)
  {
    if (node == NULL)
    {
      return;
    }
    cout << node->data << " ";
    preorderTraversal(node->left);
    preorderTraversal(node->right);
  }

  void inorderTraversal(Node *node)
  {
    if (node == NULL)
    {
      return;
    }
    inorderTraversal(node->left);
    cout << node->data << " ";
    inorderTraversal(node->right);
  }

  void postorderTraversal(Node *node)
  {
    if (node == NULL)
    {
      return;
    }
    postorderTraversal(node->left);
    postorderTraversal(node->right);
    cout << node->data << " ";
  }

  Node *findMinNode(Node *node)
  {
    Node *current = node;
    while (current && current->left != NULL)
    {
      current = current->left;
    }
    return current;
  }

  Node *deleteNode(Node *node, int key)
  {
    if (node == NULL)
    {
      return node;
    }

    if (key < node->data)
    {
      node->left = deleteNode(node->left, key);
    }
    else if (key > node->data)
    {
      node->right = deleteNode(node->right, key);
    }
    else
    {
      if (node->left == NULL)
      {
        Node *temp = node->right;
        delete node;
        return temp;
      }
      else if (node->right == NULL)
      {
        Node *temp = node->left;
        delete node;
        return temp;
      }

      Node *temp = findMinNode(node->right);
      node->data = temp->data;
      node->right = deleteNode(node->right, temp->data);
    }
    return node;
  }
};

int main()
{
  BST bst;
  int choice, data;

  do
  {
    cout << "\nBinary Search Tree Operations:" << endl;
    cout << "1. Insert Element" << endl;
    cout << "2. Delete Element" << endl;
    cout << "3. Preorder Traversal" << endl;
    cout << "4. Inorder Traversal" << endl;
    cout << "5. Postorder Traversal" << endl;
    cout << "6. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
      cout << "Enter data to insert: ";
      cin >> data;
      bst.root = bst.insert(bst.root, data);
      break;
    case 2:
      cout << "Enter data to delete: ";
      cin >> data;
      bst.root = bst.deleteNode(bst.root, data);
      break;
    case 3:
      cout << "Preorder Traversal: ";
      bst.preorderTraversal(bst.root);
      cout << endl;
      break;
    case 4:
      cout << "Inorder Traversal: ";
      bst.inorderTraversal(bst.root);
      cout << endl;
      break;
    case 5:
      cout << "Postorder Traversal: ";
      bst.postorderTraversal(bst.root);
      cout << endl;
      break;
    case 6:
      cout << "Exiting..." << endl;
      break;
    default:
      cout << "Invalid choice. Please enter a valid option." << endl;
      break;
    }
  } while (choice != 6);

  return 0;
}
