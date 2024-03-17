#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct book {
    int id;
    char title[50];
    char author[20];
    char category[20];
    long ISBN;
    char publisher[20];
    int quantity;
    int availability;
    float price;
};

typedef struct book Book;

int main() {
    FILE *fp;
    fp = fopen("./newfile.txt", "w+");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    Book b1 = {123, "C prog", "Anonymous", "programming", 1234567891234, "ASUS", 10, 5, 15.99};
    Book b12 = {1, "12 C prog", "Anonymous 12", "programming 12", 1234567891234, "ASUS 12", 10, 5, 17.99};
    fprintf(stdout, "Enter data:\n");
    Book b123;
    fscanf(stdin, "%d %s %s %s %ld %d %d %f", &(b123.id), b123.title, b123.author, b123.category, &(b123.ISBN), &(b123.quantity), &(b123.availability), &(b123.price));
    fwrite(&b123, sizeof(Book), 1, fp);
    fwrite(&b1, sizeof(Book), 1, fp);
    fwrite(&b12, sizeof(Book), 1, fp);

    fclose(fp);

    fp = fopen("./newfile.txt", "r");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    while (fread(&b1, sizeof(Book), 1, fp) == 1) {
        printf("%d %s %s %s %ld %d %d $%.2f\n", b1.id, b1.title, b1.author, b1.category, b1.ISBN, b1.quantity, b1.availability, b1.price);
    }

    fclose(fp);
    return 0;
}
