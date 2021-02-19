//INCLUDES
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>



//DEFINES
#define true 1
#define false 0



//PROTOTYPES
void interface();

//data
typedef struct ToDo todo;


struct ToDo {
    //What the text consists of
    char *buffer;

    //pointer that points to next to do buffer
    todo* next;

    int count;

};
typedef struct ToDo todo;

todo* start = NULL;


//main program
int main(void){
    short choice;
    interface();

    while(true){

        printf("\t1. Show To Do list\n");
        printf("\t2. New To Do\n");
        printf("\t3. Delete To DO\n");
        printf("\t99. EXIT\n");
        printf("\tChoice> ");
        scanf("%hi", &choice);

        switch(choice){
            case 1:
                //TODO
                break;
            case 2:
                //TODO
                break;
            case 3:
                //TODO
                break;
            case 99:
                //TODO
                break;
            default:
                printf("\tInvalid choice\n");
                exit(1);
        }
    }
    
}



void interface() 
{  
    printf("\n\n\n\n"); 
    printf("\t~~~~~~~~~~~~~~~~~~~~~"
           "~~~~~~~~~~~~~~~~~~~~~~~~"
           "~~~~~~~~~~~~~~~~~~~~~~~~"
           "~~~~~~~~~~~~~~~~~~~~~~~"
           "~~~~~~~~~~\n"); 
    printf("\t~~~~~~~~~~~~~~~~~~~~~~"
           "~~~~~~~~~~~~~~~~~~~~~~~"
           "~~~~~~~~~~~~~~~~~~~~~~~"
           "~~~~~~~~~~~~~~~~~~~~~~~~"
           "~~~~~~~~~~\n\n"); 
    printf("\t} : } : } : } : } : } "
           ": } : } : } :   "
           "WELCOME TO the TODO APP "
           "     : { : { : { : { : { "
           ": { : { : { : {\n\n"); 
    printf("\t~~~~~~~~~~~~~~~~~~~~~"
           "~~~~~~~~~~~~~~~~~~~~~~~~"
           "~~~~~~~~~~~~~~~~~~~~~~~~~"
           "~~~~~~~~~~~~~~~~~~~~~~"
           "~~~~~~~~~~\n"); 
    printf("\t~~~~~~~~~~~~~~~~~~~~~~"
           "~~~~~~~~~~~~~~~~~~~~~~~"
           "~~~~~~~~~~~~~~~~~~~~~~~"
           "~~~~~~~~~~~~~~~~~~~~~~~~"
           "~~~~~~~~~~\n"); 
    printf("\n\n\n");
  
    // Pausing screen until user 
    // presses any key 
    
} 
  