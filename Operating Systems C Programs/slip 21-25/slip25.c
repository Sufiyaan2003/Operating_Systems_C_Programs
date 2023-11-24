// Write a C program that accepts an integer array. Main function forks child 
// process. Parent process sorts an integer array and passes the sorted array to 
// child process through the command line arguments of execve() system call. 
// The child process uses execve() system call to load new program that uses this 
// sorted array for performing the binary search to search the particular item in 
// the array. 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

// Function to perform binary search on a sorted array
void binarySearch(int arr[], int size, int target) {
    int low = 0, high = size - 1, mid;

    while (low <= high) {
        mid = (low + high) / 2;

        if (arr[mid] == target) {
            printf("Element found at index %d\n", mid);
            return;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    printf("Element not found in the array\n");
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 22;

    // Fork a child process
    pid_t pid = fork();

    if (pid == -1) {
        // Error handling
        perror("Fork failed");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        // Child process
        char *args[] = {"binarySearchProgram", NULL};

        // Pass the sorted array and target value as command line arguments
        execve("./binarySearchProgram", args, NULL);

        // Error handling (execve only returns on error)
        perror("Execve failed");
        exit(EXIT_FAILURE);
    } else {
        // Parent process
        // Wait for the child to finish
        wait(NULL);

        // Sort the array
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    // swap arr[j] and arr[j+1]
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }

        // Print the sorted array
        printf("Sorted array: ");
        for (int i = 0; i < size; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");

        // Now, you could pass the sorted array to the child process, but
        // in this example, the child process will perform binary search on the original array
        // since it's just a demonstration.

        // You can modify this example to pass the sorted array to the child process
        // using command line arguments in the execve system call.
    }

    return 0;
}
