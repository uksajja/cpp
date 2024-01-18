#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <set>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>

#include "stl_set.hpp"

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
    std::set<int>::allocator_type a = s.get_allocator();
    int *mem = a.allocate(10); // declaring mem as any data type other than int* will result in an error
    for(int i = 0; i<10; i++){
        *(mem+i) = 10+i;
    }

    show(s);// s is still empty
    std::cout << "size of mem: " << sizeof(mem) << std::endl;
    for(int i = 0; i<10; i++){
        std::cout << *(mem+i) << " ";
    }
    a.deallocate(mem, 10);
}
// TODO:The Following needs to improve 
TEST(STLSET, getallocator2){
    std::set<std::string> str{"c++", "fortran", "python"};
    std::set<std::string>::allocator_type a = str.get_allocator();
    std::string* strset = a.allocate(2);
    //strset[0] = std::string("java");
    //strset[1] = std::string("c");
    //std::cout << strset[0] << "  " << strset[1] << std::endl;
    a.deallocate(strset,2);
}
TEST(STLSET, emplaceVSinsert1){
    // For user defined objects (i.e., Point in this eample), '<' and '>' operators need to be defined explicitly.
    // otherwise, sorting order is not known as there is no default order.
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
    //The pairs in a set are stored in sorted order, sorted by the key i.e. the first value of the pair.
    std::set<std::pair<int, int>> s;
    s.insert({10,4});
    s.insert({12,3});
    s.emplace(10, 3);
    s.emplace(-10,1);   
    // s.insert(1,2); This leads to an error where as s.emplace(1,2) works fine
    show(s);
}
TEST(STLSET, emplaceVSinsert4){
    //The pairs in a set are stored in sorted order, sorted by the key i.e. the first value of the pair.
    //Here the pairs are stored in descending order of first value(i.e., key)
    std::set<std::pair<int, int>, std::greater<std::pair<int, int>>> s;
    s.insert({10,4});
    s.insert({12,3});
    s.emplace(10, 3);
    s.emplace(-10,1);   
    // s.insert(1,2); This leads to an error where as s.emplace(1,2) works fine
    show(s);
}

TEST(STLSET, emplacehint) {
    std::set<int> s={2,3,6,9};
    show(s);
    std::set<int>::iterator it = s.begin();
    std::advance(it, 2);
    s.emplace_hint(it,8);
    show(s);
    s.emplace_hint(it,4); // This operation will be slow as 'it' is NOT at an optimal position to place 4
    show(s);
}
//lower_bound() - returns an iterator to the first element not less than the given key
TEST(STLSET, lowerbound){
    std::set<int> s{10, 20, 30, 40, 46, 50 };
    int n = *(s.lower_bound(25));//30 is the first elemet that is not less than 25
    EXPECT_EQ(n, 30);
}
//lower_bound() - returns an iterator to the first element not less than the given key
TEST(STLSET, lowerbound2){
    std::set<int> s{10, 20, 30, 40, 46, 50 };
    int n = *(s.lower_bound(20));// 20 is the first element that is not less than 20
    EXPECT_EQ(n, 20);
}
//upper_bound() - returns an iterator to the first element greater than the given key
TEST(STLSET, upperbound){
    std::set<int> s{10, 20, 30, 40, 46, 50 };
    int n = *(s.upper_bound(40)); //46 is the first element that is greater than 40
    EXPECT_EQ(n, 46);
}
//upper_bound() - returns an iterator to the first element greater than the given key
TEST(STLSET, upperbound2){
    std::set<int> s{10, 20, 30, 40, 46, 50 };
    int n = *(s.upper_bound(45));// 46 is the first element that is greater than 45
    EXPECT_EQ(n, 46);
}
TEST(STLSET, merge){
    /*
    Attempts to extract ("splice") each element in source and insert it into *this using the comparison object of *this. 
    If there is an element in *this with key equivalent to the key of an element from source, then that element is not extracted from source. 
    No elements are copied or moved, only the internal pointers of the container nodes are repointed. 
    All pointers and references to the transferred elements remain valid, but now refer into *this, not into source.
    */
    std::set<char> x = { 'C','A', 'K', 'B'};
    std::set<char> y = { 'A', 'L', 'C', 'D'};
    std::cout <<  x << std::endl;//{ 'A','B', 'C', 'K'}
    std::cout << y << std::endl; //{ 'A','C', 'D', 'L'}
    x.merge(y);
    std::cout <<  x << std::endl;
    std::cout << y << std::endl;
    EXPECT_THAT(x, ::testing::ContainerEq(std::set<char>{'A','B','C','D', 'K', 'L'}));
    EXPECT_THAT(y, ::testing::ContainerEq(std::set<char>{'A','C'}));
}




