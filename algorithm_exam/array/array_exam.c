#include <stdio.h>

void main()
{
    int i = 0;
    char buf[11];

    printf("소문자 11개를 입력 해봅시다.\r\n");
    printf("input : ");
    while(i < 11)
    {
        scanf("%c", &buf[i]);
        i++;
    }
    printf("문자를 입력하셨군요. 대문자로 변환합니다.\r\n");
    for(i = 0; i < 11; i++)
    {
        printf("%c", buf[i]-('a'-'A'));
    }
    printf("\r\n");
}