#include<stdio.h>

#include<string.h>


int main(){
    char test [100];

    scanf("%s",test);

    int testt = strlen(test);

    printf("%d",testt);

    for (int i = 0; i < testt; i++)
    {
        printf("%c ", test[i]);
    }
    
}