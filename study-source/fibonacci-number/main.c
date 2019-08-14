/**
 * File name : main.c
 * Author    : doukhee
 * Version   : v1.0
 * Date      : 08/14/2019
 * 
 * 문제 
 * 피보나치 수열 구하는 프로그램
 * 
 */

#include <stdio.h>

int main(){
    int i, value_new, value_1, value_2;

    printf("get fibonacci number\r\n");
    i = 0;
    value_1 = 1;
    value_2 = 0;

    while(i < 24){
        value_new = value_1 + value_2;

        if(!(i % 12)){
            printf("\r\n");
        }

        printf("%6d", value_new);

        value_2 = value_1;
        value_1 = value_new;
        i++;
    }
    printf("\r\n");
    return 0;
}