/*
	NAME: Cory Stojan
	DUE DATE: 02 October 2018
	COURSE: CSCI 340
	PROGRAM NUMBER: 4
	DISCRIPTION OF PROGRAM: Recieves input from STDIN. Converts a string of random chars to a string of lowercase letters.
				Uses one headder file (prog4.h)
*/

// Include Headder Files
#include "prog4.h"

// Main Program
int main() {
	// create an empty string
	map<string, int> words;
	
	// get_words function
	get_words(words);
	
	// print_words function 
	print_words(words);
	
	
	return(0);
}

// Function Definations

///////////////////////////////////////////////////////////////////////////////////////////////////////////	
/************************************
Function: get_words
Returns: nothing
Arguments: a refrence to a map<string, int>
Purpose: Uses STD input to get a word (may have punctuation marks on it)
************************************/
void get_words(map<string, int>& wrdStr) {
	// create two empty strings
	string word;
	string str;

	// read input file, clean input (use clean_entry)	
	while(cin >> word) {
		//counter for amount of words before cleaning
		nonDistWords++;
		// clean the input string
		clean_entry(word, str);

		//go to next input position
		wrdStr[str]++;
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////	
/************************************
Function: print_words
Returns: nothing
Arguments: a refrence to a constant map<string,int>
Purpose: Prints the results of the words without punctuation marks
************************************/
void print_words(map<string, int>& w) {
	// Constant Variables
	#define ITEM_W 16     //max size of items on line
	#define NO_ITEMS 3    //number of items per line
	
	// Varibles
	map<string, int>::iterator it;
	int num = 0; // <-- keeps track of number of items per line
	
	//print all elements
	for (it=w.begin(); it!=w.end(); it++) {
		// include counter (num)
		num++;
		// output results
		cout << setw(ITEM_W) << it->first << " : " << it->second;
		if (num == NO_ITEMS) {
			// create new line if max items per line has reached
			num = 0;
			cout << endl;
		}
    }
    // dispay message for number of word and number of distinct words
	cout << "Amount of Non Distinct Words: " << nonDistWords << endl;
	cout << "Amount of Distinct Words: " << w.size() << endl;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////	
/************************************
Function: clean_entry
Returns: nothing
Arguments: a refrence to a string constant, and a refrence to a string
Purpose: Cleans a word. Makes a word lower case and without punctuation marks.
************************************/
void clean_entry(const string& word, string& str) {
	//index vars
	unsigned int i=0;
	unsigned int j;
	
	
	//test for punctuation until word is done and there is no punctuation
	while(!isalnum(word[i]) && i<word.length()) {
		//go to next char in word
		i++;
	}
	
	//set positions
	j = i;
	
	// if word is a alpha numeric char then add it to str
	while(isalnum(word[j]) && j < word.length()) {
		// set j position
		j++;
		if(j == i)
			// skip positon if j and i are the same
			str = "";
		else {
			//copy function
			str=word.substr(i, j-i);
			
			//convert all capitals to lower case
			for_each(str.begin(), str.end(), lowerstr);
		}
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////	
/************************************
Function: lowerstr
Returns: nothing
Arguments: a char refrence (c)
Purpose: Converts a string to lowercase using the tolower function
************************************/
void lowerstr(char & c){
	// use tolower to convert string.
	c = tolower(c);
}
