/**
 * This is the h file of Graph class
 * Purpose: This class models an undirected graph. This program creates an empty graph, and read the
 * input file of a graph. The program displays the graph's adjacency matrix to the screen,
 * the result of a depth first search starting at the provided vertex, and he result of
 * a breadth first search starting at the provided vertex.
 * @author Zhou Liu
 * @version 1.0
 * 5/18/2023
 */
#ifndef GRAPH_GRAPH_H
#define GRAPH_GRAPH_H
#include <iostream>
using namespace std;
class Graph {
    int numVertices;//To hold the numbers of vertex of a graph.
    int ** adjMatrix;//To hold the adjacency matrix of a graph.
    //This is the recursive helper function of displaying DFS of a graph.
    void RecDFS(int v, bool visited[]);
    //This is the recursive helper function of displaying BFS of a graph.
    void RecBFS(int v, bool visited[]);

public:
    Graph();//This the constructor creates an empty graph.
    ~Graph();//This the destructor that deletes adjacency matrix of a graph
    void load(string);//This is the load function that reads a file of a  graph.
    void display();//This function displays the graph's adjacency matrix to the screen.
    void displayDFS(int);//This function displays the result of a depth first search starting at the provided vertex.
    void displayBFS(int);//This function displays the result of a breadth first search starting at the provided vertex.
};


#endif //GRAPH_GRAPH_H
