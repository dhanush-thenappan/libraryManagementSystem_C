#ifndef LIBRARYMANAGEMENTSYSTEM_H
// Defining LIBRARYMANAGEMENTSYSTEM_H only once
#define LIBRARYMANAGEMENTSYSTEM_H
// Macros
#define MAXBORROWLIMIT 2
// Structure definitions
struct book{
    int id; // ID
    char title[50]; // Title
    char author[20]; // Author
    char category[20]; // Category
    int ISBN; // ISBN
    char publisher[20]; // Publisher
    int quantity; // Quantity
    int availability; // Availability
    float price; // Price
};

struct user{
    char userName[20]; // Name
    char borrowedBooks[MAXBORROWLIMIT][20]; // Name of books borrowed
    int dueDates[MAXBORROWLIMIT]; // Due dates of the books borrowed
    int fineAmount; // Fine amount
};

// Type definitions
typedef struct book Book;
typedef struct user User;

// Function declarations
void greetUser(void);

#endif