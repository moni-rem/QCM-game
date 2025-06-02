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
} question;

void deleteQuestion() {
    int categoryChoice;
    char *filename;

    printf("Choose a category to delete question from:\n");
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

    while (fgets(questions[count].question, MAX_LINE_LEN, file) != NULL) {
        fgets(questions[count].optionA, MAX_LINE_LEN, file);
        fgets(questions[count].optionB, MAX_LINE_LEN, file);
        fgets(questions[count].optionC, MAX_LINE_LEN, file);
        fgets(questions[count].optionD, MAX_LINE_LEN, file);

        char answerLine[MAX_LINE_LEN];
        if (fgets(answerLine, MAX_LINE_LEN, file) == NULL) break;
        questions[count].answer = answerLine[strlen("Answer: ")];

        fgets(answerLine, MAX_LINE_LEN, file); // Skip "-----\n"
        count++;
        if (count >= MAX_QUESTIONS) break;
    }

    fclose(file);

    if (count == 0) {
        printf("No questions found in %s.\n", filename);
        return;
    }

    // Show questions
    printf("\nList of questions:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s", i + 1, questions[i].question);
    }

    int qNum;
    printf("Enter the number of the question to delete (1-%d): ", count);
    scanf("%d", &qNum);
    getchar();

    if (qNum < 1 || qNum > count) {
        printf("Invalid question number.\n");
        return;
    }

    // Show selected question for confirmation
    printf("\nYou selected to delete the following question:\n");
    printf("Q: %s", questions[qNum - 1].question);
    printf("A) %s", questions[qNum - 1].optionA);
    printf("B) %s", questions[qNum - 1].optionB);
    printf("C) %s", questions[qNum - 1].optionC);
    printf("D) %s", questions[qNum - 1].optionD);
    printf("Answer: %c\n", questions[qNum - 1].answer);

    // Confirm deletion
    char confirm;
    printf("\nAre you sure you want to delete this question? (Y/N): ");
    scanf(" %c", &confirm);
    getchar();

    if (confirm != 'Y' && confirm != 'y') {
        printf("Deletion cancelled.\n");
        return;
    }

    // Reopen file to overwrite
    file = fopen(filename, "w");
    if (!file) {
        perror("Error opening file to write");
        return;
    }

    for (int i = 0; i < count; i++) {
        if (i == qNum - 1) continue;  // Skip the question to delete
        fprintf(file, "%s", questions[i].question);
        fprintf(file, "%s", questions[i].optionA);
        fprintf(file, "%s", questions[i].optionB);
        fprintf(file, "%s", questions[i].optionC);
        fprintf(file, "%s", questions[i].optionD);
        fprintf(file, "Answer: %c\n", questions[i].answer);
        fprintf(file, "-----\n");
    }

    fclose(file);
    printf("Question deleted successfully from %s!\n", filename);
}
