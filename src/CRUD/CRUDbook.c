#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../libraryManagementSystem.h"
#include "../Admin/admin.h"
#include "../Admin/bookManagement.h"
#include "./CRUDbook.h"

int createBook(FILE *booklist) {
    Book *temporaryBook = (Book*)malloc(sizeof(Book));
    if(temporaryBook == NULL){
        printf("Memalloc failed\n");
        return 1;
    }
    printf("\e[1;1H\e[2J");
    printf("| Enter the details of the book:\n");
    printf("| Enter book ID : ");
    scanf("%d", &(temporaryBook -> id));
    getchar();
    printf("| Enter book title : ");
    // fgets(temporaryBook->title, 50, stdin);
    scanf("%[^\n]%*c", temporaryBook -> title);
    printf("| Enter book author : ");
    fgets(temporaryBook->author, 20, stdin);
    printf("| Enter book category : ");
    fgets(temporaryBook->category, 20, stdin);
    printf("| Enter book ISBN : ");
    scanf("%ld", &(temporaryBook->ISBN));
    getchar();
    printf("| Enter book publisher : ");
    fgets(temporaryBook->publisher, 20, stdin);
    printf("| Enter book quantity : ");
    scanf("%d", &(temporaryBook->quantity));
    printf("| Enter book price : ");
    scanf("%f", &(temporaryBook->price));
    printf("| Thank you for entering the details of the book\n");
    temporaryBook -> availability = temporaryBook -> quantity;
    fwrite(temporaryBook, sizeof(Book), 1, booklist);
    free(temporaryBook);
    return 0;
}


int readBook(FILE *booklist){
    char *choice = (char*)malloc(sizeof(char));
    printf("\e[1;1H\e[2J");
    readBookChoiceCheck:
    printf("| Read book details\n| [A]ll books\n| [S]pecific book\nYour choice : ");
    scanf("%c", choice);
    if(*choice >= 97 && *choice <= 123){
        *choice -= 32;
    }
    switch(*choice){
        case 'A':
            printAllBooks(booklist);
            break;
        case 'S':
            readSpecificBooks(booklist);
            break;
        default:
            printf("\e[1;1H\e[2J");
            printf("| Enter a valid choice\n");
            goto readBookChoiceCheck;
    }
    free(choice);
}

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

int readSpecificBooks(FILE *booklist) {
    char *searchStr = (char*)malloc(sizeof(char) * 20);
    Book *tempbook = (Book*)malloc(sizeof(Book));
    printf("\e[1;1H\e[2J");
    printf("| Enter title/author/category of the book to search\n");
    getchar();
    printf("| Enter here : ");
    fgets(searchStr, 20, stdin);
    searchStr[strcspn(searchStr, "\n")] = '\0';
    printf("| Search string : %s\n", searchStr);
    rewind(booklist);
    while(fread(tempbook, sizeof(Book), 1, booklist)) {
        // printf("Title: %s\n", tempbook->title);
        tempbook->author[strlen(tempbook->author)-1] = '\0';
        tempbook->category[strlen(tempbook->category)-1] = '\0';
        tempbook->publisher[strlen(tempbook->publisher)-1] = '\0';
        if((strstr(tempbook->title, searchStr) != NULL) || (strstr(tempbook->author, searchStr) != NULL) || (strstr(tempbook->category, searchStr) != NULL)){
            printf("ID %d Title %s Author %s Category %s ISBN %ld Publisher %s Quantity %d Availability %d Price $%.2f\n", tempbook->id, tempbook->title, tempbook->author, tempbook->category, tempbook->ISBN, tempbook->publisher, tempbook->quantity, tempbook->availability, tempbook->price);
        }
    }
    free(tempbook);
    free(searchStr);
    return 0;
}