//Private the message

//send

#include<stdio.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#define MAX 10

//structure for message queue

struct msg_buffer {
	long msg_type;
	char msg_text[100];
}
message;

int main()
{
	key_t key;
	int msgid;
	//ftok to generate unique key
	key=ftok("2021ict124",124);
	//msgget creates a message queue
	//and returns identifier
	msgid=msgget(key,0666 | IPC_CREAT);
	message.msg_type=1;
	printf("Write Data: ");
	fgets(message.msg_text,MAX,stdin);
	//msgsend to send message
	msgsnd(msgid,&message, sizeof(message), 0);
	//display the message
	printf("Data send is : %s \n", message.msg_text);
	return 0;
}

//receive

#include<stdio.h>
#include<sys/ipc.h>
#include <sys/msg.h>

//structure for message queue
struct msg_buffer{
	long msg_type;
	char msg_text[100];
}
message;

int main()
{
	key_t key;
	int msgid;
	//ftok to generate unique key
	key=ftok("2021ict124",124);
	//msgget creates a message queue
	//and returns identifier
	msgid=msgget(key,0666 | IPC_CREAT);
	//msgrcv to receive message
	msgrcv(msgid,&message, sizeof(message),1, 0);
	//display the message
	printf("Data received is : %s \n", message.msg_text);
	//to destroy the message queue
	msgctl(msgid,IPC_RMID,NULL);
	return 0;
}
