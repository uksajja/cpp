
#include "hash_table.h"

HashTable::HashTable() {
	// Constructor stub
	for(int i=0; i<tableSize; i++){
		entries[i] = NULL;
	}
}

HashTable::~HashTable() {
	// TODO Auto-generated destructor stub
	for(int i=0; i<tableSize; i++){
		item* parent = NULL;
		for(item* p=entries[i]; p!=NULL; p = p->next){
			if (parent !=NULL) delete parent;
			parent = p;
		}
		if (parent !=NULL) delete parent;
		entries[i] = NULL;
	}
}

int HashTable :: hashFunction(std::string key){
	int hash = 0;
	int index;
	for( int i=0; i<key.length(); i++){
		hash += (int) key[i];
		//std::cout << "hash = " << hash << std::std::endl;
	}
	index = hash%tableSize;
	return(index);
}

void HashTable :: addItem(std::string name, std::string dept, int rollNo){
	int index;
	item* newItemPtr;
	item* p;

	index = hashFunction(name);
	newItemPtr         = new item;
	newItemPtr->name   = name;
	newItemPtr->dept   = dept;
	newItemPtr->rollNo = rollNo;
	newItemPtr->next   = NULL;

	if(entries[index] == NULL){
		entries[index] = newItemPtr;
	} else{
		for(p=entries[index]; p->next!=NULL; p=p->next);
		p->next = newItemPtr;
	}
}

int HashTable :: countTableItems(){
	int count = 0;
	for(int i=0; i<tableSize; i++){
		for(item* p = entries[i]; p!=NULL; p = p->next){
			count++;
		}
	}
	return (count);
}

int HashTable :: countIndexItems(int index){
	int count = 0;
	for(item* p=entries[index]; p!=NULL; p=p->next){
		count++;
	}
	return(count);
}

void HashTable :: printTable(){
	int n = countTableItems();
	std::cout <<"========================================"<<std::endl;
	std::cout << "Table Size : " << tableSize << "  #items in the table : " << n << std::endl;
	if (n==0 ) {
		std::cout << "Table is empty " << std::endl; 
		return;
	}
	std::cout <<"----------------------------------------"<<std::endl;
	for(int i=0; i<tableSize; i++){		
		std::cout << "index = "<<i<< "  #items in Index: " << countIndexItems(i) <<std::endl;
		for(item* p=entries[i]; p!=NULL; p = p->next){

			std::cout << "name: " <<p->name << "  dept: " << p->dept<< "  rollNo: " << p->rollNo <<std::endl;
		}
		std::cout << "----------------------------------------"<<std::endl;
	}
}

void HashTable :: printIndexItems(int index){
	std::cout << "Total number of items in the index (" << index << ") : "<<countIndexItems(index) << std::endl;
	for(item* p=entries[index]; p!=NULL; p = p->next){
		std::cout << "name: " <<p->name << "  dept: " << p->dept<< "  rollNo: " << p->rollNo <<std::endl;
	}
}

void HashTable :: searchItem(std::string name){
	bool itemFound = false;
	int index;
	item* itemPtr = NULL;

	index = hashFunction(name);
	if(entries[index] == NULL){
		std::cout << "Item with name :" <<name <<" is not found in the table." <<std::endl;
	} else{
		for(itemPtr = entries[index]; itemPtr!=NULL; itemPtr=itemPtr->next){
			if(itemPtr->name == name){
				itemFound = true;
				break;
			}
		}
		if(itemFound == true){
			std::cout << "Item with name :" <<name <<" is found." <<std::endl;
			std::cout << "Details of the item are :" <<std::endl;
			std::cout << "Name: "<<itemPtr->name << "  Dept: "<<itemPtr->dept << "  RollNo.: " <<itemPtr->rollNo<<std::endl;

		} else{
			std::cout << "Item with name :" <<name <<" is not found in the table." <<std::endl;
		}
	}
}

void HashTable :: searchItem2(std::string name){
	bool itemFound=false;
	item* itemPtr=NULL;
	item* p;
	for(int i=0; i<tableSize; i++){
		for(p = entries[i]; p!=NULL; p=p->next){
			if(p->name == name){
				itemPtr = p;
				itemFound = true;
				break;
			}
		}
		if(itemFound == true) break;
	}
	if(itemFound == true){
		std::cout << "Item with name :" <<name <<" is found." <<std::endl;
		std::cout << "Details of the item are :" <<std::endl;
		std::cout << "Name: "<<itemPtr->name << "  Dept: "<<itemPtr->dept << "  RollNo.: " <<itemPtr->rollNo<<std::endl;

	} else{
		std::cout << "Item with name :" <<name <<" is not found in the table." <<std::endl;
	}
}

