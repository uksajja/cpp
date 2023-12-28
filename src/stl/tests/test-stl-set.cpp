//STL - Set
/*Sets are a type of associative containers 
(1) each elements is unique, because the value of the element identifies it
(2) elements are stored ina specific order (default order is ascending order)
(3) internally use the working principle of a Binary Search Tree to store elements 
(4) the value of the element cannot be modified once it is added to the set, though it is possible to remove and add the modified value of that element.
*/
/*
Common methods:
---------------
begin(), end()
size()
empty()
insert()
emplace() 
find()
count()
erase()
clear()
swap()
emplace() vs insert:
--------------------
When we use insert, we create an object and then insert it into the multiset. With emplace(), the object is constructed in-place.

Other methods:
--------------
rbegin(), rend()
cbegin(), cend()
crbegin(), crend()
emplace_hint(iterator position, value)

Iterators:
----------
std::set<int>::iterator
std::set<int>::const_iterator
std::set<int>::reverse_iterator
std::set<int>::const_reverse_iterator
auto
*/

#include<gmock/gmock.h>
#include<gtest/gtest.h>
#include<set>
#include<vector>
#include<algorithm>
#include<iostream>


struct compare_object{
    bool operator()(int a, int b) const{
        return (a%10 == 0 && b%10 == 0 && a<b);
    }
};
class Point {
    public:
        Point(int x, int y): mX(x), mY(y){}
        int getX() { return mX; }
        int getY() { return mY; }
        bool operator<(Point p) const {
            return (mX < p.mX)? true : (mX==p.mX)? (mY<p.mY) : false;
        }
        bool operator>(Point p) const {
            return (mX > p.mX)? true : (mX==p.mX)? (mY>p.mY) : false;
        }
        
    private:
        int mX, mY;
};

std::ostream& operator<<(std::ostream& stream, Point A) {
    stream << "( " << A.getX() << "," << A.getY() <<")" ;
    return stream;
}

std::ostream& operator<<(std::ostream& stream, std::pair<int,int> A) {
    stream << "( " << A.first << "," << A.second <<")" ;
    return stream;
}
//Show methods
/*
void show(std::set<int> s){
    if(s.empty()){
        std::cout << " The set is empty " << std::endl;
        return;
    }
    std::cout << "The elements in the set are (auto): " << std::endl;
    for(auto it : s){
        std::cout << it << "  " ;

    }
    std::cout << std::endl;
}
void show(std::set<int, std::greater<int>> s){
    if(s.empty()){
        std::cout << " The set is empty " << std::endl;
        return;
    }
    std::cout << "The elements in the set(greater) are (auto): " << std::endl;
    for(auto it : s){
        std::cout << it << "  " ;

    }
    std::cout << std::endl;
}
void show(std::set<int, compare_object> s){
    if(s.empty()){
        std::cout << " The set is empty " << std::endl;
        return;
    }
    std::cout << "The elements in the set are (auto): " << std::endl;
    for(auto it : s){
        std::cout << it << "  " ;

    }
    std::cout << std::endl;
}*/

template< class T>
void show(T s){
    if(s.empty()){
        std::cout << " The set is empty " << std::endl;
        return;
    }
    std::cout << "Set has " << s.size() << "elements." << std::endl;
    std::cout << "The elements in the set are (auto): " << std::endl;
    for(auto it : s){
        std::cout << it << "  " ;

    }
    std::cout << std::endl;
}

