// Write a C program to illustrate the concept of orphan process. Parent process. creates a child and terminates before child has finished its task. So child process becomes orphan process. (Use fork(), sleep(), getpid(), getppid()). 

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork(); // Create a child process

    if (pid < 0) {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    }

    if (pid > 0) {
        // This code is executed by the parent process
        printf("Parent process (PID: %d) is sleeping for 2 seconds and then terminating.\n", getpid());
        sleep(2);
        printf("Parent process is terminating.\n");
        exit(EXIT_SUCCESS);
    } else {
        // This code is executed by the child process
        printf("Child process (PID: %d) is doing some task and sleeping for 5 seconds.\n", getpid());
        sleep(5);
        printf("Child process is done with its task.\n");
        printf("Child process (PID: %d) is now an orphan process with PPID: %d.\n", getpid(), getppid());
        
    }

    return 0;
}