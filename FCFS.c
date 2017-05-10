#include <stdio.h>
#include <stdlib.h>
#define N 100
int main()
{
  int Count,j,n;
  int ArrivalTime[N],BurstTime[N],RemainTime[N];
  float wait_time=0;
  printf("Enter Total Process: ");
  scanf("%d",&n);
    //For handel test
  for(Count=0;Count<n;Count++)
  {
    printf("Enter Arrival Time and %d :",Count+1);
    scanf("%d",&ArrivalTime[Count]);
    printf("Burst Time for Process Process Number %d :",Count+1);
    scanf("%d",&BurstTime[Count]);
  }
  //For random test
/*    for(Count=0;Count<n;Count++)
    {
        ArrivalTime[Count]=rand()%10000;
        BurstTime[Count]=rand()%10000;
        RemainTime[Count]=BurstTime[Count];
    }*/
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
                        ArrivalTime[j]=ArrivalTime[Count];
                        BurstTime[j]=BurstTime[Count];
                        ArrivalTime[Count]=temp;
                        BurstTime[Count]=temp2;
                    }
                }
                else if (ArrivalTime[Count]>ArrivalTime[j])
                {
                    int temp= ArrivalTime[j];
                    int temp2= BurstTime[j];
                    ArrivalTime[j]=ArrivalTime[Count];
                    BurstTime[j]=BurstTime[Count];
                    ArrivalTime[Count]=temp;
                    BurstTime[Count]=temp2;

                }
            }
    }
    for(Count=0;Count<n;Count++)
    {
      if(Count==0)
           {RemainTime[Count]=0;}
      else {
        int x=ArrivalTime[Count-1]+BurstTime[Count-1]-ArrivalTime[Count];
      if (x<0)
        {x=0;wait_time=x;}
      else
        {wait_time+=x;}
        RemainTime[Count]=wait_time;
      }

      printf("the wating time for process:%d is:%f\n",Count+1,wait_time);
    }
    wait_time=0;
    for(Count=0;Count<n;Count++)
    {wait_time+=RemainTime[Count];printf("b");}
    printf("the wating time is:%f",wait_time/n);


}
