#include"list_t.h"


node_t::node_t(void)
{
   next = NULL;
   data = 0;
}
node_t::node_t(TYPE newdata)
{
   next = NULL;
   data = newdata;
}
void node_t::set_next(node_tptr nextptr)
{
   next = nextptr;
}
node_tptr  node_t::get_next(void)
{
   return next;
}
TYPE  node_t::get_data(void)
{
   return data;
}



list_t::list_t(void)
{
   head = tail = NULL;
}
list_t::list_t(const list_tptr)
{
   //This is the list copy constructor.  Since the list is 
   //dynamic, the basic copy constructor is not sufficient.
   //Need to implement is you need to copy a list.
}
void list_t::insert(TYPE newdata)
{
   node_tptr tmpptr;
   tmpptr = new node_t((void*)newdata);
   assert(tmpptr != NULL);
   if(head == NULL) {
      //list is empty so set head and tail to point to new node
      head = tail = tmpptr;
   } else {
      tail->set_next(tmpptr);
      tail = tmpptr;
   }
}
void list_t::dump(void)
{
   //dump the list with one data element per line
   current = head;
   while(current!=NULL){
      cout<<current->get_data()<<endl;
      current = current->get_next();
   }
}
bool list_t::search(TYPE curdata)
{
   current=head;
   while(current!=NULL){
      if(current->get_data() == curdata)
         return true;
      current = current->get_next();
   }
   return false;
}
TYPE list_t::start(void)
{
   current = head;
   if(current != NULL)
      return current->get_data();
   return NULL;
}
TYPE list_t::get_next(void)
{
   node_tptr tmpptr;
   if(current != NULL){
      tmpptr = current->get_next();
      if(tmpptr == NULL)
         return NULL;
      else{
         current = tmpptr;
         return current -> get_data();
      }
   }else
      return NULL;
}
