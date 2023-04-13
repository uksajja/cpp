#ifndef HASHTABLE_H_
#define HASHTABLE_H_


#include <iostream>
#include <string>


#define TABLE_SIZE 4

class HashTable {

private:
	static const int tableSize = TABLE_SIZE ;

	struct item{
		std::string name;
		std::string dept;
		int    rollNo;
		item*  next;
	};
	item* entries[tableSize];

public:
	HashTable();
	virtual ~HashTable();

	int  hashFunction(std::string key);
	void addItem(std::string, std::string, int);

	void removeItem(std::string key);
	void searchItem(std::string key);

	void removeItem2(std::string key);
	void searchItem2(std::string key);

	void removeAllItems();

	int  countTableItems();
	int  countIndexItems(int index);

	void printTable();
	void printIndexItems(int index);

};
void test_hash_table();
#endif /* HASHTABLE_H_ */
