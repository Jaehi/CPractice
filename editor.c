#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

struct Link{
    char data;
    struct Link * next;
    struct Link * prev;
};

struct Editor{
    struct Link * head;
    struct Link * tail;
    struct Link * cur;
};

char first_data[100000];
int length = 0;
int count = 0;
char order;
char aid;
int state;

int main(){
    
    scanf("%s",first_data);
    scanf("%d",&count);
    struct Editor editor;
    editor.head = NULL;
    editor.tail = NULL;
    editor.cur = NULL;

    length = strlen(first_data);
    for (int i = 0; i < length; i++)
    {
        struct Link * N = (struct Link * )malloc(sizeof(struct Link)); 
        N -> next = NULL;
        N -> prev = NULL;
        N -> data = first_data[i];

        //head tail 연결
        if( i == 0 ){

            editor.head = N;
            editor.cur = N;
            editor.tail = N;
            printf("&&& %c %c &&&\n",editor.head -> data,editor.cur -> data);

        }else if(i == length -1){
            editor.tail = N;
            editor.tail -> prev = editor.cur;
            editor.cur -> next = N;
            printf("^^^ %c ^^^\n",editor.tail -> data);

        }else{
            
            N -> prev = editor.cur;
            editor.cur -> next = N;
            editor.cur = N;
            printf("((( %c )))\n",editor.cur -> data);

        }
        
    }
    
    editor.cur = NULL;
    state = 2;

    for (int i = 0; i < count; i++)
    {
        scanf(" %c",&order);

        switch (order)
        {
        case 'L':
            if (editor.cur == NULL){
                
                editor.cur = NULL;
                state = 1;
                break;

            }else if(editor.cur -> prev == NULL)
            {
                editor.cur -> next = editor.head;
                state = 1;
                break;
            }

            editor.cur = editor.cur -> prev;
            printf("현재 커서 위치 : %c\n", editor.cur -> data);
            break;

        case 'D':
            if (editor.cur == NULL)
            {
                break;

            }else if(editor.cur -> next == NULL){
                
                editor.cur = NULL;
                state = 2;
                break;
            }
            editor.cur = editor.cur -> next;
            printf("현재 커서 위치 : %c\n", editor.cur -> data);

            break;

        case 'B':
            {struct Link * temp; 
            if (editor.cur == NULL)
            {
                switch (state)
                {
                case 1:
                    if (editor.head == NULL)
                    {
                        printf("===== \n");
                        
                    }else{
                        printf("あ \n");
                    }
                    break;
                case 2:

                    if(editor.tail == NULL ){
                        printf("b state 2 tail == NULL : %c\n",editor.cur -> data);
                        break;
                    }
                    else if (editor.tail -> prev == NULL)
                    {
                        
                        free(editor.tail);
                        editor.tail = NULL;
                        editor.head = NULL;
                        printf("b state 2 tail -> prev == NULL : \n");
                        break;

                    }else{
                        editor.cur = editor.tail -> prev;
                        free(editor.cur -> next);
                        editor.cur -> next = NULL;
                        editor.tail = editor.cur;
                        printf(" b state 2  : %c \n",editor.tail -> data);
                        editor.cur = NULL;
                        break;
                    }
                default:
                    break;
                }

                break;

            }else if (editor.cur -> next == NULL)
            {
                editor.cur -> prev -> next = NULL;
                editor.tail = editor.cur -> prev;
                free(editor.cur);
                editor.cur = editor.tail;
                printf("b cur next NULL 아닐 때 : %c\n",editor.cur -> data);
            }

            editor.cur -> prev -> next = editor.cur -> next;
            editor.cur -> next -> prev = editor.cur -> prev;
            temp = editor.cur -> prev;
            free(editor.cur);
            editor.cur = temp;
            printf("b dmdkr : %c\n", editor.cur -> data);
            if(editor.cur -> prev == NULL){
                editor.cur = NULL;
            }
            break;

            }

        case 'P':{
            struct Link * plus = (struct Link * )malloc(sizeof(struct Link)); 
            scanf(" %c",&aid);
            if(editor.cur == NULL){
                switch (state)
                {
                case 1:
                    editor.cur = editor.head;
                    plus -> data = aid;
                    plus -> next = editor.cur;
                    editor.cur -> prev = plus;
                    editor.head = plus;
                    editor.cur = editor.head;
                    printf("P cur == NULL case 1 : %c\n",editor.head -> data);
                    break;

                case 2:
                    editor.cur = editor.tail;
                    plus -> data = aid;
                    plus -> prev = editor.cur;
                    editor.cur -> next = plus;
                    editor.tail = plus;
                    editor.cur = NULL;
                    printf("P cur == NULL case 2 : %c\n",editor.tail -> data);

                default:

                    break;

                }
            }else if (editor.cur -> next == NULL)
            {
                plus -> data = aid;
                editor.cur -> next = plus;
                plus -> prev = editor.cur;
                editor.tail = plus;
                editor.cur = plus;
                printf("P cur -> next == NULL : %c\n",editor.cur -> data);
            }
            else{

                plus -> data = aid;
                editor.cur -> next -> prev = plus;
                plus -> next = editor.cur -> next;
                editor.cur -> next = plus;
                plus -> prev = editor.cur;
                editor.cur = plus;
                printf("P NULL 아닐 때 : %c\n",editor.cur -> data);
            }
            break;
            }
        default:
            break;
        }
    }
        editor.cur = editor.head;
    do
    {
        printf("%c ",editor.cur -> data);
        editor.cur = editor.cur -> next;
    } while (editor.cur != NULL);

    return 0;
}