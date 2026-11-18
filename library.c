#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 9

typedef struct {
    const char *title;
    const char *subject;
} Book;

typedef struct {
    const char *username;
    const char *password;
    const char *subject;
} Student;

static const Book books[MAX_BOOKS] = {
    {"Fundamentals of Physics", "Physics"},
    {"Concepts of Modern Physics", "Physics"},
    {"Physics for Scientists and Engineers", "Physics"},
    {"Organic Chemistry", "Chemistry"},
    {"Principles of Chemistry", "Chemistry"},
    {"Inorganic Chemistry", "Chemistry"},
    {"Algebra and Trigonometry", "Maths"},
    {"Calculus: Early Transcendentals", "Maths"},
    {"Discrete Mathematics", "Maths"}
};

static const Student students[] = {
    {"physics", "physics123", "Physics"},
    {"chemistry", "chemistry123", "Chemistry"},
    {"maths", "maths123", "Maths"}
};

static void show_books(const char *subject, int is_admin)
{
    int found = 0;

    puts("\nAvailable books:");
    for (int i = 0; i < MAX_BOOKS; i++) {
        if (is_admin || strcmp(books[i].subject, subject) == 0) {
            printf("- %s (%s)\n", books[i].title, books[i].subject);
            found = 1;
        }
    }

    if (!found)
        puts("No books found for your subject.");
}

int main(void)
{
    char username[50];
    char password[50];
    int is_admin = 0;
    const char *student_subject = NULL;

    puts("=== Library Management System ===");
    printf("Username: ");
    if (scanf("%49s", username) != 1)
        return 1;

    printf("Password: ");
    if (scanf("%49s", password) != 1)
        return 1;

    if (strcmp(username, "admin") == 0 &&
        strcmp(password, "admin123") == 0) {
        is_admin = 1;
        puts("\nAdmin login successful.");
    } else {
        for (size_t i = 0; i < sizeof(students) / sizeof(students[0]); i++) {
            if (strcmp(username, students[i].username) == 0 &&
                strcmp(password, students[i].password) == 0) {
                student_subject = students[i].subject;
                break;
            }
        }

        if (student_subject == NULL) {
            puts("\nInvalid username or password.");
            return 1;
        }

        printf("\n%s student login successful.\n", student_subject);
    }

    show_books(student_subject, is_admin);
    return 0;
}
