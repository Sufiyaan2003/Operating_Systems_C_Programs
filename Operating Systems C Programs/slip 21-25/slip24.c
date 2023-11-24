// Write a C program to accept n integers to be sorted. Main function 
// creates child process using fork system call. Parent process sorts the integers 
// using bubble sort and waits for child process using wait system call. Child 
// process sorts the integers using insertion sort. 

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

// Function prototypes
void bubbleSort(int arr[], int n);
void insertionSort(int arr[], int n);

int main() {
    int n;

    // Accept the number of integers
    printf("Enter the number of integers: ");
    scanf("%d", &n);

    int arr[n];

    // Accept the integers
    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Create a child process
    pid_t pid = fork();

    if (pid < 0) {
        // Error in fork
        fprintf(stderr, "Fork failed\n");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // Child process
        printf("Child process sorting using Insertion Sort.\n");
        insertionSort(arr, n);
        printf("Sorted array in child process:\n");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    } else {
        // Parent process
        wait(NULL); // Wait for the child process to complete
        printf("Parent process sorting using Bubble Sort.\n");
        bubbleSort(arr, n);
        printf("Sorted array in parent process:\n");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }

    return 0;
}

// Function to perform Bubble Sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to perform Insertion Sort
void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        // Move elements of arr[0..i-1] that are greater than key to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
