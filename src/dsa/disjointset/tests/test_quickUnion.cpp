//dsa tests
//disjoint set tests
#include<iostream>
#include<gtest/gtest.h>
#include<quickUnion.hpp>

TEST(DISJOINTSET, quickUnion){
    std::cout << std::boolalpha;
    QuickUnion qu = QuickUnion(10);
    qu.unionSet(1,2);
    qu.unionSet(2,5);
    qu.unionSet(5,6);
    qu.unionSet(6,7);
    qu.unionSet(3,8);
    qu.unionSet(8,9);

    std::cout << "Root of 1 is : " << qu.find(1) << std::endl;
    std::cout << "Root of 5 is : " << qu.find(5) << std::endl;
    std::cout << "Root of 9 is : " << qu.find(9) << std::endl;
    EXPECT_EQ(qu.find(1), 1);
    EXPECT_EQ(qu.find(5), 1);
    EXPECT_EQ(qu.find(9), 3);

    std::cout << "1-5 connected : " << qu.isConnected(1, 5) << std::endl;
    std::cout << "2-7 connected : " << qu.isConnected(2, 7) << std::endl;
    std::cout << "1-7 connected : " << qu.isConnected(1, 7) << std::endl;
    std::cout << "4-9 connected : " << qu.isConnected(4, 9) << std::endl;
    ASSERT_TRUE(qu.isConnected(1, 5));
    ASSERT_TRUE(qu.isConnected(2, 7));
    ASSERT_TRUE(qu.isConnected(1, 7));
    ASSERT_FALSE(qu.isConnected(4, 9)); // 4-9  Not connected
    qu.unionSet(4,9);
    std::cout << "4-9 connected : " << qu.isConnected(4, 9) << std::endl;
    ASSERT_TRUE(qu.isConnected(4, 9));

    ASSERT_FALSE(qu.isConnected(1, 4));

    qu.unionSet(2, 3);
    ASSERT_TRUE(qu.isConnected(1, 3));
    ASSERT_TRUE(qu.isConnected(1, 4));
    std::cout << "Root of 3 is : " << qu.find(3) << std::endl;
    std::cout << "Root of 4 is : " << qu.find(4) << std::endl;
    std::cout << "Root of 9 is : " << qu.find(9) << std::endl;
    EXPECT_EQ(qu.find(3), 1);

}