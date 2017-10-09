#include <stdio.h>
#include "project3.h"
#include "nodeX.h"

extern int TraceLevel;

struct distance_table dt0;
struct NeighborCosts neighbor0;

/* students to write the following two routines, and maybe some others */

void rtinit0() {
    rtinitX(0, &dt0, &neighbor0);
}


void rtupdate0( struct RoutePacket *rcvdpkt ) {
    rtupdateX(rcvdpkt, 0, &dt0, &neighbor0);
}
