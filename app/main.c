#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct ToDo todo;

struct ToDo {
    //What the text consists of
    char *buffer;

    //pointer that points to next to do buffer
    todo* next;

};
typedef struct ToDo todo;

todo* start = NULL;

int main(void){

}