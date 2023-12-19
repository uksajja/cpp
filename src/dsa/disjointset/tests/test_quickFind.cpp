//dsa tests
//disjoint set tests
#include<gtest/gtest.h>
#include<quickFind.hpp>

TEST(DISJOINTSET, quickFind){
    std::cout << std::boolalpha;
    QuickFind qf = QuickFind(10);
    qf.unionSet(1,2);
    qf.unionSet(2,5);
    qf.unionSet(5,6);
    qf.unionSet(6,7);
    qf.unionSet(3,8);
    qf.unionSet(8,9);

    std::cout << "Root of 1 is : " << qf.find(1) << std::endl;
    std::cout << "Root of 5 is : " << qf.find(5) << std::endl;
    std::cout << "Root of 9 is : " << qf.find(9) << std::endl;
    EXPECT_EQ(qf.find(1), 1);
    EXPECT_EQ(qf.find(5), 1);
    EXPECT_EQ(qf.find(9), 3);

    std::cout << "1-5 connected : " << qf.isConnected(1, 5) << std::endl;
    std::cout << "2-7 connected : " << qf.isConnected(2, 7) << std::endl;
    std::cout << "1-7 connected : " << qf.isConnected(1, 7) << std::endl;
    std::cout << "4-9 connected : " << qf.isConnected(4, 9) << std::endl;
    ASSERT_TRUE(qf.isConnected(1, 5));
    ASSERT_TRUE(qf.isConnected(2, 7));
    ASSERT_TRUE(qf.isConnected(1, 7));
    ASSERT_FALSE(qf.isConnected(4, 9)); // 4-9  Not connected
    qf.unionSet(4,9);
    std::cout << "4-9 connected : " << qf.isConnected(4, 9) << std::endl;
    ASSERT_TRUE(qf.isConnected(4, 9));

    ASSERT_FALSE(qf.isConnected(1, 4));

    qf.unionSet(2, 3);
    ASSERT_TRUE(qf.isConnected(1, 3));
    ASSERT_TRUE(qf.isConnected(1, 4));
    std::cout << "Root of 3 is : " << qf.find(3) << std::endl;
    std::cout << "Root of 4 is : " << qf.find(4) << std::endl;
    std::cout << "Root of 9 is : " << qf.find(9) << std::endl;
    EXPECT_EQ(qf.find(3), 1);

}