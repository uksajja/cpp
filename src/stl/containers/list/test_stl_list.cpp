/*
List ==> a doubly linked list. 
Lists are sequence containers that allow non-contiguous memory allocation. 
As compared to vector, the list has slow traversal, but once a position has been found, insertion and deletion are quick.
*/
#include <list>
#include <algorithm>

#include <gmock/gmock.h>
#include <gtest/gtest.h>


//Capacity related functions
//===========================
//size()
TEST(STLLIST, size){
    std::list<int> l{1,2,3};
    EXPECT_EQ(l.size(),3);
}
//max_size()
TEST(STLLIST, max_size){
    std::list<int> l{1,2,3};
    std::list<double> ld{2.55, 3.15, 4.16, 12.65,13.59};
    EXPECT_EQ(l.max_size(), 768614336404564650);
    EXPECT_EQ(ld.max_size(), 768614336404564650);
}

//Element Access:
//=================
//front()
TEST(STLLIST, front){
    std::list<int> l{1,2,3};
    EXPECT_EQ(1, l.front());
}
//back()
TEST(STLLIST, back){
    std::list<int> l{1,2,3};
    EXPECT_EQ(3, l.back());
}

//Modifiers
//=========
TEST(STLLIST, pushfront){
    std::list<int> l{1,2,3};
    std::list<int> res{4, 1,2,3};
    l.push_front(4);
    EXPECT_THAT(l, ::testing::ContainerEq(res));
}
//push_back()
TEST(STLLIST, pushback){
    std::list<int> l{1,2,3};
    std::list<int> res{1,2,3,4};
    l.push_back(4);
    EXPECT_THAT(l, ::testing::ContainerEq(res));
}
//pop_front()
TEST(STLLIST, popfront){
    std::list<int> l{1,2,3};
    std::list<int> res{2,3};
    l.pop_front();
    EXPECT_THAT(l, ::testing::ContainerEq(res));
}
//pop_back()
TEST(STLLIST, popback){
    std::list<int> l{1,2,3};
    std::list<int> res{1,2};
    l.pop_back();
    EXPECT_THAT(l, ::testing::ContainerEq(res));
}
//insert()
TEST(STLLIST, insert1){
    std::list<std::pair<int,char>>l{{1,'a'}, {2,'b'}, {4,'d'}};
    std::list<std::pair<int,char>>res{{1,'a'}, {2,'b'}, {3,'c'}, {4, 'd'}};
    std::list<std::pair<int,char>>::iterator it = l.begin();
    l.insert(std::next(it,2), {3,'c'});
    EXPECT_THAT(l, ::testing::ContainerEq(res));
}
//insert()
TEST(STLLIST, insert2){
    std::list<int> l{1, 2, 3, 4, 5};
    std::list<int> l2{10, 20, 30, 40, 50};
    std::list<int> res{1, 2, 20, 30, 40, 3, 4, 5};
    std::list<int>::iterator it = l.begin();
    std::list<int>::iterator it1 = l2.begin();
    std::list<int>::iterator it2 = l2.begin();
    std::advance(it, 2);// point to the location of 3 in list l
    std::advance(it1, 1);// point to the location of 20 in list 2
    std::advance(it2, 4);// point to the location of 50 in list 2
    //insert elements from locations it1 upto it2(excluding it2) from list2 (i.e., 20, 30, 40) in list 1 at it
    l.insert(it, it1, it2); 
    //Notice that original list itself is changed
    EXPECT_THAT(l, ::testing::ContainerEq(res));
}
//emplace()
TEST(STLLIST, emplace){
    std::list<std::pair<int,char>>l{{1,'a'}, {2,'b'}, {4,'d'}};
    std::list<std::pair<int,char>>res{{1,'a'}, {2,'b'}, {3,'c'}, {4, 'd'}};
    std::list<std::pair<int,char>>::iterator it = l.begin();
    l.emplace(std::next(it,2), 3, 'c'); //Note: here l.emplace(std::next(it,2), (2, 2)); does NOT work
    EXPECT_THAT(l, ::testing::ContainerEq(res));
}
//emplace_front(), emplace_back()
TEST(STLLIST, emplace2){
    std::list<std::pair<int,int>> l;
    std::list<std::pair<int,int>>res{{-1,-1}, {0,0}, {0,1}, {1,0}, {2,0}, {3,3}};
    l.push_back({0,1});// curly braces are necessary 
    l.push_back({1,0});
    l.emplace_back(2,0);//curly braces shouldn't be given as the object(pair) will be constructed by emplace
    l.emplace_back(3,3);
    l.emplace_front(0,0);
    l.emplace_front(-1,-1);
    EXPECT_THAT(l, ::testing::ContainerEq(res));
}
//remove()-- based on value
TEST(STLLIST, remove){
    std::list<int> l{10, 2, 30, 5, 10, 45, 45, 4};
    std::list<int> res{2,30,5,45,45,4};
    l.remove(10);
    EXPECT_THAT(l, ::testing::ContainerEq(res));
}
//remove_if()
bool multiplesof5(int x) { return (x%5 == 0);}
TEST(STLLIST, remove_if){
    std::list<int> l{10, 2, 30, 5, 10, 45, 45, 4};
    std::list<int> res{2,4};
    l.remove_if(multiplesof5);
    EXPECT_THAT(l, ::testing::ContainerEq(res));
}
//erase() - remove based on location
TEST(STLLIST, erase){
    std::list<int> l{10, 2, 30, 5, 10, 45, 45, 4};
    std::list<int> res{10, 2, 30, 5, 45, 45, 4};
    l.erase(std::next(l.begin(),4));
    EXPECT_THAT(l, ::testing::ContainerEq(res));
}

