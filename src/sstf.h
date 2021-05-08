#ifndef __SSTF__
#define __SSTF__

struct trackIndex {
	int position;
	bool serviced;
	int distance;
};

void createTrack (int *ptr, int size);

void sstf(int size);
#endif
