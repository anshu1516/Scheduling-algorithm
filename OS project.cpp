#include<stdio.h>
struct student
{
    int StudentId;
    int FoodTakenTime;
    int WaitingTime;
    int TurnAroundTime;
};
void get(struct student list[], int a);
void show(struct student list[], int b);
void scheduling(struct student list[], int c);
void waitingTime(struct student list[], int d);
void turnAroundTime(struct student list[], int e);

int main()
{
    struct student data[30];
    int p;
    char f='A';
    do
	{
    printf("Please enter the number of students who wants to eat in mess: ");
    scanf("%d", &p);
    get(data, p);
    scheduling(data, p);
    waitingTime(data,p);
    turnAroundTime(data,p);
    show(data, p);
    printf("If you want to continue then press 'A': ");
    scanf("%s",&f);
    if(f=='A')
    {
    	printf("\nYou can continue further\n");
	}
	else
	{
		printf("\nYou cannot proceed further\n");
	}
    }
	while(f=='A');
    return 0;
} 

void get(struct student list[100], int a)
{
    int i;
    for (i = 0; i < a; i++)
    {
        printf("\n\nEnter information of students %d", i + 1);
        
        printf("\nEnter Student id : ");
        scanf("%d", &list[i].StudentId);

        printf("Enter time taken for eating food in minutes: ");
        scanf("%d", &list[i].FoodTakenTime);
    } 
}
void scheduling(struct student list[100], int c)
{
    int i, j;
    struct student temp;
    
    for (i = 0; i < c - 1; i++)
    {
        for (j = 0; j < (c - 1-i); j++)
        {
            if (list[j].FoodTakenTime < list[j + 1].FoodTakenTime)
            {
                temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            } 
            else if(list[j].FoodTakenTime == list[j + 1].FoodTakenTime)
            {
            	if(list[j].StudentId > list[j + 1].StudentId)
            	{
            	temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
                }
			}
        }
    }
}

void waitingTime(struct student list[100], int d)
{
	int j;
    list[0].WaitingTime=0;
    for(j=1;j<d;j++)
    {
        list[j].WaitingTime=list[j-1].WaitingTime+list[j-1].FoodTakenTime;
    }
}


void turnAroundTime(struct student list[100], int e)
{
	int j;
    
    for(j=0;j<e;j++)
    {
        list[j].TurnAroundTime=list[j].WaitingTime+list[j].FoodTakenTime;
    }
}
void show(struct student list[100], int b)
{
    int i,AvgWaitingTime=0,AvgTurnAroundTime=0;
	int TotalWatingTime=0,TotalTurnAroundTime=0;
    printf("\n\nAccording to LRTF output is:\n");
    printf("\n|---------------------------------------------------------------|");
    printf("\n|Student id\tFoodTakenTime\tWaitingTime\tTurnAroundTime  |");
    printf("\n|---------------------------------------------------------------|");    
    for (i = 0; i < b; i++)
    {
        printf("\n| %d\t\t   %d\t\t   %d\t\t   %d\t\t|", list[i].StudentId, list[i].FoodTakenTime,list[i].WaitingTime,list[i].TurnAroundTime);
        printf("\a\n|---------------------------------------------------------------|");
		TotalWatingTime= TotalWatingTime+list[i].WaitingTime;
		TotalTurnAroundTime= TotalTurnAroundTime+list[i].TurnAroundTime;
	} 
	printf("\n\nTotal Waiting Time is: = %d",TotalWatingTime);
	printf("\nTotal Turn around Time is: = %d",TotalTurnAroundTime);
	printf("\nAverage Waiting Time is: = %d",TotalWatingTime/b);
	printf("\nAverage Turn around Time is: = %d\n\n",TotalTurnAroundTime/b);
}
