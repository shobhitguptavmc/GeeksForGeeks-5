#include<iostream>
#include<string>
#include<vector>
using namespace std;

//method 1 is based on recursive function. Method 2 is dynamic programming. Related program can be found in Leetcode
bool isSubstring(string source, string pattern){
  
  //first deal with base cases
  if(pattern.empty()) return true;
  if(source.empty()) return false;

  //recursive cases
  if(source[0] == pattern[0]){
    string subs = source.substr(1);
    string subp = pattern.substr(1);
    return isSubstring(subs, subp)||isSubstring(subs, pattern);
  }
  else{
    string subs = source.substr(1);
    return isSubstring(subs, pattern);
  }
}


//the drive function
int main(){
  string s = "THIS    IS    A TEST";
  string p = "IS A";
  cout<<isSubstring(s, p)<<endl;
}
