//dsa tests
//disjoint set tests
#include<iostream>
#include<gtest/gtest.h>
#include<unionByPathCompression.hpp>

TEST(DISJOINTSET, unionByPathCompression){
    std::cout << std::boolalpha;
    UnionByPathCompression ubpc = UnionByPathCompression(10);
    ubpc.unionSet(1,2);
    ubpc.unionSet(2,5);
    ubpc.unionSet(5,6);
    ubpc.unionSet(6,7);
    ubpc.unionSet(3,8);
    ubpc.unionSet(8,9);

    std::cout << "Root of 1 is : " << ubpc.find(1) << std::endl;
    std::cout << "Root of 5 is : " << ubpc.find(5) << std::endl;
    std::cout << "Root of 9 is : " << ubpc.find(9) << std::endl;
    EXPECT_EQ(ubpc.find(1), 1);
    EXPECT_EQ(ubpc.find(5), 1);
    EXPECT_EQ(ubpc.find(9), 3);

    std::cout << "1-5 connected : " << ubpc.isConnected(1, 5) << std::endl;
    std::cout << "2-7 connected : " << ubpc.isConnected(2, 7) << std::endl;
    std::cout << "1-7 connected : " << ubpc.isConnected(1, 7) << std::endl;
    std::cout << "4-9 connected : " << ubpc.isConnected(4, 9) << std::endl;
    ASSERT_TRUE(ubpc.isConnected(1, 5));
    ASSERT_TRUE(ubpc.isConnected(2, 7));
    ASSERT_TRUE(ubpc.isConnected(1, 7));
    ASSERT_FALSE(ubpc.isConnected(4, 9)); // 4-9  Not connected
    ubpc.unionSet(4,9);
    std::cout << "4-9 connected : " << ubpc.isConnected(4, 9) << std::endl;
    ASSERT_TRUE(ubpc.isConnected(4, 9));

    ASSERT_FALSE(ubpc.isConnected(1, 4));

    ubpc.unionSet(2, 3);
    ASSERT_TRUE(ubpc.isConnected(1, 3));
    ASSERT_TRUE(ubpc.isConnected(1, 4));
    std::cout << "Root of 3 is : " << ubpc.find(3) << std::endl;
    std::cout << "Root of 4 is : " << ubpc.find(4) << std::endl;
    std::cout << "Root of 9 is : " << ubpc.find(9) << std::endl;
    EXPECT_EQ(ubpc.find(3), 1);

}