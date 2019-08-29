//
//  classes.cpp
//  Crypto
//
//  Created by Avery Rubin on 7/31/17.
//  Copyright © 2017 Avery Rubin. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

class CurrencyNode{
public:
    string symbol;
    double minDistance;
    CurrencyNode * previous;
    
    CurrencyNode(string Symbol){
        this->symbol = symbol;
    }
};

class Edge{
public:
    int weight;
    CurrencyNode * source;
    CurrencyNode * destination;
    
    Edge(int weight, CurrencyNode* source, CurrencyNode* destination){
        this -> weight = weight;
        this -> source = source;
        this -> destination = destination;
    }
    
    void massage(){
        if ((*this -> source).minDistance != INT_MAX && (*this -> source).minDistance + this -> weight < (*this -> destination).minDistance)
        {
            (*this -> destination).minDistance = (*this -> source).minDistance + weight;
            (*this -> destination).previous = this -> source;
        }
    }
    
    bool testForNegativeCycle()
    {
        if ((*this -> source).minDistance != INT_MAX && (*this -> source).minDistance + this -> weight < (*this -> destination).minDistance)
            return true;
        else
            return false;
    }
};


class Graph{
public:
    int numCurrencies, numEdges;
    vector<Edge>* edges;
    Graph(int numCurrencies, int numEdges, vector<Edge>* edges){
        this -> numCurrencies = numCurrencies;
        this -> numEdges = numEdges;
        this -> edges = edges;
    }
};
