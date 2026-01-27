#include <stdio.h>
#include <math.h>
long long int power(long long int a, long long int b, long long int mod) {
    long long int result = 1;
    for (int i = 1; i <= b; i++)
        result = (result * a) % mod;
    return result;
}
int main() {
    long long int q = 353, alpha = 3;
    long long int XA = 97, XB = 223;
    long long int YA, YB, KA, KB;
    YA = power(alpha, XA, q);
    YB = power(alpha, XB, q);
    KA = power(YB, XA, q);
    KB = power(YA, XB, q);
    printf("Public key of A (YA): %lld\n", YA);
    printf("Public key of B (YB): %lld\n", YB);
    printf("Secret key computed by A: %lld\n", KA);
    printf("Secret key computed by B: %lld\n", KB);
    return 0;
}
