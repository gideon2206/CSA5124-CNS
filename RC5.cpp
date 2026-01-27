#include <stdio.h>
#include <stdint.h>
#define R 12
uint32_t ROTL(uint32_t x, uint32_t y) {
    return (x << (y & 31)) | (x >> (32 - (y & 31)));
}
int main() {
    uint32_t A = 0x12345678;
    uint32_t B = 0x9ABCDEF0;
    uint32_t S[2 * R + 2];
    for (int i = 0; i < 2 * R + 2; i++)
        S[i] = i * 0x9E3779B9;
    A = A + S[0];
    B = B + S[1];
    for (int i = 1; i <= R; i++) {
        A = ROTL(A ^ B, B) + S[2 * i];
        B = ROTL(B ^ A, A) + S[2 * i + 1];
    }
    printf("Encrypted A: %08X\n", A);
    printf("Encrypted B: %08X\n", B);
    return 0;
}
