#include<iostream>
#include<vector>
#include<queue>
#include<utility>
using namespace std;

//Two ways to traverse a tree level by level
struct TreeNode{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

///actually inorder processing
void dfs(TreeNode *root, vector<vector<int> >&res, int level){
  //base case
  if(root==NULL) return;

  //first deal with the root
  if(level < res.size() )
    res[level].push_back(root->val);
  else{
    vector<int>cur(root->val);
    res.push_back(cur);
  }
  
  //deal with left
  dfs(root->left, res, level + 1);
  //deal with right
  dfs(root->right, res, level + 1);
}

//bfs way

vector<vector<int> >bfs(TreeNode *root){
  //base case
   //return data structure
  vector<vector<int> >res;
  if(root==NULL) return res;
  queue<pair<TreeNode *, int> >myqueue; //<tree node, level>
  myqueue.push(make_pair(root, 0));
   //bfs way
  while(!myqueue.empty()){
    //deal with one level
    TreeNode *node = myqueue.front().first;
    int level      = myqueue.front().second;
    myqueue.pop();
    //current level
    vector<int> cur;
    cur.push_back(node->val);

    if(node->left)
      myqueue.push(make_pair(node->left, level + 1));
    if(node->right)
      myqueue.push(make_pair(node->right, level + 1));
    
    while(!myqueue.empty() && myqueue.front().second == level){
      TreeNode *temp = myqueue.front().first;
      cur.push_back(temp->val);
      myqueue.pop();

      if(temp->left)
	myqueue.push(make_pair(temp->left, level + 1));
      if(temp->right)
	myqueue.push(make_pair(temp->right, level + 1));
    }
    
    res.push_back(cur);
  }
  return res;
  
}


void print(vector<vector<int> >res){
  for(int i = 0; i < res.size(); i++){
    for(int j = 0; j < res[i].size(); j++)
      cout<<res[i][j]<<" ";
    cout<<endl;
  }
  cout<<endl;
}
//test function
int main(){
  TreeNode *root = new TreeNode(1);
  root->left     = new TreeNode(2);
  root->right    = new TreeNode(3);

  print(bfs(root));
}

