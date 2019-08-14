/**
 * File Name : main.c
 * Author    : DoukHee
 * Version   : v1.0
 * Date      : 08/14/2019
 * 문제 
 *  10진수를 16진수로 변환하거나 16진수를 10진수로 변환하는 프로그램
 */

#include <stdio.h>

int main()
{
    char key;
    int data;

    printf("decimal transform hex program\r\n");
    printf("decimal transform hex press[A].\r\n");
    printf("hex transform decimal press[B] \r\n");

    scanf("%c", &key);
    printf("input number : ");

    if(key == 'a' || key == 'A'){
        scanf("%d", &data);
        printf("decimal value : %d -> hex value : %x\r\n", data, data);
    }
    else if(key == 'b' || key == 'B'){
        scanf("%d", &data);
        printf("hex value : %x -> decimal value : %d \r\n", data, data);
    }else{
        printf("only press [A] [B] key");
    }

    return 0;

}