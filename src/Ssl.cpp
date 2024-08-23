//
// Created by k on 23.08.24.
//

#include "Ssl.h"
#include <cstring>
#include <iostream>

void Ssl::handleErrors() {
    ERR_print_errors_fp(stderr);
    abort();
}


int Ssl::encrypt(const unsigned char *plaintext, const int plaintext_len, const unsigned char *key,
            const unsigned char *iv, unsigned char *ciphertext) {
    EVP_CIPHER_CTX *ctx;

    int len;

    // Create and initialize the context
    if (!((ctx = EVP_CIPHER_CTX_new()))) handleErrors();

    // Initialize the encryption operation. Here we are using 256-bit AES in CBC mode.
    if (1 != EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), nullptr, key, iv))
        handleErrors();

    // Provide the message to be encrypted, and obtain the encrypted output.
    if (1 != EVP_EncryptUpdate(ctx, ciphertext, &len, plaintext, plaintext_len))
        handleErrors();
    int ciphertext_len = len;

    // Finalize the encryption.
    if (1 != EVP_EncryptFinal_ex(ctx, ciphertext + len, &len)) handleErrors();
    ciphertext_len += len;

    // Clean up
    EVP_CIPHER_CTX_free(ctx);

    return ciphertext_len;
}
