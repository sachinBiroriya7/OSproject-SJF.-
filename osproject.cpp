#include<stdio.h>
struct process
{
    int pno;
    int process_arrival;
    int process_burst;

};
struct result
{
    int final_pno;
    int waiting_time;
    int turnaround_time;
};
int main()
{
	struct process obj[30];
	struct result res[30];
	int i,n,j,pos,min,pro_exec,time=0,end,k,flag,ideal_time,sumwait=0,sumturn=0;
	printf("Enter the no. of processes-");
	scanf("%d",&n);

	for(i=1;i<=n;i++)
	{
		printf("\n\nPROCESS P%d\n",i);
		obj[i].pno=i;
		X:printf("Arrival Time-");
		scanf("%d",&obj[i].process_arrival);
		if(obj[i].process_arrival<0)
     		{
       		     printf("\noops! arrival time can't be 0\n");
         	     goto X;
        	}
		Y:printf("Burst Time-");
		scanf("%d",&obj[i].process_burst);
		if(obj[i].process_burst<=0)
        	{
            	     printf("\noops! burst time can't be 0\n");
                     goto Y;
		}
	}
	time!=0;
	for(i=1;i<=n;i++)
	{
		if(obj[i].process_arrival==0)
        {
            printf("Process- %d Discared Error!",i);
            for(j=i;j<n;j++)
            {
                obj[j]=obj[j+1];
            }
            time=obj[1].process_arrival;
            n--;
            i--;
        }
        if(obj[i].process_arrival<time )
        {
            time=obj[i].process_arrival;
        }
	}
	end = n;
	min=0;
	k=1;
	while(n>0)
	{
	    pro_exec=obj[1].process_burst;
	    ideal_time=time+1;
	    flag=0;
		for(j=1;j<=n;j++)
		{

			if(pro_exec>=obj[j].process_burst && obj[j].process_arrival<=time)
			{
				pro_exec = obj[j].process_burst;
				pos=j;
				flag=1;
			}
			if(ideal_time>time && ideal_time>obj[j].process_arrival && obj[j].process_arrival!=time)
            {
                ideal_time=obj[j].process_arrival;
            }
		}
		if(flag==1)
        {
            if(pos==1)
            {
                res[k].waiting_time=time-obj[pos].process_arrival;
                time = time + pro_exec;
                res[k].turnaround_time=time-obj[pos].process_arrival;
            }
            else
            {
                res[k].waiting_time=time-obj[pos].process_arrival+2;
                time = time + pro_exec;
                res[k].turnaround_time=time-obj[pos].process_arrival+2;
            }
            res[k].final_pno=obj[pos].pno;
            for(i=pos;i<n;i++)
            {
               obj[i]=obj[i+1];
            }
            n--;
            k++;

        }
        else //IDEAL TIME FOR CPU
        {
            time = ideal_time;
        }

        }
       // RESULT OF ALL PROCESSES
        printf("\n\n\nPROCESS     WAITING TIME      TURNAROUND TIME");
        for(i=1;i<=end;i++)
        {
            printf("\nP%d            %d                   %d",res[i].final_pno,res[i].waiting_time,res[i].turnaround_time);
		sumwait=sumwait+res[i].waiting_time;
		sumturn=sumturn+res[i].turnaround_time;
        }
	 printf("\n\nTotal time taken to compute all the process is -   %d \n",time);
	 printf("Average waiting time = %d\nAverage turnaround time = %d",sumwait/end,sumturn/end);
    return 0;
}
