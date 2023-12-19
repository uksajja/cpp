/*
Number of Connected Components in an Undirected Graph
=====================================================

You have a graph of n nodes. You are given an integer n and an array edges where edges[i] = [ai, bi] indicates that there is an edge between ai and bi in the graph.

Return the number of connected components in the graph.

Constraints:

1 <= n <= 2000
1 <= edges.length <= 5000
edges[i].length == 2
0 <= ai <= bi < n
ai != bi
There are no repeated edges.
*/

#include<optimizedUnion.hpp>

class SolutionConnectedComponents {
public:
    int countComponents(int n, std::vector<std::vector<int>>& edges) {
        OptimizedUnion ou = OptimizedUnion(n);
        for(int i=0; i<edges.size(); i++){
            ou.unionSet(edges[i][0], edges[i][1]);
        }
        int c = 0;
        for(int i=0; i<n; i++){
            if(i == ou.find(i))
                c++;
        }
        return c;
    }
};