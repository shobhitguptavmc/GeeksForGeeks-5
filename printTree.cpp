/*program to print all of its root-to-leaf paths for a tree*/
#include <iostream>
#include <vector>
using namespace std;
/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct node
{
    int data;
    struct node* left;
    struct node* right;
    node(int x): data(x), left(NULL), right(NULL) {}
};
 
void printArray(vector<int> num);
void printPathsRecur(struct node*, vector<int>path);
void printPaths(struct node*);
 
/* Given a binary tree, print out all of its root-to-leaf
   paths, one per line. Uses a recursive helper to do the work.*/  
void printPaths(struct node* node) 
{
  vector<int>path;
  printPathsRecur(node, path);
}
 
/* Recursive helper function -- given a node, and an array containing
 the path from the root node up to but not including this node,
 print out all the root-leaf paths. */
void printPathsRecur(struct node* node, vector<int>path) 
{
  if (node==NULL) return;
 
  /* append this node to the path array */
  path.push_back(node->data);
 
  /* it's a leaf, so print the path that led to here */
  if (node->left==NULL && node->right==NULL) 
  {
    printArray(path);
  }
  else
  {
  /* otherwise try both subtrees */
    printPathsRecur(node->left, path);
    printPathsRecur(node->right, path);
  }
}

 
/* Utility that prints out an array on a line */
void printArray(vector<int>num)
{
  int i;
  for (i=0; i<num.size(); i++) {
    cout<<num[i]<<" ";
  }
  cout<<endl;
} 
 
/* Driver program to test mirror() */
int main()
{
  node *root = new node(1);
  root->left        = new node(2);
  root->right       = new node(3);
  root->left->left  = new node(4);
  root->left->right = new node(5); 
 
  /* Print all root-to-leaf paths of the input tree */
  printPaths(root);
  return 0;
}
