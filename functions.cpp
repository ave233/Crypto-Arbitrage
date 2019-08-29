//
//  functions.cpp
//  Crypto
//
//  Created by Avery Rubin on 7/31/17.
//  Copyright © 2017 Avery Rubin. All rights reserved.
//

#include <stdio.h>
#include "classes.cpp"

void massage(Graph *graph, int index){
    CurrencyNode * source = (*(*graph).edges)[index].source;
    CurrencyNode * destination = (*(*graph).edges)[index].destination;
    int weight = (*(*graph).edges)[index].weight;
    if ((*source).minDistance != INT_MAX && (*source).minDistance + weight < (*destination).minDistance)
        (*destination).minDistance = (*source).minDistance + weight;
}

bool testForNegativeCycle(Graph *graph, int index){
    CurrencyNode * source = (*(*graph).edges)[index].source;
    CurrencyNode * destination = (*(*graph).edges)[index].destination;
    int weight = (*(*graph).edges)[index].weight;
    if ((*source).minDistance != INT_MAX && (*source).minDistance + weight < (*destination).minDistance)
        return true;
    else
        return false;
}
