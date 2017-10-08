#include <stdio.h>
#include "project3.h"
#include "nodeX.h"

extern int TraceLevel;

struct distance_table dt;
struct NeighborCosts   *neighbor;

/* students to write the following two routines, and maybe some others */

void rtinit1() {
    rtinitX(1, &dt, neighbor);
}


void rtupdate1( struct RoutePacket *rcvdpkt ) {
	rtupdateX(1, rcvdpkt, &dt, neighbor);
}
