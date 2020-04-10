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
