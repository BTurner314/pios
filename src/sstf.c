#include <stdbool.h>
#include "sstf.h"


int trackHead = 50;
struct trackIndex orderServiced[];
struct trackIndex trackArray[];

// Takes an array of ints and creates an array of trackIndexes
void createTrack(int *ptr, int size){
	
	int i;
	for (i = 0; i < size; i++){
		struct trackIndex new;
		new.position = *ptr;
		new.serviced = false;
		new.distance =0;
		trackArray[i] = new;
		ptr++;
	}
}

 void sstf(int size){
	//Would like to implement a time variable to track the time taken to do the disk search.
	int i;
	int j;
	//Creates an array with all the elements sorted in order serviced
	for (j = 0; i < size; j++){
	//Creates an array with the differences between the head and the tracks
		for (i = 0; i < size; i++){
			
			if (trackArray[i].serviced == false){
				if (trackHead < trackArray[i].position){
					trackArray[i].distance = trackArray[i].position - trackHead;
					trackHead = trackArray[i].distance;
				}
				else {
					trackArray[i].distance = trackHead - trackArray[i].position;
					trackHead = trackArray[i].distance;
				}
			}
		}
		
		//Find the shortest distance
		int shortest = 999999;
		struct trackIndex currentShortest;
		for (i = 0; i < size; i++){
			if (shortest > trackArray[i].distance){
				shortest = trackArray[i].distance;
				currentShortest = trackArray[i];
			}
		}
		
	//Service the shortest distance node and remove it from the list
	currentShortest.serviced = true;
	orderServiced[j] = currentShortest;
	
	}
}
