/**
 * File Name : main.c
 * Author    : doukhee
 * Version   : v1.0
 * Date      : 08/14/2019
 * 문제
 * 두 숫자에 공통으로 해당하는 약수 구하는 프로그램
 */

#include <stdio.h>

int main()
{
    int data1, data2;
    int i, num;

    printf("공약수를 구할 두 정숫값을 입력하시오 \r\n");

    printf("입력할 숫자 첫 번째 : ");
    scanf("%d", &data1);

    printf("입력할 숫자 두 번째 : ");
    scanf("%d", &data2);

    if(data1 > data2){
        num = data1;
    }
    else
    {
        num = data2;
    }

    for(i = 1; i <= num; i++){
        if(((data1 % i) == 0) && ((data2 & i) == 0)){
            printf("%4d", i);
            printf("\r\n");
        }
        if((i == data1) || (i == data2)){
            break;
        }
    }
    return 0;
}