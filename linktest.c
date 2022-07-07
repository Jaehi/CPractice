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
    head = NULL;
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

        }else{

           head -> next = some;
            
        
        }

        struct Lin *bingle = head;

        while (bingle != NULL)
            {     
                printf("%d",bingle->a);
            
                
                bingle = bingle -> next;

                if (bingle == NULL)
                {
                    bingle = some;
                    printf("\n");
                    break;
                }
                
                
            }
}
}