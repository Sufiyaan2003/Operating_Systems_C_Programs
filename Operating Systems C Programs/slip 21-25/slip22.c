#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    pid_t pid;

    // Fork a child process
    pid = fork();

    if (pid < 0)
    {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0)
    {
        // This code will be executed by the child process
        // Print the process ID and set a higher priority using nice()
        printf("Child process ID: %d\n", getpid());
        int nice_val = nice(10); // Set a higher priority (lower nice value)
        if (nice_val == -1)
        {
            perror("Nice failed");
            exit(EXIT_FAILURE);
        }

        // Print the new nice value
        printf("Child process nice value: %d\n", nice_val);

        // Simulate some work in the child process
        printf("Child process is doing some work...\n");
        sleep(5);

        printf("Child process exiting.\n");
        exit(EXIT_SUCCESS);
    }
    else
    {
        // This code will be executed by the parent process
        // Wait for the child process to finish
        wait(NULL);

        // Print the process ID
        printf("Parent process ID: %d\n", getpid());

        // Parent process continues here
        printf("Parent process exiting.\n");
        exit(EXIT_SUCCESS);
    }

    return 0;
}