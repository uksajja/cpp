// Disjoint Set - Quick Find Algorithm
#pragma once

#include <vector>

class QuickFind {
public:
    QuickFind(int sz): root(sz){
        for(int i=0; i< sz; i++) {
            root[i] = i;
        }
    }

    int find(int x) {
        return root[x];
    }

    void unionSet(int x, int y){
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            for( int i=0; i<root.size(); i++){
                if (root[i] == rootY) {
                    root[i] = rootX;
                }
            }
        }
    }

    bool isConnected(int x, int y){
        return (find(x) == find(y));
    }

private:
    std::vector<int> root;

};