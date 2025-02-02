//Test STL-Queue

//FIFO - First In - First OUT

#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <queue>
#include <list>
#include <deque>

TEST(QUEUE, pushpop){
    std::queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(50);
    
    EXPECT_EQ(10, q.front());
    EXPECT_EQ(50, q.back());
    q.pop();
    
    EXPECT_EQ(20, q.front());
    EXPECT_EQ(50, q.back());
    q.push(40);
    EXPECT_EQ(40, q.back());
    EXPECT_EQ(q.size(), 4);
    q.pop();
    q.pop();
    q.pop();   
    q.pop();
    EXPECT_TRUE(q.empty());
}

TEST(QUEUE, queuedq) {
    std::deque<int> dq{1,2,3,4,5,6};
    std::queue<int> q(dq);
    EXPECT_EQ(q.size(), 6);
}
TEST(QUEUE, queuelist) {
    std::list<int> l{1,2,3,4,5};
    std::queue<int, std::list<int>> q(l);
    EXPECT_EQ(q.size(), 5);
}



