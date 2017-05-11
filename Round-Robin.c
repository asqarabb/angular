#include<stdio.h>
#define N 10000
int main()
{

  int Count,j,n,time,remain,flag=0,time_quantum;
  int wait_time[N],turnaround_time[N],ArrivalTime[N],BurstTime[N],RemainTime[N];
  float avg_wait_time=0;
  float avg_turnaround_time=0;

  printf("Enter Total Process: ");
  scanf("%d",&n);
  remain=n;

    //For user test
/*  for(Count=0;Count<n;Count++)
  {
    printf("Enter Arrival Time and %d :",Count+1);
    scanf("%d",&ArrivalTime[Count]);
    printf("Burst Time for Process Process Number %d :",Count+1);
    scanf("%d",&BurstTime[Count]);
    RemainTime[Count]=BurstTime[Count];
  }*/
  //For random test
    for(Count=0;Count<n;Count++)
    {
        ArrivalTime[Count]=rand()%100;
        BurstTime[Count]=rand()%100;
        RemainTime[Count]=BurstTime[Count];
    }
      //sort base on Arrival Time
    for (Count=0;Count<n;Count++)
    {
        int j;
            for(j=Count;j<n;j++)
            {
                if (ArrivalTime[Count]==ArrivalTime[j])
                {
                    if (BurstTime[Count]>BurstTime[j])
                    {
                        int temp= ArrivalTime[j];
                        int temp2= BurstTime[j];
                        int temp3= RemainTime[j];
                        ArrivalTime[j]=ArrivalTime[Count];
                        BurstTime[j]=BurstTime[Count];
                        RemainTime[j]=RemainTime[Count];
                        ArrivalTime[Count]=temp;
                        BurstTime[Count]=temp2;
                        RemainTime[Count]=temp3;
                    }
                }
                else if (ArrivalTime[Count]>ArrivalTime[j])
                {
                        int temp= ArrivalTime[j];
                        int temp2= BurstTime[j];
                        int temp3= RemainTime[j];
                        ArrivalTime[j]=ArrivalTime[Count];
                        BurstTime[j]=BurstTime[Count];
                        RemainTime[j]=RemainTime[Count];
                        ArrivalTime[Count]=temp;
                        BurstTime[Count]=temp2;
                        RemainTime[Count]=temp3;

                }
            }
    }



 printf("Process Number\t Arrival Time\t Burst Time \n");
      for(Count=0;Count<n;Count++)
  {
    printf("\t%d\t\t%d\t\t%d\n",Count+1,ArrivalTime[Count],BurstTime[Count]);
  }

  printf("Enter Time Quantum:\t");
  scanf("%d",&time_quantum);
  for(time=0,Count=0;remain!=0;)
  {
    if((RemainTime[Count]<=time_quantum) &&( RemainTime[Count]>=0))
    {
      time+=RemainTime[Count];
      RemainTime[Count]=0;
       wait_time[Count]=time+ArrivalTime[0]-ArrivalTime[Count]-BurstTime[Count];
      turnaround_time[Count]=time-ArrivalTime[Count]+ArrivalTime[0];
      remain--;
    }
    else if(RemainTime[Count]>0)
    {
      RemainTime[Count]-=time_quantum;
      time+=time_quantum;
    }else if(RemainTime[Count]==0&&BurstTime[Count]==0){
       wait_time[Count]=time+ArrivalTime[0]-ArrivalTime[Count]-BurstTime[Count];
      turnaround_time[Count]=time-ArrivalTime[Count]+ArrivalTime[0];
      remain--;
      flag=1;
    }

    if(Count==n-1)
    {
        Count=0;
        }else if(ArrivalTime[Count+1]<=time)
    {
        Count++;
    }else{Count=0;}
    if(flag==1)
    {
        Count++;
    }

  }





 printf("Process Number\t Wating Time\t Turnaround Time \n");
      for(Count=0;Count<n;Count++)
  {
       avg_wait_time+=wait_time[Count];
      avg_turnaround_time+=turnaround_time[Count];
    printf("%d\t\t%f\t%f\n",Count+1,avg_wait_time,avg_turnaround_time);
  }

  printf("\nAverage Waiting Time= %f\n",avg_wait_time*1.0/n);
  printf("Avg Turnaround Time = %f",avg_turnaround_time*1.0/n);

  return 0;
}
