#include <stdio.h>
#include "project3.h"
#include "nodeX.h"

extern int TraceLevel;

struct distance_table dt;
struct NeighborCosts   *neighbor;

/* students to write the following two routines, and maybe some others */

void rtinit3() {
    rtinitX(3, &dt, neighbor);
}


void rtupdate3( struct RoutePacket *rcvdpkt ) {
    rtupdateX(3, rcvdpkt, &dt, neighbor);
}
