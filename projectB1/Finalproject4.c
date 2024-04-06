#include <stdio.h>
#include <string.h>

struct Student{
    char studentID[10];
    char firstName[50];
    char lastName[50];
    char birthdate[10];
    float algebra;
    float calculus;
    float basicprogramming;
    float gpa;
};

int main(){
    int numStudents;
    printf("Enter number of students : ");
    scanf("%d", &numStudents);

    struct Student ST[numStudents];
    // code to get student information
    for(int i = 0; i < numStudents; i++){
        printf("Enter information for student %d:\n", i + 1);
        printf("StudentID : ");
        scanf("%s", ST[i].studentID);
        printf("First Name : ");
        scanf("%s", ST[i].firstName);
        getchar();
        printf("Last Name :");
        fgets(ST[i].lastName, sizeof(ST[i].lastName), stdin);
        printf("Birthdate (dd/mm/yyyy) : ");
        scanf("%s", ST[i].birthdate);
        printf("Algebra Grade : ");
        scanf("%f", &ST[i].algebra);
        printf("Calculus Grade : ");
        scanf("%f", &ST[i].calculus);
        printf("Grade Basic Programming: ");
        scanf("%f", &ST[i].basicprogramming);
        // calculate GPA
        ST[i].gpa = (ST[i].algebra + ST[i].calculus + ST[i].basicprogramming) / 3;
    }

    // print table header and create file txt
    FILE *file = fopen("student_list.txt", "a");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    fprintf(file, "%-10s %-20s %-15s %-10s %-10s %-12s %-10s\n", "ID", "Name", "Birthdate", "Algebra", "Calculus", "Programming", "GPA");

    // print each student's information as a row in the table
    for (int i = 0; i < numStudents; i++){
        // remove newline character from last name
int len = strlen(ST[i].lastName);
if (ST[i].lastName[len - 1] == '\n') {
    ST[i].lastName[len - 1] = '\0';
}
       char fullName[100];
    sprintf(fullName, "%s %s", ST[i].lastName, ST[i].firstName);
    fprintf(file, "%-10s %-20s %-15s %-10.2f %-10.2f %-12.2f %-10.2f\n", ST[i].studentID, fullName, ST[i].birthdate, ST[i].algebra, ST[i].calculus, ST[i].basicprogramming, ST[i].gpa);
    }
    fclose(file);
    return 0;
}


