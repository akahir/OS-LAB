// Shortest Job First Scheduling_Preemptive

#include <stdio.h>

int main()
{
      int arrival_time[10], burst_time[10], temp[10];
      int i, smallest, count = 0, time, limit;
      double wait_time = 0, turnaround_time = 0, end;
      float avg_wt, avg_tat;
      printf("Enter the Total Number of Processes: ");
      scanf("%d", &limit);
      printf("Enter Details of %d Processes\n", limit);
      for(i = 0; i < limit; i++)
      {
            printf("\nEnter Arrival Time: ");
            scanf("%d", &arrival_time[i]);
            printf("Enter Burst Time: ");
            scanf("%d", &burst_time[i]);
            temp[i] = burst_time[i];
      }
      burst_time[9] = 9999;
      for(time = 0; count != limit; time++)
      {
            smallest = 9;
            for(i = 0; i < limit; i++)
            {
                  if(arrival_time[i] <= time && burst_time[i] < burst_time[smallest] && burst_time[i] > 0)
                  {
                        smallest = i;
                  }
            }
            burst_time[smallest]--;
            if(burst_time[smallest] == 0)
            {
                  count++;
                  end = time + 1;
                  wait_time = wait_time + end - arrival_time[smallest] - temp[smallest];
                  turnaround_time = turnaround_time + end - arrival_time[smallest];
            }
      }
      avg_wt = wait_time / limit;
      avg_tat= turnaround_time / limit;
    printf("\nAverage Waiting Time=%f",avg_wt);
    printf("\nAverage Turnaround Time=%f\n",avg_tat);
      return 0;
}
