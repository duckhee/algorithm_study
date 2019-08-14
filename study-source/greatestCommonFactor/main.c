/**
 * File Name : greatest common factor
 * Author    : doukhee
 * Version   : v1.0
 * Date      : 08/14/2019
 * 
 * 문제 
 * 두개의 숫자를 입력 받아 두 숫자의 최대 공약수를 구하는 프로그램 
 */

#include <stdio.h>

int main(){
    int data1, data2;
    int i, num, max;
    printf("약수를 구할 두 정숫값을 입력하시오\r\n");

    printf("input 1 : ");
    scanf("%d", &data1);

    printf("input 2 : ");
    scanf("%d", &data2);

    if(data1 > data2){
        num = data2;
    }
    else{
        num = data1;
    }

    for(i = 1; i <= num; i++){
        if(((data1 % i) == 0) && (data2 % i) == 0){
            max = i;
        }
    }
    printf("%d와 %d의 최대 공약수는 %d이다. \r\n", data1, data2, max);
    return 0;
}