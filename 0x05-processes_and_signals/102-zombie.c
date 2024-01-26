#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * infinite_while - Function that runs indefinitely, retruns nothing
 * Return: in the end 0
*/
int infinite_while(void)
{
	while (1)
	{
		sleep(1);
	}
	return (0);
}

/**
 * main - entry to process that creates 5 zombie processes
 * Retrun: on success: 0
*/
int main(void)
{
	int child_prcss = 0;
	pid_t pid;

	while (child_prcss < 5)
	{
		pid = fork();
		if (!pid)
			break;
		printf("Zombie process created, PID: %i\n", (int)pid);
		child_prcss++;
	}
	if (pid != 0)
		infinite_while();
	return (0);
}
