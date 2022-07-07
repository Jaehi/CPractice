#include<stdio.h>

int main(){

    int first[3][4];
   
    int result = 0;

    for (int i = 0; i <= 2; i++)
    {
        for (int j = 0; j <= 3; j++)
        {
            scanf("%d",&first[i][j]);
        }
        
    }
  
    for (int i = 0; i <= 2; i++)
    {
        for (int j = 0; j <= 3; j++)
        {
        
            if (first[i][j] == 0){
                result += 1;
            }
            
        }
        switch (result)
            {
            case 0 : 
                printf("E");
                break;
            case 1 : 
                printf("A");
                break;
            case 2 :
                printf("B");
                break;
            case 3 : 
                printf("C");
                break;
            case 4 : 
                printf("D");
                break;

            default: 
                printf("ERROR");
                break;
            }
        printf("\n");
        result = 0;
        
    }
    return 0;
}