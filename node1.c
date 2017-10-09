#include <stdio.h>
#include "project3.h"
#include "nodeX.h"

extern int TraceLevel;

struct distance_table dt1;
struct NeighborCosts neighbor1;

/* students to write the following two routines, and maybe some others */

void rtinit1() {
    rtinitX(1, &dt1, &neighbor1);
}


void rtupdate1( struct RoutePacket *rcvdpkt ) {
	rtupdateX(rcvdpkt, 1, &dt1, &neighbor1);
}
