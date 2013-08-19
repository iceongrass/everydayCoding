/*************************************************************************
*
*   frame.c
*
**************************************************************************
*   Decription:
*   
*       In this example, two functions, allc_frame and free_frame, employ 
*   a linked list to maintain the frames that a available to be allocated.
*
*************************************************************************/

#include <stdlib.h>

#include "frame.h"
#include "list.h"

/*************************************************************************
*
*   Allocate frame
*
**************************************************************************
*
*   This function retrieves the number of a free frame from a list of 
*   available frame. Given a specific page, this number is placed in the 
*   page table to indicate in which physical frame the page is to reside.
*
*************************************************************************/
int alloc_frame(List * frames) {

    int frame_number, *data;

    if (list_size(frames) == 0)
        return -1;

    else {

        if (list_rem_next(frame, NULL, (void **)&data) != 0)
            return -1;

        else {

            frame_number = *data;
            free (data);
    
        }

    } 

    return frame_number;

}

/*************************************************************************
*   
*   Free frame 
*
**************************************************************************
*
*   This function accepts a frame number and places it back into the list
*   of available frames once a page ihas been removed from physical 
*   memory.
*
*************************************************************************/
int free_frame(List * frame, int frame_number) {
    
    int *data;

    if((data = (int *) malloc (sizeof(int))) == NULL)
        return -1;

    *data = frame_number;

    if (list_ins_next(frame, NULL, data) != 0)
        return -1;

    return 0;

}