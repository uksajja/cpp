
#include<gmock/gmock.h>
#include<gtest/gtest.h>
#include<list>
#include<algorithm>


TEST(STLLIST, size){
    std::list<int> l{1,2,3};
    EXPECT_EQ(l.size(),3);
}

TEST(STLLIST, max_size){
    std::list<int> l{1,2,3};
    std::list<double> ld{2.55, 3.15, 4.16, 12.65,13.59};
    EXPECT_EQ(l.max_size(), 768614336404564650);
    EXPECT_EQ(ld.max_size(), 768614336404564650);
}

TEST(STLLIST, pushback){
    std::list<int> l{1,2,3};
    std::list<int> res{1,2,3,4};
    l.push_back(4);
    EXPECT_THAT(l, ::testing::ContainerEq(res));
}

TEST(STLLIST, insert){
    std::list<int> l{1, 2, 3, 4, 5};
    std::list<int> l2{10, 20, 30, 40, 50};
    std::list<int> res{1, 2, 20, 30, 40, 3, 4, 5};
    std::list<int>::iterator it = l.begin();
    std::list<int>::iterator it1 = l2.begin();
    std::list<int>::iterator it2 = l2.begin();
    std::advance(it, 2);
    std::advance(it1, 1);
    std::advance(it2, 4);
    l.insert(it, it1, it2); //Notice that original list itself is changed
    EXPECT_THAT(l, ::testing::ContainerEq(res));
}

TEST(STLLIST, sort){
    std::list<int> l{10,2,30, 5, 10, 45, 45, 4};
    std::list<int> res{2,4,5,10,10,30,45,45};
    l.sort(); //Notice that original list itself is changed
    EXPECT_THAT(l, ::testing::ContainerEq(res));
}

TEST(STLLIST, remove){
    std::list<int> l{10,2,30, 5, 10, 45, 45, 4};
    std::list<int> res{2,30,5,45,45,4};
    l.remove(10);
    EXPECT_THAT(l, ::testing::ContainerEq(res));
}

bool multiplesof5(int x) { return (x%5 == 0);}
TEST(STLLIST, remove_if){
    std::list<int> l{10,2,30, 5, 10, 45, 45, 4};
    std::list<int> res{2,4};
    l.remove_if(multiplesof5);
    EXPECT_THAT(l, ::testing::ContainerEq(res));
}

TEST(STLLIST, unique){
    std::list<int> l{10,2,30, 5, 10, 45, 45, 4};
    std::list<int> res{2,4,5,10,30,45};
    l.sort();
    l.unique();//unique() works properly only on sorted list
    EXPECT_THAT(l, ::testing::ContainerEq(res));
}

bool compare(double a, double b) {return((int)a == (int)b);}
TEST(STLLIST, unique2){
    std::list<double> sorted_list = { 2.55, 3.15, 4.16, 4.16, 4.77, 12.65, 12.65, 13.59 };
    std::list<double> res{2.55, 3.15, 4.16, 12.65,13.59};
    sorted_list.unique(compare);//unique() works properly only on sorted list
    EXPECT_THAT(sorted_list, ::testing::ContainerEq(res));
}