#include <stdio.h>

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
    struct Student {
    char studentID[10]; // 10 is a random number, chosen to be the maximum length of the student ID
    char fullName[50]; // Same with student ID array
    int birthDate;
    int birthMonth;
    int birthYear; // DoB needs to be separated for easier data process.
    float gradeAlg;
    float gradeCal;
    float gradeProg;
    float gradeAvg;
};

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
}