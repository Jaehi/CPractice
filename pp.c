#include <stdio.h>

int main(){
    int j = 1 ;
    int k = 1 ;
   for (int i = 1; i <= 40; i++)
   {
        printf("%d %d\n",j,k);
          
          j = j + k;
          k = j - k;
   }
    return 0;
}