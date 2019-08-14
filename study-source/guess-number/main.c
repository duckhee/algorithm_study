/**
 * File Name : man.c
 * Author    : doukhee
 * Version   : v1.0
 * Date      : 08/14/2019
 * 문제 
 * 랜덤 숫자 맞추기 프로그램
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main()
{
    int num, i, data;
    srand(time(NULL));
    num = rand() % 10;
    i = 1;
    printf("input 0 ~ 9 number \r\n");

    while(1){
        printf("[%2d try ] : ", i);
        scanf("%d", &data);

        if(data < num){
            printf("more bigger than %d\r\n", data);
        }else if(data > num){
            printf("more small than %d \r\n", data);
        }else{
            printf("current right number time %d \r\n", i);
            break;
        }
        i++;
    }
    return 0;
}
