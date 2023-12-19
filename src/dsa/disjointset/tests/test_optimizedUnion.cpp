//dsa tests
//disjoint set tests
#include<iostream>
#include<gtest/gtest.h>
#include<optimizedUnion.hpp>

TEST(DISJOINTSET, optimizedUnion){
    std::cout << std::boolalpha;
    OptimizedUnion ou = OptimizedUnion(10);
    ou.unionSet(1,2);
    ou.unionSet(2,5);
    ou.unionSet(5,6);
    ou.unionSet(6,7);
    ou.unionSet(3,8);
    ou.unionSet(8,9);

    std::cout << "Root of 1 is : " << ou.find(1) << std::endl;
    std::cout << "Root of 5 is : " << ou.find(5) << std::endl;
    std::cout << "Root of 9 is : " << ou.find(9) << std::endl;
    EXPECT_EQ(ou.find(1), 1);
    EXPECT_EQ(ou.find(5), 1);
    EXPECT_EQ(ou.find(9), 3);

    std::cout << "1-5 connected : " << ou.isConnected(1, 5) << std::endl;
    std::cout << "2-7 connected : " << ou.isConnected(2, 7) << std::endl;
    std::cout << "1-7 connected : " << ou.isConnected(1, 7) << std::endl;
    std::cout << "4-9 connected : " << ou.isConnected(4, 9) << std::endl;
    ASSERT_TRUE(ou.isConnected(1, 5));
    ASSERT_TRUE(ou.isConnected(2, 7));
    ASSERT_TRUE(ou.isConnected(1, 7));
    ASSERT_FALSE(ou.isConnected(4, 9)); // 4-9  Not connected
    ou.unionSet(4,9);
    std::cout << "4-9 connected : " << ou.isConnected(4, 9) << std::endl;
    ASSERT_TRUE(ou.isConnected(4, 9));

    ASSERT_FALSE(ou.isConnected(1, 4));

    ou.unionSet(2, 3);
    ASSERT_TRUE(ou.isConnected(1, 3));
    ASSERT_TRUE(ou.isConnected(1, 4));
    std::cout << "Root of 3 is : " << ou.find(3) << std::endl;
    std::cout << "Root of 4 is : " << ou.find(4) << std::endl;
    std::cout << "Root of 9 is : " << ou.find(9) << std::endl;
    EXPECT_EQ(ou.find(3), 1);

}