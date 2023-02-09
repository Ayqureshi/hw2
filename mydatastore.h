#ifndef MYDATASTORE_H 
#define MYDATASTORE_H
#include <string>
#include <set>
#include <map>
#include <vector>
#include "product.h"
#include "user.h"
#include "datastore.h"
#include "util.h"

class MyDataStore : public DataStore{
public:
		MyDataStore();
    ~MyDataStore();
    void addProduct(Product* p);
    void addUser(User* u);
    std::vector<Product*> search(std::vector<std::string>& terms, int type);
    void dump(std::ostream& ofile);
		void add(std::string username, Product* P);
		void buy(std::string username);
		void view(std::string username);
		std::map<std::string, std::vector<Product*>> cart;
		
		

protected:
		std::vector<Product*> Store;
		std::map<std::string,User*>  user_bank;
		std::map<std::string,std::set<Product*>> search_bank;
		std::set<std::string> keyw;
		
};
#endif


