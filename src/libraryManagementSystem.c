// Built-in header files
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// User header files
#include "libraryManagementSystem.h"

int main() {
    char userType;
    printf("| Welcome to Library Management System\n");
    UserTypeCheck:
    printf("| Are you [A]dmin or [U]ser : ");
    scanf("%c", &userType);
    switch(userType) {
        case 'A':
            admin();
            break;
        case 'a':
            admin();
            break;
        case 'U':
            user();
            break;
        case 'u':
            user();
            break;
        default:
            printf("Enter a valid user type\n");
            getchar();
            goto UserTypeCheck;
    }
    return 0;
}

void admin() {
    char *adminName = (char*)malloc(sizeof(ADMINNAME)+1);
    char *adminPassword = (char*)malloc(sizeof(ADMINPASSWORD)+1);
    int loginAttempt = 1;
    while(loginAttempt <= MAXLOGINATTEMPT)
    {
        printf("\nEnter admin name : ");
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
        printf("\nEnter admin password : ");
        scanf("%s", adminPassword);
        if(!strncmp(adminPassword, ADMINPASSWORD, sizeof(ADMINPASSWORD))){
            printf("| Password Correct\n");
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
    switch (*choice)
    {
    case 'E':
        existingUser();
        break;
    case 'e':
        existingUser();
        break;
    case 'N':
        createNewUser();
        break;
    case 'n':
        createNewUser();
        break;
    default:
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