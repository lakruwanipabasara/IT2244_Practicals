## IT2244_Practicals

Operating Systems - Practicals

### Example 1

How this works

- Pipe Creation - A pipe (p[2]) is created for interprocess communication.
- Message Writing - Three messages (msg1, msg2, msg3) are written to the pipe.
- Message Reading - The program reads the messages sequentially and prints them.


OUTPUT: 

![SS01](https://github.com/user-attachments/assets/24b8c8bd-118f-4ee0-b757-557d87d55991)




### Example 2

Create code using c language.

1. Get two input from user. (//parent process)
name:
reg no:
age:

2. Print the output from the child. (//child process)

name:abc
reg no: 2021/ict/01
age:25


- pipe(pipefd): Creates a pipe for communication.
- fork(): Creates a new child process.
- write(pipefd[1], buffer, strlen(buffer) + 1): Sends data from parent to child.
- read(pipefd[0], buffer, MSGSIZE): Reads data in the child process.


OUTPUT:

![SS02](https://github.com/user-attachments/assets/b4d8a0d0-634e-44fe-8a14-8e0c03513e90)

