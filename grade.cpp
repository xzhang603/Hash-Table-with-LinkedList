// Name: Xin Zhang
// USC NetID: xzhang55  USCID:4998-6225-16
// CSCI 455 PA5
// Spring 2021

/*
 * grades.cpp
 * A program to test the Table class.
 * How to run it:
 *      grades [hashSize]
 * 
 * the optional argument hashSize is the size of hash table to use.
 * if it's not given, the program uses default size (Table::HASH_SIZE)
 *
 */

#include "Table.h"

// cstdlib needed for call to atoi
#include <cstdlib>

using namespace std;

//Print all the instruction of help
void printInstruction();

//Excute cmd and its input
void Command(Table * grades);
   
int main(int argc, char * argv[]) {

   // gets the hash table size from the command line

   int hashSize = Table::HASH_SIZE;
   
   
   Table * grades;  // Table is dynamically allocated below, so we can call
   // different constructors depending on input from the user.

   if (argc > 1) {
      hashSize = atoi(argv[1]);  // atoi converts c-string to int
      
      if (hashSize < 1) {
         cout << "Command line argument (hashSize) must be a positive number" 
              << endl;
         return 1;
      }

      grades = new Table(hashSize);

   }
   else {   // no command line args given -- use default table size
      grades = new Table();
   }
   
   grades->hashStats(cout);
   
   //Excute cmd and its input
   Command(grades);
   
   return 0;
}

void printInstruction(){
   cout << "insert name score" << endl;
   cout << "   Insert this name and score in the grade table. If this name was already present, print a message to that effect, and don't do the insert." << endl;
   cout << "change name newscore" << endl;
   cout << "   Change the score for name. Print an appropriate message if this name isn't present." << endl;
   cout << "lookup name" << endl;
   cout << "   Lookup the name, and print out his or her score, or a message indicating that student is not in the table." << endl;
   cout << "remove name" << endl;
   cout << "   Remove this student. If this student wasn't in the grade table, print a message to that effect." << endl;
   cout << "print" << endl;
   cout << "   Prints out all names and scores in the table." << endl;
   cout << "size" << endl;
   cout << "   Prints out the number of entries in the table." << endl;
   cout << "stats" << endl;
   cout << "   Prints out statistics about the hash table at this point. (Calls hashStats() method)" << endl;
   cout << "help" << endl;
   cout << "   Prints out a brief command summary." << endl;
   cout << "quit" << endl;
   cout << "   Exits the program." << endl;
}

void Command(Table * grades){
   while(true){
      string cmd;
      string name;
      int score ;
      cout << "cmd>";
      cin >> cmd;
      if(cmd == "insert"){
         cin >> name;
         cin >> score;
         if(grades->insert(name, score) != true){
            cout << "Error: The name has already in the MAP." <<endl;
         }
      }
      else if(cmd == "change"){
         cin >> name;
         cin >> score;
         int *val = grades->lookup(name);
         if (val == NULL){
            cout << "Error: The name does not in the MAP."<<endl;
         }
         else{
            (*val) = score;
         }
      }
      else if(cmd == "lookup"){
         cin >> name;
         int *val = grades->lookup(name);
         if (val == NULL){
            cout << "Error: The name does not in the MAP."<<endl;
         }
         else{
            cout <<name<<" has: "<<*val<<endl;
         }
      }
      else if(cmd == "remove"){
         cin >> name;
         if (grades->remove(name) != true){
            cout << "Error: The name does not in the MAP."<<endl;
         }
      }
      else if(cmd == "print"){
         grades->printAll();
      }
      else if(cmd == "size"){
         cout << "The number of entry/entries is/are: " << grades->numEntries() << endl;
      }
      else if(cmd == "stats"){
         grades->hashStats(cout);
      }
      else if(cmd == "help"){
         printInstruction();
      }
      else if(cmd == "quit"){
         return;
      }
      else{
         cout << "Wrong cmd, input again." << endl;
      }
  
   }
}
