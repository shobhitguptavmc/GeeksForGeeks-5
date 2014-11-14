#include<iostream>
using namespace std;

//here is the class definition of hash entry
class hashEntry{
private:
  int key;
  int value;
public:
  hashEntry(int k, int v): key(k), value(v){}
  
  int getKey() {return key;}
  
  int getValue() {return value;}
};

const int TABLE_SIZE = 128;

//here is the class definition of hash map
class HashMap{

private:
  hashEntry **table;

public:
  HashMap(){
    table = new hashEntry*[TABLE_SIZE];
    for(int i = 0; i < TABLE_SIZE; i++)
      table[i] = NULL;
  }
  
  int get(int key){
    //this is our mapping function. It is may not very good.
    int hash = (key % TABLE_SIZE);
    
    while(table[hash]->getKey() != key && table[hash]){
      hash = (hash + 1)%TABLE_SIZE;
    }
    //we do not have the hash value
    if(!table[hash]) return -1;
    
    else return table[hash]->getValue();
  }

  int push(int key, int value){
    int hash = (key % TABLE_SIZE);
    
    while(table[hash]->getKey() != key && table[hash]) hash = (hash + 1)%TABLE_SIZE;
    
    if(table[hash]) delete table[hash];
    
    table[hash] = new hashEntry(key, value);
  }

  ~HashMap(){
    for(int i = 0; i < TABLE_SIZE; i++){
      if(table[i])
	delete table[i];
    }
    
    delete []table;
  }
};
