
//Graph - As an array of Vectors

#pragma once

#include<iostream>
#include<vector>

class GraphArrayOfVec{
    int mVertices;
    std::vector<std::pair<int, int>>* adjVec; //Pointer to store array of vectors 
    //array size is not known a priori, hence pointer is used
    int mEdges;
public:
    GraphArrayOfVec(int n): mVertices(n){
        std::cout << "Creating graph with " << mVertices << "Vertices" << std::endl;
        //Now allocating memory to store n vectors
        adjVec = new std::vector<std::pair<int, int>>[n]; // need to free this later to avoid memory leak
        mEdges =0;//Initialize to no edges
    }
    ~GraphArrayOfVec(){
        std::cout << "Graph memory is freed" << std::endl;
        delete [] adjVec;
    }
    int  weight(int x, int y){
        for(auto& ipair: adjVec[x]){
            if (ipair.first == y) {return ipair.second;}
        }
        return 0;
    }
    void addEdge(int x, int y, bool undirected=true, int wt=1){
        if (weight(x, y)==0){
            adjVec[x].emplace_back(y,wt);
            mEdges++;
        }
        if(undirected){
            if (weight(y, x)==0){
            adjVec[y].emplace_back(x,wt);
            mEdges++;
            }
        }
    }
    void show(){
        for(int i=0; i<mVertices; i++){
            std::cout << i << " ====>  " ;
            for(auto& ipair:adjVec[i]){
                //adjVec[i] --> contains all the edges info originating from vertex i
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