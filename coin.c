#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

int min (int a, int b){
    if (a < b)
    {
        return a;
    }else{
        return b;
    }
}

int main(){
    int coin_count; 
    int coin_result; 
    int coin[105]; 
    int result[10005];
    int state;
    result[0] = 0;

    scanf("%d %d",&coin_count,&coin_result);
    
    for (int i = 1; i <= coin_count; i++)
    {
        scanf("%d",&coin[i]);
    }

    if ((1 <= coin_count) && (coin_count<= 100) && (1 <= coin_result) &&(coin_result <= 10000))
    {
        for (int i = 1; i <= coin_count; i++)
        {
                if (coin[i] <= coin_result)
                {
                    state = 1;

                }
        }

        if (state == 1)
        {
            for (int i = 1; i <= coin_result; i++)
            {
                result[i] = coin_result +1;
            }
    
            for (int i = 1; i <= coin_count; i++)
            {
                for (int j = coin[i]; j <= coin_result; j++)
                {
                    if (result[j - coin[i]] <= coin_result)
                    {
                        result[j] = min(result[j], result[j - coin[i]] + 1);
                        printf("000 %d 000 \n",result[j]);
                        if (result[j] <= coin_result +1)
                        {
                            break;
                        }   
                    }
                }   
            }
            printf("%d",result[coin_result]);
         }
        //else if(){
        //     printf("%d",-1);
        // }


    }else{
        printf("%d",-1);
    }
    return 0;
    
    
}