#include <stdio.h>
#include "project3.h"
#include "nodeX.h"

extern int TraceLevel;

struct distance_table dt2;
struct NeighborCosts   *neighbor2;

/* students to write the following two routines, and maybe some others */

void rtinit2() {
    neighbor2 = malloc(sizeof(struct NeighborCosts));
    rtinitX(2, &dt2, neighbor2);
}


void rtupdate2( struct RoutePacket *rcvdpkt ) {
    rtupdateX(rcvdpkt, 2, &dt2, neighbor2);
}
