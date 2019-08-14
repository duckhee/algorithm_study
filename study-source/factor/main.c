/**
 * File Name : main.c
 * Author    : doukhee
 * Version   : v1.0
 * Date      : 08/14/2019
 * 문제 
 * 약수를 구하는 프로그램
 * 
 */

#include <stdio.h>

int main()
{
    int data;
    int i;
    printf("약수를 구할 정숫값을 입력하세요\r\n");
    printf("input : ");
    scanf("%d", &data);

    for(i = 1; i <= data; i++){
        if((data%i) == 0){
            printf("%4d", i);
            printf("\r\n");
        }
    }

    return 0;
}