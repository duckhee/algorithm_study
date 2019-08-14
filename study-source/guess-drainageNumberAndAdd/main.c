/**
 * File Name : main.c
 * Author    : doukhee
 * Version   : v1.0
 * Date      : 08/14/2019
 * 
 * 문제
 *  1 ~ 1000 사이의 숫자 중 사용자가 입력한 숫자 배수의 개수와 배수의 총합을 구하는 문제
 */

#include <stdio.h>

int main(){
    int i, num, count = 0;
    long sum = 0;

    printf("1부터 1000 사이에서 선택한 수의 배수가 몇개이고, 배수의 합은 얼마인가 ? \r\n");
    printf("1부터 1000 사이의 수 중에서 하나를 입력하시오 : ");
    scanf("%d", &num);

    for(i = 0; i < 1000; i++){
        if(i % num == 0){
            sum += i;
            count++;
        }
    }
    printf("1부터 1000 사이의 %d의 배수의 갯수 : %d, 배수의 합 : %ld\r\n", num, count, sum);
    return 0;
}