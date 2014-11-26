#include<iostream>
#include<vector>
#include<climits>
using namespace std;

//definition of tree node
struct TreeNode{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x): val(x), left(NULL), right(NULL) {}
};


TreeNode *constructBSTFromPreOrder(vector<int>&input, int maxValue, int minValue){
  //base case
  if(input.empty()) return NULL;

  //recursive case
  TreeNode *root = NULL;
  if(input[0] > minValue && input[0] < maxValue){
    int data = input[0]; //save it for future use
    root = new TreeNode(input[0]);
    input.erase(input.begin());
    
    root->left = constructBSTFromPreOrder(input, data, minValue);
    
    root->right = constructBSTFromPreOrder(input, maxValue, data);
  }
  return root;
}
