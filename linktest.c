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
    struct Lin * cur;
    printf("값 : ");
    scanf("%d", &number);
    head -> value = number;
    cur = head;
    while(1){
        struct Lin* some = (struct Lin*)malloc(sizeof(struct Lin*));
        printf("값 : ");
        scanf("%d", &number);
        some -> value = number;
        cur -> next = some;
        cur = some;
        struct Lin * bingle = head;
        while (bingle != NULL){
            printf("%d",bingle -> value);
            bingle = bingle -> next;
        }
        printf("\n");
       
    }
}