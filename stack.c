#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
    int value;
    struct Node * prev;
};

int main(){
    struct Node * tail;
    struct Node * temp = (struct Node*)malloc(sizeof(struct Node*));
    int num;
    char state[10];
    tail = NULL;
    while (1)
    {   
        struct Node * number = (struct Node*)malloc(sizeof(struct Node*));
        printf("push , pop : ");
        scanf("%s",state);
        
        if (strcmp(state,"push") == 0 )
        {
            printf("\nnumber : ");
            scanf("%d",&num);
            number -> value = num;
            number -> prev = tail;
            tail = number;
            temp = tail;
            do{
                printf("%d ",temp -> value);
                temp = temp -> prev;
            }while (temp!= NULL);
            printf("\n");
            
        }else if(strcmp(state,"pop")==0){

            if (tail -> prev != NULL)
            {
                temp = tail;
                tail = temp -> prev;
                free(temp);
                temp = tail;
            do{
                printf("%d ",temp -> value);
                temp = temp -> prev;
            }while (temp!= NULL);
                printf("\n");
            }
            else{
                printf("\nnumber : ");
                scanf("%d",&num);
                tail = NULL;
                number -> value = num;
                number -> prev = tail;
                tail = number;
                temp = tail;
                do{
                    printf("%d ",temp -> value);
                    temp = temp -> prev;
                }while (temp!= NULL);
            }
            printf("\n");
        }else{
            printf("다시 시도\n");
        }

    }
    
}