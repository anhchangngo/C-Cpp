#include <iostream>
#include <cmath>
using namespace std;

typedef struct TreeNode
{
  int value;
  struct TreeNode *parent, *tLeft, *tRight;
} * Tree;

void randomArr(int *arr, int n)
{
  for (int i = 0; i < n; i++)
    arr[i] = rand() % 100;
}

void init(Tree *t, int height)
{
  *t = (Tree)malloc(sizeof(struct TreeNode));

  (*t)->value = 0;
  (*t)->parent = NULL;
  (*t)->tLeft = NULL;
  (*t)->tRight = NULL;
  if (height > 1)
  {
    init(&((*t)->tLeft), height - 1);
    (*t)->tLeft->parent = *t;
    init(&((*t)->tRight), height - 1);
    (*t)->tRight->parent = *t;
  }
  else
  {
    (*t)->tLeft = NULL;
    (*t)->tRight = NULL;
  }
}

bool isLeaf(Tree t)
{
  return (t->tLeft == NULL && t->tRight == NULL);
}

void printTree(Tree t, string indent, bool last)
{
  string val2print = to_string(t->value);
  if (t->parent == NULL)
    val2print = "ROOT: " + val2print;
  else
    val2print = (t->parent->tLeft == t ? "L: " : "R: ") + val2print;
  cout << indent << "\\\\- " << val2print << endl;
  indent += last ? "   " : "|  ";
  if (t->tLeft != NULL)
  {
    printTree(t->tLeft, indent, t->tRight == NULL);
  }
  if (t->tRight != NULL)
  {
    printTree(t->tRight, indent, true);
  }
}

int fillArray(int *arr, int arr_length, int target_length)
{
  // Initialize a number larger than any element in the array
  int E = arr[0];
  for (int i = 1; i < arr_length; i++)
  {
    if (arr[i] > E)
      E = arr[i];
  }
  E++;
  // Add E to the array until the array length is equal to the number of leaves in the tree
  while (arr_length < pow(2, target_length - 1))
  {
    arr[arr_length] = E;
    arr_length++;
  }
  return arr_length;
}

int FILL_LEAF_INDEX = 0;
void fillLeaf(Tree *t, int data[])
{
  if (*t == NULL)
    return;
  fillLeaf(&((*t)->tLeft), data);
  if (isLeaf(*t))
  {
    (*t)->value = data[FILL_LEAF_INDEX];
    FILL_LEAF_INDEX++;
  }
  fillLeaf(&((*t)->tRight), data);
}

void fillNode(Tree *t)
{
  if (*t == NULL)
    return;
  fillNode(&((*t)->tLeft));
  fillNode(&((*t)->tRight));
  if (!isLeaf(*t))
  {
    if ((*t)->tLeft->value < (*t)->tRight->value)
      (*t)->value = (*t)->tLeft->value;
    else
      (*t)->value = (*t)->tRight->value;
  }
}

int findNode(Tree t, int value)
{
  if (t == NULL)
    return -1;
  if (t->value == value)
  {
    cout << "Found node with value " << value << endl;
    printTree(t, "", true);
    return 1;
  }
  int left = findNode(t->tLeft, value);
  int right = findNode(t->tRight, value);
  if (left == -1 && right == -1)
    return -1;
  return 1;
}

void insertNode(Tree *t, int value)
{
  if (*t == NULL)
  {
    *t = (Tree)malloc(sizeof(struct TreeNode));
    (*t)->value = value;
    (*t)->parent = NULL;
    (*t)->tLeft = NULL;
    (*t)->tRight = NULL;
    return;
  }
  if (value < (*t)->value)
  {
    if ((*t)->tLeft == NULL)
    {
      (*t)->tLeft = (Tree)malloc(sizeof(struct TreeNode));
      (*t)->tLeft->value = value;
      (*t)->tLeft->parent = *t;
      (*t)->tLeft->tLeft = NULL;
      (*t)->tLeft->tRight = NULL;
    }
    else
      insertNode(&((*t)->tLeft), value);
  }
  else
  {
    if ((*t)->tRight == NULL)
    {
      (*t)->tRight = (Tree)malloc(sizeof(struct TreeNode));
      (*t)->tRight->value = value;
      (*t)->tRight->parent = *t;
      (*t)->tRight->tLeft = NULL;
      (*t)->tRight->tRight = NULL;
    }
    else
      insertNode(&((*t)->tRight), value);
  }
}

void removeNode(Tree *t, int value)
{
  if (*t == NULL)
    return;
  if ((*t)->value == value)
  {
    if ((*t)->tLeft == NULL && (*t)->tRight == NULL)
    {
      if ((*t)->parent->tLeft == *t)
        (*t)->parent->tLeft = NULL;
      else
        (*t)->parent->tRight = NULL;
      free(*t);
      *t = NULL;
    }
    else if ((*t)->tLeft == NULL)
    {
      if ((*t)->parent->tLeft == *t)
        (*t)->parent->tLeft = (*t)->tRight;
      else
        (*t)->parent->tRight = (*t)->tRight;
      (*t)->tRight->parent = (*t)->parent;
      free(*t);
      *t = NULL;
    }
    else if ((*t)->tRight == NULL)
    {
      if ((*t)->parent->tLeft == *t)
        (*t)->parent->tLeft = (*t)->tLeft;
      else
        (*t)->parent->tRight = (*t)->tLeft;
      (*t)->tLeft->parent = (*t)->parent;
      free(*t);
      *t = NULL;
    }
    else
    {
      Tree temp = (*t)->tRight;
      while (temp->tLeft != NULL)
        temp = temp->tLeft;
      (*t)->value = temp->value;
      removeNode(&((*t)->tRight), temp->value);
    }
  }
  else if (value < (*t)->value)
    removeNode(&((*t)->tLeft), value);
  else
    removeNode(&((*t)->tRight), value);
}

int main()
{
  system("cls");

  int arr[] = {8, 20, 41, 7, 2, 5, 2, 6, 8, 92, 2};
  // randomArr(arr, n);
  int arr_length = sizeof(arr) / sizeof(arr[0]);
  int height = ceil(log2(arr_length)) + 1;
  cout << height << endl;
  arr_length = fillArray(arr, arr_length, height);
  Tree main_tree;
  init(&main_tree, height);  // Init a tree with the given height given, calculated from the number of elements in the array
  fillLeaf(&main_tree, arr); // Fill the leaves of the tree with the elements in the array
  fillNode(&main_tree);      // Fill the nodes of the tree with the smallest value of its children
  printTree(main_tree, " ", true);

  cout << "Enter a number to search: ";
  int search_value;
  cin >> search_value;

  if (findNode(main_tree, search_value) == -1)
  {
    cout << "Not found" << endl;
  }

  cout << "Enter a number to insert: ";
  int insert_value;
  cin >> insert_value;
  insertNode(&main_tree, insert_value);
  printTree(main_tree, " ", true);

  cout << "Enter a number to remove: ";
  int remove_value;
  cin >> remove_value;
  removeNode(&main_tree, remove_value);
  printTree(main_tree, " ", true);

  return 0;
}
