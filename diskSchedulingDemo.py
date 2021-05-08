import random

size = 8
disk_size = 200

# C-SCAN Disk Scheduling Algorithm

def findMin(diff):
 
    index = -1
    minimum = 999999999
 
    for i in range(len(diff)):
        if (not diff[i][1] and
                minimum > diff[i][0]):
            minimum = diff[i][0]
            index = i
    return index

def calculateDifference(queue, head, diff):
    for i in range(len(diff)):
        diff[i][0] = abs(queue[i] - head)
        
def CSCAN(array, head):
	
    left = []
    right = []
    order_serviced = []
    seek_time = 0
    current_track = 0

# Appending end values to left and right tracks

    left.append(0)
    right.append(disk_size - 1)

#Sorts tracks to either the left or right of the head

    for i in range(size):
        if (array[i] < head):
            left.append(array[i])
        if (array[i] > head):
            right.append(array[i])

    left.sort()
    right.sort()

#First service tracks to the right of the head

    for i in range(len(right)):
        current_track = right[i]

        order_serviced.append(current_track)

        seek_time += abs(current_track - head)

        head = current_track

#Then move the head to the beginning of the track
    head = 0

#Add seek time for the head moving back to 0
    seek_time += (disk_size - 1)

#Now service the tracks that were on the left of the head
    for i in range(len(left)):
        current_track = left[i]

        order_serviced.append(current_track)

        seek_time += abs(current_track - head)

        head = current_track

    print("CSCAN - Total Seek Time = ", seek_time)
    print("Order Serviced is: ")
    print(*order_serviced, sep="\n")


def FCFS(array, head):

    seek_time = 0

    for i in range(len(array)):
        seek_time += abs(array[i] - head)

        head = array[i]

    print("FCFS - Total Seek Time = ", seek_time)
    print("Order Serviced is: ")
    print(*array, sep="\n")

def SSTF(array, head):            

    l = len(array)
    diff = [0] * l
         
    # initialize array
    for i in range(l):
        diff[i] = [0, 0]
         
    # count total number of seek operation    
    seek_time = 0
         
    # stores sequence in which disk
    # access is done
    order_serviced = [0] * (l + 1)
         
    for i in range(l):
        order_serviced[i] = head
        calculateDifference(array, head, diff)
        index = findMin(diff)
             
        diff[index][1] = True
             
        # increase the total count
        seek_time += diff[index][0]
             
        # accessed track is now new head
        head = array[index]
     
        # for last accessed track
        order_serviced[len(order_serviced) - 1] = head
         
    print("SSTF - Total Seek Time = ", seek_time)
    print("Order Serviced is: ")
    print(*order_serviced, sep="\n")

def RSS(array, head):

    seek_time = 0
    random.shuffle(array)
    for i in range(len(array)):
        seek_time += abs(array[i] - head)
        head = array[i]

    print("RSS - Total Seek Time = ", seek_time)
    print("Order Serviced is: ")
    print(*array, sep="\n")


        
array = [23, 112, 30, 62, 192, 11, 49, 82]
head = 50

FCFS(array, head)
CSCAN(array, head)
SSTF(array, head)
RSS(array, head)
