#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 50
#define MAX_STUDENTS 100

// Student structure
typedef struct {
    int id;
    char name[MAX_NAME];
    float grade;
} Student;

// Stack for undo operations
typedef struct {
    Student students[MAX_STUDENTS];
    int top;
} Stack;

Stack undoStack = {.top = -1};

// Function prototypes
void addStudent(Student students[], int *count);
void saveStudents(Student students[], int count);
void loadStudents(Student students[], int *count);
void displayStudents(Student students[], int count);
void pushUndo(Student s);
Student popUndo();
void deleteStudent(Student students[], int *count, int id);

int main() {
    Student students[MAX_STUDENTS];
    int count = 0, choice, id;
    loadStudents(students, &count);

    while (1) {
        printf("\nStudent Records Management\n");
        printf("1. Add Student\n2. Display Students\n3. Delete Student\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

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
                saveStudents(students, count);
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}

void addStudent(Student students[], int *count) {
    if (*count >= MAX_STUDENTS) {
        printf("Cannot add more students.\n");
        return;
    }
    Student s;
    printf("Enter ID: ");
    scanf("%d", &s.id);
    printf("Enter Name: ");
    scanf("%s", s.name);
    printf("Enter Grade: ");
    scanf("%f", &s.grade);

    students[*count] = s;
    (*count)++;
    pushUndo(s);
    printf("Student added successfully.\n");
}

void saveStudents(Student students[], int count) {
    FILE *file = fopen("students.dat", "wb");
    if (!file) {
        printf("Error saving file!\n");
        return;
    }
    fwrite(students, sizeof(Student), count, file);
    fclose(file);
}

void loadStudents(Student students[], int *count) {
    FILE *file = fopen("students.dat", "rb");
    if (!file) return;
    *count = fread(students, sizeof(Student), MAX_STUDENTS, file);
    fclose(file);
}

void displayStudents(Student students[], int count) {
    if (count == 0) {
        printf("No students available.\n");
        return;
    }
    printf("\n%-10s %-20s %-5s\n", "ID", "Name", "Grade");
    for (int i = 0; i < count; i++) {
        printf("%-10d %-20s %-5.2f\n", students[i].id, students[i].name, students[i].grade);
    }
}

void pushUndo(Student s) {
    if (undoStack.top >= MAX_STUDENTS - 1) return;
    undoStack.students[++undoStack.top] = s;
}

Student popUndo() {
    if (undoStack.top < 0) {
        Student empty = {0, "", 0.0};
        return empty;
    }
    return undoStack.students[undoStack.top--];
}

void deleteStudent(Student students[], int *count, int id) {
    int found = 0;
    for (int i = 0; i < *count; i++) {
        if (students[i].id == id) {
            pushUndo(students[i]);
            for (int j = i; j < *count - 1; j++) {
                students[j] = students[j + 1];
            }
            (*count)--;
            found = 1;
            break;
        }
    }
    if (found)
        printf("Student deleted successfully.\n");
    else
        printf("Student not found!\n");
}
