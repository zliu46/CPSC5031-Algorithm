/**
 * This is the cpp file of Graph class
 * Purpose: This class models an undirected graph. This file includes the details of load function,
 * display adjacency matrix function, display DFS result function, and display BFS result function.
 * @author Zhou Liu
 * @version 1.0
 * 5/18/2023
 */
#include "Graph.h"
#include "fstream"
#include <queue>
Graph::Graph() {
    numVertices = 0;//Initialize the number of vertex.
    adjMatrix = nullptr;//Initialize the adjacency matrix pointers.
}
Graph::~Graph() {
    //Create a for loop to delete the adjacency matrix
    for (int i = 0; i < numVertices; i++) {
        delete [] adjMatrix[i];
    }
    //Delete the pointer.
    delete [] adjMatrix;
}

void Graph::load(string filename) {
    //Create an ifstream object to read file.
    ifstream in;
    //Open the file.
    in.open(filename.c_str());
    //check if the filepath is valid.
    if (!in) {
        cout << "File not open\n";
        return;
    }
    int u, v;//Hold the indexes of the adjacency matrix of a graph.
    in >> numVertices;//Read the number of the vertex from file.
    adjMatrix = new int *[numVertices];//Create a new adjacency matrix.
    //Create a for loop to initialize the pointer.
    for (int i = 0; i < numVertices; i++){
        adjMatrix[i] = new int[numVertices];
    }
    //Create a for loop to initialize adjacencey matrix.
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++)
            adjMatrix[i][j] = 0;
    }
    //fill the adjacency matrix.
    while(!in.eof()){
        in>>u>>v;
        adjMatrix[u][v]=1;
        adjMatrix[v][u]=1;

    }
}

void Graph::display(){
    cout<<"Adjacency Matrix\n";
    //Prints out the adjacency matrix.
    for(int i=0;i<numVertices;i++){
        for(int j=0;j<numVertices;j++)
            cout<<adjMatrix[i][j]<<" ";
        cout<<"\n";
    }
    cout<<"\n";
}

void Graph::displayDFS(int v){
    //Create a bool array to visit vertices and check.
    bool *visited = new bool[numVertices];
    //Initialize the array
    for (int i = 0; i < numVertices; i++)
        visited[i] = false;
    //Call a helper function to print out the DFS.
    RecDFS(v, visited);
}

void Graph::RecDFS(int v, bool visited[])
{
    visited[v] = true;//Reset the array.
    cout << v << " ";//Prints out the result
    //Create a for loop to prints out the result.
    for(int i = 0; i <numVertices; ++i)
        if(adjMatrix[v][i]&&!visited[i])
            RecDFS(i, visited);
}

void Graph::displayBFS(int v){
    //Create a new array.
    bool *visited = new bool[numVertices];
    //Initialize the array.
    for (int i = 0; i < numVertices; i++)
        visited[i] = false;
    //Call a helper function to print out the BFS.
    RecBFS(v, visited);
}

void Graph::RecBFS(int v, bool visited[]) {
    queue<int> Q;//Create a queue to implement BFS.
    visited[v] = true;//Reset the array.
    Q.push(v);//Push the element to the queue.
    while (!Q.empty()) {
        int ver = Q.front();
        Q.pop();//Pop the element from the queue.
        //Prints out the result.
        cout << ver << " ";
        //Create a for loop to push back the elements.
        for (int i = 0; i < numVertices; ++i) {
            if (adjMatrix[ver][i] && !visited[i]) {
                visited[i] = true;
                Q.push(i);
            }
        }
    }
}

