//
//  main.cpp
//  Crypto
//
//  Created by Avery Rubin on 7/31/17.
//  Copyright © 2017 Avery Rubin. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <iostream>
#include "functions.cpp"

using namespace std;

/*
TODO if you want to run locally:
 - implement input data parsing
 - initialize all min distances to infinite
 - make sure source distance = 0
 - construct all edges into vector
 - make sure all edges node pointers are pointing to nodes from original node vector
 - point graph's edges to constructed edges
*/

int main(int argc, const char * argv[]) {
    //Implement pulling data from what ever source you want, transform data into a graph class given in Model.cpp, run BellmanFord
    return 0;
}


vector<string> BellmanFord(Graph graph, vector<CurrencyNode> nodes)
{
    int numCurrencies = graph.numCurrencies;
    int numEdges = graph.numEdges;
    
    
    // Massage all edges |V| - 1 times
    for (int i = 1; i <= numCurrencies - 1; ++i)
    {
        for (int j = 0; j < numEdges; j++)
        {
            (*graph.edges)[j].massage();
        }
    }
    
    // check for negative-weight cycles
    vector<string> cycleList;
    for (int i = 0; i < numEdges; i++)
    {
        if ((*graph.edges)[i].testForNegativeCycle())
        {
            cout << "Graph contains negative weight cycle" << endl;
            CurrencyNode node = *(*graph.edges)[i].source;
            while (node.symbol != (*(*graph.edges)[i].destination).symbol)
            {
                cycleList.emplace_back(node.symbol);
                node = *node.previous;
            }
            cycleList.emplace_back((*(*graph.edges)[i].destination).symbol);
            return cycleList;
        }
    }
    return cycleList;
}

