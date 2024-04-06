#ifndef INC_230427___FINAL_PROJECT_MAIN_H
#define INC_230427___FINAL_PROJECT_MAIN_H

// Create a struct(ure) to store student's information.
// Struct created here so all 3 files can use the same struct
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

void oldest(struct Student studentArr[], int number);

void youngest(struct Student studentArr[], int number);

#endif //INC_230427___FINAL_PROJECT_MAIN_H