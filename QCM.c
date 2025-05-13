#include <stdio.h>
#include <ctype.h>

int main(){

    char Questions[][100] = {"What is the capital of Canada?", 
                             "Which planet is known as the Red Planet?",
                             "Who wrote Romeo and Juliet?",
                             "What does HTML stand for?",
                             "In which year did the Berlin Wall fall?"};
    
    char Options[][100] = {"A. Toronto", "B. Vancouver", "C. Ottawa", "D. Montreal",
                         "A. Venus","B. Jupiter","C. Mars"," D. Saturn",
                          "A. Charles Dickens","B. William Shakespeare","C. Jane Austen","D. Mark Twain",
                          "A. Hyperlinks and Text Markup Language","B. Home Tool Markup Language","C. Hyper Text Markup Language","D. High Text Machine Language",
                          "A. 1985","B. 1987","C. 1989","D. 1991",
                        };

    char Answer[] = {'C','C', 'B','C','C'};
    char guess;
    int score = 0;
    int numberofquestions = sizeof(Questions)/sizeof(Questions[0]);
    printf("Quiz game\n ");

    for(int i =0; i <numberofquestions; i++){
        printf("%s\n", Questions[i]);

         for(int j = (i* 4); j <(i*4)+4; j++){
        printf("%s\n", Options[j]);
        }
   
    printf("Your answer (A/B/C/D): ");
        scanf(" %c", &guess);
        guess = toupper(guess);
       if(guess == Answer[i]) {
           printf("the answer is right\n");
           score++;
        }
        else{
          printf("the answer is wrong\n");
        }
  
    printf("=== Final Score ===\n");
    printf("You got %d out of %d correct.\n", score, numberofquestions);
    }
return 0;
}