void HashTable :: removeItem(std::string name){
	bool itemFound = false;
	item* prevPtr;
	item* itemPtr;
	int index;

	index = hashFunction(name);
	if(entries[index] == NULL){
		std::cout << "Item with name :" <<name <<" is not found in the table." <<std::endl;
	} else{
		prevPtr = NULL;
		for(itemPtr = entries[index]; itemPtr!=NULL; itemPtr=itemPtr->next){
			if(itemPtr->name == name){
				itemFound = true;
				break;
			}
			prevPtr = itemPtr;
		}
		if(itemFound == false){
			std::cout << "Item with name :" <<name <<" is not found in the table." <<std::endl;
		} else {
			if(prevPtr==NULL){
				entries[index] = itemPtr->next;
			} else{
				prevPtr->next = itemPtr->next;
			}
			std::cout << "Item with name :" <<name <<" is deleted." <<std::endl;
			std::cout << "Details of the deleted item are :" <<std::endl;
			std::cout << "Name: "<<itemPtr->name << "  Dept: "<<itemPtr->dept << "  RollNo.: " <<itemPtr->rollNo<<std::endl;

			delete itemPtr;
		}
	}
}

void HashTable :: removeItem2(std::string name){
	bool itemFound = false;
	item* prevPtr;
	item* itemPtr;
	int index;

	for(int i=0; i<tableSize; i++){
		prevPtr = NULL;
		for(itemPtr = entries[i]; itemPtr!=NULL; itemPtr=itemPtr->next){

			if(itemPtr->name == name){
				itemFound = true;
				index = i;
				break;
			}
			prevPtr = itemPtr;
		}
		if(itemFound == true) break;
	}
	if(itemFound == false) {
		std::cout << "Item with name :" <<name <<" is not found in the table." <<std::endl;
	} else{
		if(prevPtr==NULL){
			entries[index] = itemPtr->next;
		}else{
			prevPtr->next = itemPtr->next;
		}
		std::cout << "Item with name :" <<name <<" is deleted." <<std::endl;
		std::cout << "Details of the deleted item are :" <<std::endl;
		std::cout << "Name: "<<itemPtr->name << "  Dept: "<<itemPtr->dept << "  RollNo.: " <<itemPtr->rollNo<<std::endl;
		delete itemPtr;
	}
}

void HashTable::removeAllItems(){
	for (int i=0; i<tableSize; i++){
		item* parent = NULL;
		for(item* p=entries[i]; p!=NULL; p=p->next){
			if(parent !=NULL) delete parent;
			parent = p;
		}
		if(parent !=NULL) delete parent;
		entries[i] = NULL;
	}
}

void test_hash_table(){
	std::cout << "\n------------------------------------------------------------" << std::endl;
    std::cout << "    Test : Hash Table example           " << std::endl;
    std::cout << "-------------------------------------------------------------" << std::endl;

	int  index;
	char choice;
	std::string name, dept;
	int    rollNo;
	HashTable hashObj;

	//hashObj.printTable();

	/*while(1){
		std::cout << "Do you want to add a student info to HashTable?" <<std::endl;
		cin >> choice;
		if ((choice == 'y') ||(choice == 'Y')){
			std::cout <<"Enter name, dept, rollNo of a student :" <<std::endl;
			cin >> name >>dept >>rollNo;
			hashObj.addItem(name, dept, rollNo);
		} else{
			break;
		}
	}*/

	hashObj.addItem("uk", "me", 613);
	hashObj.addItem("vk", "ee", 415);
	hashObj.addItem("wk", "ee", 110);
	hashObj.addItem("tl", "cs", 521);
	hashObj.addItem("wi", "me", 617);
	hashObj.addItem("ul", "civil", 613);
	hashObj.addItem("yi", "me", 635);
	hashObj.addItem("xj", "cs", 613);

	std::cout << std::endl;
	hashObj.printTable();

	std::cout << std::endl;
	hashObj.searchItem("yi");

	std::cout << std::endl;
	hashObj.removeItem("uk");

	std::cout << std::endl;
	hashObj.removeItem("tl");

	std::cout << std::endl;
	hashObj.searchItem("uk");

	std::cout << std::endl;
	hashObj.removeItem("tl");

	std::cout << std::endl;
	hashObj.printTable();

	hashObj.removeAllItems();
	std::cout << "After removing all items: " << std::endl;
	hashObj.printTable();
	hashObj.addItem("uk", "me", 613);
	hashObj.addItem("vk", "ee", 415);
	hashObj.printTable();
}
