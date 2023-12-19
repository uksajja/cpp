//TEST Count Connected Components


#include<gtest/gtest.h>
#include<countConnectedComponents.hpp>

TEST(DISJOINTSET, connectedComponents1){
    /*
    Input: n = 5, edges = [[0,1],[1,2],[3,4]]
    Output: 2
    */
    SolutionConnectedComponents sol;
    std::vector<std::vector<int>> edges = {{0,1}, {1,2}, {3,4} };
    ASSERT_EQ(sol.countComponents(5, edges), 2);
}

TEST(DISJOINTSET, connectedComponents2){
    /*
    Input: n = 5, edges = [[0,1],[1,2],[2,3],[3,4]]
    Output: 1
    */
    SolutionConnectedComponents sol;
    std::vector<std::vector<int>> edges = {{0,1}, {1,2}, {2,3}, {3,4} };
    ASSERT_EQ(sol.countComponents(5, edges), 1);
}