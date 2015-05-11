/* 2015, Joe Walnes, Sneaky Squid */

#include <stdio.h>
#include "verifysignature.h"

int main() {

    const char *public_key = "bdb9bfb228870f53d3f11272efd6747b7e413935fb61754d65cf74b57f0ca29f";
    const char *signature = "ff72e41634cf372e42cdda9413c1f18308ff9f745326d34af97c4036fb7f927f97e08b12920abd3f16c0ec40615ce8532e2aeea2acaca49326f6acb3c6941e00";

    const unsigned char *message = (const unsigned char *) "hello world\n";
    size_t message_len = 12;

    int result = verify_signature(public_key, signature, message, message_len);

    if (result != 0) {
        fprintf(stderr, "Signature verification failed!\n");
        return 1;
    } else {
        printf("ok\n");
        return 0;
    }

}
