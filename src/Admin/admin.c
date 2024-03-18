// Built-in header files
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// User header files
#include "../libraryManagementSystem.h"
#include "./admin.h"
#include "./bookManagement.h"

void adminManagement() {
    getchar();
    printf("\e[1;1H\e[2J");
    printf("| Welcome admin\n");
    char *choice = (char*)malloc(sizeof(char));
    AdminChoiceCheck:
    printf("| Choose any of the below\n| Manage [B]ooks\n| Manage [U]sers\n| Your choice : ");
    scanf("%c", choice);
    if(*choice >= 97 && *choice <= 123){
        *choice -= 32;
    }
    switch(*choice) {
        case 'B':
            getchar();
            bookManagement();
            break;
        case 'U':
            getchar();
            // userManagement();
            break;
        default:
            printf("\e[1;1H\e[2J");
            printf("| Enter a valid Choice\n");
            getchar();
            goto AdminChoiceCheck;
            break;
    }
    free(choice);
}