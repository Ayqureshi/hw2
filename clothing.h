#ifndef CLOTHING_H
#define CLOTHING_H
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include <sstream>
#include "product.h"

class Clothing: public Product{
	public:
	Clothing(std::string category, std::string name, double price, int qty, std::string size, std::string brand);
	virtual std::set<std::string> keywords() const;
	virtual std::string displayString() const;
	virtual void dump(std::ostream& os) const;
	virtual bool isMatch(std::vector<std::string>& searchTerms) const;

	protected:
		std::string brand_;
		std::string size_;


};
#endif