#include <stdio.h>
#include <string.h>
unsigned int simpleMAC(char message[], int key) {
    unsigned int mac = 0;
    for(int i = 0; i < strlen(message); i++) {
        mac += message[i];
    }
    mac += key;
    return mac % 256;  
}
int main() {
    char message[100];
    int key;
    printf("Enter message: ");
    fgets(message, sizeof(message), stdin);
    message[strcspn(message, "\n")] = '\0';
    printf("Enter secret key (integer): ");
    scanf("%d", &key);
    unsigned int mac = simpleMAC(message, key);
    printf("Generated MAC: %u\n", mac);
    unsigned int verify = simpleMAC(message, key);
    if(mac == verify)
        printf("MAC Verified Successfully!\n");
    else
        printf("MAC Verification Failed!\n");
    return 0;
}
