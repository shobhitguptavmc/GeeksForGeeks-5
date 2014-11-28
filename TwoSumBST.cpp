#include<iostream>
#include<stack>
using namespace std;

struct TreeNode{
  int value;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x): value(x), left(NULL), right(NULL) {}
};


bool twoSum(TreeNode *root1, int sum){
  stack<TreeNode *>mystack1;
  stack<TreeNode *>mystack2;
  TreeNode *cur1 = root1, *cur2 = root1;
  
  //inorder traverse both bst
  while(cur1||!mystack1.empty()||cur2||!mystack2.empty()){
    //in order processing
    if(cur1){
      mystack1.push(cur1); 
      cur1 = cur1->left;  //first visit left for bst1
    }
    
    if(cur2){
      mystack2.push(cur2);
      cur2 = cur2->right; //right first for bst2
    }
    
    else{
      if(mystack1.empty() || mystack2.empty())
	return false;
      
      cur1 = mystack1.top();
      mystack1.pop();
      
      cur2 = mystack2.top();
      mystack2.pop();
  
      if(cur1->value + cur2->value == sum){
	return true;
      }
      
      if(cur1->value >= cur2->value){
	return false;
      }


      //move cur1
      if(cur1->value + cur2->value < sum){
	cur1 = cur1->right;
	mystack2.push(cur2);
	cur2 = NULL;
      }
      //move cur2
      else{
	cur2 = cur2->left;
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

  twoSum(root1, 8);
}
