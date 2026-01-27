#include <stdio.h>
#include <string.h>
unsigned int simpleSHA3(char msg[]) {
    unsigned int state = 0xABCDEF;  
    for(int i = 0; i < strlen(msg); i++) {
        state ^= msg[i];             
        state = (state << 7) | (state >> 25); 
        state += 0x9E3779B9;         
    }
    return state;
}
int main() {
    char message[100];
    printf("Enter message: ");
    fgets(message, sizeof(message), stdin);
    message[strcspn(message, "\n")] = '\0';
    unsigned int hash = simpleSHA3(message);
    printf("SHA-3 Hash (simulated): %u\n", hash);
    return 0;
}
