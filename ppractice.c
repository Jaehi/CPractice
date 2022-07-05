#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

int main(){
    char a = 'a';
    char b = 'a';
    printf("%d",strcmp(&a,&b));
    return 0;
}