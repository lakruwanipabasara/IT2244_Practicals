## IT2244_Practicals

Operating Systems - Practicals

## Shared Memory Synchronization

Shared memory allows multiple processes to communicate by reading and writing to a common memory space. Proper synchronization is essential to prevent data conflicts.

### Example 1

- A child process writes "Hello" to shared memory.
- The parent process reads the message from shared memory.

OUTPUT:

![SS2](https://github.com/user-attachments/assets/94d4645a-7206-4cc0-ad9c-f7a5794dea89)


### Example 2

```
child --> writehello
parent --> read the message from child
```


![SS3](https://github.com/user-attachments/assets/137c86b4-0256-483f-ad02-b9f19c3b8e14)
