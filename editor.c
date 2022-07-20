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
    editor.head = (struct Link * )malloc(sizeof(struct Link));
    editor.tail = (struct Link * )malloc(sizeof(struct Link));
    editor.head -> data = 'h';
    editor.tail -> data = 't';
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

            editor.head -> next = N;
            editor.tail -> prev = N;
            editor.cur = N;
            editor.cur -> prev = editor.head;
            editor.cur -> next = editor.tail;
            printf("&&& %c %c &&&\n",editor.head -> next -> data,editor.tail -> prev -> data);

        }else if(i == length -1){
            printf("마지막 인덱스 하나 전 데이터 : %c \n",editor.cur -> data);
            editor.tail -> prev = N;
            printf("[[[ %c ]]] \n",editor.tail -> prev -> data);
            N -> prev = editor.cur;
            editor.cur -> next = N;
            editor.cur = N;
            editor.cur -> next = editor.tail;
            printf("^^^ %c ^^^\n",editor.tail -> prev -> data);

        }else{
            editor.cur -> next = N;
            editor.tail -> prev = N;
            N -> next = editor.tail;
            N -> prev = editor.cur;
            editor.cur = N;
            printf("((( %c )))\n",editor.cur -> data);
        }
    }
    
    editor.cur = editor.tail -> prev;

    printf("시작 전임 : %c\n",editor.cur -> data);

    for (int i = 0; i < count; i++)
    {
        printf("order : \n");
        scanf(" %c",&order);

        switch (order)
        {
            case 'L':
            if (editor.cur -> prev != NULL)
            {
                editor.cur = editor.cur -> prev;
                printf("현재 커서 위치 : %c \n",editor.cur -> data);
            }
            break;
           
            case 'D':
            if (editor.cur -> next != editor.tail)
            {
                editor.cur = editor.cur -> next;
                printf("현재 커서 위치 : %c \n",editor.cur -> data);
            }
            break;
            
            case 'B':
            {
                struct Link * temp; 

                if (editor.cur == editor.head)
                {
                    printf("B 왼쪽이없음 : %c \n",editor.cur -> data);
                    break;

                }else if(editor.cur -> next == editor.tail){
                    editor.tail -> prev = editor.cur -> prev; 
                    editor.cur -> prev -> next = editor.tail;
                    temp = editor.cur -> prev;
                    free(editor.cur);
                    editor.cur = temp;
                    printf("tail옆에 지움 : %c \n",editor.cur -> data);
                    break;

                }else{
                    editor.cur -> prev -> next = editor.cur -> next;
                    editor.cur -> next -> prev = editor.cur -> prev;
                    temp = editor.cur -> prev;
                    free(editor.cur);
                    editor.cur = temp;
                    printf("%c 지움 : %c %c \n",editor.cur -> prev -> data ,editor.cur -> data, editor.cur -> next -> data);
                    break;
                }
            
            }

            case 'P':{
                struct Link * plus = (struct Link * )malloc(sizeof(struct Link)); 
                scanf(" %c",&aid);
                plus -> data = aid;

                if (editor.cur == editor.head)
                {
                    editor.cur -> next -> prev = plus;
                    editor.cur -> next = plus;
                    plus -> prev = editor.cur;
                    plus -> next = editor.cur -> next;
                    editor.cur = editor.cur -> next;

                    printf("%c 헤드일때 넣음 : %c  %c\n",editor.cur -> prev -> data,editor.cur -> data,editor.cur -> next -> data);
                    break;

                }
            
                else{
                    editor.cur -> next -> prev = plus;
                    plus -> next = editor.cur -> next;
                    editor.cur -> next = plus;
                    plus -> prev = editor.cur;
                    editor.cur = editor.cur -> next;
                    printf("%c 넣음 : %c %c \n",editor.cur -> prev -> data ,editor.cur -> data, editor.cur -> next -> data);
                    break;
                }
            }
        }
    }

    editor.cur = editor.head -> next;

    while(1){
        
        if (editor.cur == editor.tail)
        {
            break;
        }
        printf("%c ",editor.cur -> data);
        editor.cur = editor.cur -> next;
        
        
    }
    
        return 0;
}