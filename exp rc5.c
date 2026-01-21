#include <stdio.h>

int main() {
    int A = 5, B = 7; 
    int key = 3;        
    int rounds = 3;
    int i;

    printf("Plain Text: A = %d, B = %d\n", A, B);

    for(i = 0; i < rounds; i++) {
        A = (A + key) ^ B;
        B = (B + key) ^ A;
    }

    printf("Cipher Text: A = %d, B = %d\n", A, B);

    return 0;
}

