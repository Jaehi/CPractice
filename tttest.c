#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

struct Lin
{
    int value;
    struct Lin * next;
};

int main(){

    int number;

    struct Lin * head = (struct Lin*)malloc(sizeof(struct Lin*));
    struct Lin * temp;
    struct Lin * previous;
    char state[10];
    struct Lin * pos = head;
    printf("값 : ");
    scanf("%d", &number);
    head -> value = number;
    temp = head;
    
    while(1){
        struct Lin* some = (struct Lin*)malloc(sizeof(struct Lin*));
        
        printf("\npush, pop : ");
        scanf("%s", state);
        
        if (strcmp(state,"push")==0)
        {
        printf("값 : ");
        scanf("%d", &number);
        some -> value = number;
        temp -> next = some;
        temp = some;
        pos = head;
        
        printf("%d\n",temp -> value);
        printf("추가\n");
        while (pos != NULL){
            printf("%d \n",pos -> value);
            printf(" ----- %d -----\n",pos -> value);
            pos = pos -> next;
        }
        printf("\n");
        }
        
        else if(strcmp(state,"pop") == 0){

            if(head -> next != NULL){
                if(head != NULL){
                pos = head;
                previous = NULL;

                while(pos -> next != NULL ){
                   // printf(" *** %d *** ", pos -> next -> value);
                    previous = pos;
                    pos = pos -> next;
                   // printf("^^^ %d ^^^\n",previous -> value);
                }

            printf(" 000 %d 000\n",pos -> value);
            
            if (previous != NULL)
            {
                previous -> next = NULL;
            }

            if (head != NULL)
            {
                printf(" @@@ %d @@@ \n",pos -> value);
                free(pos);
                printf("삭제 \n");
                pos = head;
                printf("**** %d ****\n",pos -> value);
            }

            while (pos -> next != NULL){
            printf("%d ",pos -> value);
            pos = pos -> next;
            printf("### %d ###\n",pos -> value);
            }

            }
            }else{
                printf("값 : ");
                scanf("%d", &number);
                pos -> value = number;
            }
           }
           }
           }
