
#include <gmock\gmock.h>
#include "graph_arrayofvec.hpp"

TEST(GRAPH, arrayofvec){
    std::cout << "Graph - Array of Vectors" << std::endl;
    GraphArrayOfVec gav(4);
    gav.addEdge(0,1,true,5);
    gav.addEdge(0,2);
    gav.addEdge(1,2);
    gav.addEdge(2,3);
    gav.addEdge(1,2); //repeated edge
    gav.show(); 
    EXPECT_EQ(gav.vertexCount(), 4);
    EXPECT_EQ(gav.edgeCount(), 8); 
}