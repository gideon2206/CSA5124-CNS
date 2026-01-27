#include <stdio.h>
#include <string.h>
int main() {
    char key[20], text[20];
    char mat[5][5] = {
        {'M','O','N','A','R'},
        {'C','H','Y','B','D'},
        {'E','F','G','I','K'},
        {'L','P','Q','S','T'},
        {'U','V','W','X','Z'}
    };
    int i, r1, c1, r2, c2;
    printf("Enter plaintext (even length): ");
    scanf("%s", text);
    printf("Encrypted text: ");
    for (i = 0; i < strlen(text); i += 2) {
        for (r1 = 0; r1 < 5; r1++)
            for (c1 = 0; c1 < 5; c1++)
                if (mat[r1][c1] == text[i]);
        for (r2 = 0; r2 < 5; r2++)
            for (c2 = 0; c2 < 5; c2++)
                if (mat[r2][c2] == text[i + 1]);
        if (r1 == r2)
            printf("%c%c", mat[r1][(c1 + 1) % 5], mat[r2][(c2 + 1) % 5]);
        else if (c1 == c2)
            printf("%c%c", mat[(r1 + 1) % 5][c1], mat[(r2 + 1) % 5][c2]);
        else
            printf("%c%c", mat[r1][c2], mat[r2][c1]);
    }
    return 0;
}
