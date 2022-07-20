#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

char seat[100][100][100];

void addUser(int x, int y,char name[100]){
    strcpy(seat[x][y],name);
    printf("예약 완료.\n");
}

void checkUser(int x, int y){
    printf("%s님의 좌석 입니다.\n",seat[x][y]);
}

void deleteUser(int x, int y){
    strcpy(seat[x][y],"");  
}

int main(){
    int x;
    int y;
    int state;
    char a[100];
    char stateNm[10];
    
      for (int i = 0; i < 100 ; i++)
        {
            for (int j = 0; j < 100; j++)
            {       
                strcpy(
                    seat[i][j],""
                );}}

       while (1)
       {    
           printf("예약,종료 : ");
           scanf("%s", stateNm);
           if (strcmp(stateNm,"예약")==0)
           {
               state = 1;
           }else{
               //종료
               state = 2;
           }
           
            switch (state) {

                case 1:
        
                    scanf("%d %d", &x,&y);
                    scanf("%s", a);
            
                    if(strcmp(a,"out")==0){
                        deleteUser(x,y);
                        printf("%s 퇴실\n",seat[x][y]);
                    }
                    else if(strcmp(seat[x][y],"") != 0){
                        checkUser(x,y);

                    }else{
                        addUser(x,y,a);
                    }

                    break;
                
                case 2:
                    exit(1);
                    
                default:
                    break;}}
  
    return 0;
}