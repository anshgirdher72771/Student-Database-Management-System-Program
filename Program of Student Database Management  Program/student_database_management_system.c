#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
typedef struct student_database_system
{
    char Name[25];
    int Regn_id;
    char Grade[3];
    char Attendance[10];
} database;
char *attendance(int N);
void print_star();

int main()
{
    printf("                                                                Welcome To Our Student Database Management System                                    ");
    printf("                                                                                                 Made By Ansh Girdher                                              \n");
    FILE *ptr;
    ptr = fopen("Student_database_management_system.txt", "a");
    int n;
    start:
    printf("\nHow many students do you want to submit data : ");
    scanf("%d", &n);
    database *students = (database *)malloc(n * sizeof(database));
    if (students == NULL)
    {
        printf("Memory allocation failed. Exiting...\n");
        return 1;
    }
    for (int i = 0; i < n; i++)
    {
        printf("Enter a Name of the %d Student : ", i + 1);
        fflush(stdin);
        gets(students[i].Name);
        printf("Enter a Registration Id of the %d Student : ", i + 1);
        fflush(stdin);
        scanf("%d", &students[i].Regn_id);
        printf("Enter a Grade of the %d Student : ", i + 1);
        fflush(stdin);
        gets(students[i].Grade);
        int N;
        printf("If this student is 'Promoted', type 1 or if demoted, type 0 : ");
        fflush(stdin);
        scanf("%d", &N);
        fflush(stdin);
        strcpy(students[i].Attendance, attendance(N));
        fflush(stdin);
        print_star();
    }
    for (int i = 0; i < n; i++)
    {
        fprintf(ptr,"\n");
        fprintf(ptr, "    Name            :- %s\n", students[i].Name);
        fprintf(ptr, "Registration Id     :- %d\n", students[i].Regn_id);
        fprintf(ptr, "   Grade            :- %s\n", students[i].Grade);
        fprintf(ptr, " Attendance         :- %s\n", students[i].Attendance);
        fprintf(ptr, "****************************************************************************************************");
    }
    printf("\nData written to student_database_management_system.txt successfully.\n");
int start_end;
    printf("\nIf you want to exit, type '0'or to start, type '1' : ");
    scanf("%d",&start_end);
    if (start_end==0)
    {
        goto exit;
        
    }
    else if (start_end==1)
    {
       goto start;
    }
    fclose(ptr);
    free(students);
    exit:
    printf("\n");
    printf("                                                                          Great!Thanks for using our Program                                           ");

    getch();
    return 0;
}
char *attendance(int N)
{
    static char str[] = "Promoted";
    static char str1[] = "Demoted";
    if (N == 1)
    {
        return str;
    }
    else if (N == 0)
    {
        return str1;
    }
    return NULL; // Return NULL if N is neither 0 nor 1
}
void print_star()
{
    for (int i = 0; i < 80; i++)
    {
        printf("*");
    }
    printf("\n");
}