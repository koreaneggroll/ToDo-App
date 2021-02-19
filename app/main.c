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
void create_todo();
void see_todo();
void adjust_count();
void todo_to_file();


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
    int choice;

    clear();

    interface();

    while(true){

        printf("\t1. Show To Do list\n");
        printf("\t2. New To Do\n");
        printf("\t3. Delete To DO\n");
        printf("\t4. EXIT\n");
        printf("\tChoice> ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                see_todo();
                break;
            case 2:
                create_todo();
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



void create_todo(){
    //choice
    char c;

    //pointers
    todo *add, *temp;
    clear();

    //if 'n' is pressed it breaks out of the loop
    while(true){
        printf("\tWant to add a new To Do? \n");
        printf("\tPress 'y' for yes and 'n' for no\n");

        //GETS INPUT
        scanf("%c", &c);

        if(c == 'n'){
            break;
        }

        else{

            if(start == NULL){
                add = (todo*)malloc(sizeof(todo));

                start = add;
                printf("\tTO DO...\n");

                fgets(add->buffer, 255, stdin);

                add->count = 1;

                start->next = NULL;

                todo_to_file();
            }

            else{
                temp = (todo*)malloc(sizeof(todo));
                printf("\tTO DO...\n");

                fgets(temp->buffer, 255, stdin);

                temp->next = NULL;

                add->next = temp;
                add = add->next;

                todo_to_file();
            }

            adjust_count();
        }
    }
}



void see_todo(){

    clear();

    todo* tmp = start;

    if(start = NULL){
        printf("The todo list is empty\n");
    }

    while(tmp != NULL){
        printf("%d. %s", tmp->count, tmp->buffer);

        tmp = tmp->next;
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
  
    
} 



void adjust_count(){
    todo* temp;
    int i = 1;
    temp = start;

    while(temp != NULL){
        temp->count = i;
        i++;
        temp = temp->next;
    }
}