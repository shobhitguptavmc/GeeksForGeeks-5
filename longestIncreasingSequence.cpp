#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<ctime>
using namespace std;

//this algorithm is based on dynampic programming
int LIS(vector<int>&seq){
  int n = seq.size(), res = 0;
  vector<int>dp(n, 1);
 
  for(int i = 0; i < n; i++){
    for(int j = 0; j < i; j++)
      if(seq[i] > seq[j]){
	dp[i] = max(dp[i], 1 + dp[j]);
      }
    res  = max(res, dp[i]);
  }

  return res;
}


//a simple test function
int main(){
  srand(time(NULL));
  vector<int>data(10);
  for(int i = 0; i < 10; i++)
    data[i] = rand()%100;
  
  for(int i = 0; i < 10; i++)
    cout<<data[i]<<" ";
  cout<<endl;
  
  cout<<"The longest increasing sequence is "<<LIS(data)<<endl;
}

