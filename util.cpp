#include <iostream>
#include <sstream>
#include <cctype>
#include <algorithm>
#include "util.h"

using namespace std;
std::string convToLower(std::string src)
{
    std::transform(src.begin(), src.end(), src.begin(), ::tolower);
    return src;
}

/** Complete the code to convert a string containing a rawWord
    to a set of words based on the criteria given in the assignment **/
std::set<std::string> parseStringToWords(string rawWords)
{

	std::set<std::string> temp;

	for(unsigned int i = 0; i < rawWords.length(); i++){
		if(ispunct(rawWords[i])){
			rawWords[i] = ' ';
		}
	}
	istringstream ss(rawWords);
	string word;
	string temp_word;
	while(ss >> word){
		if(word.length() > 1){
			trim(word);
			temp.insert(word);
			temp.insert(convToLower(word));
		}
	}

	// istringstream ss(rawWords);
	// string word;
	// string temp_word;
	// while(ss >> word){
	// 	if(word.length() > 1){
	// 		for(unsigned int i=0;i<word.length();i++){
	// 			if(!ispunct(word[i])){
	// 				temp_word.push_back(word[i]);
	// 			}
	// 			else{
	// 				if(temp_word.size()>1){
	// 					convToLower(temp_word);
	// 					temp.insert(temp_word);
	// 				}
	// 				temp_word = "";	
	// 			}
	// 		}
	// 	}
	// }
return temp;
	
		
    //go throught the string and when it gets to a space stop
    //save that to a new string
    //create a dictionary with the raw word and all the new strings
    //in addition to making the rawWord a key

    //Essentially make a dictionary of the string
    // iterate through the string and set each word
    // into a key for that dictionary 
    // in addition to making the rawWord a key

}

/**************************************************
 * COMPLETED - You may use the following functions
 **************************************************/

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// trim from start
std::string &ltrim(std::string &s) {
    s.erase(s.begin(), 
	    std::find_if(s.begin(), 
			 s.end(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))));
    return s;
}

// trim from end
std::string &rtrim(std::string &s) {
    s.erase(
	    std::find_if(s.rbegin(), 
			 s.rend(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))).base(), 
	    s.end());
    return s;
}

// trim from both ends
std::string &trim(std::string &s) {
    return ltrim(rtrim(s));
}
