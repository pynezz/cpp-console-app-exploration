//
// Created by k on 23.08.24.
//

#ifndef SSL_H
#define SSL_H

#include <openssl/conf.h>
#include <openssl/evp.h>
#include <openssl/err.h>
#include <openssl/aes.h>
#include <cstring>
#include <iostream>

class Ssl {
    public:
    static void handleErrors(void);
        static int encrypt(const unsigned char *plaintext, const int plaintext_len,
            const unsigned char *key, const unsigned char *iv, unsigned char *ciphertext);

    private:

};

#endif //SSL_H
