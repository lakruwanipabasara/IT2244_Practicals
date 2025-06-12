Exercise 01

Create code using c language.

1. Get two input from user. (//parent process)
name:
reg no:
age:

2. Print the output from the child. (//child process)

name:abc
reg no: 2021/ict/01
age:25



CODE:

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MSGSIZE 100

int main() {
    int pipefd[2]; 
    pid_t pid;
    char buffer[MSGSIZE]; 

    if (pipe(pipefd) == -1) {
        perror("Pipe creation failed");
        exit(1);
    }

    pid = fork(); 

    if (pid < 0) {
        perror("Fork failed");
        exit(1);
    }

    if (pid > 0) {
        close(pipefd[0]); 
        
        char name[50], reg_no[50], age[10];

       
        printf("Enter your name: ");
        fgets(name, sizeof(name), stdin);
        name[strcspn(name, "\n")] = '\0';

        printf("Enter your reg no: ");
        fgets(reg_no, sizeof(reg_no), stdin);
        reg_no[strcspn(reg_no, "\n")] = '\0'; 

        printf("Enter your age: ");
        fgets(age, sizeof(age), stdin);
        age[strcspn(age, "\n")] = '\0'; 
		
        
        snprintf(buffer, MSGSIZE, "name: %s\nregno: %s\nage: %s", name, reg_no, age);

        
        write(pipefd[1], buffer, strlen(buffer) + 1);
        close(pipefd[1]);
    } else {
        close(pipefd[1]); 
        
        read(pipefd[0], buffer, MSGSIZE); 
        close(pipefd[0]); 
        
       
        printf("\nChild Process Output:\n%s\n", buffer);
    }

    return 0;
}


/*
vi Exercise66.c
gcc Exercise66.c -o Exercise66
./Exercise66
*/
