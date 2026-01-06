#include <stdio.h>

int main() {
    char text[200];
    int key, choice;

    printf("Enter your message: ");
    fgets(text, sizeof(text), stdin);

    printf("Enter key (number of shifts): ");
    scanf("%d", &key);
  
    printf("\nWhat do you want to do?\n");
    printf("1. Encrypt\n");
    printf("2. Decrypt\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    for (int i = 0; text[i] != '\0'; i++) {
        char ch = text[i];

        // For encryption
        if (choice == 1) {
            if (ch >= 'A' && ch <= 'Z') {
                ch = ((ch - 'A' + key) % 26) + 'A';
            }
            else if (ch >= 'a' && ch <= 'z') {
                ch = ((ch - 'a' + key) % 26) + 'a';
            }
        }

        // For decryption
        else if (choice == 2) {
            if (ch >= 'A' && ch <= 'Z') {
                ch = ((ch - 'A' - key + 26) % 26) + 'A';
            }
            else if (ch >= 'a' && ch <= 'z') {
                ch = ((ch - 'a' - key + 26) % 26) + 'a';
            }
        }

        text[i] = ch;
    }

    if (choice == 1)
        printf("\nEncrypted message: %s", text);
    else if (choice == 2)
        printf("\nDecrypted message: %s", text);
    else
        printf("\nInvalid choice!");

    return 0;
}
