#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define max 30
void main()
{
    //user inputs and declaration
    int i,j,n,temp,p[max],at[max],bt[max],wt[max],tat[max];
    float awt=0,atat=0;
    printf("Enter the number of process:");
    scanf("%d",&n);
    printf("Enter the process number : ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&p[i]);
    }
    printf("Enter the arrival time for each process:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&at[i]);
    }
    printf("Enter the burst time for each process:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&bt[i]);
    }

    //applying bubble sort to sort the process based on burst time
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(bt[j]>bt[j+1])
            {
                //swapping the burst time
                temp=bt[j];
                bt[j]=bt[j+1];
                bt[j+1]=temp;

                //swapping the arrival time
                temp=at[j];
                at[j]=at[j+1];
                at[j+1]=temp;

                //swapping the process id
                temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
        }
    }

    //Gantt Chart
    printf("\nGantt Chart:\n");
    for (i = 0; i < n; i++) {
        printf("| P%d ", i + 1);
    }
    printf("|\n");
    printf("\n");

    //calculations and output
    printf("process \t arrival time \t burst time \t waiting time \t turn around time\n");
    for(i=0;i<n;i++)
    {
        wt[i]=0;
        tat[i]=0;
        for(j=0;j<i;j++)
        {
            wt[i]=wt[i]+bt[j];
        }
        tat[i]=wt[i]+bt[i];
        awt=awt+wt[i];
        atat=atat+tat[i];
        printf("%d\t\t %d\t\t %d\t\t %d\t\t %d\n",p[i],at[i],bt[i],wt[i],tat[i]);
    }
    
    awt=awt/n;
    atat=atat/n;
    printf("Average waiting time=%f \n",awt);
    printf("Average turn around time=%f \n",atat);
}