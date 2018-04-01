#include "stdafx.h"
#include "mpi.h"
#include <stdlib.h>
#include <time.h>

#define  ARRAYSIZE	16000000
#define  MASTER		0

static int taskLider = 0;

int main(int argc, char *argv[])
{
	int   numtasks, taskid, rc = 0, dest, i, index, j, source;
	int previousRandomNumber = 0, procesNumberRandom = 0, numberTaskID=0;
	int tag1 = 1, tag2 = 2;
	int randomNumber = 0;

	MPI_Status status;

	/***** Initializations *****/
	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &numtasks);
	if (numtasks <= 1) {
		printf("Quitting. Number of procs is less than 2.\n");
		MPI_Abort(MPI_COMM_WORLD, rc);
		return(0);
	}
	MPI_Comm_rank(MPI_COMM_WORLD, &taskid);
	printf("MPI task %d has started...\n", taskid);

	/***** Master task only ******/
	if (taskid == MASTER) {

		for (index = 1; index<numtasks; index++) {
			MPI_Recv(&numberTaskID, 1, MPI_INT, index, tag1, MPI_COMM_WORLD, &status);
			MPI_Recv(&procesNumberRandom, 1, MPI_INT, index, tag2, MPI_COMM_WORLD, &status);

			if (procesNumberRandom > previousRandomNumber) {
				taskLider = numberTaskID;
			}
			else if (procesNumberRandom == previousRandomNumber) {
				if (numberTaskID > taskLider)
				{
					taskLider = numberTaskID;
				}
			}
		}

		printf("Task lider : %d", taskLider);

	} 
	/***** Non-master tasks only *****/

	if (taskid > MASTER) {

		srand(time(NULL));
		
		randomNumber = rand() % numtasks+1;

		dest = MASTER;
		MPI_Send(&taskid, 1, MPI_INT, dest, tag1, MPI_COMM_WORLD);
		MPI_Send(&randomNumber, 1, MPI_INT, dest, tag2, MPI_COMM_WORLD);

	} 	
	MPI_Finalize();

} 