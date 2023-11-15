#include <stdio.h>

int main(void)
{
    printf("**********************************************************\n");
    printf("* Welcome to the Fells Wargo banking terminal interface. *\n");
    printf("**********************************************************\n\n");
    //Super basic design, if you have a good idea please implement!

    int choice;

    while(1)
    {

        printf("Choose an option:\n\n1. Create Account\n2. Log In\n3. Admin Access\n4. Quit\n-> ");
        scanf("%d", &choice);

        switch(choice)
        {
        case 1:
            createAccount(); // ->functions.c
            break;

        case 2:
            logIn(); // ->functions.c
            break;

        case 3:
            adminAccess(); // ->functions.c TODO: implement
            break;

        case 4:
            printf("Quitting...");
            return 0;

        default:
            printf("\nChoice out of range. Try again.\n\n");
        }
    }


    return 0;
}
