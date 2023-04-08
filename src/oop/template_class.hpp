
#ifndef VECTEMP_H_
#define VECTEMP_H_


#include <iostream>

/*
 * Class definition and the function definitions
 * should not be separated into different files
 */

template <class T>
class VecTemp {
 private:
	int length;
	T*   data;
public:
	VecTemp(int, T*);
	virtual ~VecTemp();
	void displayVec();
};


template <class T>
VecTemp<T>::VecTemp(int l, T* entries) {
	// constructor stub
	length = l;
	data = new T [length];
	for( int i=0; i<l; i++){
		data[i] = *(entries+i);
	}

}
template <class T>
VecTemp<T>::~VecTemp() {
	// destructor stub
	delete data;

}
template  <class T>
void VecTemp<T> :: displayVec(){
	for (int i=0; i<length; i++){
		std::cout << data[i] <<std::endl;
	}
}

void test_template_class(){
	std::cout << "\n------------------------------------------------------------" << std::endl;
    std::cout << "    Test : Template class example                       " << std::endl;
    std::cout << "-------------------------------------------------------------" << std::endl;
	int n=5, arr[5]= {10, 20, 30, -5, 1};
	VecTemp<int> V(n, arr);
	V.displayVec();
};

#endif /* VECTEMP_H_ */
