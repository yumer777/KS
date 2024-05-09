#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <openssl/err.h>

void clear(BIO *bp_public, BIO *bp_private, RSA *rsa, BIGNUM *big){
    BIO_free_all(bp_public);
    BIO_free_all(bp_private);
    RSA_free(rsa);
    BN_free(big);
}

int main()
{
    RSA *rsa = NULL;
    BIO *bp_public = NULL, *bp_private = NULL;
    int bits = 2048;
    int result = 0;
    BIGNUM* big = BN_new();
    if(big == NULL)
    {
        fprintf(stderr, "Error allocating big numbers");
        return EXIT_FAILURE;
    }

    result = BN_set_word(big, RSA_F4);

    if(result != 1)
    {
        fprintf(stderr, "Error setting exponent");
        clear(bp_public, bp_private, rsa, big);
        return EXIT_FAILURE;
    }

    rsa = RSA_new();
    if(rsa == NULL)
    {
        fprintf(stderr, "Error allocating RSA");
        return EXIT_FAILURE;
    }

    result = RSA_generate_key_ex(rsa, bits, big, NULL);
    if(result != 1)
    {
        fprintf(stderr, "Error generating RSA key");
        clear(bp_public, bp_private, rsa, big);
        return EXIT_FAILURE;
    }

    bp_public = BIO_new_file("public.pem", "w+");
    if(bp_public == NULL)
    {
        fprintf(stderr, "Error opening public key file.");
        return EXIT_FAILURE;
    }
    result = PEM_write_bio_RSAPublicKey(bp_public, rsa);
    if(result != 1)
    {
        fprintf(stderr, "Error writing public key");
        clear(bp_public, bp_private, rsa, big);
        return EXIT_FAILURE;
    }

    bp_private = BIO_new_file("private.pem", "w+");
    if(bp_private == NULL)
    {
        fprintf(stderr, "Error opening private key file.");
        return EXIT_FAILURE;
    }
    result = PEM_write_bio_RSAPrivateKey(bp_private, rsa, NULL, NULL, 0, NULL, NULL);
    if(result != 1)
    {
        fprintf(stderr, "Error writing private key");
        clear(bp_public, bp_private, rsa, big);
        return EXIT_FAILURE;
    }

    printf("Done");
    return EXIT_SUCCESS;
}