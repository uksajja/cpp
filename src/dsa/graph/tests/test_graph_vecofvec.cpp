#include <gmock\gmock.h>
#include "graph_vecofvec.hpp"

TEST(GRAPH, vecofvec){
    std::cout << "Graph - Vector of Vectors" << std::endl;
    GraphVecOfVec gvv(4);
    gvv.addEdge(0,1,true,5);
    gvv.addEdge(0,2);
    gvv.addEdge(1,2);
    gvv.addEdge(2,3);
    gvv.show();
    EXPECT_EQ(gvv.vertexCount(), 4);
    EXPECT_EQ(gvv.edgeCount(), 8); 
}
