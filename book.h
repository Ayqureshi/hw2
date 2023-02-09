#ifndef BOOK_H
#define BOOK_H
#include "product.h"
#include <sstream>

class Book: public Product{
	public:
	Book(std::string category, std::string name, double price, int qty, std::string isbn, std::string author);
	virtual std::set<std::string> keywords() const;
	virtual std::string displayString() const;
	virtual void dump(std::ostream& os) const;
	virtual bool isMatch(std::vector<std::string>& searchTerms) const;

	protected:
		std::string isbn_;
		std::string author_;


};
#endif