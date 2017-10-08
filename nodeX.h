#pragma once
#include <stdio.h>
#include "project3.h"


//Function and struct definitions intended to make implementation across all nodes
//This might be the laziest #define I've yet written
#define NODE_ARGS struct distance_table* dt, struct NeighborCosts* neighbor
struct distance_table {
  int costs[MAX_NODES][MAX_NODES];
};

void rtinitX(const int callerId, NODE_ARGS);
void rtupdateX(const int callerId, struct RoutePacket* rcvdpkt, NODE_ARGS);
void printdtX(int MyNodeNumber, struct NeighborCosts* neighbor, struct distance_table* dtptr);
