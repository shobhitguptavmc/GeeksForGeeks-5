// C++ program to find maximum path sum between two leaves of
// a binary tree
#include <iostream>
using namespace std;
 
// A binary tree node
struct Node
{
    int data;
    struct Node* left, *right;
};
 
// Utility function to allocate memory for a new node
struct Node* newNode(int data)
{
    struct Node* node = new(struct Node);
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}
 
// Utility function to find maximum of two integers
int max(int a, int b)
{   return (a >= b)? a: b;  }
 
// A utility function to find the maximum sum between any two leaves.
// This function calculates two values:
// 1) Maximum path sum between two leaves which is stored in res.
// 2) The maximum root to leaf path sum which is returned.
int maxPathSumUtil(struct Node *root, int &res)
{
    // Base case
    if (root==NULL) return 0;
 
    // Find maximum sum in left and right subtree. Also find
    // maximum root to leaf sums in left and right subtrees
    // and store them in lLPSum and rLPSum
    int lLPSum = maxPathSumUtil(root->left, res);
    int rLPSum = maxPathSumUtil(root->right, res);
 
    // Find the maximum path sum passing through root
    int curr_sum = lLPSum+rLPSum+root->data;
 
    // Update res (or result) if needed
    if (res < curr_sum)
        res = curr_sum;
 
    // Return the maximum root to leaf path sum
    return max(lLPSum, rLPSum)+root->data;
}
 
// The main function which returns sum of the maximum
// sum path between two leaves.  This function mainly uses
// maxPathSumUtil()
int maxPathSum(struct Node *root)
{
    int res = 0;
    maxPathSumUtil(root, res);
    return res;
}
 
// driver program to test above function
int main()
{
    struct Node *root = newNode(-15);
    root->left = newNode(5);
    root->right = newNode(6);
    root->left->left = newNode(-8);
    root->left->right = newNode(1);
    root->left->left->left = newNode(2);
    root->left->left->right = newNode(6);
    root->right->left = newNode(3);
    root->right->right = newNode(9);
    root->right->right->right= newNode(0);
    root->right->right->right->left= newNode(4);
    root->right->right->right->right= newNode(-1);
    root->right->right->right->right->left= newNode(10);
    cout << "Max pathSum of the given binary tree is " << maxPathSum(root)<<endl;
    return 0;
}
