//Write a C program that:
//01.Prompts the user to enter an integer number.

//02.Creates three child processes using fork():
//Child 1 (C1): Calculates and prints the factorial of the entered number.
//Child 2 (C2): Calculates and prints 2 raised to the power of the entered number.
//Child 3 (C3): Calculates and prints the square of the entered number.

//03.Each child should also print its parent process ID.

//04.The parent process should:
//Print its own process ID.
//Wait for all three child processes to complete before terminating.




#include<stdio.h>
#include<unistd.h>
#include <sys/wait.h>
int main()
{
	int num;
	printf("Enter a number:");
	scanf("\n%d",&num);
	
	int f1=fork();
	if(f1==0)
	{
		printf("\nC1");
		printf("\nParent Id:%d",getppid());
		int factorial=1;
		for(int i=1;i<=num;i++)
		{
			factorial=factorial*i;
		}
		printf("\nFactorial of first number:%d",factorial);
		
	}
	
	else
	{
		printf("\nP");
		printf("\n Id:%d",getpid());
		
		int f2=fork();
		if(f2==0)
		{
			printf("\nC2");
		    printf("\nParent Id:%d",getppid());
			int power = 1;
            for (int i = 0; i < num; i++) {
                power *= 2;
            }
            printf("2 raised to the power %d: %d\n", num, power);

			
		}
		
		else
		{
			int f3=fork();
			if(f3==0)
			{
			printf("\nC3");
		    printf("\nParent Id:%d",getppid());
			int square = num * num;
            printf("Square of %d (calculated by c3): %d\n", num, square);
			}
			
			else
			{
				printf("Parent P (PID %d)\n", getpid());

                
                wait(NULL);
                wait(NULL);
                wait(NULL);
			}
		}
	}
	
	
}
