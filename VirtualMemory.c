#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <alloca.h>

#define FRAME_NUMBER	256	// total number of frames in physical memory
#define FRAME_SIZE	256	// size of the frame
#define OFFSET_MASK  	0xFF	//mask all but the offset
#define TLB_SIZE 	16	// size of the TLB
#define PAGE_TABLE_SIZE 256	// size of the page table
#define MAXIMUM_INPUT   7	// Maximum input per line from address.txt file
#define CHUNK		256	// number of bytes to read


int pageTable[PAGE_TABLE_SIZE];			// page table array
int freeFrames[FRAME_NUMBER];			// free frames array 
int physicalMemory[FRAME_NUMBER][FRAME_SIZE];	// physical memory array
int TLB[TLB_SIZE][2];				// TLB table

/* Statistics */
int page_fault = 0;
int TLB_hits = 0;
int no_references = 0;

/* FIFO Queue */
int QueueIn = 0;
int QueueOut = 0;

/* Backing Store and Input File */
FILE    *address_file;
FILE    *backing_store;

/* Line input storing */
char address_array[MAXIMUM_INPUT];
int virtual_address;

/* Buffer reads from backing store */
signed char back_read[CHUNK];


/* Function Prototyping */
void Paging(int address);
int Backing(int pageNumber);
int Is_TLB(int pageNumber);
void Add_TLB_highlevel(int pageNumber, int mapped_frame);
int QueuePut(int pageNumber, int mapped_frame);
int QueueGet();

/* main function */
int main(int argc, char *argv[])
{

   /* error handeling */

    if (argc != 2)
    {
        fprintf(stderr,"Usage: ./VirtualMemory.out [input file]\n");
        return -1;
    }

    /* open the file containing the backing store, rb agrument is given for NON-TEXT files such as this file */
    backing_store = fopen("BACKING_STORE.bin", "rb");

    /* If the backing store is empty */
    if (backing_store == NULL)
    {
        fprintf(stderr, "Error opening BACKING_STORE.bin %s\n","BACKING_STORE.bin");
        return -1;
    }

    /* open the file containing the logical addresses, read only */
    address_file = fopen(argv[1], "r");

    /* If the the address file is empty */
    if (address_file == NULL)
    {
        fprintf(stderr, "Error opening addresses.txt %s\n",argv[1]);
        return -1;
    }


    /* initializing memory free frames */
    for(int i = 0;i<FRAME_NUMBER; i++)
    	freeFrames[i] = 1; // all frames are free at the beginning

    /* initializing page table */
    for(int i = 0;i<PAGE_TABLE_SIZE; i++)
    	pageTable[i] = -1; // initialiing

    /* initializing TLB */
    for(int i = 0;i<TLB_SIZE; i++){
    	TLB[i][0] = -1;
    	TLB[i][1] = -1;
    }

    /* read through the input file and output each logical address */
    while (fgets(address_array, MAXIMUM_INPUT, address_file) != NULL)
    {
        /* char *fgets(char *str, int n, FILE *stream)
           str − This is the pointer to an array of chars where the string read is stored.
           n − This is the maximum number of characters to be read (including the final null-character). Usually, the length of the array passed as str is used.
           stream − This is the pointer to a FILE object that identifies the stream where characters are read from. */

        virtual_address = atoi(address_array);
        Paging(virtual_address);
	no_references++;
    }

    /* close the input file and backing store */
    fclose(address_file);
    fclose(backing_store);

    printf("Number of references = %d\n", no_references);
    printf("Number of page faults = %d\n",page_fault);
    printf("Number of TLB Hits = %d\n",TLB_hits);
    printf("Page-fault rate = %f\n",page_fault/(float)no_references);
    printf("TLB hit rate = %f\n",TLB_hits/(float)no_references);

    return 0;
}


void Paging(int virtual_address)
{

    /* bit masking from 16 bits to 8 bits */
    int pageNumber = (virtual_address>>8);
    int offset = (virtual_address & OFFSET_MASK);
    int mapped_frame = 0;
    int value = 0;

   /* check if the page number is stored in TLB, if not, search in page table. If not, then get it from the backing store  */
   if(Is_TLB(pageNumber) != 0){
            mapped_frame = Is_TLB(pageNumber);
	    printf("Found in TLB, page number = %d correspond to frame = %d \n",pageNumber,mapped_frame);

   } else {

	    /* check if the page number is stored inside the page table */
	    if(pageTable[pageNumber] != -1){
		mapped_frame = pageTable[pageNumber];
		value = physicalMemory[mapped_frame][offset];
		Add_TLB_highlevel(pageNumber, mapped_frame);
	    }
	    else {
		mapped_frame = Backing(pageNumber); // bring page from disk
		value = physicalMemory[mapped_frame][offset];
		Add_TLB_highlevel(pageNumber, mapped_frame);
	    }
    }

    /* terminal output */
    printf("Page number = %d Frame Number = %d offset: %d \n", pageNumber, mapped_frame, offset);
    printf("Virtual address: %d Physical address: %d Value: %d\n\n", virtual_address, (mapped_frame << 8) | offset, value);
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
    for(int i = 0; i< FRAME_NUMBER;i++)
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

void Add_TLB_highlevel(int pageNumber, int mapped_frame){
	/* implementing FIFO */
	if(QueuePut(pageNumber, mapped_frame) != -1){
		QueueGet();
		QueuePut(pageNumber, mapped_frame);
	}
}


int QueuePut(int pageNumber, int mapped_frame)
{
    if(QueueIn == (( QueueOut - 1 + TLB_SIZE) % TLB_SIZE))
    {
        return -1; /* Queue Full*/
    }

    TLB[QueueIn][0] = pageNumber;
    TLB[QueueIn][1] = mapped_frame;

    QueueIn = (QueueIn + 1) % TLB_SIZE;

    return 0; // No errors
}

int QueueGet()
{
    if(QueueIn == QueueOut)
    {
        return -1; /* Queue Empty - nothing to get*/
    }

    QueueOut = (QueueOut + 1) % TLB_SIZE;
    return 1;
}
