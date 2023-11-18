#include <stdio.h>
#include <stdlib.h>

void main()
{
    int hit = 0, miss = 0, i, j, noPages, noFrames, min;
    int frames[10], pages[20];
    int flag = 0, flag1 = 0, flag2 = 0;
    int flagFound = 0;
    int count = 0;
    int frameAge[50], frameFREQ[50];

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

    for (j = 0; j < noFrames; j++)
        frameFREQ[j] = 0;

    for (j = 0; j < noPages; j++)
    {
        int index;
        printf(" page:%d   ", pages[j]);
        flagFound = 0, flag = 0, flag2 = 0;

        for (i = 0; i < noFrames; i++)
        {
            if (frames[i] == pages[j])
            {
                flagFound = 1;
                flag = 1;
                index = i;
                printf("hit ");

                hit++;

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

                    miss++;
                    frameFREQ[i] = 1;
                    printf("miss ");
                    break;
                }
            }

            if (flag == 0)
            {
                int bestmfu = 0;
                for (i = 0; i < noFrames; i++)
                {
                    if (frameFREQ[i] > frameFREQ[bestmfu])
                        bestmfu = i;
                }
                frames[bestmfu] = pages[j];
                miss++;
                printf("miss ");
                frameFREQ[bestmfu] = 1;
            }

        } // FLAG FOUND ends
        else
        {
            frameFREQ[index]++;
        }

        for (i = 0; i < noFrames; i++)
        {
            printf("   %d ", frames[i]);
        }
        printf("\n");
    }

    printf("number of hits %d\n", hit);
    printf("number of miss %d\n", miss);
}