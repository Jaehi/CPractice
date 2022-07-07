#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

struct Lin
{
    int a;
    struct Lin *next;

};

int main(){
    
    char stateNm[10] = "";
    int num;
    struct Lin  *head = malloc(sizeof(struct Lin));
    head = NULL;

   for (int i = 0; i < 100; i++)
   {
        struct Lin *number = (struct Lin*)malloc(sizeof(struct Lin));
            
            scanf("%d",&num);
            number->a = num;
            
            number -> next = number -> next;
            number -> next = NULL;
            struct Lin *bingle = number -> next;
            
            while (bingle != NULL)
            {     
                printf("%d\n",bingle->a);
                bingle = bingle -> next;
            }

   }
   
     
    
           
    
    // while (1)
    // {
    //     printf("입력, 종료 : ");
    //     scanf("%s",stateNm);

    //     if (strcmp("입력",stateNm)==0)
    //     {   
            
            
            
            
            
    //     }else if (strcmp("종료",stateNm) == 0)
    //     {
    //         exit(1);
    //     }
        
        
        
    // }

}