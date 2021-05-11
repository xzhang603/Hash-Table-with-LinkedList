// Name: Xin Zhang
// USC NetID: xzhang55  USCID:4998-6225-16
// CSCI 455 PA5
// Spring 2021

// Table.cpp  Table class implementation


#include "Table.h"

#include <iostream>
#include <string>
#include <cassert>

// for hash function called in private hashCode method defined below
#include <functional>

using namespace std;


// listFuncs.h has the definition of Node and its methods.  -- when
// you complete it it will also have the function prototypes for your
// list functions.  With this #include, you can use Node type (and
// Node*, and ListType), and call those list functions from inside
// your Table methods, below.

#include "listFuncs.h"


//*************************************************************************


Table::Table() {
   hashsize = HASH_SIZE;
   hashset = new ListType[hashsize]();
}


Table::Table(unsigned int hSize) {
   assert(hSize >= 0);
   hashsize = hSize;
   hashset = new ListType[hashsize]();
}


int * Table::lookup(const string &key) {
   assert(key.length() > 0);
   ListType list = hashset[hashCode(key)];
   ListType Address = getAddress(list, key);
   if(Address == NULL){
      return 0;
   }
   return &(Address->value); 
}


bool Table::remove(const string &key) {
   assert(key.length() > 0);
   ListType & list = hashset[hashCode(key)];
   return removeKey(list, key);  
}


bool Table::insert(const string &key, int value) {
   assert(key.length() > 0);
   assert(value >= 0);
   ListType &list = hashset[hashCode(key)];
   if(containsKey(list,key)){
      return false;
   }
   put(list, key, value);
   return true;
}


int Table::numEntries() const {
   int num = 0;
   for (int i=0; i<hashsize; i++){
      //ListType list = hashset[i];
      num += listLen(hashset[i]);
      //cout<< num<<endl;
   }
   return num;      
}


void Table::printAll() const {
   for (int i = 0; i < hashsize; i++){
      ListType list = hashset[i];
      printList(list);
   }
}


void Table::hashStats(ostream &out) const {
   cout<<"number of buckets: "<<hashsize<<endl;
   cout<<"number of entries: "<<numEntries()<<endl;
   cout<<"number of non-empty buckets: "<<numNonEmptyBuck()<<endl;
   cout<<"longest chain: "<<LongestChain()<<endl;
}


// hash function for a string
// (we defined it for you)
// returns a value in the range [0, hashSize)
unsigned int Table::hashCode(const string &word) const {

   // Note: calls a std library hash function for string (it uses the good hash
   //   algorithm for strings that we discussed in lecture).
   return hash<string>()(word) % hashsize;

}


// add definitions for your private methods here

int Table::numNonEmptyBuck() const{
   int num = 0;
   for (int i = 0; i < hashsize; i++){
      ListType list = hashset[i];
      if (listLen(list) != 0){
         num ++;
      }
   }
   return num;      
}

int Table::LongestChain() const{
   int longest = 0;
   for (int i = 0; i < hashsize; i++){
      ListType list = hashset[i];
      if (listLen(list) > longest){
         longest = listLen(list);
      }
   }
   return longest;      
}
