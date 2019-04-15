#include <stdio.h>


void main(void)
{
    int data = 10;
    int *ptr;

    printf("data의 주소 : 0x%p, data의 값 : %d \r\n", &data, data);
    ptr = &data;

    printf("ptr의 주소 : 0x%p , ptr의 값 : 0x%p \r\n", &ptr, ptr);

    printf("ptr이 가르키는 곳의 값 : %d, data의 값 : %d \r\n", *ptr, data);

    printf("ptr의 주소 : 0x%p, ptr의 값 : 0x%p, ptr이 가르키는 값 : %d \r\n", &ptr, ptr, *ptr);
    
}