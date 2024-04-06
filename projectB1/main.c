#include <stdio.h>
#include "main.h"

// For task 5
// Each function takes the array of students into the input and process from that array
void maxAvg(struct Student studentArr[], int number) {
    int max = 0; // Take the first student as the default value
    for (int i = 1; i < number; i++) { // Skip the first student
        if (studentArr[i].gradeAvg > studentArr[max].gradeAvg)
            max = i;
    }

    printf("\nStudent(s) with highest GPA (%.1f): ", studentArr[max].gradeAvg);
    printf("%s (%s)", studentArr[max].fullName, studentArr[max].studentID);
    // Prints out student at index max first

    // Loop beginning after index max to find other students with the same GPA
    for (int i = max + 1; i < number; i++) {
        if (studentArr[i].gradeAvg == studentArr[max].gradeAvg)
            printf(", %s (%s)", studentArr[i].fullName, studentArr[i].studentID);
    }
};

void minAvg(struct Student studentArr[], int number) {
    int min = 0; // Take the first student as the default value
    for (int i = 1; i < number; i++) { // Skip the first student
        if (studentArr[i].gradeAvg < studentArr[min].gradeAvg)
            min = i;
    }

    printf("\nStudent(s) with lowest GPA (%.1f): ", studentArr[min].gradeAvg);
    printf("%s (%s)", studentArr[min].fullName, studentArr[min].studentID);
    // Prints out student at index min first

    // Loop beginning after index min to find other students with the same GPA
    for (int i = min + 1; i < number; i++) {
        if (studentArr[i].gradeAvg == studentArr[min].gradeAvg)
            printf(", %s (%s)", studentArr[i].fullName, studentArr[i].studentID);
    }
};

void maxProg(struct Student studentArr[], int number) {
    int max = 0; // Take the first student as the default value
    for (int i = 1; i < number; i++) {
        if (studentArr[i].gradeProg > studentArr[max].gradeProg)
            max = i;
    }

    printf("\nStudent(s) with highest Basic Programming final result (%.1f): ", studentArr[max].gradeProg);
    printf("%s (%s)", studentArr[max].fullName, studentArr[max].studentID);
    // Prints out student at index max first

    // Loop beginning after index max to find other students with the same GPA
    for (int i = max + 1; i < number; i++) {
        if (studentArr[i].gradeProg == studentArr[max].gradeProg)
            printf(", %s (%s)", studentArr[i].fullName, studentArr[i].studentID);
    }
};

