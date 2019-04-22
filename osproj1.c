#include<stdio.h>
#include<string.h>
typedef struct prc
{
	char id[20];
	int at,bt,ft,rbt;
}prc;
prc r[100],s[100],m[100];
int quantum_time,rc=0,sc=0,mc=0;

void input_fun(void);
void display_fun(void);

int main()
{
printf("*****************************WELCOME TO QUERY HANDLING PLATFORM***********************\n\n\n");
printf("\nAll time entered are in minutes\n");
printf("enter arrival time in ascending order\n\n");
int n;
input_fun();
display_fun();
return 0;	
}

void input_fun(void)
{
		int choice,i,t,n,rc=0;
		
	printf("Enter total no of queries: "); 
	scanf("%d", &n);
	if(n==0) 
	{ 
	printf("\n No queries\n"); 
	}
	else
	{
		printf("\nEnter quantum time for each Process: "); 
		scanf("%d", &quantum_time);
		for(i=0; i<n; i++){
			printf("\nfaculty queue/student queue (1/2): "); scanf("%d", &choice);
			if(choice==1)
			{
				printf("process Id: "); 
				scanf("%d", &r[rc].id);
				printf("Arrival Time: "); 
				scanf("%d", &t);
				if(t<1000 || t>1200){
					printf("\nenter correct time");
					input_fun();
				}
				else
				{
				r[rc].at= t-1000;
				}
				printf("burst Time: "); 
				scanf("%d", &r[rc].bt);	 
				r[rc].rbt= r[rc].bt; 
				rc++;
			} else
			{
				printf("process Id: "); 
				scanf("%d", &s[sc].id);
				printf("Arrival Time: "); 
				scanf("%d", &t); 
				if(t<1000 || t>1200)
				{
					printf("\nEnter Correct time\n");
					input();
				}
				else 
				{
				s[sc].at= t-1000; 
				}
				printf("burst Time: "); 
				scanf("%d", &s[sc].bt);	 
				s[sc].rbt= s[sc].bt;
				sc++;
			}
		}
	}
}
void display_fun(void)
{
	int i=0, total=0, s=0; 
	float avg;
	printf("\n******************PROCESS TABLE*******************\n");
	printf("\nQuery ID\tArrival Time\tburst Time\tCompletion Time\tTurn Around Time\tWaiting Time");
	for(i; i<mc; i++)
	{
		printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d",
		m[i].id, (m[i].at+1000), m[i].bt, (m[i].ft+1000), (m[i].ft-m[i].at), ((m[i].ft-m[i].at)- m[i].bt));
		total= m[i].ft;
		s+= (m[i].ft-m[i].at);
	}
	avg = s/mc;
	printf("\n\ntotal time for query handeling: %d",total);
	printf("\naverage query handing time: %lf", avg);
}
