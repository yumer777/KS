#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/des.h>
#define KEY_SIZE 8
#define DATA_SIZE 1000

int main()
{
    unsigned char key[KEY_SIZE] = "banichka";
    
    unsigned char encrypted[DATA_SIZE] = {0x91, 0x80, 0x0e, 0x0e, 0x28, 0x3a, 0xe8, 0xf2};
    
    int encrypted_length = strlen(encrypted);
    unsigned char decrypted[DATA_SIZE];
    
    DES_key_schedule key_schedule;
    DES_set_key((DES_cblock*) key, &key_schedule);
    DES_ecb_encrypt((DES_cblock*) encrypted, (DES_cblock*) decrypted,
        &key_schedule, DES_DECRYPT);
    
    for(int i = 0; i < encrypted_length; i++)
    {
        printf("%c", decrypted[i]);
    }
    
    return EXIT_SUCCESS;
}