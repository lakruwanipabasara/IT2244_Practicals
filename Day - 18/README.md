# IT2244_Practicals

Operating Systems - Practicals

## Inter-Process Communication Using Message Queues in C

## Code Overview:

Sender.c

-  Generates a unique key using ftok().
  
-  Creates a message queue using msgget().
   
-  Sends a message using msgsnd().
  
-  Prints confirmation of the sent message.


Receiver.c

-  Accesses the same message queue using ftok().

-  Retrieves messages using msgrcv().

-  Displays the received message.

-  Deletes the queue with msgctl() after use.


## OUTPUT -:

![SS1](https://github.com/user-attachments/assets/cb540649-beda-4133-a758-44b2c697bf69)

![SS2](https://github.com/user-attachments/assets/f01cf3ef-6626-4e36-ac65-cc2c955d55c5)


