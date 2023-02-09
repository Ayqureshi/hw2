#include <string>
#include <set>
#include <vector>
#include <map>
#include "mydatastore.h"
#include <queue>



using namespace std;


MyDataStore::MyDataStore(){
}
MyDataStore::~MyDataStore(){
	for(unsigned int i =0; i<Store.size();i++){
		delete Store[i];
	}
	for(map<string,User*>::iterator it = user_bank.begin(); it != user_bank.end();it++){
		delete it->second;
	}
}
void MyDataStore::addProduct(Product* p){
	set<string>words = p->keywords();
	Store.push_back(p);
	for(set<string>::iterator it = words.begin(); it!=words.end();it++){
		// std::cout << *it << std::endl;
		if(search_bank.find(*it) != search_bank.end()){
			search_bank.find(*it)->second.insert(p);
		}
		else{
			set<Product*> product_list;
			product_list.insert(p);
			search_bank.insert(make_pair(*it,product_list));
		}
	}

}
void MyDataStore::addUser(User* u){
	user_bank.insert(std::make_pair(u->getName(), u));
}
vector<Product*> MyDataStore::search(vector<string>& terms, int type){
	vector<Product*> results;
	set<Product*> intersect;
	set<Product*> temp;
	if(type == 0){ // and
		if(terms.size()==0){
		return results;
		}
		else{
			temp = search_bank[terms[0]];
			for(unsigned int i=0;i < terms.size();i++){
				map<string,set<Product*>>::iterator it = search_bank.find(terms[i]);
				if(it != search_bank.end()){
					intersect = it->second;
					temp = setIntersection(intersect,temp);
				}
				else{
					continue; 
				}
			}
			for(set<Product*>::iterator its = temp.begin();its!=temp.end();its++){
				results.push_back(*its);
				
			}
		}
		return results;
	}
	else if(type == 1){
		temp = search_bank[terms[0]];
		for(unsigned int i=0;i < terms.size();i++)
		{
			
			map<string,set<Product*>>::iterator it;
			it = search_bank.find(terms[i]);
			if(it != search_bank.end())
			{
				intersect = it->second;
				temp = setUnion(intersect,temp);
			}
			else{
				// std::cout<<"nothing found"<<std::endl;
					continue; 
					
					
				}
		}
			for(set<Product*>::iterator its = temp.begin();its!=temp.end();its++){
				results.push_back(*its);
				
			}
		}
		return results;
}
void MyDataStore::dump(std::ostream& ofile){
	ofile << "<products>" << endl;
	for(unsigned int i =0;i<Store.size();i++){

		Store[i]->dump(ofile);
	}
	ofile << "</products>" << endl;
	ofile << "<users>" << endl;
	for(map<std::string, User*>::iterator dmp2 = user_bank.begin();dmp2!=user_bank.end();dmp2++){
		(dmp2->second)->dump(ofile);
	}
	ofile << "</users>" << endl;
}

void MyDataStore::add(std::string username, Product* P){
	std::map<std::string, User*>::iterator it = user_bank.find(username);
	if (it != user_bank.end()) 
	{
  	if(cart.find(username) == cart.end()){
			
				vector<Product*>cart_contents;
				cart_contents.push_back(P);
				
				cart.insert(std::make_pair(username,cart_contents));
				std::cout<<cart[username].size()<<endl;
		}
		else{
			
			cart.find(username)->second.push_back(P);
		}
	}
	else{
		
		std::cout<<"Invalid request"<<std::endl;
	}
}
void MyDataStore::buy(string username){
	if(user_bank.find(username)== user_bank.end()){
		cout <<"Invalid Username" <<endl;
		return;
	}
	if(cart.find(username)== cart.end()){
		cout <<"Invalid request" <<endl;
		return;
	}

	for(unsigned int i = 0; i < cart[username].size();i++){
		if(cart[username][i]->getQty() > 0){
			if(user_bank[username]->getBalance() > cart[username][i]->getPrice()){
				user_bank[username]->deductAmount(cart[username][i]->getPrice());
				cart[username][i]->subtractQty(1);	
				// cart[username].erase(cart[username].begin());
			}
			else{
					cart[username].erase(cart[username].begin()+i);
			}
		}
	}
}
	
void MyDataStore::view(string username){
	if(user_bank.find(username)== user_bank.end()){
		cout <<"Invalid username" <<endl;
	}
	else{
		for(unsigned int i = 0; i < cart[username].size();i++){
			cout << "Item " << i+1<<"\n" << (cart[username][i])->displayString()<<endl; 
		}
	}
}
