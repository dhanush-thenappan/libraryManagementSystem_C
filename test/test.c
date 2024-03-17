#include <stdio.h>

#include "../src/libraryManagementSystem.h"

int main(){
    FILE *fp;
    fp = fopen("./newfile", "wb+");
    int read;
    Book b1 = {1, "A", "B", "C", 123, "4", 12, 2, 14.99};
    Book b2 = {2, "A", "B", "C", 1234, "D", 15, 3, 15.99};
    fwrite(&b1, sizeof(Book), 1, fp);
    fwrite(&b2, sizeof(Book), 1, fp);
    fclose(fp);
    fp = fopen("./newfile", "rb+");
    Book b3[2];
    // while(!feof(fp)){
        read = fread(&b3, sizeof(Book), 2, fp);
    // }
    printf("%d\n", read);
    FILE *fop = fopen("./x", "wb+");
    fwrite(&b3, sizeof(Book), 2, fop);
    fclose(fop);
    fclose(fp);
    return 0;
}