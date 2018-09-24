#include<bits/stdc++.h>

using namespace std;



//FCFS algorithm
class Process
{
public:

    int ID;
    int AT,BT,WT,TAT,CT;
};

bool compAT(Process a,Process b)
{
    return (a.AT<b.AT);
}

void FCFS()
{
    int numProcess;

    printf("Enter the number of process:");
    scanf("%d",&numProcess);

    Process P[numProcess];

    double sumT=0,sumW=0;
    sort(P+1,P+numProcess+1,compAT);
    P[1].CT=P[1].BT;
    P[1].TAT=P[1].CT-P[1].AT;
    P[1].WT=0;
    sumT+=P[1].TAT;
    sumW+=P[1].WT;
    for(int i=2;i<=numProcess;i++)
    {
        P[i].CT=P[i].BT+P[i-1].CT;
        P[i].TAT=P[i].CT-P[i].AT;
        P[i].WT=P[i].TAT-P[i].BT;
        sumT+=P[i].TAT;
        sumW+=P[i].WT;
    }

    printf("\nResults:\n");
    printf("P.ID\tAT\tBT\tCT\tTAT\tWT\tRT\n\n");
    for(int i=1;i<=numProcess;i++)
    {

        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",P[i].ID,P[i].AT,P[i].BT,P[i].CT,P[i].TAT,P[i].WT,P[i].WT);
        cout<<endl;
    }

    printf("\nAverage Turn Around Time : %.2lf\n",(sumT/numProcess));
    printf("\nAverage Waiting Time : %.2lf\n",(sumW/numProcess));
    printf("Exiting FCFS. . . . . \n");
    printf("\n");

}


void SJF()
{
    int burst_time[20],process[20],waiting_time[20],tat[20],i,j,n,total=0,pos,temp;
    float wait_avg,TAT_avg;
  cout<<"Enter number of process: ";
    cin>>n;

   cout<<"\nEnter Burst time: \n";
    for(i=0;i<n;i++)
    {
       cout<<"Process["<<i+1<<"]: ";
       cin>>burst_time[i];
        process[i]=i+1;           //Process Number
    }

//Sorting
       for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(burst_time[j]<burst_time[pos])
                pos=j;
        }

        temp=burst_time[i];
        burst_time[i]=burst_time[pos];
        burst_time[pos]=temp;

        temp=process[i];
        process[i]=process[pos];
        process[pos]=temp;
    }
  //First process has 0 waiting time
    waiting_time[0]=0;
    //calculate waiting time
    for(i=1;i<n;i++)
    {
        waiting_time[i]=0;
        for(j=0;j<i;j++)
            waiting_time[i]+=burst_time[j];

        total+=waiting_time[i];
    }
     //Calculating Average waiting time
    wait_avg=(float)total/n;
      total=0;

   cout<<"\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time";
    for(i=0;i<n;i++)
    {
        tat[i]=burst_time[i]+waiting_time[i]; //Calculating Turnaround Time
        total+=tat[i];
        cout<<"\n"<<process[i]<<"\t\t"<<burst_time[i]<<"\t\t"<<waiting_time[i]<<"\t\t"<<tat[i];
    }

 //Calculation of Average Turnaround Time
    TAT_avg=(float)total/n;
   cout<<"\n\nAverage Waiting Time: "<<wait_avg;
    cout<<"\nAverage Turnaround Time: "<<TAT_avg;

    cout<<"Exiting SJF . . . .. \n\n";
}


void RoundRobin()
{
      int i,j,n,time,remain,flag=0,time_quantum;
  int wait_time=0,turnaround_time=0,AT[10],bt[10],rt[10];
  printf("Enter Total Process:\t ");
  scanf("%d",&n);
  remain=n;
  for(i=0;i<n;i++)
  {
    printf("Enter Arrival Time and Burst Time for Process Process Number %d :",i+1);
    scanf("%d",&AT[i]);
    scanf("%d",&bt[i]);
    rt[i]=bt[i];
  }
  printf("Enter Time Quantum:\t");
  scanf("%d",&time_quantum);
  printf("\n\nProcess\t|Turnaround Time|Waiting Time\n\n");
  for(time=0,i=0;remain!=0;)
  {
    if(rt[i]<=time_quantum && rt[i]>0)
    {
      time+=rt[i];
      rt[i]=0;
      flag=1;
    }
    else if(rt[i]>0)
    {
      rt[i]-=time_quantum;
      time+=time_quantum;
    }
    if(rt[i]==0 && flag==1)
    {
      remain--;
      printf("P[%d]\t|\t%d\t|\t%d\n",i+1,time-AT[i],time-AT[i]-bt[i]);
      wait_time+=time-AT[i]-bt[i];
      turnaround_time+=time-AT[i];
      flag=0;
    }
    if(i==n-1)
      i=0;
    else if(AT[i+1]<=time)
      i++;
    else
      i=0;
  }
  printf("\nAverage Waiting Time= %f\n",wait_time*1.0/n);
  printf("Avg Turnaround Time = %f",turnaround_time*1.0/n);
  printf("Exiting Round Robin . . . . . \n");
}


void PriorityScheduling()
{
    int bt[20],p[20],wt[20],tat[20],pr[20],i,j,n,total=0,pos,temp,avg_wt,avg_tat;
    cout<<"Enter Total Number of Process:";
    cin>>n;

    cout<<"\nEnter Burst Time and Priority\n";
    for(i=0;i<n;i++)
    {
        cout<<"\nP["<<i+1<<"]\n";
        cout<<"Burst Time:";
        cin>>bt[i];
        cout<<"Priority:";
        cin>>pr[i];
        p[i]=i+1;           //contains process number
    }

    //sorting burst time, priority and process number in ascending order using selection sort
    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(pr[j]<pr[pos])
                pos=j;
        }

        temp=pr[i];
        pr[i]=pr[pos];
        pr[pos]=temp;

        temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;

        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    }

    wt[0]=0;            //waiting time for first process is zero

    //calculate waiting time
    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];

        total+=wt[i];
    }

    avg_wt=total/n;      //average waiting time
    total=0;

    cout<<"\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time";
    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];     //calculate turnaround time
        total+=tat[i];
        cout<<"\nP["<<p[i]<<"]\t\t  "<<bt[i]<<"\t\t    "<<wt[i]<<"\t\t\t"<<tat[i];
    }

    avg_tat=total/n;     //average turnaround time
    cout<<"\n\nAverage Waiting Time="<<avg_wt;
    cout<<"\nAverage Turnaround Time="<<avg_tat;
    printf("Exiting Priority Scheduling. . . . 'n");
}


int main()
{
    char choice;

    printf("This is a simple scheduling algorithms simulation and calculation\n");
    printf("*****************************************************************\n");


    while(1)
    {
        printf("Menu:\n");
        printf("A.First Come First Serve\n");
        printf("B.Shortest Job First\n");
        printf("C.Round Robin\n");
        printf("D.Priority Scheduling\n");

        printf("\nEnter your choice:");

        scanf("%c",&choice);
        fflush(stdin);

        switch(choice)
        {
        case 'A':
            {
                printf("Entering FCFS. . . . . \n");
                printf("\n");
                FCFS();
                break;
            }
        case 'B':
            {
                printf("Entering SJF. . . . . \n");
                printf("\n");
                SJF();
                break;
            }
        case 'C':
            {
                printf("Entering Round Robin. . . . \n");
                printf("\n");

            }
        case 'D':
            {
                printf("Entering Priority Scheduling. . . . . \n");
                printf("\n");
                PriorityScheduling();
                break;

            }
        }
    }
}
