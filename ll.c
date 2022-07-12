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
    struct Lin * stella;
    char state[10];
    struct Lin * bingle = head;
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
        bingle = head;
        
        printf("%d\n",temp -> value);
        printf("추가");
        while (bingle != NULL){
            printf("%d ",bingle -> value);
            // printf(" ----- %d -----\n",temp -> value);
            bingle = bingle -> next;
        }
        printf("\n");
        }
        
        else if(strcmp(state,"pop") == 0){

            if(head -> next != NULL){
                if(head != NULL){
            bingle = head;
            stella = NULL;

            while(bingle -> next != NULL ){
                printf(" *** %d ***\n", bingle -> next -> value);
                stella = bingle;
                bingle = bingle -> next;
            }

            printf(" 000 %d 000\n",bingle -> value);
            
            if (stella != NULL)
            {
                stella -> next = NULL;
            }

            if (head != NULL)
            {
                free(bingle);
                printf("삭제 \n");
                bingle = head;
            }

            while (bingle != NULL){
            printf("%d ",bingle -> value);
            bingle = bingle -> next;
            }

            }
            }else{
                printf("값 : ");
                scanf("%d", &number);

                stella -> value = number;
                temp -> next = stella;
                temp = stella;
            }
           }
           }
           }
