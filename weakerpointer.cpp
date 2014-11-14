#include<iostream>
#include<memory>
using namespace std;

weak_ptr<int> gw;

void f(){
  if(auto spt = gw.lock())
    cout<<*spt<<endl;
  else
    cout<<"expired"<<endl;
}

int main(){
  {
    auto sp = make_shared<int> (42);
    gw = sp;
    f();
  }
  f();

}
