#include<stdio.h>
#define N 10000
int main()
{

  int Count,j,n,time,remain,flag=0,time_quantum;
  int wait_time=0,turnaround_time=0,ArrivalTime[N],BurstTime[N],RemainTime[N];
  printf("Enter Total Process: ");
  scanf("%d",&n);
  remain=n;

    //For user test
  for(Count=0;Count<n;Count++)
  {
    printf("Enter Arrival Time and %d :",Count+1);
    scanf("%d",&ArrivalTime[Count]);
    printf("Burst Time for Process Process Number %d :",Count+1);
    scanf("%d",&BurstTime[Count]);
    RemainTime[Count]=BurstTime[Count];
  }
  //For random test
   /* for(Count=0;Count<n;Count++)
    {
        ArrivalTime[Count]=rand()%10;
        BurstTime[Count]=rand()%10;
        RemainTime[Count]=BurstTime[Count];
    }*/
  printf("Enter Time Quantum:\t");
  scanf("%d",&time_quantum);
  printf("\n\nProcess\t|Turnaround Time|Waiting Time\n\n");
  for(time=0,Count=0;remain!=0;)
  {
    if(RemainTime[Count]<=time_quantum && RemainTime[Count]>0)
    {
      time+=RemainTime[Count];
      RemainTime[Count]=0;
      flag=1;
    }
    else if(RemainTime[Count]>0)
    {
      RemainTime[Count]-=time_quantum;
      time+=time_quantum;
    }
    if(RemainTime[Count]==0 && flag==1)
    {
      remain--;
      printf("P[%d]\t|\t%d\t|\t%d\n",Count+1,time-ArrivalTime[Count],time-ArrivalTime[Count]-BurstTime[Count]);
      wait_time+=time-ArrivalTime[Count]-BurstTime[Count];
      turnaround_time+=time-ArrivalTime[Count];
      flag=0;
    }
    if(Count==n-1)
      Count=0;
    else if(ArrivalTime[Count+1]<=time)
      Count++;
    else
      Count=0;
  }
  printf("\nAverage Waiting Time= %f\n",wait_time*1.0/n);
  printf("Avg Turnaround Time = %f",turnaround_time*1.0/n);

  return 0;
}
