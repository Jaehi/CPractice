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
    struct Lin * prev;
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
        printf("추가");

        while (pos != NULL){
            printf("%d ",pos -> value);
            //printf(" ----- %d -----\n",temp -> value);
            pos = pos -> next;
        }
        
        printf("\n");
        }
        
        else if(strcmp(state,"pop") == 0){

            if(head -> next != NULL){
                if(head != NULL){
            pos = head;
            prev = NULL;

            while(pos -> next != NULL ){
                printf(" *** %d ***\n", pos -> next -> value);
                prev = pos;
                pos = pos -> next;
            }

            printf(" 000 %d 000\n",pos -> value);
            
            if (prev != NULL)
            {
                prev -> next = NULL;
            }

            if (head != NULL)
            {
                free(pos);
                printf("삭제 \n");
                pos = head;
            }

            while (pos != NULL){
            printf("%d ",pos -> value);
            pos = pos -> next;
            }

            }
            }else{
                printf("값 : ");
                scanf("%d", &number);

                prev -> value = number;
                temp -> next = prev;
                temp = prev;
                
            }
           }
           }
           }
