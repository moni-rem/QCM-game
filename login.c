#include<stdio.h>
#include<conio.h>
#include<windows.h>
#define ENTER 13
#define TAB 9
#define BCKSPC 8

struct user{
    char fullName[50];
    char email[50];
    char password [50];
    char username[50];
    char phone[50];


};
void takeinpute(char ch[50]){
    fgets(ch,50,stdin);
    ch[strlen(ch) - 1] = 0;
}
void generateUsername(char email[50], char username[50]) {
    int i;
    for (i = 0; i < strlen(email); i++) {
        if (email[i] == '@') break;
        username[i] = email[i];
    }
    username[i] = '\0';
}


void takepassword(char pwd[50]){
    int i;
    char ch;
    while(1){
        ch = getch();
        if ( ch == ENTER || ch == TAB){
            pwd[i] = '\0';
            break;
        }else if (ch == BCKSPC ){
            if(i>0){
                i--;
                printf("\b \b"); //abc
            }

        }else{
                pwd[i++]= ch;
                printf("* \b");
            }
    }

}





int main(){

    FILE *fp;



    int opt;
    struct user user;
    char password2 [50];

    printf(" \n\t\t\t----Welcome to quizsystem system-------");
    printf("\nPlease choose your operation");
    printf("\n1.Signup");
    printf("\n2.Login");
    printf("\n3,Exit");

    printf("\n\nYour choice: \t");
    scanf("%d", &opt);
    fgetc(stdin);

    switch(opt){
    case 1:
        printf("\nEnter your full name: \t");
        takeinpute(user.fullName);
        printf("Enter your email:\t");
        takeinpute(user.email);
        printf("Enter your contact no:\t");
        takeinpute(user.phone);
        printf("Enter password:\t");
        takepassword(user.password);
        printf("\nconfirm your password:\t");
        takepassword(password2);

        if(!strcmp(user.password,password2)){
            generateUsername( user.email, user.username);
            fp = fopen("User.dat", "a+");
            fwrite(&user, sizeof(struct user), 1, fp);
            if(fwrite != 0){
                printf("\n\nUser resgistration succes, Your user name is %s ", user.username);
            }else printf("\n\nSorry!! Something went wrong: (");

        }
        else{
            printf("\nPassword not match ");
            Beep(750,300);
        }





    }

   return 0;
}