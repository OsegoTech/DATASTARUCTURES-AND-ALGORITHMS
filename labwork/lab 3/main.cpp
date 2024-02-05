#include <iostream>
#include <string>

// Class for Course
class Course {
public:
    std::string course_code;
    std::string course_name;
};

// Class for Grade
class Grade {
public:
    int mark;
    char the_grade;

    // Constructor to initialize grade attributes
    Grade() : mark(-1), the_grade('N') {}

    // Function to calculate grade based on the grading system
    void calculateGrade() {
        if (mark > 69)
            the_grade = 'A';
        else if (mark > 59)
            the_grade = 'B';
        else if (mark > 49)
            the_grade = 'C';
        else if (mark > 39)
            the_grade = 'D';
        else
            the_grade = 'E';
    }
};

// Class for Student
class Student {
public:
    std::string reg_number;
    std::string name;
    int age;
    Course course;
    Grade grade;
    bool grades_calculated;  // Flag to track whether grades are calculated

    // Constructor to initialize grades_calculated to false
    Student() : grades_calculated(false) {}

    // Function to add marks and calculate grades
    void addMarks() {
        if (grades_calculated) {
            std::cout << "Grades are already calculated and cannot be altered." << std::endl;
            return;
        }

        std::cout << "Enter marks: ";
        std::cin >> grade.mark;

        // Calculate grade based on the grading system
        grade.calculateGrade();
        grades_calculated = true;  // Set the flag to indicate grades are calculated

        std::cout << "Marks and grade added successfully!" << std::endl;
    }

    // Function to display details of a student including grades
    void displayStudentDetails() const {
        std::cout << "\nStudent Details:\n";
        std::cout << "Registration Number: " << reg_number << std::endl;
        std::cout << "Name: " << name << std::endl;
        std::cout << "Age: " << age << std::endl;
        std::cout << "Course Code: " << course.course_code << std::endl;
        std::cout << "Course Name: " << course.course_name << std::endl;

        // Check if grades are calculated
        if (grades_calculated) {
            std::cout << "Marks: " << grade.mark << std::endl;
            std::cout << "Grade: " << grade.the_grade << std::endl;
        } else {
            std::cout << "Grades not calculated yet." << std::endl;
        }
    }
};

int main() {
    Student students[40];
    int numStudents = 0;
    int choice;

    do {
        // Display menu
        std::cout << "\nMenu:\n";
        std::cout << "1. Add a student\n";
        std::cout << "2. Edit student details\n";
        std::cout << "3. Add marks and calculate grades\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                if (numStudents < 40) {
                    Student newStudent;

                    // Input details
                    std::cout << "Enter registration number: ";
                    std::cin >> newStudent.reg_number;

                    std::cout << "Enter name: ";
                    std::cin >> newStudent.name;

                    std::cout << "Enter age: ";
                    std::cin >> newStudent.age;

                    std::cout << "Enter course code: ";
                    std::cin >> newStudent.course.course_code;

                    std::cout << "Enter course name: ";
                    std::cin >> newStudent.course.course_name;

                    // Add the new student
                    students[numStudents] = newStudent;
                    numStudents++;

                    std::cout << "Student added successfully!" << std::endl;
                } else {
                    std::cout << "Maximum number of students reached!" << std::endl;
                }
                break;
            }
            case 2: {
                std::string regNumber;
                std::cout << "Enter registration number to edit: ";
                std::cin >> regNumber;

                for (int i = 0; i < numStudents; i++) {
                    if (students[i].reg_number == regNumber) {
                        std::cout << "Enter new age: ";
                        std::cin >> students[i].age;

                        std::cout << "Enter new course code: ";
                        std::cin >> students[i].course.course_code;

                        std::cout << "Enter new course name: ";
                        std::cin >> students[i].course.course_name;

                        std::cout << "Student details updated successfully!" << std::endl;
                        break;
                    }
                }
                std::cout << "Student not found!" << std::endl;
                break;
            }
            case 3: {
                std::string regNumber;
                std::cout << "Enter registration number to add marks: ";
                std::cin >> regNumber;

                for (int i = 0; i < numStudents; i++) {
                    if (students[i].reg_number == regNumber) {
                        students[i].addMarks();
                        break;
                    }
                }
                std::cout << "Student not found!" << std::endl;
                break;
            }
            case 4:
                std::cout << "Exiting program." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }

        // Display details of the added student
        if (choice == 1) {
            students[numStudents - 1].displayStudentDetails();
        }

    } while (choice != 4);

    return 0;
}
