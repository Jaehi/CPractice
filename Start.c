#include <stdio.h>

int main(){

    int count;

    scanf("%d",&count);

    int a[100];

    for (int i = 0; i < count; i++)
    {
        scanf("%d", &a[i]);
    }
    
    for(int i = 0; i < count; i++){
        printf("%d\n",a[i]);
    }
    
    for (int i = 0; i < count-1; i++)
    {
        for (int j = 0; j < count-1; j++)
        {
           if (a[j] > a[j+1])
           {
               int temp;
               temp = a[j];
               a[j] = a[j+1];
               a[j+1] = temp;
           }
           
        }
        
    }

    for (int i = 0; i < count; i++)
    {
        printf("%d",a[i]);
    }
    
    


    return 0;
}