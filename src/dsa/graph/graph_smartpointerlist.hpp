//Graph - As a smart pointer of Lists

#pragma once

#include<iostream>
#include<memory>
#include<list>

class GraphSmartPointerList{
    int mVertices;
    std::unique_ptr<std::list<std::pair<int, int>>[]> adjList; //Pointer to store array of vectors
    //array size is not known a priori, hence pointer is used
    int mEdges;
public:
    GraphSmartPointerList(int n): mVertices(n){
        std::cout << "Creating graph with " << mVertices << "Vertices" << std::endl;
        //Now allocating memory to store n vectors
        adjList = std::make_unique<std::list<std::pair<int, int>>[]>(n);
        mEdges=0;
    }
    ~GraphSmartPointerList(){} //No need to explicitly free Graph memory as smart pointers are used
    int  weight(int x, int y){
        for(auto& ipair: adjList[x]){
            if (ipair.first == y) {return ipair.second;}
        }
        return 0;
    }
    void addEdge(int x, int y, bool undirected=true, int wt=1){
        //index of adjList --> Origin vertex (where the edge is originated)
        //pair.frirst     --> Tail vertex (where the edge is ended)
        //pair.second     --> Weight of the edge
        if (weight(x, y)==0){
            adjList[x].emplace_back(y,wt);
            mEdges++;
        }
        if(undirected){
            if (weight(y, x)==0){
            adjList[y].emplace_back(x,wt);
            mEdges++;
            }
        }
    }  
    void show(){
        for(int i=0; i<mVertices; i++){
            std::cout << i << " ====>  " ;
            for(auto& ipair:adjList[i]){
                //adjList[i] --> contains all the edges info originating from vertex i
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