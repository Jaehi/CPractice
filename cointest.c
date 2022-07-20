#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

int main(){
    int coin_count; //동전 몇개
    int coin_result; //얼마
    int coin[coin_count-1]; //어떤 동전
    int list_result[coin_count][coin_result];//냅다 느
    int star_result[coin_count-1];
    int star_count = 0;
    int min;
    int i = 0;
    int count;
    
    scanf("%d %d",&coin_count,&coin_result);
    for (int i = 0; i < coin_count; i++)
    {
        scanf("%d",&coin[i]);
        
    }
    int result = coin_result;

    while (i < coin_count)
    {
        int rest[coin_count];
        int number = coin[i];
       printf("^^^ %d ^^^\n",number);
       printf("$$$ %d $$$\n",result);
      
        if(result >= number){
            
            result = result - number;
            rest[i] = result;
           printf("### %d ###\n",rest[i]);
            star_count += 1;
           printf("=== %d === [%d]\n",star_count,coin[i]);
           
        }else{

            star_result[i] = star_count;
            result = coin_result;
            star_count = 0;
            i++;
        }
        
    }
    i = 0;
    

    for (int l = 0; l < coin_count; l++)
    {
        if (l == 0)
        {
            min = star_result[l];
        }else if(star_result[l] < min){
            min = star_result[l];
        }
    
        
    }
    printf("%d\n",min);
    

    

    for (int i = 0; i < coin_count; i++)
    {
       printf("%d ",star_result[i]);
    }
    
    // while(i != coin_count){
    //     int coin_now = coin[i];
    //     printf("000 %d 000\n",coin_now);
    //     int result = coin_now * k;
    //     printf("@@@ %d @@@\n",result);
    //     list_result[i][j] += result;
    //     if (result == coin_result)
    //     {
    //         count ++;
    //     }
    //     k++;
    //     j++;
    //     if (result >= coin_result)
    //     {
    //         k = 1;
    //         j = 0;
    //         i++;
            
    //     }
        
    // }

  

    

    
 
    return 0;


}