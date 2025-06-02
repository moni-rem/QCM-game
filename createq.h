 #include <stdio.h>
#include <stdlib.h>
#include <string.h>

 void AdminAddToFile(){
    int categoryChoice;
    const char *filename;

    gotoxy(20,5);
    printf("=======Welcome Admin========\n");
    gotoxy(20,7);
    printf("Please Choose category :\n");
    //printf("Choose a category:\n");
    gotoxy(20,9);
    printf("1. Information Technology\n");
    gotoxy(20,11);
    printf("2. Science & Technology\n");
    gotoxy(20,13);
    printf("3. General Knowlenge\n");
    gotoxy(20,15);
    printf("4.Sports\n");
    gotoxy(20,17);
    printf("Enter your number: ");
    scanf("%d", &categoryChoice);
    getchar();

    switch(categoryChoice){
        case 1: filename = "for Add Question (demo).txt"; break;
        case 2: filename = "science.txt"; break;
        case 3: filename = "general.txt"; break;
        case 4: filename = "sport.txt"; break;

        default:

            printf("Invalid category choice.\n");
            return;
    }
       FILE *file = fopen(filename, "a");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    char question[256];
    char optionA[100], optionB[100], optionC[100], optionD[100];
    char correctAnswer;
    system("cls");
    gotoxy(20,5);
    //printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(20,7);
    printf("Enter the question: ");
    //fgets(question, sizeof(question), stdin);
    fgets(question, sizeof(question), stdin);
    gotoxy(20,9);
    printf("Enter option A: ");
    fgets(optionA, sizeof(optionA), stdin);
    gotoxy(20,11);

    printf("Enter option B: ");
    fgets(optionB, sizeof(optionB), stdin);
    gotoxy(20,13);

    printf("Enter option C: ");
    fgets(optionC, sizeof(optionC), stdin);
    gotoxy(20,15);

    printf("Enter option D: ");
    fgets(optionD, sizeof(optionD), stdin);
    gotoxy(20,17);

    printf("Enter the correct answer (A/B/C/D): ");
    scanf(" %c", &correctAnswer);
    getchar();

    fprintf(file, "%s", question);
    fprintf(file, "A. %s", optionA);
    fprintf(file, "B. %s", optionB);
    fprintf(file, "C. %s", optionC);
    fprintf(file, "D. %s", optionD);
    fprintf(file, "Answer: %c\n", correctAnswer);
    fprintf(file, "-----\n");

    fclose(file);
    gotoxy(20,19);
    printf("Question added successfully to %s!\n", filename);


  }
