#include <stdio.h>
#include <string.h>
int main() {
    char text[100];
    int i;
    char map[26] = {
        'D','E','F','G','H','I','J','K','L','M',
        'N','O','P','Q','R','S','T','U','V','W',
        'X','Y','Z','A','B','C'
    };
    printf("Enter plaintext (UPPERCASE): ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';
    printf("Encrypted text: ");
    for (i = 0; text[i] != '\0'; i++) {
        if (text[i] >= 'A' && text[i] <= 'Z')
            printf("%c", map[text[i] - 'A']);
        else
            printf("%c", text[i]);
    }
    return 0;
}
