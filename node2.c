#include <stdio.h>
#include "project3.h"
#include "nodeX.h"

extern int TraceLevel;

struct distance_table dt;
struct NeighborCosts   *neighbor;

/* students to write the following two routines, and maybe some others */

void rtinit2() {
    rtinitX(2, &dt, neighbor);
}


void rtupdate2( struct RoutePacket *rcvdpkt ) {
    rtupdateX(2, rcvdpkt, &dt, neighbor);
}
