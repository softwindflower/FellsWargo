#include <stdio.h>
// Functions for viewing current amount of money.
void viewFunds(char userName[20], char passWord[20])
{
    FILE* file;
    file = fopen(userName, "r");

    int balance;
    int digits[20];
    char c;

    for(int i=0; i<strlen(passWord)+1; i++){
        c = fgetc(file);
    }

    printf("You have: ");
    for(int i = 0; i<16; i++){
        if(c == EOF) break;
        c = fgetc(file);
        printf("%c", c);
    }
    printf("funds in your account.\n\n");
    fclose(file);
    return;
}
// TODO: Complete these functions
void addFunds(){

}

void withdrawFunds(){

}
