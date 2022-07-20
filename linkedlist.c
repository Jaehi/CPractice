//머리에서 생각난 그대로 바로 적은거라
//코드가 많이 더럽습니다
//나중에 차차 정리하도록 하겠습니다.
#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
struct Lin
{
    int value;
    struct Lin * next;
};


int main(){

    int number;
    int state = 0;

    struct Lin * head = (struct Lin*)malloc(sizeof(struct Lin*));
    
    printf("값 : ");
    scanf("%d", &number);
    head -> value = number;
    printf("%d\n",head->value);

    while(1){
        struct Lin* some = (struct Lin*)malloc(sizeof(struct Lin*)); 
        struct Lin * bingle; 
        struct Lin * temp;
        printf("값 : ");
        scanf("%d", &number);

        some -> value = number; 
				//bingle은 head의 값을 가짐
        bingle = head; 
				//some -> value 값이 bingle ->과 같으면 삭제
        if(some -> value == bingle -> value){
                temp = head -> next;
                free(head);
                free(some);
                printf("삭제\n");
                head =  temp;
                state = 1;
        }
				//head의 next 값이 NULL이 아니면 노드를 순환하면서 같은 값이 들어가면 삭제
        while (bingle->next != NULL)
        {
            if (some -> value == bingle ->next -> value)
            {
                temp = bingle->next;
                bingle -> next = temp -> next;
                free(temp);
                free(some);
                printf("삭제\n");
                state = 1;
            }
            bingle = bingle -> next;
        }

        bingle = head;

				//삭제가 진행되지 않았을 때 value값을 비교해서 추가
        if (state != 1)
        {
						//some의값이 head보다 작을경우
            if(some -> value < head -> value){
            some -> next = head;
            head = some;
            printf(" = %d\n",head -> value);
            
            }else{
						//some의 값이 head보단 크고 bingle -> next가 NULL이 아닐때
            while(bingle->next!= NULL ){
            if (some -> value < bingle->next-> value)
            {   
                some -> next = bingle ->next;
                bingle -> next = some;
                break;
            }
            bingle = bingle -> next;
            }

            bingle -> next = some;
            }
        }
				//bingle을 다시 head에 연결
        bingle = head;
        printf("완료!\n");
        
        while (bingle != NULL){
            printf("%d ",bingle -> value);
            bingle = bingle -> next;
        }
        printf("\n");
				//state 초기화
        state = 0;
       
    }
    return 0;
}