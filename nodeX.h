#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "project3.h"


//Function and struct definitions intended to make implementation across all nodes
#define NODE_ARGS const int callerId, struct distance_table* dt, struct NeighborCosts* neighbor
#define BASE_COST(src, dst) ((const int)getNeighborCosts(src)->NodeCosts[dst])
#define CONNECTED(src, dst) (BASE_COST(src, dst) != INFINITY)

struct distance_table {
  int costs[MAX_NODES][MAX_NODES];
};

void rtinitX(NODE_ARGS);
void rtupdateX(struct RoutePacket* rcvdpkt, NODE_ARGS);
int getLeastCost(const struct distance_table* dt, const int dest);
void printdtX(int MyNodeNumber, struct NeighborCosts* neighbor, struct distance_table* dtptr);
