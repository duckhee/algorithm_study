#include <stdio.h>

void main(void)
{
    int data = 0;
    int *ptr;

    printf("data의 주소 : 0x%p, data 의 값 : %d \r\n", &data, data);
    ptr = &data;

    printf("ptr의 주소 : 0x%p, ptr의 값 : 0x%p \r\n", &ptr, ptr);
    
}