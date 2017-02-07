#include<iostream>
using namespace std;

#ifndef LIST_T
#define LIST_T

#include<cstdlib>
#include<cassert>

class node_t;
typedef node_t* node_tptr;
class list_t;
typedef list_t* list_tptr;

typedef void* TYPE;

class node_t
{
   public:
      node_t(void);         //default constructor
      node_t(TYPE newdata);   //constructor
      void set_next(node_tptr );  
      node_tptr get_next(void);
      TYPE get_data(void);
   private:
      node_tptr next;  //next link in the list
      TYPE data;        //the data 
};

class list_t
{
   public:
      list_t(void);
      list_t(const list_tptr);
      void insert(TYPE newdata);
      void remove(TYPE curdata);
      bool search(TYPE curdata);
      void dump(void);
      TYPE start(void);
      TYPE get_next(void);
   private:
      node_tptr head;
      node_tptr tail;
      node_tptr current;

};
#endif
