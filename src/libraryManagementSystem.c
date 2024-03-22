// Built-in header files
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// User header files
#include "libraryManagementSystem.h"
#include "./Admin/admin.h"
// Global definitions
FILE *booklist;

int main() {
    char userType;
    booklist = fopen("./bookList", "ab+");
    printf("\e[1;1H\e[2J");
    printf("| Welcome to Library Management System\n");
    UserTypeCheck:
    printf("| Are you [A]dmin or [U]ser : ");
    scanf("%c", &userType);
    if(userType >= 97 && userType <= 123){
        userType -= 32;
    }
    switch(userType) {
        case 'A':
            admin();
            break;
        case 'U':
            user();
            break;
        default:
            printf("Enter a valid user type\n");
            getchar();
            goto UserTypeCheck;
    }
    fclose(booklist);
    return 0;
}

void admin() {
    char *adminName = (char*)malloc(sizeof(ADMINNAME)+1);
    char *adminPassword = (char*)malloc(sizeof(ADMINPASSWORD)+1);
    int loginAttempt = 1;
    printf("\e[1;1H\e[2J");
    while(loginAttempt <= MAXLOGINATTEMPT)
    {
        printf("| Enter admin name : ");
        scanf("%s", adminName);
        if(!strncmp(adminName, ADMINNAME, sizeof(ADMINNAME))){
            printf("| Welcome %s\n", ADMINNAME);
            break;
        }
        else {
            printf("| Wrong admin name. Please try again. %d attempts left\n", MAXLOGINATTEMPT - loginAttempt++);
        }
    }
    while(loginAttempt <= MAXLOGINATTEMPT)
    {
        printf("| Enter admin password : ");
        scanf("%s", adminPassword);
        if(!strncmp(adminPassword, ADMINPASSWORD, sizeof(ADMINPASSWORD))){
            printf("| Password Correct\n");
            adminManagement(booklist);
            break;
        }
        else {
            printf("| Wrong admin password. Please try again. %d attempts left\n", MAXLOGINATTEMPT - loginAttempt++);
        }
    }

    free(adminName);
    free(adminPassword);
}

void user() {
    char *choice = (char*)malloc(sizeof(char));
    UserTypeChoice:
    printf("\n| Choose one:\n| [E]xisting user (or) [N]ew user\n| Your choice:");
    getchar();
    scanf("%c", choice);
    if(*choice >= 97 && *choice <= 123){
        *choice -= 32;
    }
    switch (*choice)
    {
    case 'E':
        existingUser();
        break;
    case 'N':
        createNewUser();
        break;
    default:
        printf("\e[1;1H\e[2J");
        printf("| Enter a valid choice\n");
        getchar();
        goto UserTypeChoice;
        break;
    }
    free(choice);
}


void existingUser() {
    printf("Existing\n");
}

int createNewUser() {
    printf("New\n");
}