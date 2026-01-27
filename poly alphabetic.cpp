#include <stdio.h>
#include <string.h>
int main() {
    char text[100], cipher[100];
    int key, i, j, k = 0;
    printf("Enter plaintext: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';
    printf("Enter key (number of columns): ");
    scanf("%d", &key);
    int len = strlen(text);
    int rows = (len + key - 1) / key;
    char mat[rows][key];
    int index = 0;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < key; j++) {
            if (index < len)
                mat[i][j] = text[index++];
            else
                mat[i][j] = 'X';   // padding
        }
    }
    for (j = 0; j < key; j++) {
        for (i = 0; i < rows; i++) {
            cipher[k++] = mat[i][j];
        }
    }
    cipher[k] = '\0';
    printf("Encrypted text: %s\n", cipher);
    return 0;
}
