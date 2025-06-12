//writer process1

CODE:

#include <stdio.h>
#include <sys/ipc.h>
#include <stdlib.h>
#include <string.h>
#include <sys/shm.h>

#define SHM_SIZE 1024 //Size of shared memory segment

int main()
{
	key_t key = ftok("shmfile", 10124); //Generate unique key
	int shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666); //Create shared memory segment
	if(shmid == -1)
	{
		perror("shmget");
		exit(1);
	}
	
	char *shmaddr = (char*) shmat(shmid,NULL,0); //Attach to shared memory
	if(shmaddr == (char*)-1)
	{
		perror("shmat");
		exit(1);
	}
	
	printf("Write Data: ");
	fgets(shmaddr, SHM_SIZE,stdin); //Write data
	
	printf("Data written in memory: %s\n",shmaddr);
	
	shmdt(shmaddr); //Detach from shared memory
	
	return 0;
}

/*
vi writer.c
gcc writer.c -o writer
./writer
*/
------------------------------------------------------------------------------------------------

//reader

CODE:

#include <stdio.h>
#include <sys/ipc.h>
#include <stdlib.h>
#include <sys/shm.h>

#define SHM_SIZE 1024 //Size of shared memory segment

int main()
{
	key_t key = ftok("shmfile", 10124); //Generate unique key
	int shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666); //Access shared memory segment
	if(shmid == -1)
	{
		perror("shmget");
		exit(1);
	}
	
	char *shmaddr = (char*) shmat(shmid,NULL,0); //Attach to shared memory
	if(shmaddr == (char*)-1)
	{
		perror("shmat");
		exit(1);
	}
	
	printf("Data read from memory: %s\n",shmaddr); //Read data from shared memory
	
	shmdt(shmaddr); //Detach from shared memory
	
	shmctl(shmid, IPC_RMID, NULL); //Remove shared memory segment
	
	return 0;
}


/*
vi reader.c
gcc reader.c -o reader
./reader

touch shmfile
chmod 644 shmfile
gcc writer.c -o writer
./writer
gcc reader.c -o reader
./reader

*/


