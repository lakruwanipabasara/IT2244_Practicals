Exercise-:

/* 
IPC using message queue

read inputs from the parent process
Enter name:hi
Enter regno:2314
Enter age:24

Message sent successfully

give the output from the child process

Received name: hi 
Received regno: 2314
Received age:24

*/


#include <sys/msg.h>             // For message queue system calls: msgget, msgsnd, msgrcv, msgctl
#include <stdio.h>               // For standard I/O functions like printf, scanf
#include <string.h>              // For string functions
#include <stdlib.h>              // For exit() function
#include <unistd.h>              // For fork() and sleep() system calls

#define MSGKEY 1111              // Define a constant message queue key
#define MAX_NAME_LEN 100         // Maximum length for name string
#define MAX_REGNO_LEN 100        // Maximum length for regno string

// Define a struct to hold the message data
struct person {
    long mtype;     // Message type
    int age;        // Age field
    char name[MAX_NAME_LEN];      // Name field
    char regno[MAX_REGNO_LEN];    // Registration number field
};

int main() {
    int msqid;                     // Message queue identifier
    struct person p1, p2;          // Two person structures: one to send, one to receive
    int f = fork();                // Create a new process using fork()

    if (f == 0) {
        // Child process: Receiver
        msqid = msgget(MSGKEY, IPC_CREAT | 0666);      // Create or get message queue with key MSGKEY and permissions 0666
        if (msqid == -1) {
            perror("msgget failed");                // Print error if message queue creation fails
            exit(EXIT_FAILURE);                     // Exit program on failure
        
        }

        int msg_size = sizeof(struct person) - sizeof(long);    // Calculate message size excluding mtype

        if (msgrcv(msqid, &p2, msg_size, 0, 0) == -1) {         // Receive message of any type (type = 0)
            perror("msgrcv failed");                            // Print error if message receive fails
            exit(EXIT_FAILURE);                                 // Exit program on failure
        } else {
            printf("Received Name: %s\n", p2.name);             // Display received name
            printf("Received RegNo: %s\n", p2.regno);           // Display received registration number
            printf("Received Age: %d\n", p2.age);               // Display received age
        }

        if (msgctl(msqid, IPC_RMID, NULL) == -1) {              // Remove the message queue after use
            perror("msgctl failed");                            // Print error if message queue removal fails
            exit(EXIT_FAILURE);                                 // Exit program on failure
        }
    } else {
        // Parent process: Sender
        msqid = msgget(MSGKEY, IPC_CREAT | 0666);               // Create or get message queue with key MSGKEY
        if (msqid == -1) {
            perror("msgget failed");                            // Print error if message queue creation fails
            exit(EXIT_FAILURE);                                 // Exit program on failure
        }

        p1.mtype = 1;                                           // Set message type to 1

        printf("Enter Name: ");                                 // Prompt user for name
        scanf("%s", p1.name);                                   // Read name (warning: doesn't handle spaces)

        printf("Enter RegNo: ");                                // Prompt user for registration number
        scanf("%s", p1.regno);                                  // Read registration number

        printf("Enter Age: ");                                  // Prompt user for age
        scanf("%d", &p1.age);                                   // Read age

        int msg_size = sizeof(struct person) - sizeof(long);    // Calculate message size excluding mtype

        if (msgsnd(msqid, &p1, msg_size, IPC_NOWAIT) == -1) {   // Send message without waiting if queue is full
            perror("msgsnd failed");                            // Print error if message send fails
        } else {
            printf("Message sent successfully.\n");             // Inform that message was sent successfully
        }

        exit(0);                                               // Exit parent process
    }

    return 0;         // Return from main function
}