// Main programme
int main() {
// Task 1
    int number = 0;
    printf("Enter number of students (Up to 1000): ");
    scanf("%d", &number);

    // Check to see if the number of students are in the range 1 - 1000
    // If not, print out "Invalid" and require user to type in a valid input
    // Repeat until 'number' is valid.
    while (number > 1000 || number < 1) {
        printf("Invalid.\n");
        printf("Enter number of students (Up to 1000): ");
        scanf("%d", &number);
    }

// Task 2
    // Create an array with the data type 'struct Student'
    // Each element of the array will have the properties define in 'struct Student'
    struct Student studentArr[number];

    // Enter data for each student from 0 to (number-1) (Because that's how array elements are counted)
    // Use a 'for' loop from 0 to before number
    for (int i = 0; i < number; i++) {
        printf("\nStudent No.%d\n", i + 1);

        printf("Student ID: ");
        scanf("%s", studentArr[i].studentID);
        fflush(stdin);
        // Removing the fflush will skip name input, idk why this has to be put here either, it just works

        printf("Full name: ");
        scanf("%[0-9A-Za-z ]s", studentArr[i].fullName);
        // Works similarly to %s, but also accepts white spaces
        // Check out regex for better understanding

        printf("Date of Birth (dd/mm/yyyy): ");
        scanf("%d/%d/%d", &studentArr[i].birthDate, &studentArr[i].birthMonth, &studentArr[i].birthYear);
        // Check if DoB is a valid date or not
        while (studentArr[i].birthDate > 31 || studentArr[i].birthDate < 0
               || studentArr[i].birthMonth < 0 || studentArr[i].birthMonth > 12) {
            printf("Invalid Date of Birth\n");
            printf("Date of Birth (dd/mm/yyyy): ");
            scanf("%d/%d/%d", &studentArr[i].birthDate, &studentArr[i].birthMonth, &studentArr[i].birthYear);
        }

        printf("Linear Algebra result: ");
        scanf("%f", &studentArr[i].gradeAlg);
        while (studentArr[i].gradeAlg > 20 || studentArr[i].gradeAlg < 0) {
            printf("Invalid value\n");
            printf("Linear Algebra result: ");
            scanf("%f", &studentArr[i].gradeAlg);
        }

        printf("Calculus result: ");
        scanf("%f", &studentArr[i].gradeCal);
        while (studentArr[i].gradeCal > 20 || studentArr[i].gradeCal < 0) {
            printf("Invalid value\n");
            printf("Calculus result: ");
            scanf("%f", &studentArr[i].gradeCal);
        }

        printf("Basic Programming result: ");
        scanf("%f", &studentArr[i].gradeProg);
        while (studentArr[i].gradeProg > 20 || studentArr[i].gradeProg < 0) {
            printf("Invalid value\n");
            printf("Basic Programming result: ");
            scanf("%f", &studentArr[i].gradeProg);
        }

        studentArr[i].gradeAvg = (studentArr[i].gradeAlg + studentArr[i].gradeCal + studentArr[i].gradeProg) / 3;
    }

// Task 3
    printf("\n------------------------------------------------------------------------------------------------------");
    printf("\n| Student ID |                 Full Name                |     DoB    | L.Alg |  Cal  | BProg |  Avg  |");
    printf("\n------------------------------------------------------------------------------------------------------");
    for (int i = 0; i < number; i++) {
        printf("\n| %-10s | %-40s | %s%d/%s%d/%d | %-5.1f | %-5.1f | %-5.1f | %-5.1f |",
               studentArr[i].studentID, studentArr[i].fullName,
               (studentArr[i].birthDate >= 10) ? "" : "0", studentArr[i].birthDate,
                // If birthDate only has 1 digit, then add a 0 to it. Same with birthMonth.
               (studentArr[i].birthMonth >= 10) ? "" : "0", studentArr[i].birthMonth, studentArr[i].birthYear,
               studentArr[i].gradeAlg, studentArr[i].gradeCal, studentArr[i].gradeProg, studentArr[i].gradeAvg);
        printf("\n------------------------------------------------------------------------------------------------------");
    }

// Task 4
    FILE *fptr;
    fptr = fopen("StudentInfo.txt", "w");
    fprintf(fptr,
            "------------------------------------------------------------------------------------------------------");
    fprintf(fptr,
            "\n| Student ID |                 Full Name                |     DoB    | L.Alg |  Cal  | BProg |  Avg  |");
    fprintf(fptr,
            "\n------------------------------------------------------------------------------------------------------");
    for (int i = 0; i < number; i++) {
        fprintf(fptr, "\n| %-10s | %-40s | %s%d/%s%d/%d | %-5.1f | %-5.1f | %-5.1f | %-5.1f |",
                studentArr[i].studentID, studentArr[i].fullName,
                (studentArr[i].birthDate >= 10) ? "" : "0", studentArr[i].birthDate,
                // If birthDate only has 1 digit, then add a 0 to it. Same with birthMonth.
                (studentArr[i].birthMonth >= 10) ? "" : "0", studentArr[i].birthMonth, studentArr[i].birthYear,
                studentArr[i].gradeAlg, studentArr[i].gradeCal, studentArr[i].gradeProg, studentArr[i].gradeAvg);
        fprintf(fptr,
                "\n------------------------------------------------------------------------------------------------------");
    }
    fclose(fptr);

// Task 5
    maxAvg(studentArr, number);
    minAvg(studentArr, number);
    maxProg(studentArr, number);

// Task 7
    oldest(studentArr, number);

// Task 8
    youngest(studentArr, number);
}