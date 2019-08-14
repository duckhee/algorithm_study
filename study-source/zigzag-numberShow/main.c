/**
 * File Name : main.c
 * Author    : doukhee
 * Version   : v1.0
 * Date      : 08/14/2019
 * 문제
 * 1 ~ 25 사이의 숫자를 다음과 같은 실행 결과 형태로 화면에 출력하는 프로그램 만들기
 * 1    2   3   4   5
 * 10   9   8   7   6
 * 11   12  13  14  15
 * 20   19  18  17  16
 * 21   22  23  24  25
 */

#include <stdio.h>

int main(){
    int MaxLine = 5;
    int data;
    int MInteger;
    int LineNumber;

    printf("지그재그 숫자 풀력 프로그램\r\n");

    for(LineNumber = 1; LineNumber <= MaxLine; LineNumber++){
        if((LineNumber % 2) == 0){
            for(data = LineNumber * 5; data >= (LineNumber * 5)-4; data--){
                printf("%d\t", data);
            }
            printf("\r\n");
        }else{
            for(data = (5 * (LineNumber - 1))+1; data <= (5 * (LineNumber - 1))+5; data++){
                printf("%d\t", data);
            }
            printf("\r\n");
        }
    }
    return 0;
}