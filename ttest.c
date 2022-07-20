#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

struct Lin
{
    int a;
    struct Lin *next;
    struct Lin *back;
};


int main(){
    int i;
    struct Lin *head = (struct Lin*)malloc(sizeof(struct Lin));

        scanf("%d",&i);
        head->a=i;
//     struct Lin *a = malloc(sizeof(struct Lin));
//     struct Lin *b = malloc(sizeof(struct Lin));
//     struct Lin *c = malloc(sizeof(struct Lin));

//     head -> next = a;
//     a -> a = 3;
//     b -> a = 4;
//     c -> a = 5;

//     a -> next = c;
//     c -> next = b;

//    
//             }

    while(1){
        struct Lin *some = (struct Lin*)malloc(sizeof(struct Lin));
        
        scanf("%d",&i);
        
        some -> a = i; 

        if (head == NULL)
        {
            head = some;
            head -> next = NULL;
        }
        
        some -> next = head -> next;
        
        head -> next = some;

        //some -> next = some -> next;

        some -> next = NULL;

        struct Lin *bingle = head;

        while (bingle != NULL)
            {     
                printf("%d",bingle -> a);
                bingle = bingle -> next;

            }
            printf("\n");

        while (bingle == NULL){
                    bingle -> next = some;
                    bingle = some;
                    bingle = bingle -> next;
                    printf("\n");
                    break;
        }
    }
}
