#include "stdafx.h"
#include <stdlib.h>
#include <time.h>
#include "mpi.h"
#include <stdio.h>
#include <math.h>

#define MAXSIZE 16
int data[MAXSIZE] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };
int main(int argc, char **argv)
{
	int myid, numprocs;
	int i, x, low, high, myresult = 0, result;
	
	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
	MPI_Comm_rank(MPI_COMM_WORLD, &myid);
	
	/* broadcast data */
	MPI_Bcast(data, MAXSIZE, MPI_INT, 0, MPI_COMM_WORLD);
	/* add portion of data */
	x = MAXSIZE / numprocs; /* must be an integer */
	low = myid * x;
	high = low + x;
	for (i = low; i<high; i++) {
		myresult += data[i];
	}
	printf("I got %d from %d\n", myresult, myid);
	/* compute global sum */
	MPI_Reduce(&myresult, &result, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
	if (0 == myid) {
		printf("The sum is %d.\n", result);
	}
	MPI_Finalize();
}