void show1(std::set<int> s){
    if(s.empty()){
        std::cout << " The set is empty " << std::endl;
        return;
    }
    std::cout << "The elements in the set are (iterator): " << std::endl;
    for(std::set<int>::iterator it = s.begin(); it!=s.end(); it++){
        std::cout << *it << "  " ;

    }
    std::cout << std::endl;
}
void show2(std::set<int> s){
    if(s.empty()){
        std::cout << " The set is empty " << std::endl;
        return;
    }
    std::cout << "The elements in the set are (const_iterator): " << std::endl;
    for(std::set<int>::const_iterator it = s.cbegin(); it!=s.cend(); it++){
        std::cout << *it << "  " ;

    }
    std::cout << std::endl;
}
void show3(std::set<int> s){
    if(s.empty()){
        std::cout << " The set is empty " << std::endl;
        return;
    }
    std::cout << "The elements in the set in reverse order are (reverse_iterator): " << std::endl;
    for(std::set<int>::const_reverse_iterator it = s.rbegin(); it!=s.rend(); it++){
        std::cout << *it << "  " ;

    }
    std::cout << std::endl;
}
void show4(std::set<int> s){
    if(s.empty()){
        std::cout << " The set is empty " << std::endl;
        return;
    }
    std::cout << "The elements in the set in reverse order are (const_reverse_iterator): " << std::endl;
    for(std::set<int>::const_reverse_iterator it = s.crbegin(); it!=s.crend(); it++){
        std::cout << *it << "  " ;

    }
    std::cout << std::endl;
}
TEST(STLSET, show){
    std::set<int> s({4,3,1,5,2});
    std::set<int, std::greater<int>> rs({4,3,1,5,2});
    show1(s);
    show2(s);
    show3(s);
    show(s);
    show(rs);
}
//Different ways of set initialization methods
TEST(STLSET,initialization1){
    std::set<int> s({4,3,1,5,2});
    std::set<int> res({1,2,3,4,5});
    EXPECT_THAT(s, ::testing::ContainerEq(res));
}
TEST(STLSET,initialization2){
    std::set<int> s;
    std::set<int> res({1,2,3,4,5});
    s.insert(5);
    s.insert(1);
    s.insert(4);
    s.insert(3);
    s.insert(2);
    EXPECT_THAT(s, ::testing::ContainerEq(res));
}
TEST(STLSET,initialization3){
    int arr[] = {4,5,2,1,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    std::set<int> s;
    std::set<int> res({1,2,3,4,5});
    s.insert(arr, arr+n);
    EXPECT_THAT(s, ::testing::ContainerEq(res));
}
TEST(STLSET,initialization4){
    std::vector<int>v{4,5,2,1,3};
    std::set<int> s;
    std::set<int> res({1,2,3,4,5});
    s.insert(v.begin(), v.end());
    EXPECT_THAT(s, ::testing::ContainerEq(res));
}
TEST(STLSET,initialization5){
    std::set<int> old_s({4,3,1,5,2});
    std::set<int> res({1,2,3,4,5});
    std::set<int> s(old_s.begin(), old_s.end());
    EXPECT_THAT(s, ::testing::ContainerEq(res));
}
TEST(STLSET,initialization6){
    std::set<int> old_s({4,3,1,5,2});
    std::set<int> res({1,2,3,4,5});
    std::set<int> s(old_s);
    EXPECT_THAT(s, ::testing::ContainerEq(res));
}

//Different ways of deletion from a set
TEST(STLSET, erase1){
    std::set<int> s({4,1,2,5,3});
    std::set<int> res({1,2,3,5});
    s.erase(4); // erase by value. set does not have remove()
    EXPECT_THAT(s, ::testing::ContainerEq(res));
}
TEST(STLSET, erase2){
    std::set<int> s({4,1,2,5,3});
    std::set<int> res({1,2,3,5});
    std::set<int>::iterator it;
    it = s.find(4); // returns the position(iterator) corresponding to element 4
    s.erase(it);
    EXPECT_THAT(s, ::testing::ContainerEq(res));
}
TEST(STLSET, erase3){
    std::set<int> s({4,1,2,5,3});
    std::set<int> res({1,2,3,5});
    std::set<int>::iterator it = std::next(s.begin(), 3); //3 is index here
    s.erase(it);
    EXPECT_THAT(s, ::testing::ContainerEq(res));
}
TEST(STLSET, erase4){
    std::set<int> s({4,1,2,5,3});
    std::set<int> res({1,2,3,5});
    std::set<int>::iterator it = s.begin(); 
    std::advance(it, 3);//it is advanced 3 positions i.e., to position 3 is index here
    s.erase(it);
    EXPECT_THAT(s, ::testing::ContainerEq(res));
}
TEST(STLSET, erase5){
    std::set<int> s({4,1,2,5,3});
    std::set<int> res({1,2,5});
    std::set<int>::iterator it1, it2;
    it1 = std::next(s.begin(), 2); // position 2 iterator
    it2 = std::next(s.begin(), 4); // position 3 iterator
    s.erase(it1, it2); // element at position it2 is not deleted. only elements at positions 2 and 3 are deleted
    EXPECT_THAT(s, ::testing::ContainerEq(res));
}
TEST(STLSET, clear){
    std::set<int> s({4,1,2,5,3});
    std::set<int> res({});    
    s.clear();
    EXPECT_THAT(s, ::testing::ContainerEq(res));
    EXPECT_TRUE(s.empty());
}
TEST(STLSET, empty){
    std::set<int> s({4,1,2,5,3});  
    s.clear();
    EXPECT_TRUE(s.empty());
}
TEST(STLSET, count){
    std::set<int> s({4,1,2,5,3,4});  
    EXPECT_EQ(s.count(4), 1); //set contains unique elements and no duplicates. Hence for a set, count is ether 1 (if element is present) or 0 (if element doesn't exist)
}
TEST(STLSET, size){
    std::set<int> s({4,1,2,5,3,4});  
    EXPECT_EQ(s.size(), 5);
}
TEST(STLSET, find){
    std::set<int> s({4,1,2,5,3,0});  
    EXPECT_EQ(*(s.find(4)), 4); //find() returns iterator position for element value=4. Hence, indirection(*) needs to be used in order to access the element
}
TEST(STLSET, swap){
    std::set<int> s1({4,1,2,5,3,0});
    std::set<int> s2({90,80});
    s1.swap(s2);
    EXPECT_THAT(s1, ::testing::ContainerEq(std::set<int>({80,90})));
    EXPECT_THAT(s2, ::testing::ContainerEq(std::set<int>({0,1,2,3,4,5})));
}
TEST(STLSET, keycomp1){
    std::set<int> s({10,20,50,30,40});
    std::set<int>::key_compare f_comp = s.key_comp();
    EXPECT_TRUE(f_comp(5, 7));
    EXPECT_FALSE(f_comp(7, 5));
    EXPECT_FALSE(f_comp(5, 5));
}
TEST(STLSET, keycomp2){
    std::set<int, std::greater<int>> s({10,20,50,30,40});
    std::set<int, std::greater<int>>::key_compare f_comp = s.key_comp();
    EXPECT_FALSE(f_comp(5, 7));
    EXPECT_TRUE(f_comp(7, 5));
    EXPECT_FALSE(f_comp(5, 5));
}

//Only multiples of 10 are stored in ascending order }
TEST(STLSET, keycomp3){
    std::set<int, compare_object> s({10, 20, 11, 50, 33, 30, 56, 40, 77, 90, 40});
    std::set<int, compare_object>::key_compare f_comp = s.key_comp();
    show(s);
    EXPECT_TRUE(f_comp(10, 30));
    EXPECT_FALSE(f_comp(20, 10));
    EXPECT_FALSE(f_comp(5, 5));
    EXPECT_FALSE(f_comp(15, 5));
}
TEST(STLSET, equaloperator){
    std::set<int> s1 = {1,2,3,4}, s2;
    s2 = s1;
    EXPECT_THAT(s1, ::testing::ContainerEq(s2));
}
TEST(STLSET, insert){
    std::set<int> s1 = {5,1,7,3}, s2={8,4,2,6, 1};
    s1.insert(s2.begin(), s2.end());
    EXPECT_THAT(s1, ::testing::ContainerEq(std::set<int>{1,2,3,4,5,6,7,8}));
}
TEST(STLSET, getallocator){
    //The set::get_allocator() in C++ STL is an in-built function which returns the copy of the allocator object associated with the set.
    std::set<int> s;
    int *mem = s.get_allocator().allocate(10); // declaring mem as any data type other than int* will result in an error
    for(int i = 0; i<10; i++){
        *(mem+i) = 10+i;
    }

    show(s);// s is still empty
    std::cout << "size of mem: " << sizeof(mem) << std::endl;
    for(int i = 0; i<10; i++){
        std::cout << *(mem+i) << " ";
    }
}
TEST(STLSET, emplaceVSinsert1){
    std::set<Point> s;
    Point p(2,3);
    s.insert(Point(0,3));
    s.insert(p);
    s.emplace(-1,1);   
    // s.insert(1,2); This leads to an error where as s.emplace(1,2) works fine
    show(s);
}
TEST(STLSET, emplaceVSinsert2){
    std::set<Point, std::greater<Point>> s;
    Point p(2,3);
    s.insert(Point(0,3));
    s.insert(p);
    s.emplace(-1,1);   
    // s.insert(1,2); This leads to an error where as s.emplace(1,2) works fine
    show(s);
}
TEST(STLSET, emplaceVSinsert3){
    std::set<std::pair<int, int>, std::greater<std::pair<int, int>>> s;
    s.insert({10,4});
    s.insert({12,3});
    s.emplace(10, 3);
    s.emplace(-10,1);   
    // s.insert(1,2); This leads to an error where as s.emplace(1,2) works fine
    show(s);
}



