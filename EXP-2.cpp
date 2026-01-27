#include <stdio.h>
int main() {
    char str[] = "Gideondevanbu";
    char *ptr = str;
    int i;
    printf("Original String : %s\n", ptr);
    for (i = 0; ptr[i] != '\0'; i++) {
        ptr[i] = ptr[i] & 127;
    }
    printf("After AND with 127 : %s\n", ptr);
    char str2[] = "Gideondevanbu";
    ptr = str2;

    for (i = 0; ptr[i] != '\0'; i++) {
        ptr[i] = ptr[i] ^ 127;
    }
    printf("After XOR with 127 : %s\n", ptr);
    return 0;
}
