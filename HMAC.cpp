#include <stdio.h>
#include <string.h>
unsigned int simpleHMAC(char message[], int key) {
    unsigned int sum = key; // start with key
    for(int i = 0; i < strlen(message); i++)
        sum += message[i];  
    return sum;  
}
int main() {
    char message[100];
    int key;
    printf("Enter message: ");
    fgets(message, sizeof(message), stdin);
    message[strcspn(message, "\n")] = '\0'; 
    printf("Enter secret key (integer): ");
    scanf("%d", &key);
    unsigned int hmac = simpleHMAC(message, key);
    printf("Generated HMAC: %u\n", hmac);
    if(hmac == simpleHMAC(message, key))
        printf("HMAC Verified Successfully!\n");
    else
        printf("HMAC Verification Failed!\n");

    return 0;
}
