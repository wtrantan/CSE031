#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declarations of the two functions you will implement
// Feel free to declare any helper functions or global variables
void printPuzzle(char **arr);
void searchPuzzle(char **arr, char *word);
char toUpperCase(char *word);
void printAll();
void convertUpper(char *word);
void findOrder(char **arr, char *word, int x, int y);
void pathRecord(int x, int y);
void finder(char **arr, char *word, int x, int y);
void reverseFinder(char **arr, char *word, int x, int y);
void reset();
int bSize;
int **set;
int x = -1;
int y = -1;
int q = 0;
int p = 0;
int find = 0;
int count = 0;

// Main function, DO NOT MODIFY
int main(int argc, char **argv)
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <puzzle file name>\n", argv[0]);
        return 2;
    }
    int i, j;
    FILE *fptr;

    // Open file for reading puzzle
    fptr = fopen(argv[1], "r");
    if (fptr == NULL)
    {
        printf("Cannot Open Puzzle File!\n");
        return 0;
    }

    // Read the size of the puzzle block
    fscanf(fptr, "%d\n", &bSize);

    // Allocate space for the puzzle block and the word to be searched
    char **block = (char **)malloc(bSize * sizeof(char *));
    char *word = (char *)malloc(20 * sizeof(char));

    // Read puzzle block into 2D arrays
    for (i = 0; i < bSize; i++)
    {
        *(block + i) = (char *)malloc(bSize * sizeof(char));
        for (j = 0; j < bSize - 1; ++j)
        {
            fscanf(fptr, "%c ", *(block + i) + j);
        }
        fscanf(fptr, "%c \n", *(block + i) + j);
    }
    fclose(fptr);

    printf("Enter the word to search: ");
    scanf("%s", word);

    // Print out original puzzle grid
    printf("\nPrinting puzzle before search:\n");
    printPuzzle(block);

    // Call searchPuzzle to the word in the puzzle
    searchPuzzle(block, word);

    return 0;
}

void printPuzzle(char **arr)
{
    // This function will print out the complete puzzle grid (arr).
    // It must produce the output in the SAME format as the samples
    // in the instructions.
    // Your implementation here...
    for (int i = 0; i < bSize; i++)
    {
        for (int j = 0; j < bSize; j++)
        {
            printf("%c ", *(*(arr + i) + j));
        }
        printf("\n");
    }
    printf("\n");
}

