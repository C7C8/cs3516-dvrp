#include "nodeX.h"

void rtinitX(NODE_ARGS){
	*neighbor = *getNeighborCosts(callerId);

	//Initialize all values of the costs table to INFINITY, except for the ones we already
	//have distance values for.
	for (int i = 0; i < MAX_NODES; i++)
		for (int j = 0; j < MAX_NODES; j++)
			dt->costs[i][j] = INFINITY;
	for (int i = 0; i < MAX_NODES; i++)
		dt->costs[i][i] = neighbor->NodeCosts[i]; //Direct routes
	dt->costs[callerId][callerId] = 0; //Not sure if this is correct

	//Broadcast out the current distance vector
	printdtX(callerId, neighbor, dt);
	struct RoutePacket pkt;
	pkt.sourceid = callerId;
	printf("Sending destination vector { ");
	for (int i = 0; i < MAX_NODES; i++) {
		pkt.mincost[i] = getLeastCost(dt, i);
		printf("%d ", pkt.mincost[i]);
	}
	printf("} to nodes ");
	for (int i = 0; i < MAX_NODES; i++){
		if (neighbor->NodeCosts[i] != INFINITY && i != callerId){
			pkt.destid = i;
			toLayer2(pkt);
			printf("%d ", i);
		}
	}

	printf("\n-------\n\n");
}

void rtupdateX(struct RoutePacket *rcvdpkt, NODE_ARGS){
	printf("%d BEFORE: { ", callerId);
	for (int i = 0; i < MAX_NODES; i++)
		printf("%d ", neighbor->NodeCosts[i]);
	printf("}\n");
	printdtX(callerId, neighbor, dt);

	//First copy the results into the table
	int tableChanged = 0;
	for (int i = 0; i < MAX_NODES; i++)
		if (rcvdpkt->mincost[i] != INFINITY && rcvdpkt->mincost[i] != 0){
			const int newCost = rcvdpkt->mincost[i] + BASE_COST(callerId, rcvdpkt->sourceid);
			if (newCost < dt->costs[i][rcvdpkt->sourceid]) {
				dt->costs[i][rcvdpkt->sourceid] = newCost;
				tableChanged = 1;
			}
		}

	if (tableChanged){
		//Update distance vector
		int dvChanged = 0;
		struct RoutePacket pkt;
		pkt.sourceid = callerId;
		for (int i = 0; i < MAX_NODES; i++) {
			const int cost = getLeastCost(dt, i);
			pkt.mincost[i] = cost;
			if (neighbor->NodeCosts[i] != cost) {
				neighbor->NodeCosts[i] = getLeastCost(dt, i);
				dvChanged = 1;
			}
		}

		//Only broadcast to other nodes if the distance vector changed, not the route table
		if (dvChanged) {
			printf("Updated distance vector to ");
			for (int i = 0; i < MAX_NODES; i++)
				printf("%d ", neighbor->NodeCosts[i]);
			printf("; broadcasting to nodes ");
			for (int i = 0; i < MAX_NODES; i++) {
				if (i != callerId && CONNECTED(callerId, i)) {
					pkt.destid = i;
					toLayer2(pkt);
					printf("%d ", i);
				}
			}
			printf("\nAFTER:\n");
			printdtX(callerId, neighbor, dt);
		}
		else
			printf("No changes made to route table\n");
	}
	else
		printf("No changes made to route table\n");


	printf("\n-----------\n\n");
}

int getLeastCost(const struct distance_table* dt, const int dest){
	int cost = INFINITY;
	for (int i = 0; i < MAX_NODES; i++){
		if (dt->costs[dest][i] < cost)
			cost = dt->costs[dest][i];
	}
	return cost;
}

/*  printdt
 *  This routine is being supplied to you.  It is the same code in
 *  each node and is tailored based on the input arguments.
 *  Required arguments:
 *  MyNodeNumber:  This routine assumes that you know your node
 *                 number and supply it when making this call.
 *  struct NeighborCosts *neighbor:  A pointer to the structure
 *                 that's supplied via a call to getNeighborCosts().
 *                 It tells this print routine the configuration
 *                 of nodes surrounding the node we're working on.
 *  struct distance_table *dtptr: This is the running record of the
 *                 current costs as seen by this node.  It is
 *                 constantly updated as the node gets new
 *                 messages from other nodes.
 */
void printdtX( int MyNodeNumber, struct NeighborCosts *neighbor,
			   struct distance_table *dtptr ) {
#ifndef NVERBOSE
	int       i, j;
	int       TotalNodes = neighbor->NodesInNetwork;     // Total nodes in network
	int       NumberOfNeighbors = 0;                     // How many neighbors
	int       Neighbors[MAX_NODES];                      // Who are the neighbors

	// Determine our neighbors
	for ( i = 0; i < TotalNodes; i++ )  {
		if (( neighbor->NodeCosts[i] != INFINITY ) && i != MyNodeNumber )  {
			Neighbors[NumberOfNeighbors] = i;
			NumberOfNeighbors++;
		}
	}
	// Print the header
	printf("                via     \n");
	printf("   D%d |", MyNodeNumber );
	for ( i = 0; i < NumberOfNeighbors; i++ )
		printf("     %d", Neighbors[i]);
	printf("\n");
	printf("  ----|-------------------------------\n");

	// For each node, print the cost by travelling thru each of our neighbors
	for ( i = 0; i < TotalNodes; i++ )   {
		if ( i != MyNodeNumber )  {
			printf("dest %d|", i );
			for ( j = 0; j < NumberOfNeighbors; j++ )  {
				printf( "  %4d", dtptr->costs[i][Neighbors[j]] );
			}
			printf("\n");
		}
	}
	printf("\n");
#else
	printf("[NVERBOSE -- Verbose routing table output omitted]\n");
#endif
}
