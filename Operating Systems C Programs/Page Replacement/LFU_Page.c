#include <stdio.h>
#include <stdlib.h>

#define MAX_PAGES 100

int main() {
    int n, i, j, page_faults = 0;

    printf("Enter the number of frames: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid number of frames. Exiting...\n");
        return 1;
    }

    int frames[n], counters[n], reference[MAX_PAGES];

    printf("Enter the reference string size: ");
    int reference_size;
    scanf("%d", &reference_size);

    printf("Enter the reference string (space-separated): ");
    for (i = 0; i < reference_size; i++) {
        scanf("%d", &reference[i]);
    }

    for (i = 0; i < n; i++) {
        frames[i] = -1; // Initialize frames with -1 to indicate empty frame
        counters[i] = 0; // Initialize counters to 0
    }

    printf("\nPage Scheduling:\n");

    for (i = 0; i < reference_size; i++) {
        int page = reference[i];
        int page_found = 0;

        // Check if the page is already in a frame
        for (j = 0; j < n; j++) {
            if (frames[j] == page) {
                page_found = 1;
                counters[j]++;
                break;
            }
        }

        // If the page is not in a frame, perform page fault
        if (!page_found) {
            int min_count = counters[0];
            int min_index = 0;

            // Find the page with the least frequency
            for (j = 1; j < n; j++) {
                if (counters[j] < min_count) {
                    min_count = counters[j];
                    min_index = j;
                }
            }

            // Replace the page with the least frequency
            frames[min_index] = page;
            counters[min_index] = 1; // Reset frequency count to 1
            page_faults++;

            // Display page scheduling
            printf("Page %d loaded into frame %d\n", page, min_index);
        }
    }

    printf("\nTotal Page Faults: %d\n", page_faults);

    return 0;
}
