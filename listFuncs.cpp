// Name: Xin Zhang
// USC NetID: xzhang55  USCID:4998-6225-16
// CSCI 455 PA5
// Spring 2021


#include <iostream>

#include <cassert>

#include "listFuncs.h"

using namespace std;

Node::Node(const string &theKey, int theValue) {
   key = theKey;
   value = theValue;
   next = NULL;
}

Node::Node(const string &theKey, int theValue, Node *n) {
   key = theKey;
   value = theValue;
   next = n;
}



//*************************************************************************
// put the function definitions for your list functions below
bool containsKey(ListType & list, const string &this_key){
   assert(this_key.length() > 0);
   Node *cur_list = list;
   if(cur_list == NULL){
      return false;
   }
   
   if(cur_list->key == this_key){
      return true;
   }
   
   while(cur_list->next != NULL){
      cur_list = cur_list->next;
      if(cur_list->key == this_key){
         return true;
      }
   }
   return false;
}


void put(ListType & list, const string &key, int value){
   assert(key.length() > 0);
   assert(value >=0);
   Node *newNode = new Node(key, value);
   Node *cur_list = list;
   if(list == NULL){
      list = newNode;
      return;
   }
   
   while(cur_list->next != NULL){
      cur_list = cur_list->next;
   }
   cur_list->next = newNode;

}


bool removeKey(ListType & list, const string &this_key){
   assert(this_key.length() > 0);
   Node *left = list;
   
   if(containsKey(left, this_key) == false){
      return false;
   }
   
   if(list->key == this_key){
      list = list->next;
      delete left;
      return true;
   }
   
   while(left->next != NULL && (left->next)->key != this_key){
      left = left->next;
   }
   Node *del = left->next;
   left->next = left->next->next;
   delete del;
   return true;
}


ListType getAddress(ListType &list, const string &this_key){
   assert(this_key.length() > 0);
   Node *cur_list = list;
   if(containsKey(cur_list, this_key) == false){
      return NULL;
   }
   
   while(cur_list->key != this_key){
      cur_list = cur_list->next;
   }
   return cur_list;
}


void printList(ListType & list){
   Node *cur_list = list;
   
   while (cur_list != NULL){
      cout<<(cur_list->key)<<" "<<(cur_list->value)<<endl;
      cur_list = cur_list->next;
   }
}


int listLen(ListType & list){
   int len = 0;
   Node *cur_list = list;
   while (cur_list != NULL){
      len ++;
      cur_list = cur_list->next;
   }
   return len;
}
