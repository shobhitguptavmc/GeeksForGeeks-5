#include<iostream>
using namespace std;

/*This is problem is from geeksforgeeks and is to implement a double linked-list based queue
*/

//definition of a list node
struct ListNode{
  int val;
  ListNode *next;
  ListNode *prev;
  ListNode(int x): val(x), next(NULL), prev(NULL) {}
};

class queue{
private:
  ListNode *head;
public:
  queue() { head = NULL; }

  //enqueue function
  void push(int x);
  
  //dequeue function
  void pop();
  
  //get the front element function
  int front(){ return head->val;}

  //print function for debugging
  void print();
};

void queue::push(int x){
  //if this queue is empty
  if(head==NULL){
    head = new ListNode(x);
    head->next = head;
    head->prev = head;
    return;
  }
  
  ListNode *tail   = head->prev;
  ListNode *temp   = new ListNode(x);
  temp->next       = tail->next;
  tail->next->prev = temp;
  tail->next       = temp;
  temp->prev       = tail;
}

void queue::pop(){
  if(head==NULL){
    cout<<"empty queue"<<endl;
    return;
  }
  
  //deal with the case we have only one node
  if(head->next == head){
    ListNode *temp = head;
    delete temp;
    head = NULL;
    return;
  }
  
  //deal with the other cases
  ListNode *temp       = head, *next = head->next;
  head->prev->next     = next;
  next->prev           = head->prev;
  head                 = next;
  delete temp;
}

void queue::print(){
  //corner case: the queue is empty
  if(head==NULL){
    cout<<"empty queue"<<endl;
    return;
  }
  
  ListNode *cur = head->next;
  cout<<head->val<<" ";

  while(cur != head) {
    cout<<cur->val<<" ";
    cur = cur->next;
  }
  cout<<endl;
}



//a simple test function
int main(){
  cout<<"test function for myqueue"<<endl;
  queue myqueue;
  
  for(int i = 0; i < 10; i++){
    myqueue.push(i);
  }
  myqueue.print();

  for(int i = 0; i < 10; i++)
    myqueue.pop();
  
  myqueue.print();
}
