/*
The Earliest Moment When Everyone Become Friends
================================================
There are n people in a social group labeled from 0 to n - 1. You are given an array logs where logs[i] = [timestampi, xi, yi] indicates that xi and yi will be friends at the time timestampi.

Friendship is symmetric. That means if a is friends with b, then b is friends with a. Also, person a is acquainted with a person b if a is friends with b, or a is a friend of someone acquainted with b.

Return the earliest time for which every person became acquainted with every other person. If there is no such earliest time, return -1.

*/
#pragma once

#include <algorithm>

#include "optimized_union.hpp"

class SolutionEarliestMoment {
public:
    int earliestAcq(std::vector<std::vector<int>>& logs, int n) {
        OptimizedUnion ou = OptimizedUnion(n);
        int n_edges = 0;
        std::sort(logs.begin(), logs.end(), [](const std::vector<int>& a, const std::vector<int>& b){ return a[0]<b[0];});
        for(int i=0; i<logs.size(); i++) {
            if (!ou.isConnected(logs[i][1], logs[i][2])) {
                ou.unionSet(logs[i][1], logs[i][2]);
                n_edges += 1;
                if(n_edges == n-1) return logs[i][0];
            }
        }
        return -1;
    }
};