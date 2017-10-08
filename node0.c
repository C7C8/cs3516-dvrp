#include <stdio.h>
#include "project3.h"
#include "nodeX.h"

extern int TraceLevel;

struct distance_table dt;
struct NeighborCosts   *neighbor;

/* students to write the following two routines, and maybe some others */

void rtinit0() {
    rtinitX(0, &dt, neighbor);
}


void rtupdate0( struct RoutePacket *rcvdpkt ) {
    rtupdateX(0, rcvdpkt, &dt, neighbor);
}