//sort()
TEST(STLLIST, sort){
    std::list<int> l{10, 2, 30, 5, 10, 45, 45, 4};
    std::list<int> res{2,4,5,10,10,30,45,45};
    l.sort(); //Notice that original list itself is changed
    EXPECT_THAT(l, ::testing::ContainerEq(res));
}
//reverse()
TEST(STLLIST, reverse){
    std::list<int> l{10,2,30, 5, 10, 45, 45, 4};
    std::list<int> res{45, 45, 30, 10, 10, 5, 4, 2};
    l.sort(); //Notice that original list itself is changed
    l.reverse(); //Notice that original list itself is changed
    EXPECT_THAT(l, ::testing::ContainerEq(res));
}

//unique()
TEST(STLLIST, unique){
    std::list<int> l{10,2,30, 5, 10, 45, 45, 4};
    std::list<int> res{2,4,5,10,30,45};
    l.sort();
    l.unique();//unique() works properly only on sorted list
    EXPECT_THAT(l, ::testing::ContainerEq(res));
}
//unique()
bool compare(double a, double b) {return((int)a == (int)b);}
TEST(STLLIST, unique2){
    std::list<double> sorted_list = { 2.55, 3.15, 4.16, 4.16, 4.77, 12.65, 12.65, 13.59 };
    std::list<double> res{2.55, 3.15, 4.16, 12.65,13.59}; // result does not contain 4.77 because only integer portion is compared
    sorted_list.unique(compare);//unique() works properly only on sorted list
    EXPECT_THAT(sorted_list, ::testing::ContainerEq(res));
}
//assign()
TEST(STLLIST, assign1){
    std::list<int> l;
    l.assign(4, 10);
    EXPECT_THAT(l, ::testing::ContainerEq(std::list<int>{10,10,10,10}));
}
//assign() - 2
TEST(STLLIST, assign2){
    std::list<std::pair<int,int>> l;
    std::list<std::pair<int,int>>res{{0,0}, {0,1}, {1,0}, {2,0}, {3,3}};
    l.assign(res.begin(), res.end());
    EXPECT_THAT(l, ::testing::ContainerEq(res));
}
//assign() - 3, nested list
TEST(STLLIST, nestedlist){
    std::list<std::list<int>> l;
    l.assign(4, {1,2,3});
    EXPECT_THAT(l, ::testing::ContainerEq(std::list<std::list<int>>{{1,2,3}, {1,2,3}, {1,2,3}, {1,2,3}}));
}
//swap()
TEST(STLLIST, swap){
    std::list<int> l1{1,2,3};
    std::list<int> l2(5, 10);
    l1.swap(l2);
    EXPECT_THAT(l1, ::testing::ContainerEq(std::list<int>{10, 10, 10, 10, 10}));
    EXPECT_THAT(l2, ::testing::ContainerEq(std::list<int>{1,2,3}));
}