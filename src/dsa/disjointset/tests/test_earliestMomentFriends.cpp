//TEST The Earliest Moment When Everyone Become Friends
/*
Example 1:
Input: logs = [[20190101,0,1],[20190104,3,4],[20190107,2,3],[20190211,1,5],[20190224,2,4],[20190301,0,3],[20190312,1,2],[20190322,4,5]], n = 6
Output: 20190301
Explanation: 
The first event occurs at timestamp = 20190101, and after 0 and 1 become friends, we have the following friendship groups [0,1], [2], [3], [4], [5].
The second event occurs at timestamp = 20190104, and after 3 and 4 become friends, we have the following friendship groups [0,1], [2], [3,4], [5].
The third event occurs at timestamp = 20190107, and after 2 and 3 become friends, we have the following friendship groups [0,1], [2,3,4], [5].
The fourth event occurs at timestamp = 20190211, and after 1 and 5 become friends, we have the following friendship groups [0,1,5], [2,3,4].
The fifth event occurs at timestamp = 20190224, and as 2 and 4 are already friends, nothing happens.
The sixth event occurs at timestamp = 20190301, and after 0 and 3 become friends, we all become friends.

Example 2:
Input: logs = [[0,2,0],[1,0,1],[3,0,3],[4,1,2],[7,3,1]], n = 4
Output: 3
Explanation: At timestamp = 3, all the persons (i.e., 0, 1, 2, and 3) become friends.
*/
#include<gtest/gtest.h>
#include<earliestMomentFriends.hpp>

TEST(DISJOINTSET, EarliestMoment1){
    SolutionEarliestMoment sol;
    std::vector<std::vector<int>> logs = {{20190101,0,1}, {20190104,3,4}, {20190107,2,3}, {20190211,1,5}, {20190224,2,4}, {20190301,0,3}, {20190312,1,2}, {20190322,4,5}};
    ASSERT_EQ(sol.earliestAcq(logs, 6), 20190301);
}

TEST(DISJOINTSET, EarliestMoment2){
    SolutionEarliestMoment sol;
    std::vector<std::vector<int>> logs = {{0,2,0}, {1,0,1}, {3,0,3}, {4,1,2}, {7,3,1}};
    ASSERT_EQ(sol.earliestAcq(logs, 4), 3);
}

TEST(DISJOINTSET, EarliestMoment3){
    SolutionEarliestMoment sol;
    std::vector<std::vector<int>> logs = {{9,3,0}, {0,2,1}, {8,0,1}, {1,3,2}, {2,2,0}, {3,3,1}};
    ASSERT_EQ(sol.earliestAcq(logs, 4), 2);
}

TEST(DISJOINTSET, EarliestMoment4){
    SolutionEarliestMoment sol;
    std::vector<std::vector<int>> logs = {{0,2,0}, {7,4,3}, {2,2,1}, {1,0,1}, {5,4,1}, {6,3,2}, {8,3,1}, {3,0,4}};
    ASSERT_EQ(sol.earliestAcq(logs, 5), 6);
}
