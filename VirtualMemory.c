#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <alloca.h>

#define FRAME_SIZE 256        // size of the frame
#define NUMBER_OF_FRAMES 256  // total number of frames in physical memory

#define OFFSET_MASK  0xFF //mask all but the offset
#define TLB_SIZE 16       // size of the TLB
#define PAGE_TABLE_SIZE 256  // size of the page table
#define MAXIMUM_INPUT        7	//Maximum input per line from address.txt file
#define CHUNK               256 // number of bytes to read


int pageTable[PAGE_TABLE_SIZE];  // page table sarray
int freeFrames[NUMBER_OF_FRAMES];   // freeFrames array 
int physicalMemory[NUMBER_OF_FRAMES][FRAME_SIZE];
int page_fault = 0;
int TLB_hits = 0;
int TLB[TLB_SIZE][2];

// input file and backing store
FILE    *address_file;
FILE    *backing_store;

// to store input and pass it the function
char    address_array[MAXIMUM_INPUT];
int     virtual_address;

// the buffer containing reads from backing store
signed char     back_read[CHUNK];

void Paging(int address);
int Backing(int pageNumber);
int Is_TLB(int pageNumber);
void Add_TLB(int pageNumber, int mapped_frame);

int main(int argc, char *argv[])
{

   /* error handeling */

    if (argc != 2)
    {
        fprintf(stderr,"Usage: ./VirtualMemory.out [input file]\n");
        return -1;
    }

    // open the file containing the backing store , rb agrument is given for NON-TEXT files such as this file
    backing_store = fopen("BACKING_STORE.bin", "rb");

    //If the backing store is empty
    if (backing_store == NULL)
    {
        fprintf(stderr, "Error opening BACKING_STORE.bin %s\n","BACKING_STORE.bin");
        return -1;
    }

    // open the file containing the logical addresses , read only
    address_file = fopen(argv[1], "r");

    //If the the address file is empty
    if (address_file == NULL)
    {
        fprintf(stderr, "Error opening addresses.txt %s\n",argv[1]);
        return -1;
    }


    /* initializing memory free frames */
    for(int i = 0;i<NUMBER_OF_FRAMES; i++)
    	freeFrames[i] = 1; // all frames are free at the beginning



    for(int i = 0;i<PAGE_TABLE_SIZE; i++)
    	pageTable[i] = -1; // initialiing


    // read through the input file and output each logical address
    while (fgets(address_array, MAXIMUM_INPUT, address_file) != NULL)
    {
        //char *fgets(char *str, int n, FILE *stream)
        //str − This is the pointer to an array of chars where the string read is stored.
        //n − This is the maximum number of characters to be read (including the final null-character). Usually, the length of the array passed as str is used.
        //stream − This is the pointer to a FILE object that identifies the stream where characters are read from.

        virtual_address = atoi(address_array);
        Paging(virtual_address);
    }

    // close the input file and backing store
    fclose(address_file);
    fclose(backing_store);
    printf("Number of page faults = %d\n",page_fault);
    return 0;
}


void Paging(int virtual_address)
{

    // bit masking from 16 bits to 8 bits
    int pageNumber = (virtual_address>>8);
    int offset = (virtual_address & OFFSET_MASK);
    int mapped_frame = 0;
    int physical_address = 0;

   if(Is_TLB(pageNumber) != 0){
	
	    printf("Found in TLB, page number = %d correspond to frame = %d",pageNumber,Is_TLB(pageNumber));

	    } else {

	    /* check if the page number is stored inside the page table */
	    if(pageTable[pageNumber] != -1){
		mapped_frame = pageTable[pageNumber];
		physical_address = physicalMemory[mapped_frame][offset];
		Add_TLB(pageNumber, mapped_frame);
	    }
	    else {
		mapped_frame = Backing(pageNumber); // bring page from disk
		physical_address = physicalMemory[mapped_frame][offset];
		Add_TLB(pageNumber, mapped_frame);
	    }
    }


    printf("Page number = %d Frame Number = %d offset: %d \n", pageNumber, mapped_frame, offset);

    // output the virtual address, physical address
    printf("Virtual address: %d Physical address: %d \n\n", virtual_address, (mapped_frame << 8) | offset);
}



int Backing(int pageNumber)
{
    int available_frame = 0;
    // first seek to byte CHUNK in the backing store
    // SEEK_SET --> Beginning of file
    if (fseek(backing_store, pageNumber * CHUNK, SEEK_SET) != 0)
    {
        fprintf(stderr, "Error seeking in backing store\n");
    }

    // read from backing_store file to back_read array
    if (fread(back_read, sizeof(signed char), CHUNK, backing_store) == 0)
    {
        fprintf(stderr, "Error reading from backing store\n");
    }

    /* search for an available frame */
    for(int i = 0; i< NUMBER_OF_FRAMES;i++)
	if(freeFrames[i] == 1){
		available_frame = i;
		freeFrames[i] = 0;
		pageTable[pageNumber] = available_frame;
		page_fault++;
		break;
	}

    printf("Page Fault! Obtaining page from disk and assigning to frame %d\n",available_frame);

    //find the first avaliable friame --> put it into physical memory arrayrray
    for(int i = 0; i < CHUNK; i++)
    {
        physicalMemory[available_frame][i] = back_read[i];
    }

    return available_frame;
}


int Is_TLB(int pageNumber){
	
	for(int i=0; i<TLB_SIZE;i++){
		if(TLB[i][0] == pageNumber){
			TLB_hits++;
			return TLB[i][1];
		}
	}

return 0;

}

void Add_TLB(int pageNumber, int mapped_frame){
	/* implementing FIFO */

	// TODO
}
