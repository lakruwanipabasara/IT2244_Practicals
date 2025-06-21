Q1 --> Write a C program that creates two threds. Each thread should print a message indicating it is running. 
       The main thread should wait for both threads to finish before exiting. 

Q2 --> Write a C program that creates 5 threds. Each thread should print its thread ID and then exit. 
       The main thread should join all threads and print a completion message.

Q3 --> Write a C program that creates a threds whitch prints numbers from 1 to 10 with a 1-second delay between each number. 
       The main thread should wait for this threads to finish.

Q4 --> Create two threads here one thread increments a global counter 100 times and the other thread decrements the same counter 100 times. 
       Print the final value of the counter after both threads finish.

Q5 --> Implement a thread function that takes an integer argument, squares it, and returns the result to the main thread using pthread_exit and pthread_join.



//Q1

CODE :

#include <stdio.h>
#include <pthread.h>

void* thread_func(void* arg) {
    printf("Thread %d is running.\n", *(int*)arg);
    return NULL;
}

int main() {
    pthread_t t1, t2;
    int id1 = 1, id2 = 2;

    pthread_create(&t1, NULL, thread_func, &id1);
    pthread_create(&t2, NULL, thread_func, &id2);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Main thread: both threads have finished.\n");
    return 0;
}





OUTPUT:

/*
vi Qthread1.c
gcc Qthread1.c -o Qthread1
./Qthread1
*/


---------------------------------------------------------------------------------------------------------------------

//Q2

CODE :

#include <stdio.h>
#include <pthread.h>

void* show_id(void* arg) {
    pthread_t tid = pthread_self();
    printf("Thread ID: %lu\n", tid);
    return NULL;
}

int main() {
    pthread_t threads[5];

    for (int i = 0; i < 5; i++) {
        pthread_create(&threads[i], NULL, show_id, NULL);
    }

    for (int i = 0; i < 5; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("All 5 threads have completed.\n");
    return 0;
}



OUTPUT:

/*
vi Qthread2.c
gcc Qthread2.c -o Qthread2
./Qthread2
*/



---------------------------------------------------------------------------------------------------------------------

//Q3

CODE :

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void* print_numbers(void* arg) {
    for (int i = 1; i <= 10; i++) {
        printf("%d\n", i);
        sleep(1);
    }
    return NULL;
}

int main() {
    pthread_t t;
    pthread_create(&t, NULL, print_numbers, NULL);
    pthread_join(t, NULL);
    printf("Finished printing numbers.\n");
    return 0;
}



OUTPUT:

/*
vi Qthread3.c
gcc Qthread3.c -o Qthread3
./Qthread3
*/

---------------------------------------------------------------------------------------------------------------------

//Q4

CODE :

#include <stdio.h>
#include <pthread.h>

int counter = 0;
pthread_mutex_t lock;

void* increment(void* arg) {
    for (int i = 0; i < 100; i++) {
        pthread_mutex_lock(&lock);
        counter++;
        pthread_mutex_unlock(&lock);
    }
    return NULL;
}

void* decrement(void* arg) {
    for (int i = 0; i < 100; i++) {
        pthread_mutex_lock(&lock);
        counter--;
        pthread_mutex_unlock(&lock);
    }
    return NULL;
}

int main() {
    pthread_t t1, t2;
    pthread_mutex_init(&lock, NULL);

    pthread_create(&t1, NULL, increment, NULL);
    pthread_create(&t2, NULL, decrement, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    pthread_mutex_destroy(&lock);

    printf("Final counter value: %d\n", counter);
    return 0;
}



OUTPUT:

/*
vi Qthread4.c
gcc Qthread4.c -o Qthread4
./Qthread4
*/


---------------------------------------------------------------------------------------------------------------------

//Q5

CODE :

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* square(void* arg) {
    int num = *(int*)arg;
    int* result = malloc(sizeof(int));
    *result = num * num;
    pthread_exit(result);
}

int main() {
    pthread_t t;
    int value = 7;
    int* result;

    pthread_create(&t, NULL, square, &value);
    pthread_join(t, (void**)&result);

    printf("Square of %d is %d\n", value, *result);
    free(result);
    return 0;
}



OUTPUT:

/*
vi Qthread5.c
gcc Qthread5.c -o Qthread5
./Qthread5
*/

