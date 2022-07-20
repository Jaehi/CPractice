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
    
    printf("값 : ");
    scanf("%d", &number);
    head -> value = number;
  
    while(1){
        struct Lin* some = (struct Lin*)malloc(sizeof(struct Lin*));
        struct Lin * bingle = head;
        printf("값 : ");
        scanf("%d", &number);

        some -> value = number;
        
        if(some -> value < head -> value){
            some -> next = head;
            head = some;
            
        }else{
             
             while(bingle != NULL ){
            if (some -> value > bingle -> value)
            {   
                bingle = bingle -> next;
                if(bingle -> next == NULL){
                    bingle -> next = some;
                }
            }else{
                break;
            }
            }

        }

        
        while (bingle != NULL){
            printf("%d",bingle -> value);
            bingle = bingle -> next;
        }
        printf("\n");
       
    }
}