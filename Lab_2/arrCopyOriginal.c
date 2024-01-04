#include<stdio.h>
#include <stdlib.h>
#include<string.h>

int size; // Variable to record size of original array arr
int evenCount = 0, oddCount = 0; // Variables to record sizes of new arrays arr_even and arr_odd
int *arr; // Dynamically allocated original array with #elements = size
int *arr_even;  // Dynamically allocated array with #elements = #even elements in arr (evenCount)
int *arr_odd;   // Dynamically allocated array with #elements = #odd elements in arr (oddCount)
char *str1 = "Original array's contents: ";
char *str2 = "Contents of new array containing even elements from original: ";
char *str3 = "Contents of new array containing odd elements from original: ";

// DO NOT change the definition of the printArr function when it comes to 
// adding/removing/modifying the function parameters, or changing its return 
// type. 
void printArr(int *a, int size, char *prompt){
	// Your code here
    printf("\n%s", prompt);
        if(size == 0){
            printf("empty");
        }
    for(int i = 0; i < size; i++){
        printf("%d ", *(a+i));
    }
}

// DO NOT change the definition of the arrCopy function when it comes to 
// adding/removing/modifying the function parameters, or changing its return 
// type. 
void arrCopy(){
	// Your code here
    int *arr_copy;
    int j=0;
    int k=0;
    for(int i = 0; i < size; i++){
        if(*(arr+i) % 2 == 0){
            *(arr_even+j) = *(arr+i);
            j++;
        }else{
            *(arr_odd+k) = *(arr+i);
            k++;
            
        }
    }

}

int main(){
    int i;
    printf("Enter the size of array you wish to create: ");
    scanf("%d", &size);

    // Dynamically allocate memory for arr (of appropriate size)
    // Your code here
    arr = malloc(size);

    // Ask user to input content of arr and compute evenCount and oddCount
	// Your code here
    int count = 0;
   
    while(count<size){
        printf("Enter array element #%d: " , count+1);
        
        scanf("%d",  (arr+count));
        count++;
    }

    for(int i = 0; i < size; i++){
        if(*(arr+i) % 2 == 0){
            evenCount++;
        }else{
            oddCount++;

        }
    }

    // Dynamically allocate memory for arr_even and arr_odd (of appropriate size)
    // Your code here    
    arr_even = malloc(evenCount);
    arr_odd = malloc(oddCount);
	
/*************** YOU MUST NOT MAKE CHANGES BEYOND THIS LINE! ***********/
	
	// Print original array
    printArr(arr, size, str1);

	/// Copy even elements of arr into arr_even and odd elements into arr_odd
    arrCopy();

    // Print new array containing even elements from arr
    printArr(arr_even, evenCount, str2);

    // Print new array containing odd elements from arr
    printArr(arr_odd, oddCount, str3);

    printf("\n");

    return 0;
}