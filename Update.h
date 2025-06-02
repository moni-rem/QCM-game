#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 100
#define MAX_LINE_LEN 256

typedef struct {
    char question[MAX_LINE_LEN];
    char optionA[MAX_LINE_LEN];
    char optionB[MAX_LINE_LEN];
    char optionC[MAX_LINE_LEN];
    char optionD[MAX_LINE_LEN];
    char answer;
} Question;

void updateQuestion() {
    int categoryChoice;
    char *filename;

    printf("Choose a category to update question:\n");
    printf("1. Information Technology\n");
    printf("2. Science & Technology\n");
    printf("3. General Knowledge\n");
    printf("4. Sports\n");
    printf("Your choice: ");
    scanf("%d", &categoryChoice);
    getchar();

    switch (categoryChoice) {
        case 1: filename = "for Add Question (demo).txt"; break;
        case 2: filename = "science.txt"; break;
        case 3: filename = "general.txt"; break;
        case 4: filename = "sport.txt"; break;
        default:
            printf("Invalid category choice.\n");
            return;
    }

    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return;
    }

    Question questions[MAX_QUESTIONS];
    int count = 0;

    // Read all questions
    while (fgets(questions[count].question, MAX_LINE_LEN, file) != NULL) {
        fgets(questions[count].optionA, MAX_LINE_LEN, file);
        fgets(questions[count].optionB, MAX_LINE_LEN, file);
        fgets(questions[count].optionC, MAX_LINE_LEN, file);
        fgets(questions[count].optionD, MAX_LINE_LEN, file);

        char answerLine[MAX_LINE_LEN];
        if (fgets(answerLine, MAX_LINE_LEN, file) == NULL) break;
        questions[count].answer = answerLine[strlen("Answer: ")]; // the char after "Answer: "


        fgets(answerLine, MAX_LINE_LEN, file);

        count++;
        if (count >= MAX_QUESTIONS) break;
    }
    fclose(file);
    if (count == 0) {
        printf("No questions found in %s.\n", filename);
        return;
    }
    printf("\nList of questions:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s", i + 1, questions[i].question);
    }
    int qNum;
    printf("Enter the number of the question you want to update (1-%d): ", count);
    scanf("%d", &qNum);
    getchar();
    if (qNum < 1 || qNum > count) {
        printf("Invalid question number.\n");
        return;
    }
    printf("Enter new question text:\n");
    fgets(questions[qNum - 1].question, MAX_LINE_LEN, stdin);

    printf("Enter option A:\n");
    fgets(questions[qNum - 1].optionA, MAX_LINE_LEN, stdin);

    printf("Enter option B:\n");
    fgets(questions[qNum - 1].optionB, MAX_LINE_LEN, stdin);

    printf("Enter option C:\n");
    fgets(questions[qNum - 1].optionC, MAX_LINE_LEN, stdin);

    printf("Enter option D:\n");
    fgets(questions[qNum - 1].optionD, MAX_LINE_LEN, stdin);

    printf("Enter correct answer (A/B/C/D): ");
    scanf(" %c", &questions[qNum - 1].answer);
    getchar();
    // Rewrite file with updated questions
    file = fopen(filename, "w");
    if (!file) {
        perror("Error opening file for writing");
        return;
    }
    for (int i = 0; i < count; i++) {
        fprintf(file, "%s", questions[i].question);
        fprintf(file, "%s", questions[i].optionA);
        fprintf(file, "%s", questions[i].optionB);
        fprintf(file, "%s", questions[i].optionC);
        fprintf(file, "%s", questions[i].optionD);
        fprintf(file, "Answer: %c\n", questions[i].answer);
        fprintf(file, "-----\n");
    }
    fclose(file);
    printf("Question updated successfully in %s!\n", filename);
}
