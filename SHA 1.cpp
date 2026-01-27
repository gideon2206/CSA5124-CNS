#include <stdio.h>
#include <string.h>
unsigned int simpleSHA1(char str[]) {
    unsigned int hash = 0;
    for(int i = 0; i < strlen(str); i++) {
        hash += str[i];        
        hash = (hash << 5) | (hash >> 27);  
    }
    return hash;
}
int main() {
    char message[100];
    printf("Enter message: ");
    fgets(message, sizeof(message), stdin);
    message[strcspn(message, "\n")] = '\0'; 
    unsigned int digest = simpleSHA1(message);
    printf("SHA-1 (simulated) hash: %u\n", digest);
    return 0;
}
