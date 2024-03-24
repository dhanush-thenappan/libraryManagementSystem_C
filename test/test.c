#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct book {
    int id; // ID
    char title[50]; // Title
    char author[20]; // Author
    char category[20]; // Category
    long ISBN; // ISBN
    char publisher[20]; // Publisher
    int quantity; // Quantity
    int availability; // Availability
    float price; // Price
};

typedef struct book Book;

int printAllBooks(FILE *booklist){
    rewind(booklist);
    Book *temp = (Book*)malloc(sizeof(Book));
    int i=0;
    while(fread(temp, sizeof(Book), 1, booklist)){
        temp->author[strlen(temp->author)-1] = '\0';
        temp->category[strlen(temp->category)-1] = '\0';
        temp->publisher[strlen(temp->publisher)-1] = '\0';
        printf("%d ID %d Title %s Author %s Category %s ISBN %ld Publisher %s Quantity %d Availability %d Price $%.2f\n", i++, temp->id, temp->title, temp->author, temp->category, temp->ISBN, temp->publisher, temp->quantity, temp->availability, temp->price);
    }
    return 0;
}

void updateBook(FILE *booklist) {
    char updateStr[20];
    printf("| Enter title of the book to update\n");
    printf("| Enter here : ");
    fgets(updateStr, sizeof(updateStr), stdin);
    updateStr[strcspn(updateStr, "\n")] = '\0';
    rewind(booklist);
    Book tempbook;
    long pos;
    int tempID = -1; // Initialize tempID to an invalid value
    while (fread(&tempbook, sizeof(Book), 1, booklist)) {
        pos = ftell(booklist) - sizeof(Book); // Record the position of the current record
        if ((strstr(tempbook.title, updateStr) != NULL)) {
            // printf("ID %d Title %s Author %s Category %s ISBN %ld Publisher %s Quantity %d Availability %d Price $%.2f\n", tempbook.id, tempbook.title, tempbook.author, tempbook.category, tempbook.ISBN, tempbook.publisher, tempbook.quantity, tempbook.availability, tempbook.price);
            char choice;
            printf("\e[1;1H\e[2J");
            UpdateChoiceTypeCheck:
            printf("ID %d Title %s Author %s Category %s ISBN %ld Publisher %s Quantity %d Availability %d Price $%.2f\n", tempbook.id, tempbook.title, tempbook.author, tempbook.category, tempbook.ISBN, tempbook.publisher, tempbook.quantity, tempbook.availability, tempbook.price);
            printf("| Choose which one to update\n| [I]D\n| [T]itle\n| [A]uthor\n| [C]ategory\n| I[S]BN\n| [P]ublisher\n| [Q]uantity\n| A[v]ailability\n| P[r]ice\nYour option : ");
            scanf(" %c", &choice);
            getchar(); // Consume newline
            if(choice >= 97 && choice <= 123){
                choice = choice - 32;
            }
            switch (choice) {
                case 'I':
                    printf("| Enter the new ID to update : ");
                    scanf("%d", &(tempbook.id));
                    fseek(booklist, pos, SEEK_SET); // Move file pointer to the position of the current record
                    fwrite(&tempbook, sizeof(Book), 1, booklist);
                    tempID = tempbook.id; // Update tempID with the ID of the updated book
                    break;
                case 'T':
                    printf("| Enter the new title to update : ");
                    fgets(tempbook.title, sizeof(tempbook.title), stdin);
                    tempbook.title[strcspn(tempbook.title, "\n")] = '\0'; // Remove newline
                    fseek(booklist, pos, SEEK_SET); // Move file pointer to the position of the current record
                    fwrite(&tempbook, sizeof(Book), 1, booklist);
                    break;
                case 'A':
                    printf("| Enter the new author name to update : ");
                    fgets(tempbook.author, sizeof(tempbook.author), stdin);
                    tempbook.author[strcspn(tempbook.author, "\n")] = '\0'; // Remove newline
                    fseek(booklist, pos, SEEK_SET); // Move file pointer to the position of the current record
                    fwrite(&tempbook, sizeof(Book), 1, booklist);
                    break;
                case 'C':
                    printf("| Enter the new category to update : ");
                    fgets(tempbook.category, sizeof(tempbook.category), stdin);
                    tempbook.category[strcspn(tempbook.category, "\n")] = '\0'; // Remove newline
                    fseek(booklist, pos, SEEK_SET); // Move file pointer to the position of the current record
                    fwrite(&tempbook, sizeof(Book), 1, booklist);
                    break;
                case 'S':
                    printf("| Enter the new ISBN to update : ");
                    scanf("%13ld", &(tempbook.ISBN));
                    fseek(booklist, pos, SEEK_SET); // Move file pointer to the position of the current record
                    fwrite(&tempbook, sizeof(Book), 1, booklist);
                    break;
                case 'P':
                    printf("| Enter the new publisher to update : ");
                    fgets(tempbook.publisher, sizeof(tempbook.publisher), stdin);
                    tempbook.publisher[strcspn(tempbook.publisher, "\n")] = '\0'; // Remove newline
                    fseek(booklist, pos, SEEK_SET); // Move file pointer to the position of the current record
                    fwrite(&tempbook, sizeof(Book), 1, booklist);
                    break;
                case 'Q':
                    printf("| Enter the new quantity to update : ");
                    scanf("%d", &(tempbook.quantity));
                    fseek(booklist, pos, SEEK_SET); // Move file pointer to the position of the current record
                    fwrite(&tempbook, sizeof(Book), 1, booklist);
                    break;
                case 'V':
                    printf("| Enter the new availability to update : ");
                    scanf("%d", &(tempbook.availability));
                    fseek(booklist, pos, SEEK_SET); // Move file pointer to the position of the current record
                    fwrite(&tempbook, sizeof(Book), 1, booklist);
                    break;
                case 'R':
                    printf("| Enter the new price to update : ");
                    scanf("%f", &(tempbook.price));
                    fseek(booklist, pos, SEEK_SET); // Move file pointer to the position of the current record
                    fwrite(&tempbook, sizeof(Book), 1, booklist);
                    tempID = tempbook.id; // Update tempID with the ID of the updated book
                    break;
                default:
                    printf("\e[1;1H\e[2J");
                    printf("| Enter a valid Choice\n");
                    goto UpdateChoiceTypeCheck;
                    break;
            }
            UpdateAgain:
            printf("\nDo you want to update anything else for this book? (y/n): ");
            char ch;
            scanf(" %c", &ch);
            getchar(); // Consume newline
            if (ch == 'Y' || ch =='y') {
                printf("\e[1;1H\e[2J");
                goto UpdateChoiceTypeCheck;
            }
            else if(ch == 'N' || ch =='n') {
                printf("| Thank you for updating\n");
                break;
            }
            else {
                printf("\e[1;1H\e[2J");
                printf("| Enter a valid choice\n");
                goto UpdateAgain;
            }
            if (tempID != -1) {
                // If tempID is valid, set the file pointer to the position of the updated record
                fseek(booklist, 0, SEEK_SET); // Move file pointer to the beginning of the file
                while (fread(&tempbook, sizeof(Book), 1, booklist)) {
                    if (tempbook.id == tempID) {
                        // Found the updated record, set the file pointer to its position
                        fseek(booklist, -sizeof(Book), SEEK_CUR);
                        break;
                    }
                }
            }
        }
    }
}
int main() {
    FILE *booklist = fopen("./bookList", "rb+");
    if (booklist == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    printAllBooks(booklist);
    printf("\n");
    updateBook(booklist);

    printf("\nAfter updating:\n");
    booklist = fopen("./bookList", "rb");
    if (booklist == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    Book temp;
    while (fread(&temp, sizeof(Book), 1, booklist)) {
        printf("ID %d Title %s Author %s Category %s ISBN %ld Publisher %s Quantity %d Availability %d Price $%.2f\n", temp.id, temp.title, temp.author, temp.category, temp.ISBN, temp.publisher, temp.quantity, temp.availability, temp.price);
    }
    fclose(booklist);

    return 0;
}
