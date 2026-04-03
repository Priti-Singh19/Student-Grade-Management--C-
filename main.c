#include <stdio.h>
#include <stdbool.h>

struct Student {
    char name[50];
    int roll;
    float marks[6];
    float total;
    float percentage;
    char grade;
    bool isPass;
};

void calculate(struct Student *s) {
    s->total = 0;

    float min = s->marks[0];
    for (int i = 0; i < 6; i++) {
        if (s->marks[i] < min) {
            min = s->marks[i];
        }
        s->total += s->marks[i];
    }

    s->total -= min;              // Remove lowest subject
    s->percentage = s->total / 5.0;

    if (s->percentage >= 90)
        s->grade = 'A';
    else if (s->percentage >= 75)
        s->grade = 'B';
    else if (s->percentage >= 60)
        s->grade = 'C';
    else if (s->percentage >= 45)
        s->grade = 'D';
    else
        s->grade = 'F';

    if (s->grade == 'F')
        s->isPass = false;
    else
        s->isPass = true;
}

void display(struct Student s) {
    printf("\nName: %s", s.name);
    printf("\nRoll No: %d", s.roll);
    printf("\nTotal Marks: %.2f", s.total);
    printf("\nPercentage: %.2f%%", s.percentage);
    printf("\nGrade: %c", s.grade);

    printf("\nStatus: ");
    s.isPass ? printf("Pass\n") : printf("Fail\n");
}

int main() {
    struct Student students[100];
    int choice, count = 0;

    while (1) {
        printf("\n===== STUDENT GRADE SYSTEM =====");
        printf("\n1. Add Student");
        printf("\n2. Display All Students");
        printf("\n3. Search Student by Roll");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("\nEnter Student Name: ");
            scanf("%s", students[count].name);

            printf("Enter Roll Number: ");
            scanf("%d", &students[count].roll);

            printf("Enter marks of 6 subjects:\n");
            char subjects[6][20] = {"Physics", "Maths", "Chemistry", "Hindi", "English", "Music"};

            for (int i = 0; i < 6; i++) {
                printf("%s: ", subjects[i]);
                scanf("%f", &students[count].marks[i]);
            }

            calculate(&students[count]);
            count++;
            printf("\n✔ Student Added Successfully!\n");
        }

        else if (choice == 2) {
            if (count == 0) {
                printf("\nNo students found!\n");
            } else {
                for (int i = 0; i < count; i++) {
                    printf("\n----- Student %d -----", i + 1);
                    display(students[i]);
                }
            }
        }

        else if (choice == 3) {
            int roll, found = 0;

            printf("\nEnter Roll Number to Search: ");
            scanf("%d", &roll);

            for (int i = 0; i < count; i++) {
                if (students[i].roll == roll) {
                    printf("\n===== Student Found =====");
                    display(students[i]);
                    found = 1;
                    break;
                }
            }

            if (!found)
                printf("\n❌ Student Not Found!\n");
        }

        else if (choice == 4) {
            printf("\nExiting...");
            break;
        }

        else {
            printf("\nInvalid choice! Try again\n");
        }
    }

    return 0;
}
