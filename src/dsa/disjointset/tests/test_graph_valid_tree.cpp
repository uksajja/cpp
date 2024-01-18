// Test Graph Valid Tree

#include<gtest/gtest.h>

#include"graph_valid_tree.hpp"

TEST(DISJOINTSET, GraphValidTree1){
    SolutionGraphValidTree Sol;
    std::vector<std::vector<int>> edges = {{0,1}, {0,2}, {0,3}, {1,4}};
    int num_nodes = 5;
    std::cout << "Graph is a Valid Tree" << std::endl;
    ASSERT_TRUE(Sol.validTree(num_nodes, edges));
}

TEST(DISJOINTSET, GraphValidTree2){
    SolutionGraphValidTree Sol;
    std::vector<std::vector<int>> edges = {{0,1}, {1,2}, {2,3}, {1,3}, {1,4}};
    int num_nodes = 5;
    std::cout << "Graph is NOT a Valid Tree" << std::endl;
    ASSERT_FALSE(Sol.validTree(num_nodes, edges));
}