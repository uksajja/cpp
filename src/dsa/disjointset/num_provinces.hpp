/*
There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

A province is a group of directly or indirectly connected cities and no other cities outside of the group.

You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

Return the total number of provinces.

*/

#include<optimizedUnion.hpp>


class SolutionNumberOfProvinces {
public:
    int findCircleNum(std::vector<std::vector<int>>& isConnected) {
        int n = isConnected.size();
        std::set<int> provinces;
        OptimizedUnion ou = OptimizedUnion(n);
        for (int i=0; i<n; i++) {
            for(int j=0; j<=i; j++){
                if (isConnected[i][j] == 1) {
                    ou.unionSet(i,j);
                }
            }
        }
        for(int i=0; i<n; i++) {
            if(i == ou.find(i)){
                provinces.insert(i);
            }
        }
        return provinces.size();
    }
};