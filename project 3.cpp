#include <stdio.h>
#include <string.h>

#define students 10
#define subjects 5

struct Student
 {
    int roll;
    char name[30];
    int marks[5];
    int total;
    float average;
};

int main()
{
    struct Student s[10], temp;
    int i, j;
    int maxmarks[5];
    char topname[5][30];

    for (i = 0; i < 10; i++)
    {
        printf("\nEnter details of student %d\n", i + 1);
        printf("Roll No: ");
        scanf("%d", &s[i].roll);

        printf("Name: ");
        scanf("%s", s[i].name);

        s[i].total = 0;
        for (j = 0; j < 5; j++) 
        {
            printf("Enter marks of subject %d: ", j + 1);
            scanf("%d", &s[i].marks[j]);
            s[i].total =s[i].total+s[i].marks[j];
        }
        s[i].average = s[i].total / 5.0;
    }


    printf("\n\n-------------------- RESULT SYSTEM --------------------\n");
    printf("Roll\tName\tS1\tS2\tS3\tS4\tS5\tTotal\tAvg\n");

    for (i = 0; i < 10; i++)
     {
        printf("%d\t%s\t", s[i].roll, s[i].name);
        for (j = 0; j < 5; j++)
            printf("%d\t", s[i].marks[j]);
        printf("%d\t%.2f\n", s[i].total, s[i].average);
    }

    for (i = 0; i < 10- 1; i++)
    {
        for (j = i + 1; j < 10; j++)
        {
            if (s[i].average < s[j].average)
            {
                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }
    printf("\n-------------------- TOP 3 RANK STUDENTS --------------------\n");
    printf("Rank\tRoll\tName\tAverage\n");
    for (i = 0; i < 3; i++)
     {
        printf("%d\t%d\t%s\t%.2f\n", i + 1, s[i].roll, s[i].name, s[i].average);
    }
    for (j = 0; j < 5; j++)
    {
        maxmarks[j] = s[0].marks[j];
        strcpy(topname[j], s[0].name);

        for (i = 1; i < 10; i++)
        {
            if (s[i].marks[j] > maxmarks[j])
            {
                maxmarks[j] = s[i].marks[j];
                strcpy(topname[j], s[i].name);
            }
        }
    }

    printf("\n-------------------- SUBJECT TOPPERS --------------------\n");
    for (j = 0; j < 5; j++)
     {
        printf("Subject %d: %s (%d marks)\n",j + 1, topname[j], maxmarks[j]);
               
     }

    return 0;
}