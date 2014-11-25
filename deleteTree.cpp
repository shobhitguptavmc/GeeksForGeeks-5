#include<iostream>
using namespace std;

//this problem is from geeksforgeeks
struct TreeNode{
  int value;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x): value(x), left(NULL), right(NULL) {}
};

void deleteTree(TreeNode *root){
  //base case
  if(root==NULL) return;
  //recursive case
  deleteTree(root->left);
  deleteTree(root->right);
  
  delete root;
}


//driver program to test deleteTree function
int main(){
  TreeNode *root    = new TreeNode(1);
  root->left        = new TreeNode(2);
  root->right       = new TreeNode(3);
  root->left->left  = new TreeNode(4);
  root->left->right = new TreeNode(5);
  
  deleteTree(root);
}
