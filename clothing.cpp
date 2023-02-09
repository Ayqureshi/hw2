#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include "clothing.h"
#include "util.h"

using namespace std;

Clothing::Clothing(const std::string category, const std::string name, double price, int qty, const std::string size, const std::string brand):
Product::Product(category, name, price, qty){
	size_ = size;	
	brand_ = brand;
}
set<string> Clothing::keywords()const{
	set<string> temp;
	set<string> temp2;
	set<string> nAme=parseStringToWords(name_);
	set<string> brAnd=parseStringToWords(brand_);
	temp2.insert(convToLower(size_));
	temp = setUnion(nAme,brAnd);
	temp = setUnion(temp,temp2);
	return temp;
}
string Clothing::displayString() const{
	string temp1,temp2;
	string p,q;
	stringstream ss(temp1);
	ss << price_;
	ss >> p;
	stringstream sc(temp2);
	sc << qty_;
	sc >> q;
	return name_ + "\n" + "Size: " +size_ + " Brand: " + brand_ + "\n" + p + " " + q + " left";
}
void Clothing::dump(std::ostream& os) const{
	Product::dump(os);
	os << size_ << endl;
	os << brand_ << endl;
}
bool Clothing::isMatch(std::vector<std::string>& searchTerms) const{
	return false;
}
