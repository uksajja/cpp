
#include <gmock/gmock.h>
#include "graph_smartpointerlist.hpp"

TEST(GRAPH, smartpointerlist){
    std::cout << "Graph - Smart Pointer List" << std::endl;
    GraphSmartPointerList gspl(4);
    gspl.addEdge(0,1,true,5);
    gspl.addEdge(0,2);
    gspl.addEdge(1,2);
    gspl.addEdge(2,3);
    gspl.addEdge(0,2); //repeated edge
    gspl.show(); 
    EXPECT_EQ(gspl.vertexCount(), 4);
    EXPECT_EQ(gspl.edgeCount(), 8); 
}