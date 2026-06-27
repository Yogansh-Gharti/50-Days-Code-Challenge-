#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student
{
    int roll;
    char name[50];
    float marks;
};

void addStudent()
{
    FILE *fp = fopen("students.dat", "ab");
    if (fp == NULL)
    {
        printf("Unable to open file.\n");
        return;
    }

    struct Student s;

    printf("\nEnter Roll Number: ");
    scanf("%d", &s.roll);

    printf("Enter Name: ");
    scanf(" %[^\n]", s.name);

    printf("Enter Marks: ");
    scanf("%f", &s.marks);

    fwrite(&s, sizeof(s), 1, fp);
    fclose(fp);

    printf("\nStudent Added Successfully.\n");
}

void displayStudents()
{
    FILE *fp = fopen("students.dat", "rb");

    if (fp == NULL)
    {
        printf("\nNo Records Found.\n");
        return;
    }

    struct Student s;

    printf("\n-------------------------------------\n");
    printf("Roll\tName\t\tMarks\n");
    printf("-------------------------------------\n");

    while (fread(&s, sizeof(s), 1, fp))
    {
        printf("%d\t%-15s%.2f\n", s.roll, s.name, s.marks);
    }

    printf("-------------------------------------\n");

    fclose(fp);
}

int main()
{
    int choice;

    while (1)
    {
        printf("\n===== STUDENT MANAGEMENT SYSTEM =====\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                addStudent();
                break;

            case 2:
                displayStudents();
                break;

            case 3:
                printf("Thank You!\n");
                return 0;

            default:
                printf("Invalid Choice.\n");
        }
    }

    return 0;
}
