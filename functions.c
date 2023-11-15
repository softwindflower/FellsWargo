#include <stdio.h>
#include <stdbool.h>
#include <string.h>

/*
    This program works by creating a file (userName).txt in
    the directory, (userName) is replaced with whatever the user chooses.
*/

int accountExists(char userName[20])
{
    /*
        This checks if the account exists by attempting to open
        the userName.txt as "r", which does not create a file
        if there was no file found named userName. Opening as "w" would
        create a file which is not what we want, this only checks
        if the account exists.
    */
    strcat(userName, ".txt"); //Needed here?
    FILE* file;
    file = fopen(userName, "r");
    if(file == NULL)
    {
        fclose(file);
        return 0;
    }
    fclose(file);
    return 1;
}

/*
    account files are structured as follows

    userName.txt
    {
    password
    balance
    }
*/

void createAccount()
{
    char userName[20];
    char passWord[20];
    printf("Enter Your Username.\n-> ");
    scanf("%s", userName);
    printf("Enter Your Password.\n-> ");
    scanf("%s", passWord);

    FILE* file;


    if(accountExists(userName) == 1)
    {
        printf("Account already exists.\n");
        return;
    }
    else
    {
        //strcat(userName, ".txt"); //Not needed here?
        file = fopen(userName, "w");
        if(file == NULL)
        {
            printf("Error Creating Account.\n");
            return;
        }
        printf("Account created successfully. Please log in for options.\n");
        fprintf(file, "%s\n0", passWord); //Here 0 is printed in the new line, meaning the balance is zero upon account creation.
        fclose(file);
        return;
    }
}

void logIn()
{
    char userName[20];
    char passWord[20];
    while(1)
    {
        printf("Enter Your Username.\n-> ");
        scanf("%s", userName);
        if(accountExists(userName) == 1)
        {
            break;
        }
        else if(strncmp(userName, "QUIT", 4) == 0)
        {
            return;
        }
        printf("Account not found. Try again. Type QUIT to abort login.\n");
    }

    FILE* file;
    file = fopen(userName, "r");
    if(file == NULL)
    {
        printf("Error logging in.\n");
        return;
    }

    char c;
    int i = 0;

    printf("Enter Your Password.\n-> ");
    scanf("%s", passWord);
    while(c != EOF) //Password checker.
    {

        c = fgetc(file);
        if (c == passWord[i])
        {
            i++;
            if (i == strlen(passWord))
            {
                printf("Login success.\n");
                break;
            }
        }
        else
        {
            printf("Incorrect password.\n");
            return; //returns to main menu, can be changed to try password again.
        }
    }


    while(1)
    {

        int choice;
        printf("Choose an option:\n\n1. View Funds\n2. Add Funds\n3. Withdraw Funds\n4. Log Out\n-> ");
        scanf("%d", &choice);


        switch(choice)
        {
        case 1:
            viewFunds(userName, passWord); // ->accountFunctions.c
            break;

        case 2:
            addFunds();// ->accountFunctions.c TODO: implement
            break;

        case 3:
            withdrawFunds();// ->accountFunctions.c TODO: implement
            break;

        case 4:
            printf("Logging out...\n\n");
            return;

        default:
            printf("\nChoice out of range. Try again.\n\n");
        }
    }

    return;
}

void adminAccess(){

}
