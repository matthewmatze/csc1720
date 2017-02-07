#include<string>
#include<iostream>

using namespace std;

/* table_lookup: the main purpose of this function is to reduce the
 *               size and complexity of the parsing the model
 * pre-condition: table contains a list of key words.  len is the number
 *                of key words in the table.  sv is the item of interest
 * post-condition: return the location of sv in the table.  if not
 *                 present, then return -1.
 */
int table_lookup(const string table[], int len, const string &sv)
{
   int i=0;
   bool found=false;
   while(i<len && !found){
      if(table[i] == sv)
         found = true;
      else
         i++;
   }
   if(found) 
      cerr << sv << " found at " << i << endl;
   else
      cerr << sv << " not found." << endl;
   return found?i:-1;
}
