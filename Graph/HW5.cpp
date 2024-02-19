/**
 * This is the program that implements the Graph class.
 * @author Zhou Liu
 * @version 1.0
 * 5/18/2023
 */
#include "Graph.h"
#include <iostream>
using namespace std;
//This is the main function that creates a new Graph object, and implements the Graph.
//This function will call methods to print out the adjacency matrix of a graph, DFS of a graph, and BFS of a graph.
int main() {
    Graph graph;//Create a Graph object.
    graph.load("graph0.txt");//Call the load function of Graph to read from a file.
    graph.display();//Call a function that display the adjacency matrix of a graph.
    cout<<"DFS at vertex 0 : ";
    //Call a function to prints out the DFS of a graph.
    graph.displayDFS(0);
    cout<<"\nBFS at vertex 0 : ";
    //Call a function to prints out the BFS of a graph.
    graph.displayBFS(0);
    return 0;
}
