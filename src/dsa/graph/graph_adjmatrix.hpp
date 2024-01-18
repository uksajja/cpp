//Array implementation of Graph as an Adjacent Matrix - Inefficient
#pragma once

#include<iostream>

class GraphM{
    int mVertices;
    int** adjMatrix;
    int mEdges;
public:
    GraphM(int n):mVertices(n){
        adjMatrix = new int*[n];
        for(int i=0; i< n; i++){
            adjMatrix[i] = new int[n];
        }
        for(int i=0; i< n; i++){
            for(int j=0; j<mVertices; j++){
                adjMatrix[i][j] = 0;
            }
        }
        mEdges = 0;
    };
    ~GraphM(){
        for(int i=0; i<mVertices; i++){
            delete [] adjMatrix[i];
        }
        delete [] adjMatrix;
    }
    void addEdge(int x, int y, bool undirected=true, int wt=1){
        if(adjMatrix[x][y]==0 ){
            adjMatrix[x][y] = wt;
            mEdges++;
        }
        if(undirected) {
            if(adjMatrix[y][x]==0){
                adjMatrix[y][x] = wt;
                mEdges++;
            }
        }
    }
    void removeEdge(int x, int y, bool undirected=true){
        if(adjMatrix[x][y]!=0 ){
            adjMatrix[x][y] = 0;
            mEdges--;
        }
        if(undirected) {
            if(adjMatrix[y][x]!=0 ) {
                adjMatrix[y][x] = 0;
                mEdges--;
            }
        }
    }
    void show() {
        for(int i=0; i< mVertices; i++){
            std::cout << i << " ====>  ";
            for(int j=0; j<mVertices; j++){
                if(adjMatrix[i][j] != 0){
                    std::cout << "(" << i << "," << j << "," << adjMatrix[i][j] << ")  "  ;
                }
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