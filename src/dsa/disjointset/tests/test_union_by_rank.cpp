//dsa tests
//disjoint set tests
#include<iostream>
#include<gtest/gtest.h>

#include"union_by_rank.hpp"

TEST(DISJOINTSET, unionByRank){
    std::cout << std::boolalpha;
    UnionByRank ubr = UnionByRank(10);
    ubr.unionSet(1,2);
    ubr.unionSet(2,5);
    ubr.unionSet(5,6);
    ubr.unionSet(6,7);
    ubr.unionSet(3,8);
    ubr.unionSet(8,9);

    std::cout << "Root of 1 is : " << ubr.find(1) << std::endl;
    std::cout << "Root of 5 is : " << ubr.find(5) << std::endl;
    std::cout << "Root of 9 is : " << ubr.find(9) << std::endl;
    EXPECT_EQ(ubr.find(1), 1);
    EXPECT_EQ(ubr.find(5), 1);
    EXPECT_EQ(ubr.find(9), 3);

    std::cout << "1-5 connected : " << ubr.isConnected(1, 5) << std::endl;
    std::cout << "2-7 connected : " << ubr.isConnected(2, 7) << std::endl;
    std::cout << "1-7 connected : " << ubr.isConnected(1, 7) << std::endl;
    std::cout << "4-9 connected : " << ubr.isConnected(4, 9) << std::endl;
    ASSERT_TRUE(ubr.isConnected(1, 5));
    ASSERT_TRUE(ubr.isConnected(2, 7));
    ASSERT_TRUE(ubr.isConnected(1, 7));
    ASSERT_FALSE(ubr.isConnected(4, 9)); // 4-9  Not connected
    ubr.unionSet(4,9);
    std::cout << "4-9 connected : " << ubr.isConnected(4, 9) << std::endl;
    ASSERT_TRUE(ubr.isConnected(4, 9));

    ASSERT_FALSE(ubr.isConnected(1, 4));

    ubr.unionSet(2, 3);
    ASSERT_TRUE(ubr.isConnected(1, 3));
    ASSERT_TRUE(ubr.isConnected(1, 4));
    std::cout << "Root of 3 is : " << ubr.find(3) << std::endl;
    std::cout << "Root of 4 is : " << ubr.find(4) << std::endl;
    std::cout << "Root of 9 is : " << ubr.find(9) << std::endl;
    EXPECT_EQ(ubr.find(3), 1);

}