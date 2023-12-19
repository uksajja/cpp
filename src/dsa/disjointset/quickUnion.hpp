#pragma once
class QuickUnion{
public:
    QuickUnion(int sz): root(sz) {
        for (int i=0; i<sz; i++) {
            root[i] = i;
        }
    }

    int find(int x) {
        while(x!= root[x]) {
            x = root[x];
        }
        return x;
    }

    void unionSet(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if(rootX != rootY)   {
            root[rootY] = rootX;
        }
    }

    bool isConnected(int x, int y) {
        return (find(x) == find(y));
    }
private:
    std::vector<int> root;
};