# IT2244_Practicals

Operating Systems - Practicals

## Inter-Process Communication Using Message Queues in C

## Code Overview:

Sender.c

 Generates a unique key using ftok().
🔹 Creates a message queue using msgget().
🔹 Sends a message using msgsnd().
🔹 Prints confirmation of the sent message.

Receiver.c
🔹 Accesses the same message queue using ftok().
🔹 Retrieves messages using msgrcv().
🔹 Displays the received message.
🔹 Deletes the queue with msgctl() after use.



