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
