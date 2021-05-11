// Name: Xin Zhang
// USC NetID: xzhang55  USCID:4998-6225-16
// CSCI 455 PA5
// Spring 2021


//*************************************************************************
// Node class definition 
// and declarations for functions on ListType

// Note: we don't need Node in Table.h
// because it's used by the Table class; not by any Table client code.

// Note2: it's good practice to not put "using" statement in *header* files.  Thus
// here, things from std libary appear as, for example, std::string

#ifndef LIST_FUNCS_H
#define LIST_FUNCS_H

#include <string>
  

struct Node {
   std::string key;
   int value;

   Node *next;

   Node(const std::string &theKey, int theValue);

   Node(const std::string &theKey, int theValue, Node *n);
};


typedef Node * ListType;

//*************************************************************************
//add function headers (aka, function prototypes) for your functions
//that operate on a list here (i.e., each includes a parameter of type
//ListType or ListType&).  No function definitions go in this file.



/*
   Check Wether the key (word) in the entry. return False if not, return True if it is.
   Input: Reference of List, the String we want to check
*/
bool containsKey(ListType & list, const std::string &this_key);


/*
   Put the Key and its value into the linklist.
   Input: Reference of List, the String and its corresponding value we want to put.
*/
void put(ListType & list, const std::string &key, int value);
   

/*
   Remove the key in the linklist. Return False if the key not in the list. Return True if successfully remove
   Input: Reference of List, the String we want to remove
*/
bool removeKey(ListType & list, const std::string &this_key);


/*
   Get the a Address of the key, Return Address or NULL if not in the list.
   Input: Reference of List, the String we want to get address
*/
ListType getAddress(ListType &list, const std::string &this_key);


/*
   Print the entire list for debug and Table.
   Input: Reference of list
*/
void printList(ListType & list);


/*
   Return the length of the list.
   Input: Reference of list
*/
int listLen(ListType & list);



// keep the following line at the end of the file
#endif
