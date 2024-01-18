#include <gmock\gmock.h>
#include "graph_adjmatrix.hpp"

TEST(GRAPH, adjmatrix) {
    std::cout << "Graph - Adjacentcy Matrix" << std::endl;
    GraphM g(4);
    g.addEdge(0,1,true,5);
    g.addEdge(0,2);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.show();
    EXPECT_EQ(g.vertexCount(), 4);
    EXPECT_EQ(g.edgeCount(), 8);
}