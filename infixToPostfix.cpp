#include<iostream>
#include<stack>
#include<string>
#include<cctype>
using namespace std;

bool isOperator(char ch){
  if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
    return true;
  return false;
}

//return the precedence of operator, + -: 1, * / : 2, ^: 3
int precedence(char ch){

  switch(ch){
  case '+':
  case '-':
    return 1;
  case '*':
  case '/':
    return 2;
  case '^':
    return 3;
  }
  //this is an exception
  return -1;
}
string infixToPostfix(string input){
  //use stack to help this process
  stack<char> mystack;
  
  string res;
  
  for(int i = 0; i < input.size(); i++){
    //deal with the case input[i] is an alphabet
    if(isalpha(input[i]))
       res = res + input[i];

    else if(isOperator(input[i])){
	//if the stack is empty or its precedence is higher than the top element of the stack
      if(mystack.empty() || precedence(input[i]) > precedence(mystack.top()) )
	  mystack.push(input[i]);
	else{
	  //pop out current top, and push input[i]
	  res = res + mystack.top();
	  mystack.pop();
	  mystack.push(input[i]);
	}
    }
    //deal with the case '(', push it to the stack
    else if(input[i] == '(')
      mystack.push(input[i]);
    
    else if(input[i] == ')'){
      //pop out everything till we meet '('
      while(mystack.top() != '('){
	res = res + mystack.top();
	mystack.pop();
      }
      //pop out '('
      mystack.pop();
    }
  }
  
  //pop out everything
  while(!mystack.empty()){
    res = res + mystack.top();
    mystack.pop();
  }

  return res;
}
      

//a simple test function
int main(){
  string str = "(a+b-c*d/e)";
  string res = infixToPostfix(str);
  cout<<"The infix is "<<str<<endl;
  cout<<"The post fix result is ";
  cout<<res<<endl;
}
