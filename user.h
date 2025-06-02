#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_QUESTIONS 100

extern char currentUsername[50];

typedef struct {
    char question[256];
    char optionA[100];
    char optionB[100];
    char optionC[100];
    char optionD[100];
    char correctAnswer;
} QuizQuestion;

void shuffle(QuizQuestion *arr, int n) {
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        QuizQuestion temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

void UserTakeQuiz() {
    int categoryChoice;
    const char *filename;

    printf("======= Welcome User =======\n");
    printf("Choose a category:\n");
    printf("1. Information Technology\n");
    printf("2. Science & Technology\n");
    printf("3. General Knowledge\n");
    printf("4. Sports\n");
    printf("Enter your choice: ");
    scanf("%d", &categoryChoice);
    getchar();
    system("cls");

    switch (categoryChoice) {
        case 1: filename = "for Add Question (demo).txt"; break;
        case 2: filename = "science.txt"; break;
        case 3: filename = "general.txt"; break;
        case 4: filename = "sport.txt"; break;
        default:
            printf("Invalid category.\n");
            return;
    }

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    QuizQuestion questions[MAX_QUESTIONS];
    int total = 0;

    while (!feof(file) && total < MAX_QUESTIONS) {
        fgets(questions[total].question, sizeof(questions[total].question), file);
        fgets(questions[total].optionA, sizeof(questions[total].optionA), file);
        fgets(questions[total].optionB, sizeof(questions[total].optionB), file);
        fgets(questions[total].optionC, sizeof(questions[total].optionC), file);
        fgets(questions[total].optionD, sizeof(questions[total].optionD), file);

        char answerLine[20];
        fgets(answerLine, sizeof(answerLine), file);
        sscanf(answerLine, "Answer: %c", &questions[total].correctAnswer);

        char separator[10];
        fgets(separator, sizeof(separator), file);

        total++;
    }

    fclose(file);

    if (total < 10) {
        printf("Not enough questions. At least 10 are required.\n");
        return;
    }

    int score = 0;
    int totalAsked = 0;

    // Easy: First 4 questions
    printf("\n===== Easy Level =====\n");
    for (int i = 0; i < 4; i++) {
        totalAsked++;
        printf("\nQ%d: %s", i + 1, questions[i].question);
        printf("%s%s%s%s", questions[i].optionA, questions[i].optionB,
               questions[i].optionC, questions[i].optionD);
        printf("Your answer (A/B/C/D): ");

        char userAnswer;
        scanf(" %c", &userAnswer);

        if (userAnswer >= 'a' && userAnswer <= 'z') {
            userAnswer -= 32;
        }

        if (userAnswer == questions[i].correctAnswer) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Wrong. Correct answer was %c.\n", questions[i].correctAnswer);
        }
    }

    char proceed;
    printf("\nDo you want to continue to the Medium level? (Y/N): ");
    scanf(" %c", &proceed);
    if (proceed != 'Y' && proceed != 'y') goto finish;

    // Medium: Next 3 questions
    printf("\n===== Medium Level =====\n");
    for (int i = 4; i < 7; i++) {
        totalAsked++;

        printf("\nQ%d: %s", i + 1, questions[i].question);
        printf("%s%s%s%s", questions[i].optionA, questions[i].optionB,
               questions[i].optionC, questions[i].optionD);
        printf("Your answer (A/B/C/D): ");

        char userAnswer;
        scanf(" %c", &userAnswer);

        if (userAnswer >= 'a' && userAnswer <= 'z') {
            userAnswer -= 32;
        }

        if (userAnswer == questions[i].correctAnswer) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Wrong. Correct answer was %c.\n", questions[i].correctAnswer);
        }
    }

    printf("\nDo you want to continue to the Hard level? (Y/N): ");
    scanf(" %c", &proceed);
    if (proceed != 'Y' && proceed != 'y') goto finish;

    // Hard: Last 3 questions
    printf("\n===== Hard Level =====\n");
    for (int i = 7; i < 10; i++) {
        totalAsked++;

        printf("\nQ%d: %s", i + 1, questions[i].question);
        printf("%s%s%s%s", questions[i].optionA, questions[i].optionB,
               questions[i].optionC, questions[i].optionD);
        printf("Your answer (A/B/C/D): ");

        char userAnswer;
        scanf(" %c", &userAnswer);

        if (userAnswer >= 'a' && userAnswer <= 'z') {
            userAnswer -= 32;
        }

        if (userAnswer == questions[i].correctAnswer) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Wrong. Correct answer was %c.\n", questions[i].correctAnswer);
        }
    }

finish:
    printf("\nQuiz finished. Your score: %d out of %d.\n", score, totalAsked);

    time_t t = time(NULL);
    struct tm *tm_info = localtime(&t);
    char timeStr[100];
    strftime(timeStr, sizeof(timeStr), "%Y-%m-%d %H:%M:%S", tm_info);

    FILE *resultFile = fopen("quiz_results.txt", "a");
    if (resultFile != NULL) {
        fprintf(resultFile, "Name: %s | Score: %d/%d | Time: %s\n", currentUsername, score, totalAsked, timeStr);
        fclose(resultFile);
    } else {
        printf("Error: Could not save result.\n");
    }

    backUser();
}