void searchPuzzle(char **arr, char *word)
{
    // This function checks if arr contains the search word. If the
    // word appears in arr, it will print out a message and the path
    // as shown in the sample runs. If not find, it will print a
    // different message as shown in the sample runs.
    // Your implementation here...
    convertUpper(word);
    set = (int **)malloc(bSize * sizeof(int *));
    for (int i = 0; i < bSize; i++)
    {
        *(set + i) = (int *)malloc(bSize * sizeof(int));
    }
    for (int i = 0; i < bSize; i++)
    {
        for (int j = 0; j < bSize; j++)
        {
            *(*(set + i) + j) = 0;
        }
    }
    findOrder(arr, word, x, y);
    printAll();
}
void printAll(){
    if (find == 0){
        printf("Word not find!\n");
    }
    else
    {
        printf("Word find!\n");
        printf("Printing the search path:\n");
        for (int i = 0; i < bSize; i++){
            for (int j = 0; j < bSize; j++){
                if (*(*(set + i) + j) < 10){
                    printf("%d       ", *(*(set + i) + j));
                }
                else if (*(*(set + i) + j) >= 10 && *(*(set + i) + j) < 100){
                    printf("%d      ", *(*(set + i) + j));
                }
                else if (*(*(set + i) + j) >= 100 && *(*(set + i) + j) < 1000){
                    printf("%d     ", *(*(set + i) + j));
                }
                else if (*(*(set + i) + j) >= 1000 && *(*(set + i) + j) < 10000){
                    printf("%d    ", *(*(set + i) + j));
                }
                else if (*(*(set + i) + j) >= 10000 && *(*(set + i) + j) < 100000){
                    printf("%d   ", *(*(set + i) + j));
                }
                else if (*(*(set + i) + j) >= 100000 && *(*(set + i) + j) < 1000000){
                    printf("%d  ", *(*(set + i) + j));
                }
                else if (*(*(set + i) + j) >= 1000000 && *(*(set + i) + j) < 10000000){
                    printf("%d ", *(*(set + i) + j));
                }
                else{
                    printf("%d", *(*(set + i) + j));
                }
            }
            printf("\n");
        }
    }
}
char toUpperCase(char *word)
{
    for (int i = 0; *(word + i) != 0; i++)
    {
        if (*(word + i) >= 'a' && *(word + i) <= 'z')
        {
            *(word + i) -=  32;
        }
    }
    return word;
}
void convertUpper(char *word)
{
    toUpperCase(word);
}
void reset()
{
    for (int i = 0; i < bSize; i++)
    {
        for (int j = 0; j < bSize; j++)
        {
            *(*(set + i) + j) = 0;
        }
    }
    find = 0;
    count = 0;
    x = q;
    y = p;
}
void findOrder(char **arr, char *word, int x, int y)
{
    if (x == -1 && y == -1){
        for (int i = 0; i < bSize; i++)
        {
            for (int j = 0; j < bSize; j++)
            {
                if (*(word) == *(*(arr + i) + j))
                {
                    q = i;
                    p = j;
                    x = i;
                    y = j;
                    find++;
                    break;
                }
                if (i == bSize - 1 && j == bSize - 1)
                {
                    find = 0;
                }
            }
            if (find > 0)
            {
                break;
            }
        }

        if (*(word) == *(*(arr + q) + p))
        {
            pathRecord(x, y);
            finder(arr, word, x, y);
        }
    }
    else
{
        int i = x;
        int j = y + 1;
       

        while (i != bSize)
        {
            if (j == bSize)
            {
                j = 0;
                i++;
            }
            if (*(word) == *(*(arr + i) + j))
            {
                q = i;
                p = j;
                x = i;
                y = j;
                find++;
                break;
            }
            j++;
        }
        if (*(word) == *(*(arr + q) + p)){
            pathRecord(x, y); 
            finder(arr, word, x, y);
        }
        else
        {
            find = 0;
        }
    }
}
void pathRecord(int x, int y)
{ // mark path if find letter
    int total = *(*(set + x) + y);
    int temp = 1;
    count++;
    for (int i = 0; i < bSize; i++){ 
        if (temp - 1 < total)
        {
            temp *= 10;
        }
        else
        {
            total = temp * count + total;
            break;
        }
    }
    *(*(set + x) + y) = total;
}
void finder (char** arr, char* word, int x, int y){ 
    if(x - 1 >= 0 && y - 1 >= 0 && *(word + count)!='\0'){
        if (*(word + count) == *(*(arr + (x - 1)) + (y - 1))){
            x--;y--;
            pathRecord(x,y);
            finder(arr, word, x, y);
        }
    }
    if(x - 1 >= 0 && *(word + count)!='\0'){// top 
        if (*(word + count) == *(*(arr + (x - 1)) + y)){
            x--;
            pathRecord(x,y);
            finder(arr, word, x, y);
        }
    }
    if(x - 1 >= 0 && y + 1 < bSize && *(word + count)!='\0'){// top right
        if (*(word + count) == *(*(arr + (x - 1)) + (y + 1))){
            x--;y++;
            pathRecord(x,y);
            finder(arr, word, x, y);
        }
    }
    if(y - 1 >= 0 && *(word + count)!='\0'){// left 
        if (*(word + count) == *(*(arr + x) + (y - 1))){
            y--;
            pathRecord(x,y);
            finder(arr, word, x, y);
        }
    }
    if(y + 1 < bSize && *(word + count)!='\0'){// right 
        if (*(word + count) == *(*(arr + x) + (y + 1))){
            y++;
            pathRecord(x,y);
            finder(arr, word, x, y);
        }
    }
    if(x + 1 < bSize && y - 1 >= 0 && *(word + count)!='\0'){// bottom left
        if (*(word + count) == *(*(arr + (x + 1)) + (y - 1))){
            x++;y--;
            pathRecord(x,y);
            finder(arr, word, x, y);
        }
    }
    if(x + 1 < bSize && *(word + count)!='\0'){// bottom 
        if (*(word + count) == *(*(arr + (x + 1)) + y)){
            x++;
            pathRecord(x,y);
            finder(arr, word, x, y);
        }
    }
    if(x + 1 < bSize && y + 1 < bSize && *(word + count)!='\0'){// bottom right
        if (*(word + count) == *(*(arr + (x + 1)) + (y + 1))){
            x++;y++;
            pathRecord(x,y);
            finder(arr, word, x, y);
        }
    }
    if(*(word + count) != '\0'){ // search counterclockwise 
        reset();
        x = q;
        y = p;
        pathRecord(x, y);
        reverseFinder(arr, word, x, y);
    }else{
        find = 1;
    }
}
void reverseFinder(char** arr, char* word, int x, int y){ //countercolckwise search, recursive
    if(x + 1 < bSize && y + 1 < bSize && *(word + count)!='\0'){// bottom right
        if (*(word + count) == *(*(arr + (x + 1)) + (y + 1))){
            x++;y++;
            pathRecord(x,y);
            reverseFinder(arr, word, x, y);
        }
    }
    if(x + 1 < bSize && *(word + count)!='\0'){// bottom 
        if (*(word + count) == *(*(arr + (x + 1)) + y)){
            x++;
            pathRecord(x,y);
            reverseFinder(arr, word, x, y);
        }
    }
    if(x + 1 < bSize && y - 1 >= 0 && *(word + count)!='\0'){// bottom left
        if (*(word + count) == *(*(arr + (x + 1)) + (y - 1))){
            x++;y--;
            pathRecord(x,y);
            reverseFinder(arr, word, x, y);
        }
    }
    if(y + 1 < bSize && *(word + count)!='\0'){// right 
        if (*(word + count) == *(*(arr + x) + (y + 1))){
            y++;
            pathRecord(x,y);
            reverseFinder(arr, word, x, y);
        }
    }
    if(y - 1 >= 0 && *(word + count)!='\0'){// left 
        if (*(word + count) == *(*(arr + x) + (y - 1))){
            y--;
            pathRecord(x,y);
            reverseFinder(arr, word, x, y);
        }
    }
    if(x - 1 >= 0 && y + 1 < bSize && *(word + count)!='\0'){// top right
        if (*(word + count) == *(*(arr + (x - 1)) + (y + 1))){
            x--;y++;
            pathRecord(x,y);
            reverseFinder(arr, word, x, y);
        }
    }
    if(x - 1 >= 0 && *(word + count)!='\0'){// top 
        if (*(word + count) == *(*(arr + (x - 1)) + y)){
            x--;
            pathRecord(x,y);
            reverseFinder(arr, word, x, y);
        }
    }
    if(x - 1 >= 0 && y - 1 >= 0 && *(word + count)!='\0'){// top left
        if (*(word + count) == *(*(arr + (x - 1)) + (y - 1))){
            x--;y--;
            pathRecord(x,y);
            reverseFinder(arr, word, x, y);
        }
    }
    if(*(word+count) != '\0'){
        reset();
        x = q;
        y = p;
        findOrder(arr, word, x, y);
    }else{
        find = 1;
    }
}