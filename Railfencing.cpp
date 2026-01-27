#include <stdio.h>
#include <string.h>
int main() {
    char text[100], cipher[100];
    int key, i, j = 0;
    printf("Enter plaintext: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';
    printf("Enter key (rails): ");
    scanf("%d", &key);
    for (i = 0; i < key; i++) {
        int k = i;
        while (k < strlen(text)) {
            cipher[j++] = text[k];
            k += key;
        }
    }
    cipher[j] = '\0';
    printf("Encrypted text: %s\n", cipher);

    return 0;
}
