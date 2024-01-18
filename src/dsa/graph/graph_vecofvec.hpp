//Graph - As a vector of vectors


#pragma once

#include<iostream>
#include<vector>

class GraphVecOfVec{
    int mVertices;
    std::vector<std::vector<std::pair<int, int>>> adjVec;
    int mEdges;
public:
    GraphVecOfVec(int n): mVertices(n){
        std::cout << "Creating graph with " << mVertices << "Vertices" << std::endl;
        adjVec.resize(mVertices);
        mEdges = 0;
    }
    int  weight(int x, int y){
        for(auto& ipair: adjVec[x]){
            if (ipair.first == y) {return ipair.second;}
        }
        return 0;
    }
    void addEdge(int x, int y, bool undirected=true, int wt=1){
        if (weight(x, y)!=0){
            std::cout << "Edge: "<< x << " ====> " << y << " already exists." << std::endl;
            return;
        }
        /*(adjVec.at(x)).emplace_back(y,wt);
        if(undirected){
            (adjVec.at(y)).emplace_back(x,wt);
        }*/
        
        adjVec[x].emplace_back(y,wt);
        mEdges++;
        if(undirected){
            if (weight(y, x)!=0){
                std::cout << "Edge: "<< y << " ====> " << x << " already exists." << std::endl;
                return;
            }
            adjVec[y].emplace_back(x,wt);
            mEdges++;
        }
    }
    void show(){
        for(int i=0; i<mVertices; i++){
            std::cout << i << " ====>  " ;
            for(auto& ipair:adjVec[i]){                
                std::cout << "( " << i << "," << ipair.first << "," << ipair.second <<")  ";
            }
            std::cout << std::endl;
        }
    }
    int vertexCount(void) {
        return mVertices;
    }
    int edgeCount(void) {
        return mEdges;
    }
};
