#include <stdio.h>
#include <stdlib.h>

struct users {
    char fullName[50];
    char email[50];
    char password[50];
    char username[50];
    char phone[50];
};

#define USER_FILE "User.txt"

void ViewUsersAndQuestions() {
    int choice;
    FILE *fp;
    struct users usr;
    char *fileNames[] = {
        "for Add Question (demo).txt",
        "science.txt",
        "sport.txt",
        "general.txt"
    };

#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif

    printf("What would you like to view?\n");
    printf("1. View Users\n");
    printf("2. View Questions\n");
    printf("Enter your choice (1-2): ");

    char input[10];
    fgets(input, sizeof(input), stdin);
    sscanf(input, "%d", &choice);

    switch (choice) {

                case 1:
            fp = fopen(USER_FILE, "rb");
            if (fp == NULL) {
                printf("Error: Could not open user file.\n");
                return;
            }

            printf("\n----- User List -----\n");
            while (fread(&usr, sizeof(struct users), 1, fp)) {
                printf("Name: %s\nEmail: %s\nPhone: %s\n\n", usr.fullName, usr.email, usr.phone);
            }
            fclose(fp);
            break;
            break;

            case 2:
            printf("Choose a category to view questions:\n");
            printf("1. information ANd Technology\n");
            printf("2. Science \n");
            printf("3. General Knowlenge\n");
            printf("4. Sport\n");
            printf("Enter your choice (1-4): ");

            fgets(input, sizeof(input), stdin);
            sscanf(input, "%d", &choice);

            if (choice < 1 || choice > 4) {
                printf("Invalid category selection.\n");
                return;
            }

            fp = fopen(fileNames[choice - 1], "rb");
            if (fp == NULL) {
                printf("Error opening questions file.\n");
                return;
            }

            printf("\n----- Questions in %s -----\n", fileNames[choice - 1]);
            char line[256];
            while (fgets(line, sizeof(line), fp)) {
                printf("%s", line);
            }
            fclose(fp);
            break;

            default:
            printf("Invalid choice. Returning to the main menu.\n");
            return;
    }
}


