#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include "util.h"
#include "movie.h"

using namespace std;

Movie::Movie(const std::string category, const std::string name, double price, int qty, const std::string rating, const std::string genre):
Product::Product(category, name, price, qty){
	genre_ = genre;	
	rating_ = rating;
}
set<string> Movie::keywords() const{
	set<string> temp;
	set<string> temp2;
	// name_ = convToLower(name_);
	set<string> nAme=parseStringToWords(name_);
	set<string> gEnre=parseStringToWords(genre_);
	temp2.insert(rating_);
	temp=setUnion<string>(nAme,gEnre);
	temp=setUnion<string> (temp,temp2);
	return temp;
}
string Movie::displayString() const{
	string temp1,temp2;
	string p,q;
	stringstream ss(temp1);
	ss << price_;
	ss >> p;
	stringstream sc(temp2);
	sc << qty_;
	sc >> q;
	return name_ + "\n" + "Genre: " + genre_ + " " + "Rating: " + rating_ + "\n" + p + " " + q + " left";
}
void Movie::dump(std::ostream& os) const{
	Product::dump(os);
	os << genre_ << std::endl;
	os << rating_<< std::endl;
}
bool Movie::isMatch(std::vector<std::string>& searchTerms)const {
	return false;
}