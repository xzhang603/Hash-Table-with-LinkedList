// Name: Xin Zhang
// USC NetID: xzhang55  USCID:4998-6225-16
// CSCI 455 PA5
// Spring 2021

// pa5list.cpp
// a program to test the linked list code necessary for a hash table chain

// You are not required to submit this program for pa5.

// We gave you this starter file for it so you don't have to figure
// out the #include stuff.  The code that's being tested will be in
// listFuncs.cpp, which uses the header file listFuncs.h

// The pa5 Makefile includes a rule that compiles these two modules
// into one executable.

#include <iostream>
#include <string>
#include <cassert>

using namespace std;

#include "listFuncs.h"

typedef Node * ListType;

int main() {

   Node* cur = NULL;
   
   cout<<listLen(cur)<<endl;
   if(getAddress(cur, "look") == NULL){
      cout<<getAddress(cur, "look")<<endl;
   }
   
   put(cur, "the", 1);
   put(cur, "look", 2);
   put(cur, "Xin", 3);
   
   printList(cur);
   if(containsKey(cur, "look") == true){
      update(cur,"look");
      cout<<"yes!!!!"<<endl;
   }
   printList(cur);
   
   cout<<listLen(cur)<<endl;
   bool isRemove = removeKey(cur, "Xin");
   if (isRemove == true){
      cout<<"remove!!!"<<endl;
   }
   
   printList(cur);
   cout<<listLen(cur)<<endl;
   cout<<getAddress(cur, "look")<<endl;
   return 0;
}
