/**
 * File Name : main.c
 * Author    : doukhee
 * Version   : v1.0
 * Date      : 08/14/2019
 * 
 * 문제 
 * 재귀 호출을 사용한 방식과 반복문을 이요하여 만든 프로그램을 비교해서 재귀 호출을 사용할 때의 장점과 단점을 알아보자
 * 
 */

#include <stdio.h>

int gcd(int, int);

int gcd(int x, int y){
    static int ExecNum = 1;
    printf("%d회 실행한다.\r\n", ExecNum++);

    if(y != 0){
        printf("x : %d, y : %d\r\n", x, y);
        return gcd(y, x%x);
    }else{
        return x;
    }
}

int main(){
    
    int result;
    int num1, num2;
    printf("최대 공약수를 구하는 프로그램 \r\n");
    printf("2개의 수를 입력하시오 \r\n");
    printf("입력 => ");
    scanf("%d %d", &num1, &num2);

    result = gcd(num1,num2);
    printf("%d와 %d의 최대 공약수는 : %d \r\n", num1, num2, result);
    return 0;
}