#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100

struct Student {
    int id;
    char name[50];
    float gpa;
};

void showMenu();
void addStudent(struct Student students[], int *count);
void displayStudents(struct Student students[], int count);
void deleteStudent(struct Student students[], int *count, int id);
void updateStudent(struct Student students[], int count, int id);

int main() {
    struct Student students[MAX_STUDENTS];
    int count = 0;
    int choice, id;

    while (1) {
        showMenu();

        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            return 0;
        }

        switch (choice) {
            case 1:
                addStudent(students, &count);
                break;

            case 2:
                displayStudents(students, count);
                break;

            case 3:
                printf("Enter student ID to delete: ");
                scanf("%d", &id);
                deleteStudent(students, &count, id);
                break;

            case 4:
                printf("Enter student ID to update: ");
                scanf("%d", &id);
                updateStudent(students, count, id);
                break;

            case 5:
                printf("Exiting the program. Goodbye!\n");
                return 0;

            default:
                printf("Invalid choice. Please select a number from 1–5.\n");
        }
    }

    return 0;
}

void showMenu() {
    printf("\n=== Student Management System ===\n");
    printf("1. Add a student\n");
    printf("2. Display all students\n");
    printf("3. Delete a student by ID\n");
    printf("4. Update student details\n");
    printf("5. Exit\n");
    printf("=================================\n");
}

void addStudent(struct Student students[], int *count) {
    if (*count >= MAX_STUDENTS) {
        printf("Cannot add more students. List is full.\n");
        return;
    }

    struct Student newStudent;

    printf("Enter student ID: ");
    scanf("%d", &newStudent.id);

    // Check duplicate ID
    for (int i = 0; i < *count; i++) {
        if (students[i].id == newStudent.id) {
            printf("A student with this ID already exists.\n");
            return;
        }
    }

    printf("Enter student name: ");
    scanf(" %[^\n]s", newStudent.name);

    printf("Enter student GPA: ");
    scanf("%f", &newStudent.gpa);

    students[*count] = newStudent;
    (*count)++;

    printf("Student added successfully!\n");
}

void displayStudents(struct Student students[], int count) {
    if (count == 0) {
        printf("No students available.\n");
        return;
    }

    printf("\n--- Student List ---\n");
    printf("%-10s %-20s %s\n", "ID", "Name", "GPA");
    printf("----------------------------------------\n");

    for (int i = 0; i < count; i++) {
        printf("%-10d %-20s %.2f\n", students[i].id, students[i].name, students[i].gpa);
    }
}

void deleteStudent(struct Student students[], int *count, int id) {
    int index = -1;

    for (int i = 0; i < *count; i++) {
        if (students[i].id == id) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Student with ID %d not found.\n", id);
        return;
    }

    for (int i = index; i < *count - 1; i++) {
        students[i] = students[i + 1];
    }

    (*count)--;

    printf("Student with ID %d deleted successfully.\n", id);
}

void updateStudent(struct Student students[], int count, int id) {
    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            printf("Student found: %s (GPA: %.2f)\n", students[i].name, students[i].gpa);

            printf("Enter new ID: ");
            scanf("%d", &students[i].id);

            printf("Enter new name: ");
            scanf(" %[^\n]s", students[i].name);

            printf("Enter new GPA: ");
            scanf("%f", &students[i].gpa);

            printf("Student details updated successfully.\n");
            return;
        }
    }

    printf("Student with ID %d not found.\n", id);
}

