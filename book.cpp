#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include "book.h"
#include "util.h"

using namespace std;

Book::Book( std::string category, std::string name, double price, int qty, std::string isbn, std::string author ):
Product::Product(category, name, price, qty){
	isbn_ = isbn;	
	author_ = author;
}
std::set<std::string> Book::keywords() const{
	set<string> temp;
	set<string> temp2;
	set<string> nAme=parseStringToWords(convToLower(name_));
	set<string> auThor=parseStringToWords(author_);
	temp2.insert(isbn_);
	temp = setUnion(nAme,auThor);
	temp = setUnion(temp,temp2);
	return temp;
}
string Book::displayString() const{
	string temp1,temp2;
	string p,q;
	stringstream ss(temp1);
	ss << price_;
	ss >> p;
	stringstream sc(temp2);
	sc << qty_;
	sc >> q;
	return name_ + "\n" + "Author: " + author_ + " " + "ISBN: " + isbn_ + "\n" + p + " " + q + " left";
}
void Book::dump(std::ostream& os) const{
	Product::dump(os);
	os << isbn_ << endl;
	os << author_ << endl;
}
bool Book::isMatch(std::vector<std::string>& searchTerms) const{
	return false;
}
