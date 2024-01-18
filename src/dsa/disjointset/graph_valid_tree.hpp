/*
Graph Valid Tree
================
You have a graph of n nodes labeled from 0 to n - 1. 
You are given an integer n and a list of edges where edges[i] = [ai, bi] indicates that there is an undirected edge between nodes ai and bi in the graph.

Return true if the edges of the given graph make up a valid tree, and false otherwise.
*/
#pragma once

#include "optimized_union.hpp"

class SolutionGraphValidTree {
public:
    bool validTree(int n, std::vector<std::vector<int>>& edges) {
        OptimizedUnion ou = OptimizedUnion(n);
        if (edges.size() != n-1) return false;
        for (int i=0; i<edges.size(); i++){
            if(ou.isConnected(edges[i][0], edges[i][1])) {
                return false;
            }
            ou.unionSet(edges[i][0], edges[i][1]);
        }
        return true;  
    }
};