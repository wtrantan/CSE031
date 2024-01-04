#include <stdio.h>
int main() { 
    int sum = 0, count = 0, temp = 0;
    float userIn, oddAvg = 0, evenAvg = 0, evenCount = 0, oddCount = 0;
    char ordinal[] = "st";

    while(userIn != 0){
        count++;
        if((count % 10) == 1 && count != 11 ){
           ordinal[0] = 's';
           ordinal[1] = 't';
        } else if((count % 10) == 2 && count != 12){
           ordinal[0] = 'n';
           ordinal[1] = 'd';
        } else if((count % 10) == 3 && count != 13){
           ordinal[0] = 'r';
           ordinal[1] = 'd';
        } else{
           ordinal[0] = 't';
           ordinal[1] = 'h';
        }
        
        printf("Enter the %d%s number: ", count, ordinal);
        scanf("%f", &userIn);
        temp = userIn;
       
        while(temp != 0){
            sum = sum + (temp % 10);
            temp = temp / 10;

        }

        if (sum % 2 == 0 && userIn != 0){ 
            evenAvg = evenAvg + userIn;
            evenCount++;
            sum = 0;
        } else if(userIn != 0){
            oddAvg = oddAvg + userIn;
            oddCount++;
            sum = 0; 
        }
        
    }

    if (evenAvg != 0){
        evenAvg = evenAvg / evenCount;
        printf("Average of inputs whose digits sum up to an even number: %0.2f\n", evenAvg);
    }
    if (oddAvg != 0){
        oddAvg = oddAvg / oddCount;
        printf("Average of inputs whose digits sum up to an odd number: %0.2f\n", oddAvg);
    }
    if (oddAvg == 0 && evenAvg == 0){
        printf("There is no average to compute. ");
    }
    return 0;
}