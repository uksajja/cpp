// Quick union with rank
#pragma once
class UnionByRank {
public:
    UnionByRank(int sz): root(sz), rank(sz) {
        for(int i=0; i<sz; i++){
            root[i] = i;        
            rank[i] = 1;
        }
    }
    int find(int x){
        while(x !=root[x]){
            x = root[x];
        }
        return x;
    }
    void unionSet(int x, int y){
        int rootX = find(x);
        int rootY = find(y);
        if(rootX != rootY){
            if(rank[rootX] > rank[rootY]) {
                root[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]){
                root[rootX] = rootY;
            } else {
                root[rootY] = rootX;
                rank[rootX] += 1;
            }
        }
    }
    bool isConnected(int x, int y) {
        return (find(x) == find(y));
    }

private:
    std::vector<int> root;
    std::vector<int> rank;

};