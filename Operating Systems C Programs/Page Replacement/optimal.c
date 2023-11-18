// optimal page replacement
#include <stdio.h>
#include <stdlib.h>

void main()
{
    int hit = 0, miss = 0, i, j, k, noPages, noFrames, max;
    int frames[10], pages[20], pos;
    int flag = 0, flag1 = 0, flag2 = 0, flag3 = 0;
    int flagFound = 0;
    int count = 0, temp[10];
    int frameAge[10];

    printf("enter number of frames\n");
    scanf("%d", &noFrames);
    printf("enter number of pages\n");
    scanf("%d", &noPages);

    printf("enter the page string ");
    for (i = 0; i < noPages; i++)
    {
        scanf("%d", &pages[i]);
    }

    for (i = 0; i < noFrames; i++)
    {
        frames[i] = -1;
        frameAge[i] = -1;
    }

    printf("\nPageNo    miss/hit              frames");
    printf("\n---------------------------------------------------\n");
    for (j = 0; j < noPages; j++)
    {
        printf("%3d       ", pages[j]);
        flagFound = 0, flag = 0, flag2 = 0;

        for (i = 0; i < noFrames; i++)
        {
            if (frames[i] == pages[j])
            {
                flagFound = 1;
                flag = 1;
                count++;
                frameAge[i] = count;
                // age frame
                hit++;
                printf("hit \t");
                break;
            }
        }

        if (flagFound == 0) // if frame not found and empty frame avalible
        {
            for (i = 0; i < noFrames; i++)
            {

                if (frames[i] == -1)
                {
                    frames[i] = pages[j];

                    flag = 1;
                    count++;
                    frameAge[i] = count;
                    printf("miss\t");
                    miss++;
                    break;
                }
            }
        }

        if (flag == 0)
        {
            flag3 = 0;

            for (i = 0; i < noFrames; i++)
            {
                temp[i] = -1;

                for (k = j + 1; k < noPages; k++) // checking in future
                {
                    if (frames[i] == pages[k])
                    {
                        temp[i] = k;
                        break;
                    }
                }
            }

            for (i = 0; i < noFrames; i++) // if element not present
            {
                if (temp[i] == -1)
                {
                    pos = i;
                    flag3 = 1;
                    break;
                }
            }

            if (flag3 == 0) // if all elements prrresent
            {
                max = temp[0];
                pos = 0;

                for (i = 1; i < noFrames; i++)
                {
                    if (temp[i] > max)
                    {
                        max = temp[i];
                        pos = i;
                    }
                }
            }

            frames[pos] = pages[j];
            count++;
            frameAge[pos] = count;
            miss++;
            printf("miss\t");
        }

        for (i = 0; i < noFrames; i++)
        {
            printf("   %3d ", frames[i]);
        }
        printf("\n");
    }

    printf("number of hits %d\n", hit);
    printf("number of miss %d\n", miss);
}
