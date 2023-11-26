void addFunds(char *userName){
    FILE* file;
    float balance, userDeposit;
    
    printf("Please enter the amount you would like to deposit: \n");
    scanf("%f", userDeposit);
    
    file = fopen(userName, "r+");
    
    if (file == NULL) {
        fprint("Username not found!\n");
        return;
    }

    fseek(file, 0, SEEK_SET);

    int count = 0;
    char ch;

    //count lines
    while ((ch = fgetc(file)) != EOF) {
        if (ch == '\n') {
            count++;
        }
    }
    //return pointer to the beginning of the file 
    fseek(file, 0, SEEK_SET);
    //find last line
    int currentLine = 0;
    while (currentLine < count - 1) {
        if (fgetc(file) == '\n') {
            currentLine++;
        }
    }
    //read balance from last line
    fscanf(file, "%lf", &balance);
    
    balance += userDeposit;
    
    printf("Your new balance is %f.\n", balance);
    
    fseek(file, 0, SEEK_END);
    //write new balance to a new line in the file
    fprintf(file, "\n%f", balance);
    
    fclose(file);
}

void withdrawFunds(char *userName){
    FILE* file;
    float balance, userWithdraw;
    
    printf("Please enter the amount you would like to withdraw: \n");
    scanf("%f", userWithdraw);
    
    file = fopen(userName, "r+");
    
    if (file == NULL) {
        fprint("Username not found!\n");
        return;
    }

    fseek(file, 0, SEEK_SET);

    int count = 0;
    char ch;

    //count lines
    while ((ch = fgetc(file)) != EOF) {
        if (ch == '\n') {
            count++;
        }
    }
    //return pointer to the beginning of the file 
    fseek(file, 0, SEEK_SET);
    //find last line
    int currentLine = 0;
    while (currentLine < count - 1) {
        if (fgetc(file) == '\n') {
            currentLine++;
        }
    }
    //read balance from last line
    fscanf(file, "%lf", &balance);
    
    balance -= userWithdraw;
    
    printf("Your new balance is %f.\n", balance);
    
    fseek(file, 0, SEEK_END);
    //write new balance to a new line in the file
    fprintf(file, "\n%f", balance);
    
    fclose(file);
    
}
