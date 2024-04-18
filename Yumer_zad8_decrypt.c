#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAXN 1024

char* vigenere_encrypt(char* plaintext, char* key)
{
    int length = strlen(plaintext);
    int key_length = strlen(key);
    char* cipher = (char*) malloc(sizeof(char) * (length + 1));
    int index = 0;
    while(plaintext[index] != '\0')
    {
        int shift = tolower(key[index % key_length]) - 'a';
        if(islower(plaintext[index]))
        {
            cipher[index] = 'a' + (plaintext[index] - 'a' + shift) % 26;
        }
        else if(isupper(plaintext[index]))
        {
            cipher[index] = 'A' + (plaintext[index] - 'A' + shift) % 26;
        }
        else
        {
            cipher[index] = plaintext[index];
        }
        index++;
    }
    cipher[index] = '\0';
    return cipher;
}
char* vigenere_decrypt(char* cipher, char* key)
{
    int length = strlen(cipher);
    int key_length = strlen(key);
    char* plaintext = (char*) malloc(sizeof(char) * (length + 1));
    int index = 0;
    while(cipher[index] != '\0')
    {
        int shift = tolower(key[index % key_length]) - 'a';
        if(islower(cipher[index]))
        {
            plaintext[index] = 'a' + (cipher[index] - 'a' - shift + 26) % 26;
        }
        else if(isupper(cipher[index]))
        {
            plaintext[index] = 'A' + (cipher[index] - 'A' - shift + 26) % 26;
        }
        else
        {
            plaintext[index] = cipher[index];
        }
        index++;
    }
    plaintext[index] = '\0';
    return plaintext;
}

int main()
{
    char plaintext[MAXN];
    scanf("%s", plaintext);
    
    char key[MAXN];
    scanf("%s", key);
    
    char* result = vigenere_encrypt(plaintext, key);
    printf("Encrypted message: %s\n", result);
    
    char* decrypted = vigenere_decrypt(result, key);
    printf("Decrypted message: %s", decrypted);
    return EXIT_SUCCESS;
}

