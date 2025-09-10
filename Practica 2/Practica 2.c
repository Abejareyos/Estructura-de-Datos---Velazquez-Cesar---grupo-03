#include <stdio.h>

int main(void) {

    int a[5] = {2, 4, 6, 8, 10};
    int *p = a; // p apunta a a[0]

    printf("1) a[q] = %d\n", a[1]); // 4
    printf("2) *(a+3) = %d\n", *(a+3)); // 8
    printf("3) *p++ = %d\n", *p++); // 2
    printf("4) *++p = %d\n", *++p); // 6
    printf("5) *p[1] = %d\n", a[1]); // 4
    printf("6) *(p+=2) = %d\n", *(p+=2)); // 10
    printf("7) p-a = %d\n", p-a); // 4
    
    return 0;

}