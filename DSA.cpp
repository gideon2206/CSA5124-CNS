#include <stdio.h>
#include <string.h>
#include <stdint.h>
typedef uint32_t UINT32;
UINT32 F(UINT32 x, UINT32 y, UINT32 z) { return (x & y) | (~x & z); }
UINT32 G(UINT32 x, UINT32 y, UINT32 z) { return (x & z) | (y & ~z); }
UINT32 H(UINT32 x, UINT32 y, UINT32 z) { return x ^ y ^ z; }
UINT32 I(UINT32 x, UINT32 y, UINT32 z) { return y ^ (x | ~z); }
UINT32 ROTATE_LEFT(UINT32 x, int n) {
    return (x << n) | (x >> (32 - n));
}
int main() {
    char msg[64];
    printf("Enter message: ");
    fgets(msg, sizeof(msg), stdin);
    msg[strcspn(msg, "\n")] = '\0';
    UINT32 A = 0x67452301;
    UINT32 B = 0xefcdab89;
    UINT32 C = 0x98badcfe;
    UINT32 D = 0x10325476;
    UINT32 M[16] = {0};
    memcpy(M, msg, strlen(msg));
    A = B + ROTATE_LEFT(A + F(B, C, D) + M[0] + 0xd76aa478, 7);
    D = A + ROTATE_LEFT(D + F(A, B, C) + M[1] + 0xe8c7b756, 12);
    C = D + ROTATE_LEFT(C + F(D, A, B) + M[2] + 0x242070db, 17);
    B = C + ROTATE_LEFT(B + F(C, D, A) + M[3] + 0xc1bdceee, 22);
    printf("MD5 Hash (demo output): %08x%08x%08x%08x\n", A, B, C, D);
    return 0;
}
