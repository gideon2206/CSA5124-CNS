#include <stdio.h>
#include <math.h>
long int power(long int a, long int b, long int mod) {
    long int result = 1;
    for (int i = 1; i <= b; i++)
        result = (result * a) % mod;
    return result;
}
int main() {
    long int p = 3, q = 7;
    long int n = p * q;
    long int phi = (p - 1) * (q - 1);
    long int e = 5, d = 5;
    long int msg = 4, cipher, decrypt;

    cipher = power(msg, e, n);
    decrypt = power(cipher, d, n);
    printf("Public Key (e, n) = (%ld, %ld)\n", e, n);
    printf("Private Key (d, n) = (%ld, %ld)\n", d, n);
    printf("Original Message: %ld\n", msg);
    printf("Encrypted Message: %ld\n", cipher);
    printf("Decrypted Message: %ld\n", decrypt);
    return 0;
}
