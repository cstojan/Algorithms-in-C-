/*
	NAME: Cory Stojan
	DUE DATE: 16 November 2018
	COURSE: CSCI 340
	PROGRAM NUMBER: 9
	DISCRIPTION OF PROGRAM: Source code for the hTable.h file. 
*/
#include "/home/cs340/progs/18f/p9/hTable.h"


/*************************************************************
   Function: HT()
   Discription: Constructor method to create a new hash Table
   Arguments:  const unsigned refrence hs - declares the size of the table
   Returns: Nothing. Is constructor.
*************************************************************/
HT::HT(const unsigned& hs){

   //set values
  hTable.resize(hs);
  pTable.resize(hs);
  hsize = hs;
  psize = 0;
  for (unsigned i = 0; i != hs; i++)
    {
        hTable[i].key = FREE;
    }
    
}

/*************************************************************
   Function: ~HT()
   Discription: Destructor of the two different arrays.
   Arguments: NONE
   Returns: Nothing. Is destructior for the HT class.
*************************************************************/
HT:: ~HT(){
// possibly causes a seg fault in first output
	// destroy hTable
	hTable.clear();

	// destroy pTable
	pTable.clear();
	
	// tables are not fully destoryed
}

/*************************************************************
   FUNCTION: insert()
   Discription: this method will insert the Entry object into the correct
        spot within the hash table based on the key
   ARGUEMENTS:  const Entry refrence (newEntry)
    Returns: void
*************************************************************/
void HT:: insert(const Entry& newEntry){

	// local Variables
   int ihash = hash(newEntry.key);
   unsigned sub = ihash;

 // check for space and insert new entry
   for(auto i = hTable.begin(); i != hTable.end(); i++){
   		// Check for a duplicate key
      if (hTable[sub].key == newEntry.key){
         cout << "not inserted - duplicate key!!!" << endl;
         return;
      }

      // Check if the table is full
      if (sub == hsize){
         cout << "not inserted = table full!!!" << endl;
         return;
     }

      // Check for an empty hash table slot
      if (hTable[sub].key == FREE){

         //copy newEntry into hTable[subscript]
         hTable[sub] = newEntry;

         //set pTable[psize] to the address of hTable[subscript]
		 pTable[psize] = &hTable[sub]; // <-- seg fault?
         psize++;

         //print the rest of the successful insert message
         cout << "entry = " << setw(2) << sub << endl;
         return;
      }

      // Increment subscript
      sub = (sub + 1) % hsize;
      ihash++;
  }
}
      
/*************************************************************
   FUNCTION: search()
   Discription: Searches hTable for a given search key
   ARGUEMENTS: const string& (searchKey)
   Returns: void
*************************************************************/
void HT::search(const string& searchKey){

	// Local Variables
   int hashValue = hash(searchKey);
   int sub = hashValue;
 
   // Find key
   while (true){
   	
      // Check for a matching key
      if (hTable[sub].key == searchKey){

         //print the other fields of hTable[subscript]
         cout << "search:  " << "Key " << hTable[sub].key << " ==> number: " 
              << setw(4) << right << hTable[sub].num << " - item: " 
              << hTable[sub].desc << endl;
         break;
      } 


      // Increment subscript
      sub = (sub + 1) % hsize;

      // Check if the table is full
      if (sub == hashValue){
         cout << "Key " << searchKey << " not in table!!" << endl; 
         break;
      }
   }
}

/*************************************************************
   FUNCTION: hTable_print()
   Discription: prints hTable
   ARGUEMENTS: NONE
   Returns: void
*************************************************************/
void HT:: hTable_print(){

	// local Variables
   bool lastEmpty = false;
   
   // Print hTable
   for(unsigned i = 0; i < hsize; i++){

   	// Ensure free spots are not being printed
      if(hTable[i].key != FREE){
      	
	  	// create new line for entry
	     if(lastEmpty)
		    cout << endl;

		 // output table 
         cout << setw(4) << i <<":  "
              << hTable[i].key << "  - "
              << setw(5) << hTable[i].num << "  -  "
              << hTable[i].desc << endl;

		// set lastempty to false
         lastEmpty = false;				 
      }
      // if spot is free set last empty to true
      else 
         lastEmpty = true;
   }
   // output new line
   cout << endl;
} 

/*************************************************************
   FUNCTION: pTable_print()
   Discription: Sorts pTable and then prints the contents of pTable
   Arguments: NONE
   Returns: void
*************************************************************/
void HT:: pTable_print(){
	
   // sort pTable
   sort( pTable.begin(), pTable.end(),
        []( Entry* p, Entry* q) {
                return p->key < q->key;
        }
    );
	// set output to be formatted to the right
    cout << right;
	// output pTable
    for(auto it = pTable.begin(); it != pTable.end(); it++)
            cout << setw(6) << (*it)->key << "  -  " << (*it)->num << "  -  " << (*it)->desc  << endl;
   
}
	


