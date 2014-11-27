#include<iostream>
using namespace std;

//definition of linked node and tree node
struct LinkedNode{
  int value;
  LinkedNode *next;
  //constructor
  LinkedNode(int x): value(x), next(NULL) {}
};

struct TreeNode{
  int value;
  TreeNode *left;
  TreeNode *right;
  //constructor
  TreeNode(int x): value(x), left(NULL), right(NULL) {}
};

//count the number of linked nodes in a head
int countLNode(LinkedNode *head){
  int res = 0;
  while(head) {
    head = head->next;
    res++;
  }
  return res;
}

//a helper function
TreeNode *helper(LinkedNode *& head, int n){
  //base case
  if(n == 0) return NULL;
  
  //in order processing: first left
  TreeNode *left = helper(head, n/2);
  
  //in order processing: node
  TreeNode *root = new TreeNode(head->value);
  
  root->left     = left;
  
  //move head, node the declaration *&
  head           = head->next;

  //in order processing: first right
  root->right    = helper(head, n - n/2 - 1);

  return root;
}

TreeNode *constructBSTFromLinkedList(LinkedNode *head){
  return helper(head, countLNode(head));
}

//this is a test function
int main(){
  LinkedNode *head = new LinkedNode(1);
  
  head->next = new LinkedNode(2);
  head->next->next = new LinkedNode(3);
  head->next->next->next = new LinkedNode(4);
  head->next->next->next->next = new LinkedNode(5);

  TreeNode *root = constructBSTFromLinkedList(head);
}

