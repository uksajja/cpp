//Test Number of Provinces
#include<gtest/gtest.h>
#include<num_provinces.hpp>

TEST(DISJOINTSET, NumProvinces1){
    SolutionNumberOfProvinces Sol;
    std::vector<std::vector<int>> isConnected = {{1,1,0},{1,1,0},{0,0,1}};
    int num = Sol.findCircleNum(isConnected);
    std::cout << "Number of Provinces = " << num << std::endl;
    EXPECT_EQ(num, 2); 
}

TEST(DISJOINTSET, NumProvinces2){
    SolutionNumberOfProvinces Sol;
    std::vector<std::vector<int>> isConnected = {{1,0,0},{0,1,0},{0,0,1}};
    int num = Sol.findCircleNum(isConnected);
    std::cout << "Number of Provinces = " << num << std::endl;
    EXPECT_EQ(num, 3);
}