//INCLUDES
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>



//DEFINES
#define true 1
#define false 0
#define clear() printf("\e[1;1H\e[2J")



//PROTOTYPES
void interface();
void createtodo();
void adjustcount();


//data
typedef struct ToDo todo;


struct ToDo {
    //What the text consists of
    char buffer[255];

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

    clear();

    while(true){

        printf("\t1. Show To Do list\n");
        printf("\t2. New To Do\n");
        printf("\t3. Delete To DO\n");
        printf("\t4. EXIT\n");
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
            case 4:
                //TODO
                exit(1);
            default:
                printf("\tInvalid choice\n");
                exit(1);
        }
    }
    
}



void createtodo(){
    //choice
    char c;

    //pointers
    todo *add, *temp;
    clear();

    //if 'n' is pressed it breaks out of the loop
    while(true){
        printf("Want to add a new To Do? \n");
        printf("Press 'y' for yes and 'n' for no\n");
        printf("Choice> ");
        fflush(stdin);

        //GETS INPUT
        scanf("%c", &c);

        if(c == 'n'){
            break;
        }
        else{
            if(start == NULL){
                add = (todo*)calloc(1, sizeof(todo));

                start = add;
                printf("TO DO...\n");

                fflush(stdin);
                gets(add->buffer);

                add->count = 1;

                start->next = NULL;

            }

            else{
                temp = (todo*)calloc(1, sizeof(todo));
                printf("TO DO...\n");
                fflush(stdin);
                gets(temp->buffer);

                temp->next = NULL;

                add->next = temp;
                add = add->next;
            }

            adjustcount();
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



void adjustcount(){
    todo* temp;
    int i = 1;
    temp = start;

    while(temp != NULL){
        temp->count = i;
        i++;
        temp = temp->next;
    }
}