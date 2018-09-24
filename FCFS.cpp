#include<bits/stdc++.h>

using namespace std;


class Process
{
public:

    int ID;
    int AT,BT,WT,TAT,CT;
};

void FCFS(Process P[],int numProcess);
void SJF(Process P[],int numProcess);

bool compAT(Process a,Process b)
{
    return (a.AT<b.AT);
}

int main()
{
    int choice;

    int numProcess;
    printf("This is a simple CPU Scheduling Algorithm Program. Several Algorithms are tied uip here for testing\n");
    printf("And finding out the average Turn Around Time and Average Waiting Time.\n\n");

    string message="A.FCFS(Non Preemptive)\n B.SJF(Non Preemptive)\nC.Round Robin\nD.Priority Scheduling\n";
    cout<<message;
    while(1)
    {
        fflush(stdin);

        printf("\nEnter your choice:");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
            {
                printf("\nEnter the number of process:");
                scanf("%d",&numProcess);
                Process P[numProcess+1];
                for(int i=1;i<=numProcess;i++)
                {
                    printf("\tEnter process ID:");
                    scanf("%d",&P[i].ID);
                    printf("\tEnter AT:");
                    scanf("%d",&P[i].AT);
                    printf("\tEnter BT:");
                    scanf("%d",&P[i].BT);

                }
                FCFS(P,numProcess);
                break;
            }

        case 2:
        {
            printf("\nEnter the number of process:");
                scanf("%d",&numProcess);
                Process P[numProcess+1];
                for(int i=1;i<=numProcess;i++)
                {
                    printf("\tEnter process ID:");
                    scanf("%d",&P[i].ID);
                    printf("\tEnter AT:");
                    scanf("%d",&P[i].AT);
                    printf("\tEnter BT:");
                    scanf("%d",&P[i].BT);

                }
                SJF(P,numProcess);

                break;
        }

        default:
            {
                printf("Invalid Prompt. Please Try Again\n");
            }
        }
    }
    return 0;
}


void FCFS(Process P[],int numProcess)
{
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

}
