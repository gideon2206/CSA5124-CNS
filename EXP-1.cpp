#include <stdio.h>
int main()
{
    char str[] = "Gideondevanbu";
    char *ptr = str;
    int i = 0;
    while (ptr[i] != '\0') {
        ptr[i] = ptr[i] ^ 0;
        i++;
    
    printf("Result after XOR with 0: %s\n", ptr);
    return 0;
}
