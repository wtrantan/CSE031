void finder (char** arr, char* word, int x, int y){ //search of next letter clockwise, recursive
    if(x - 1 >= 0 && y - 1 >= 0 && *(word + count)!='\0'){// top left
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
        if (*(word + count) == *(*(arr + (y + 1)) + (y + 1))){
            x++;y++;
            pathRecord(x,y);
            finder(arr, word, x, y);
        }
    }
    if(*(word + count) != '\0'){ //in case of multiple letters in 3x3, search counterclockwise 
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