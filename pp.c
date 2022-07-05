#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

int main(){
    int j = 1 ;
    int k = 1 ;
    int l = 0 ;
   for (int i = 1; i <= 40; i++)
   {
        printf("%d %d\n",k,j);
 
        l = k + j;
        j = k;
        k = l;
        l = 0;
       
   }
   
    return 0;
}