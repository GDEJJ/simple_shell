#include <stdio.h>
#include <unistd.h>
#include<stdlib.h>
#include <string.h>
#include <sys/wait.h>

int main(void)
{
	int status;
	char *buffer = NULL;
	size_t bufsize = 0;
	char *args[] = {"/bin/ls", NULL};
	pid_t my_pid;

	while (1)
	{
		printf("$ ");
		getline(&buffer, &bufsize, stdin);

		my_pid = fork();
		if (my_pid == 0)
		{
			if (execve(args[0], args, NULL) == -1)
			{
				perror("error with command");
				printf("\n");
			}
			exit(EXIT_SUCCESS);
		}
		else
			wait(&status);
	}
	printf("\n");

	free(buffer);
	return (0);
}
