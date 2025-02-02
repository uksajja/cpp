#include<iostream>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <queue>
#include <vector>
#include <deque>


void show(std::priority_queue<int> pq){
    if(pq.empty()) {
        std::cout<< "Priority Queue is Empty" << std::endl;
    } else {
        std::cout<< "Priority Queue Items are: " << std::endl;
        while (!pq.empty()) {   
            std::cout << pq.top() << " ";
            pq.pop();
        }
        std::cout << std::endl;
    }   
}

// Initialize priority queue an initialize list
//However, initializer cannot be used directly as pq({1,3,2} as 
//priority_queue is not a container but a container adaptor.
TEST(PRIORITYQ, initialize1)
{
    const auto data = {4, 3, 1, 2};
    std::priority_queue<int> pq;
    for(auto& i: data){
        pq.push(i);
    }
    while (!pq.empty())
    {
        std::cout << pq.top() << " ";
        pq.pop();
    }
}
//Initialize priority queue with a default container - vector
TEST(PRIORITYQ, initialize2)
{
    std::vector<int> v={4, 3, 1, 2};
    std::priority_queue<int, std::vector<int>> pq(v.begin(), v.end());
    while (!pq.empty())
    {
        std::cout << pq.top() << " ";
        pq.pop();
    }
}
// Initialize priority queue with a default container - vector
TEST(PRIORITYQ, initialize3)
{
    std::vector<int> v = {40, 30, 1, 25};
    // default container is vector, hence no need to specify
    std::priority_queue<int> pq(v.begin(), v.end());
    while (!pq.empty())
    {
        std::cout << pq.top() << " ";
        pq.pop();
    }
}
// Initialize priority queue with a non default container - deque
TEST(PRIORITYQ, initialize4)
{
    std::deque<int> dq({3, 5, 1, 2});
    std::priority_queue<int, std::deque<int>> pq(dq.begin(), dq.end());
    while (!pq.empty())
    {
        std::cout << pq.top() << " ";
        pq.pop();
    }
}

TEST(PRIORITYQ, pushpop){
    std::priority_queue<int> pq;
    pq.push(50);
    pq.push(10);
    pq.push(40);
    pq.push(30);
    EXPECT_EQ(4, pq.size());
    EXPECT_EQ(50, pq.top());
    show(pq);
    
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq2;
    pq2.push(50);
    pq2.push(10);
    pq2.push(40);
    pq2.push(30);
    while (!pq2.empty()) {   
        std::cout << pq2.top() << " ";
        pq2.pop();
    }
}
