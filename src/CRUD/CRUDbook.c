#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../libraryManagementSystem.h"
#include "../Admin/admin.h"
#include "../Admin/bookManagement.h"
#include "./crud.h"

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
