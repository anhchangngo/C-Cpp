#include <stdio.h>
#include "main.h"

void oldest(struct Student studentArr[], int number) {
    int result = 0; // Default to first student in the array

    for (int i = 1; i < number; i++) { // Skip the first student in the array
        if (studentArr[i].birthYear < studentArr[result].birthYear) // Smaller birthYear -> Older
            result = i;
        else if (studentArr[i].birthYear == studentArr[result].birthYear) {
            // Same birthYear -> Move onto birthMonth
            if (studentArr[i].birthMonth < studentArr[result].birthMonth)
                result = i;
            else if (studentArr[i].birthMonth == studentArr[result].birthMonth)
				// Same birthMonth -> Move onto birthDate
                if (studentArr[i].birthDate < studentArr[result].birthDate)
                    result = i;
					/* No need to consider the case of same birthDate, as this means both have the same birthday,
					and this is already taken into account below */
        }
    }

    // This programme takes into account the case where there are people having the same birthday
    // If the oldest student shares a birthday with another student in the array, result will store the value of the
    // smallest index (the student who appear first in the array)

    printf("\nOldest student(s) (born on %d/%d/%d): %s (%s)",
           studentArr[result].birthDate, studentArr[result].birthMonth, studentArr[result].birthYear,
           studentArr[result].fullName, studentArr[result].studentID);
    // Print out the student at index 'result'

    for (int i = result + 1; i < number; i++) {
        // Starts after result,
        // as it can be safely assumed that the students with index before result do not share the same birthday
        if (studentArr[i].birthYear == studentArr[result].birthYear &&
            studentArr[i].birthMonth == studentArr[result].birthMonth &&
            studentArr[i].birthDate == studentArr[result].birthDate)
            printf(", %s (%s)", studentArr[i].fullName, studentArr[i].studentID);
    }
}