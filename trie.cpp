#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
using namespace std;
//trie node
typedef struct trie_node trie_node_t;

struct trie_node{
  int value;
  trie_node *children[26];
};

//trie ADT
typedef struct trie trie_t;
struct trie{
  trie_node_t *root;
  int count;
};

//returns new trie node (initialized to NULLS)
trie_node_t *getNode(void){
 
  trie_node_t *pNode = NULL;
  
  pNode = (trie_node_t *)malloc(sizeof(trie_node_t));
  
  if(pNode){

    int i;
    
    pNode->value = 0;
    
    for(int i = 0; i < 26; i++)
      pNode->children[i] = NULL;
  }

  return pNode;
}

//initialize trie (root is dummy node)
void initialize(trie_t *pTrie){
  pTrie->root  = getNode();
  pTrie->count = 0;
}

//If not present, inserts key into trie
//If the key is prefix of trie node, just marks leaf node
void insert(trie_t *pTrie, char key[]){
  int length = strlen(key);
  
  trie_node_t *pCrawl;
  
  pTrie->count++;
  pCrawl = pTrie->root;
  
  for(int level = 0; level < length; level++){
    int index = key[level] - 'a';
    if(!pCrawl->children[index])
      pCrawl->children[index] = getNode();
    pCrawl = pCrawl->children[index];
  }
  //mark last node as leaf
  pCrawl->value = pTrie->count;
}

//return its longest prefix
int search(trie_t *pTrie, char key[]){
  int length = strlen(key);
  trie_node_t *pCrawl;
  
  string res;
  pCrawl = pTrie->root;
  
  for(int level = 0; level < length; level++){
    int index = key[level] - 'a';
    if(!pCrawl->children[index])
      return 0;

    pCrawl = pCrawl->children[index];
  }
  return (0 != pCrawl && pCrawl->value);
}

//Driver
int main(){
  //Input keys (use only 'a' through 'z' and lower case)
  char keys[][8] = {"the", "a", "there", "anwser", "any", "by", "bye", "their"};
  
  trie_t trie;
  
  initialize(&trie);
  
  //construct trie
  for(int i = 0; i < 8; i++)
    insert(&trie, keys[i]);
  
  return 0;
}
