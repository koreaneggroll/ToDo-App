//INCLUDES
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>


//DEFINES
#define true 1
#define false 0
#define clear() printf("\e[1;1H\e[2J")



//PROTOTYPES
void interface();
void create_todo();
void del_todo();
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

        printf("\n\n\t1. Show To Do list\n");
        printf("\t2. New To Do\n");
        printf("\t3. Delete To Do\n");
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
                del_todo();
                break;
            case 4:
                exit(1);
            default:
                if (!isdigit(choice)){
                    printf ("\n\n\n\tERR: Please enter a valid number\n\n\n");
                    exit(1);
                }
                exit(1);
        }
    }
    
}



void create_todo(){
    //choice
    char c;

    //pointers
    todo *add, *tmp;
    clear();

    //if 'n' is pressed it breaks out of the loop
    while(true){
        printf("\tWant to add a new To Do? Press 'y' for yes and 'n' for no\n");

        sleep(1);
        //GETS INPUT
        scanf("%c", &c);

        if(c == 'n'){
            break;
        }
        else if(c != 'y'){
            printf("Please only enter 'y' and 'n'");
            continue;
        }




        else{

            if(start == NULL){

                printf("\tWant to add a new To Do? Press 'y' for yes and 'n' for no \n");

                //GETS INPUT
                scanf("%c", &c);

                if(c == 'n'){
                    break;
                }


                add = (todo*)calloc(1, sizeof(todo));

                if(add == NULL){
                    printf("\n\n\n\tERR: Coudn't allocate memory\n\n\n");
                    exit(1);
                }

                start = add;
                printf("\tTO DO...\n");

                fgets(add->buffer, 255, stdin);


                if(tmp->buffer == NULL){
                    printf("The to do taks can't be empty\n");
                    continue;
                }

                add->count = 1;

                start->next = NULL;


            }

            else{

                printf("\tWant to add a new To Do? Press 'y' for yes and 'n' for no\n");

                //GETS INPUT
                scanf("%c", &c);

                if(c == 'n'){
                    break;
                }


                tmp = (todo*)calloc(1, sizeof(todo));

                if(tmp == NULL){
                    printf("\n\n\n\tERR: Couldn't allocate memory\n\n\n\n");
                    exit(1);
                }

                printf("\tTO DO...\n");

                fgets(tmp->buffer, 255, stdin);

                tmp->next = NULL;

                add->next = tmp;
                add = add->next;


            }

            adjust_count();
        }
    }

    printf("\n\n\n");
}



void del_todo(){
    clear();

    if(start == NULL){
        printf("\n\n\n\tERR: No To Do's\n\n\n");
    }

    int x;

    todo *del, *tmp;
    printf("\n\tEnter To Do's number: \n");
    
    scanf("%d", &x);

    del = start;

    tmp = start->next;

    while(true){
        if(del->count == x){
            start = start->next;

            free(del);

            adjust_count();
            break;
        }

        if(tmp->count == x){
            del->next = tmp->next;
            free(tmp);
            adjust_count();
            break;
        }

        else{
            del = tmp;
            tmp = tmp->next;
        }
    }

    printf("\n\n\n\n");

}



void see_todo(){

    clear();

    todo* tmp = start;

    if(start = NULL){
        printf("\tThe todo list is empty\n");
    }

    while(tmp != NULL){
        printf("\t%d. %s", tmp->count, tmp->buffer);

        tmp = tmp->next;
    }

    printf("\n\n\n\n\n\n\n");
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