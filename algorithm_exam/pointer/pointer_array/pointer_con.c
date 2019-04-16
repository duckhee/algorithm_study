#include <stdio.h>

void main()
{
    char buf[6] = {'a', 'b', 'c', 'd', 'e', 'f'};
    char *ptr = buf;
    int i = 0;
    printf("ptr 1 by one up\r\n");

    for(i = 0; i < 6; i++)
    {
        printf("ptr : 0x%p, *ptr : %c \r\n", ptr, *ptr);
        ptr++;
    }

    printf("\r\n ptr retry give buf address \r\n");
    ptr = buf;

    printf("ptr++\r\n");
    printf("ptr : 0x%p, *ptr : %c \r\n", ptr, *ptr++);

    printf("*(ptr++) result\r\n");
    printf("ptr : 0x%p, *ptr : %c \r\n", ptr, *(ptr++));

    printf("--ptr *(ptr++) result\r\n");
    --ptr;
    printf("ptr : 0x%p, *ptr : %c \r\n", ptr, *(ptr++));

    printf("(*ptr)++ result \r\n");
    (*ptr)++;
    printf("ptr : 0x%p, *ptr : %c \r\n", ptr, *ptr);

    printf("ptr += 1 then result *ptr \r\n");
    ptr += 1;
    printf("ptr : 0x%p, *ptr : %c \r\n", ptr, *ptr);

    printf("ptr -= 2 then *ptr result \r\n");
    ptr -= 2;
    printf("ptr : 0x%p, *ptr ; %c \r\n", ptr, *ptr);

}