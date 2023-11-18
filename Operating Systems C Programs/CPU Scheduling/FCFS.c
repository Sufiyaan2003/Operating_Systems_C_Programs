#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define max 30
void main()
{

    //Declarations and User Input for process, burst time and arrival time
    int i,j,n,bt[max],at[max],wt[max],tat[max],temp[max];
    float awt=0,atat=0;
    printf("Enter the number of process:");
    scanf("%d",&n);
    printf("Enter the burst time:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&bt[i]);
    }
    printf("Enter the arrival time:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&at[i]);
    }
    temp[0]=0;


    //Gantt Chart
    printf("\nGantt Chart:\n");
    for (i = 0; i < n; i++) {
        printf("| P%d ", i + 1);
    }
    printf("|\n");


    //Output and Calculations
    printf("Process\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\n");
    for(i=0;i<n;i++)
    {
        wt[i]=0;
        tat[i]=0;
        temp[i+1]=temp[i]+bt[i];
        wt[i]=temp[i]-at[i];
        tat[i]=wt[i]+bt[i];
        awt=awt+wt[i];
        atat=atat+tat[i];
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n",i+1,bt[i],at[i],wt[i],tat[i]);
    }
    awt = awt/n;
    atat = atat/n;
    printf("Average Waiting Time = %f\n",awt);
    printf("Average Turnaround Time = %f\n",atat);
    
}
