#include <stdio.h>
#include <string.h>

#define MAX 100

struct Patient
{
    char name[50];
    int age;
    char disease[50];
    int priority;
};

struct Patient p[MAX];
int count = 0;

void addPatient()
{
    if(count==MAX)
    {
        printf("\nHospital Database Full!\n");
        return;
    }

    printf("\nEnter Name : ");
    scanf(" %[^\n]",p[count].name);

    printf("Enter Age : ");
    scanf("%d",&p[count].age);

    printf("Enter Disease : ");
    scanf(" %[^\n]",p[count].disease);

    printf("Enter Priority (1-5) : ");
    scanf("%d",&p[count].priority);

    count++;

    printf("\nPatient Added Successfully.\n");
}

void servePatient()
{
    if(count==0)
    {
        printf("\nNo Patients Available.\n");
        return;
    }

    int highest = 0;

    for(int i=1;i<count;i++)
    {
        if(p[i].priority < p[highest].priority)
        {
            highest = i;
        }
    }

    printf("\nServing Patient...\n");
    printf("----------------------------\n");
    printf("Name     : %s\n",p[highest].name);
    printf("Age      : %d\n",p[highest].age);
    printf("Disease  : %s\n",p[highest].disease);
    printf("Priority : %d\n",p[highest].priority);

    for(int i=highest;i<count-1;i++)
    {
        p[i]=p[i+1];
    }

    count--;
}

void displayPatients()
{
    if(count==0)
    {
        printf("\nNo Patients Found.\n");
        return;
    }

    printf("\n-------------------------------\n");

    for(int i=0;i<count;i++)
    {
        printf("\nPatient %d\n",i+1);
        printf("Name : %s\n",p[i].name);
        printf("Age : %d\n",p[i].age);
        printf("Disease : %s\n",p[i].disease);
        printf("Priority : %d\n",p[i].priority);
    }
}

int main()
{
    int choice;

    while(1)
    {
        printf("\n========= HOSPITAL MANAGEMENT =========\n");
        printf("1. Add Patient\n");
        printf("2. Serve Highest Priority Patient\n");
        printf("3. Display Patients\n");
        printf("4. Exit\n");

        printf("\nEnter Choice : ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                addPatient();
                break;

            case 2:
                servePatient();
                break;

            case 3:
                displayPatients();
                break;

            case 4:
                printf("\nThank You!\n");
                return 0;

            default:
                printf("\nInvalid Choice\n");
        }
    }

    return 0;
}
