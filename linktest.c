#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
struct Lin
{
    int value;
    struct Lin * next;
};


int main(){

    int number;
    int state = 0;

    struct Lin * head = (struct Lin*)malloc(sizeof(struct Lin*));
    
    printf("값 : ");
    scanf("%d", &number);
    head -> value = number;
    printf("%d\n",head->value);

    while(1){
        struct Lin* some = (struct Lin*)malloc(sizeof(struct Lin*)); 
        struct Lin * bingle; 
        struct Lin * temp;
        printf("값 : ");
        scanf("%d", &number);

        some -> value = number; 
        bingle = head; 

        if(some -> value == bingle -> value){
                temp = head -> next;
                free(head);
                free(some);
                printf("삭제\n");
                head =  temp;
                state = 1;
        }

        while (bingle->next != NULL)
        {
            if (some -> value == bingle ->next -> value)
            {
                temp = bingle->next;
                bingle -> next = temp -> next;
                free(temp);
                free(some);
                printf("삭제\n");
                state = 1;
            }
            bingle = bingle -> next;
        }

        bingle = head;

        if (state != 1)
        {
            if(some -> value < head -> value){
            some -> next = head;
            head = some;
            printf(" = %d\n",head -> value);
            
            }else{

            while(bingle->next!= NULL ){
            if (some -> value < bingle->next-> value)
            {   
                some -> next = bingle ->next;
                bingle -> next = some;
                break;
            }
            bingle = bingle -> next;
            }

            bingle -> next = some;
            }
        
        }
        bingle = head;
        printf("완료!\n");
        
        while (bingle != NULL){
            printf("%d ",bingle -> value);
            bingle = bingle -> next;
        }
        printf("\n");
        state = 0;
       
    }
    return 0;
}