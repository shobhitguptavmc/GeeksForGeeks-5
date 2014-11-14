#include<iostream>
#include<string>
using namespace std;

//This problem is from Bloomberg interview
string reverseWords(string str){
  string res;
  //append space
  string s = str + " ";
  int prev = 0;
  for(int i = 0; i < s.size(); i++){
    if(s[i] == ' '){
      string sub = s.substr(prev, i - prev);
      res = " " + sub + res;
      prev = i + 1;
    }
  }
  return res.substr(1);
}

//a test function
int main(){
  string s = "li qing";
  cout<<reverseWords(s)<<endl;
}
