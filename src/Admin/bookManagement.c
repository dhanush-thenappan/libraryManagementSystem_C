// Built-in header files
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// User header files
#include "../libraryManagementSystem.h"
#include "./admin.h"
#include "./bookManagement.h"
#include "../CRUD/CRUDbook.h"

void bookManagement(FILE *booklist) {
    char *choice = (char*)malloc(sizeof(char));
    printf("\e[1;1H\e[2J");
    printf("| Welcome to Book management\n");
    BMChoiceCheck:
    printf("| [C]reate book\n| [U]pdate book\n| [D]elete book\n| [R]ead details of a book\n| Your options : ");
    scanf("%c", choice);
    
    if(*choice > 97 && *choice < 123){
        *choice -= 32;
    }
    switch(*choice) {
        case 'C':
            createBook(booklist);
            break;
        case 'U':
            break;
        case 'D':
            break;
        case 'R':
            break;
        default:
            printf("\e[1;1H\e[2J");
            printf("| Enter a valid Choice\n");
            getchar();
            goto BMChoiceCheck;
            break;
    }
    free(choice);
}