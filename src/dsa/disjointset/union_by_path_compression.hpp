// Path Compression of a Disjoint Set
#pragma once

#include <vector>

class UnionByPathCompression{
public:
    UnionByPathCompression(int sz) : root(sz) {
        for (int i=0; i< sz; i++) {
            root[i] = i;
        }
    }
    int find(int x) {
        if(x != root[x])
            x = find(root[x]);
        return x;
    }

    void unionSet(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if(rootX != rootY){
            root[rootY] = rootX;
        }
    }
    bool isConnected(int x, int y) {
        return (find(x) == find(y));
    }

private:
    std::vector<int> root;
};