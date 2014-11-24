#include<iostream>
using namespace std;

//this is the implementation of linkedHashEntry

//the following is the class declaration of linked hash entry
class LinkedHashEntry{
private:
  int key;
  int value;
  LinkedHashEntry *next;
public:
  //constructor
  LinkedHashEntry(int key, int value){
    this->key   = key;
    this->value = value;
    this->next  = NULL;
  }
  
  int getKey(){
    return key;
  }

  int getValue(){
    return value;
  }

  void setValue(int value){
    this->value = value;
  }

  LinkedHashEntry *getNext(){
    return next;
  }
  
  void setNext(LinkedHashEntry *next){
    this->next = next;
  }
};

const int TALBE_SIZE = 128;

//the following is the class declaration of hash map
class HashMap{
private:
  LinkedHashEntry **table;

public:
  //constructor
  HashMap(){
    table = new LinkedHashEntry *[TABLE_SIZE];
    for(int i = 0; i < TABLE_SIZE; i++)
      table[i] = NULL;
  }
  
  int get(int key){
    int hash = (key % TABLE_SIZE);
    
    if(table[hash] == NULL)
      return -1;
    else{
      LinkedHashEntry *entry = table[hash];
      while(entry != NULL && entry->getKey() != key)
	entry = entry->getNext();
      
      if(entry == NULL)
	return -1;
      else
	return entry->getValue();
    }
  }

  void put(int key, int value){
    int hash = (key % TABLE_SIZE);
    
    if(table[hash] = NULL)
      table[hash] = new LinkedHashEntry(key, value);
    else{
      LinkedHashEntry *entry = table[hash];
      
      while(entry->getNext() != NULL)
	entry = entry->getNext();
      
      if(entry->getKey() == key)
	entry->setValue(value);
      else
	entry->setNext(new LinkedHashEntry(key, value));
    }
  }

  void remove(int key){
    int hash = (key % TABLE_SIZE);
    
    if(table[hash] != NULL){
      LinkedHashEntry *prevEntry = NULL;
      LinkedHashEntry *entry     = table[hash];
      
      while(entry->getNext() != NULL && entry->getKey() != key){
	preEntry = entry;
	entry    = entry->getNext();
      }
      
      if(entry->getKey() == key){
	if(prevEntry == NULL){
	  LinkedHashEntry *nextEntry = entry->getNext();
	  delete entry;
	  table[hash] = nextEntry;
	}
	else{
	  LinkedHashEntry *next = entry->getNext();
	  delete entry;
	  prevEntry->setNext(next);
	}
      }
    }
  }
  
  //deconstructor
  ~HashMap(){
    for(int i = 0; i < TABLE_SIZE; i++)
      //the following part is actually delete a linked list
      if(table[i]  != NULL){
	LinkedHashEntry *prev  = NULL;
	LinkedHashEntry *entry = table[i];
	while(entry != NULL){
	  prevEntry = entry;
	  entry     = entry->getNext();
	  delete prevEntry;
	}
      }
    delete[] table;
  }
};
