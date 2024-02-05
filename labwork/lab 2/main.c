#include <stdio.h>
#include <string.h>

// Structure for Course
struct Course {
    char course_code[10];
    char course_name[50];
};

// Structure for Grade
struct Grade {
    int mark;
    char the_grade;
};

// Structure for Student
struct Student {
    char reg_number[20];
    char name[50];
    int age;
    struct Course course;
    struct Grade grade;
    int grades_calculated;  // Flag to track whether grades are calculated
};

// Function to calculate grade based on the grading system
char calculateGrade(int mark) {
    if (mark > 69)
        return 'A';
    else if (mark > 59)
        return 'B';
    else if (mark > 49)
        return 'C';
    else if (mark > 39)
        return 'D';
    else
        return 'E';
}

// Function to add a student
void addStudent(struct Student students[], int* numStudents) {
    if (*numStudents < 40) {
        struct Student newStudent;

        // Input details
        printf("Enter registration number: ");
        scanf("%s", newStudent.reg_number);

        printf("Enter name: ");
        scanf("%s", newStudent.name);

        printf("Enter age: ");
        scanf("%d", &newStudent.age);

        printf("Enter course code: ");
        scanf("%s", newStudent.course.course_code);

        printf("Enter course name: ");
        scanf("%s", newStudent.course.course_name);

        // Initialize grade to default values
        newStudent.grade.mark = -1;
        newStudent.grade.the_grade = 'N';
        newStudent.grades_calculated = 0;  // Grades not calculated initially

        // Add the new student
        students[*numStudents] = newStudent;
        (*numStudents)++;



        printf("Student added successfully!\n");
    } else {
        printf("Maximum number of students reached!\n");
    }
}

// Function to edit a student's details
void editStudent(struct Student students[], int numStudents) {
    char regNumber[20];
    printf("Enter registration number to edit: ");
    scanf("%s", regNumber);

    for (int i = 0; i < numStudents; i++) {
        if (strcmp(students[i].reg_number, regNumber) == 0) {
            printf("Enter new age: ");
            scanf("%d", &students[i].age);

            printf("Enter new course code: ");
            scanf("%s", students[i].course.course_code);

            printf("Enter new course name: ");
            scanf("%s", students[i].course.course_name);

            printf("Student details updated successfully!\n");
            return;
        }
    }

    printf("Student not found!\n");
}

// Function to add marks and calculate grades
void addMarks(struct Student students[], int numStudents) {
    char regNumber[20];
    printf("Enter registration number to add marks: ");
    scanf("%s", regNumber);

    for (int i = 0; i < numStudents; i++) {
        if (strcmp(students[i].reg_number, regNumber) == 0) {
            if (students[i].grades_calculated) {
                printf("Grades are already calculated and cannot be altered.\n");
                return;
            }

            printf("Enter marks: ");
            scanf("%d", &students[i].grade.mark);

            // Calculate grade based on the grading system
            students[i].grade.the_grade = calculateGrade(students[i].grade.mark);
            students[i].grades_calculated = 1;  // Set the flag to indicate grades are calculated

            printf("Marks and grade added successfully!\n");
            return;
        }
    }

    printf("Student not found!\n");
}
void displayStudentDetails(struct Student student)
{
    printf("\nStudent Details:\n");
    printf("Registration Number: %s\n", student.reg_number);
    printf("Name: %s\n", student.name);
    printf("Age: %d\n", student.age);
    printf("Course Code: %s\n", student.course.course_code);
    printf("Course Name: %s\n", student.course.course_name);

    // Check if grades are calculated
    if (student.grades_calculated) {
        printf("Marks: %d\n", student.grade.mark);
        printf("Grade: %c\n", student.grade.the_grade);
    } else {
        printf("Grades not calculated yet.\n");
    }
}

int main() {
    struct Student students[40];
    int numStudents = 0;
    int choice;

    do {
        // Display menu
        printf("\nMenu:\n");
        printf("1. Add a student\n");
        printf("2. Edit student details\n");
        printf("3. Add marks and calculate grades\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(students, &numStudents);
                break;
            case 2:
                editStudent(students, numStudents);
                break;
            case 3:
                addMarks(students, numStudents);
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    displayStudentDetails(students[numStudents - 1]);

    return 0;
}
