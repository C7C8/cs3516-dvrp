#include <stdio.h>
#include "project3.h"
#include "nodeX.h"

extern int TraceLevel;

struct distance_table dt3;
struct NeighborCosts neighbor3;

/* students to write the following two routines, and maybe some others */

void rtinit3() {
    rtinitX(3, &dt3, &neighbor3);
}


void rtupdate3( struct RoutePacket *rcvdpkt ) {
    rtupdateX(rcvdpkt, 3, &dt3, &neighbor3);
}
