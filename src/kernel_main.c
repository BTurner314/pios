#include <stdbool.h>
#include "sstf.h"
#include "rprintf.h"

void kernel_main() {
  
  int array[5] = {52, 37, 5, 235, 80};
  int *ptr = array;
  int size = 5;
  int i;
  int seekTime = 0;
  int head = 50;
  extern struct trackIndex trackArray[];
  extern struct trackIndex orderServiced[];
  
  //I think something wrong with how i declare the createTrack function
  createTrack(ptr, size);
  
  for (i = 0; i < size; i++){
    esp_printf("Track index is %d \n", (int)trackArray[i].position);
  
  }
  
  sstf(size);

//Calculates the total seek time
    for (i = 0; i < size; i++){
	if (orderServiced[i].position < head ){
	    seekTime+= head - orderServiced[i].position; 
	}
	else {seekTime+= orderServiced[i].position - head;
	}
	head = orderServiced[i].position;    
    }
    esp_printf("Total seek time is %d \n" , seekTime);
}

