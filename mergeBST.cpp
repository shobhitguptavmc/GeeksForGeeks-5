#include<iostream>
#include<stack>
using namespace std;

struct TreeNode{
  int value;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x): value(x), left(NULL), right(NULL) {}
};


void inorder(TreeNode *root){
  if(root == NULL) return;
  
  inorder(root->left);
  
  cout<<root->value<<" ";
  
  inorder(root->right);
}

void mergeBST(TreeNode *root1, TreeNode *root2){
  stack<TreeNode *>mystack1;
  stack<TreeNode *>mystack2;
  TreeNode *cur1 = root1, *cur2 = root2;
  
  //inorder traverse both bst
  while(cur1||!mystack1.empty()||cur2||!mystack2.empty()){
    //in order processing
    if(cur1){
      mystack1.push(cur1); 
      cur1 = cur1->left;  //first visit left
    }
    
    if(cur2){
      mystack2.push(cur2);
      cur2 = cur2->left; //left first
    }
    
    else{
      if(mystack1.empty()){
	while(!mystack2.empty()){
	  cur2 = mystack2.top();
	  mystack2.pop();
	  cur2->left = NULL;
	  inorder(cur2);
	}
	return;
      }
      
      if(mystack2.empty()){
	while(!mystack1.empty()){
	  cur1 = mystack1.top();
	  mystack1.pop();
	  cur1->left = NULL;
	  inorder(cur1);
	}
	return;
      }

      cur1 = mystack1.top();
      mystack1.pop();
      
      cur2 = mystack2.top();
      mystack2.pop();

      if(cur1->value < cur2->value){
	cout<<cur1->value<<" ";
	cur1 = cur1->right;
	mystack2.push(cur2);
	cur2 = NULL;
	
      }
      
      else{
	cout<<cur2->value<<" ";
	cur2 = cur2->right;
	mystack1.push(cur1);
	cur1 = NULL;
      }
    }  
  }
}

//A test function
int main(){
  TreeNode *root1 = new TreeNode(3);
  root1->left  = new TreeNode(1);
  root1->right = new TreeNode(5);

  TreeNode *root2 = new TreeNode(4);
  root2->left     = new TreeNode(2);
  root2->right    = new TreeNode(6);

  mergeBST(root1, root2);
}
