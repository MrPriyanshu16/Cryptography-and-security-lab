#include <stdio.h>
#include <string.h>

int main() {
    int key;
    char plainText[100];
    printf("Enter plain text: ");
    fgets(plainText, sizeof(plainText), stdin);

    printf("Enter key: ");
    scanf("%d", &key);

    int length = strlen(plainText);
    plainText[length - 1] = '\0';
    length = strlen(plainText);
    
    char cipherText[key][length];

    for(int i = 0; i < key; i++) {
        for(int j = 0; j < length; j++) {
            cipherText[i][j] = ' ';
        }
    }

    int row = 0;
    int dir = 1;
    for(int i = 0; plainText[i] != '\0'; i++) {
        cipherText[row][i] = plainText[i];
        if(row == key - 1) dir = -1;
        else if(row == 0) dir = 1;
        row = row + dir;
    }

    for(int i = 0; i < key; i++){
        for(int j = 0; j < length; j++){
            if(cipherText[i][j] != ' ')
                printf("%c", cipherText[i][j]);
        }
    }
    return 0;
}