#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

struct Lin
{
    int a;
    struct Lin *next;
};

struct Lin* insert(int number){
   struct Lin *num = malloc(sizeof(struct Lin));
   num -> a = number; 
   num -> next = NULL;
   return num;
}

int main(){
    int s = insert(3);
    printf("%d",s);
}