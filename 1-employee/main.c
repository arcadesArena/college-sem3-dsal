/*
Write a C program to create a sequential file with at least five records, each record having the structure shown below:
EMPLOYEE_ID : Non-Zero Positive integer
NAME        : 25 Characters
DEPARTMENT  : 25 Characters
SALARY      : Positive Integer
AGE         : Positive Integer
Write necessary functions to perform the following operations:
a) to display all the records in the file.
b) to search for a specific record based on EMPLOYEE_ID
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
    int emp_id,salary,age;
    char name[25],dept[25];
} EMPLOYEE;
EMPLOYEE e;
void add_record(FILE *fp){
    printf("\nEnter the details of the Employee:\n");
    printf("Employee ID:");
    scanf("%d",&e.emp_id);
    printf("NAME:");
    scanf("%s",e.name);
    printf("DEPARTMENT:");
    scanf("%s",e.dept);
    printf("SALARY:");
    scanf("%d",&e.salary);
    printf("AGE:");
    scanf("%d",&e.age);
    fprintf(fp,"%d\t\t %s\t\t %s\t\t %d\t\t%d\n",e.emp_id,e.name,e.dept,e.salary,e.age);
    printf("\nINFO: your record is saved successfully!\n");
}
void display_record(FILE *fp){
    printf("ID\tNAME\tDEPT\tSALARY\tAGE\n");
    while((fscanf(fp,"%d%s%s%d%d",&e.emp_id,e.name,e.dept,&e.salary,&e.age))!=EOF)
        printf("%d\t%s\t\t%s\t%d\t%d\n",e.emp_id,e.name,e.dept,e.salary,e.age);
}
void search(FILE *fp){
    int id,flag=0;
    printf("Enter the Employee ID to search:");
    scanf("%d",&id);
    while((fscanf(fp,"%d%s%s%d%d",&e.emp_id,e.name,e.dept,&e.salary,&e.age))!=EOF)
    {
        if(e.emp_id==id)
        {
            if(flag==0)
            {
                printf("ID\t NAME\tDEPT\tSALARY\tAGE\n");
                flag=1;
            }
            printf("%d\t%s\t%s\t%d\t%d\n",e.emp_id,e.name,e.dept,e.salary,e.age);
        }
    }
    if (flag==0)
        printf("INFO: no match found!\n");
}
int main(){
    FILE *fp;
    int choice;
    while(1)
    {
        printf("Enter your choice\n1.Add a Record\n2.Display the record\n3.Search a record\n4.Exit\n");
        printf("Enter your choice:\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            fp=fopen("file","a");
            add_record(fp);
            fclose(fp);
            break ;
        case 2:
            fp=fopen("file","r");
            display_record(fp);
            fclose(fp);
            break ;
        case 3:
            fp=fopen("file","r");
            search(fp);
            fclose(fp);
            break ;
        case 4:
            exit(0);
        default:
            printf("Please Enter a valid choice!\n");
        }
    }
    return 0;
}
