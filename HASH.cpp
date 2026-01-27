#include <stdio.h>
#include <string.h>
unsigned int simpleHash(char str[]) {
    unsigned int hash = 0;
    for(int i = 0; i < strlen(str); i++) {
        hash = (hash + str[i]) * 31;  
    }
    return hash;
}
int main() {
    char message[100];
    printf("Enter a message: ");
    fgets(message, sizeof(message), stdin);
    message[strcspn(message, "\n")] = '\0';  
    unsigned int hashValue = simpleHash(message);
    printf("Hash value: %u\n", hashValue);
    return 0;
}
