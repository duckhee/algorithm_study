/**
 * File Name : main.c
 * Author    : doukhee
 * Version   : v1.0
 * Date      : 08/14/2019
 * 문제
 * 1 ~ 1000 사이의 숫자 중에서 1과 그 자신 이외의 정수로는 나누어지지 않는 소수를 구하는 프로그램
 */

#include<stdio.h>

int main(){
    int i, j, count = 1;
    long sum = 0;

    printf("1부터 1000 사이의 수 중에서 소수를 구하는 프로그램 \r\n");
    printf("%d\t", 1);

    for(i = 1; i < 1000; i++){
        for(j = 2; j < i; j++){
            if((i%j) == 0){
                break;
            }
        }
        if(i == j){
            printf("%d\t", i);
            count++;
            if((count % 8) == 0){
                printf("\r\n");
            }
        }
    }
    printf("\r\n 1부터 1000 사이의 소수는 %d개 이다. \r\n", count);

    return 0;
}