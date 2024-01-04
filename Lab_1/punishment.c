#include <stdio.h>
int main(){
    int repeat, typo;

    printf("Enter the number of repetitions for the punishment phrase: ");
    scanf("%d", &repeat);
    while(repeat <= 0){
        printf("You entered an invalid value for the number of repetitions! \n");
        printf("Enter the number of repetitions for the punishment phrase again:");
        scanf("%d", &repeat);
    }
    printf("Enter the line where you wish to introduce the typo: ");
    scanf("%d", &typo);

    while(typo <= 0 || typo > repeat){
        printf("You entered an invalid value for the typo placement! \n");
        printf("Enter the line where you wish to introduce the typo again: ");
        scanf("%d", &typo);
    }
    for(int i = 1; i <= repeat; i++){
        if(i != typo){
           printf("Coding in C is fun and interesting \n"); 
        } else{
            printf("Cading in C is fun and interesting \n");
        }
        
    }

    }
 