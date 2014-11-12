#include<iostream>
using namespace std;

/*This problem is geeksforgeeks*/

//definition of linked node
struct LinkedNode{
  int val;
  LinkedNode *next;
  LinkedNode *down;
  LinkedNode(int x): val(x), next(NULL), down(NULL) {}
};

//insert a node into linked list
void insert(LinkedNode **head, int x){
  LinkedNode *node = new LinkedNode(x);
  
  //insert head as down linked list of node
  node->down       = *head;

  //the head pointer has changed
  *head            = node;
}


//print out the linked list for debugging
void print(LinkedNode *head){
  while(head){
    cout<<head->val<<" ";
    head = head->down;
  }
  cout<<endl;
}

//recursively merge two sorted linked list. It looks more simplier than the iterative case
LinkedNode *merge(LinkedNode *l1, LinkedNode *l2){
  //base cases
  if(l1==NULL) return l2;
  
  if(l2==NULL) return l1;
  
  LinkedNode *res;
  //recursive cases
  if(l1->val < l2->val){
    res = l1;
    res->down = merge(l1->down, l2);
  }
  else{
    res = l2;
    res->down = merge(l1, l2->down);
  }
}


LinkedNode *flattern(LinkedNode *root){
  //deal with some base cases
  if(root==NULL ||root->next == NULL) return root;
  
  
  return merge(root, flattern(root->next));
}


//now here is a very simple test cases
int main(){
  LinkedNode *root = new LinkedNode(30);
  insert(&root, 8);
  insert(&root, 7);
  insert(&root, 5);
  
  insert(&(root->next), 20);
  insert(&(root->next), 10);
  
  insert(&(root->next->next), 50);
  insert(&(root->next->next), 22);
  insert(&(root->next->next), 19);
  
  insert(&(root->next->next->next), 45);
  insert(&(root->next->next->next), 40);
  insert(&(root->next->next->next), 35);
  insert(&(root->next->next->next), 28);
  
  root = flattern(root);
  print(root);
}
