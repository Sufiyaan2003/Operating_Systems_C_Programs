#include <stdio.h>
int main()
{
    int i, j, n, ref_string[50], frame[10], no, k, avail, count = 0;

    /*n is the number of pages.
    //ref_string is an array that stores the reference string.
    //frame is an array that stores the current set of frames.
    //no is the number of frames.
    //count is the number of page faults.
    //avail is a flag used to check whether a page is already present in the current set of frames. If avail is 1, the page is already in a frame; if it's 0, the page is not in any frame, and a page fault will occur.*/

    printf("\n ENTER THE NUMBER OF PAGES:\n");
    scanf("%d", &n);
    printf("\n ENTER THE PAGE NUMBER :\n");
    for (i = 1; i <= n; i++)
        scanf("%d", &ref_string[i]);
    printf("\n ENTER THE NUMBER OF FRAMES :");
    scanf("%d", &no);
    for (i = 0; i < no; i++)
        frame[i] = -1;
    j = 0;
    printf("\tref string\t page frames\n");
    for (i = 1; i <= n; i++)
    {
        printf("%d\t\t", ref_string[i]);
        avail = 0;
        for (k = 0; k < no; k++)
            if (frame[k] == ref_string[i])
                avail = 1;
        if (avail == 0)
        {
            frame[j] = ref_string[i];
            j = (j + 1) % no;
            count++;
            for (k = 0; k < no; k++)
                printf("%d\t", frame[k]);
        }
        printf("\n");
    }
    printf("Page Fault Is %d", count);
    return 0;
}
