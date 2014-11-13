#include<iostream>
#include<deque>
using namespace std;

void printKMax(int arr[], int n, int k){
  deque<int> Qi(k);
  //process first k (or first windown) elements of arry
  int i;
  for(i = 0; i < k; i++){
    //remove all elements smaller than the
    //currently being added element
    while((!Qi.empty() && arr[i] >= arr[Qi.back()]))
	  Qi.pop_back(); //remove from rear
	
    //Add new element at rear of queue
    Qi.push_back(i);
  }
  
  //process rest of the elements, i.e., from arr[k] to arr[n-1]
  for(; i < n; i++){
    //The element at the front of the queue is the largest element of the previous windown, so print it
    cout<<arr[Qi.front()]<<" ";
    
    //remove the elements which are out of this window
    while( (!Qi.empty()) && Qi.front() <= i - k)
      Qi.pop_front(); //remove from front of queue
    
    //remove all elements smaller than the currently being added element
    while( (!Qi.empty()) && arr[i] >= arr[Qi.back()])
      Qi.pop_back();
    
    //add current element at the rear of Qi
    Qi.push_back(i);
  }
  
  cout<<arr[Qi.front()];
  cout<<endl;
}

//Driver program to test above functions
int main(){
  int arr[] = {12, 1, 78, 90, 57, 89, 56};
  int n = sizeof(arr)/sizeof(int);
  printKMax(arr, n, 3);
}
