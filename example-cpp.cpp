/* 2015, Joe Walnes, Sneaky Squid */

#include <iostream>
#include <string>

#include "verifysignature.h"

int main() {
    std::string public_key("bdb9bfb228870f53d3f11272efd6747b7e413935fb61754d65cf74b57f0ca29f");
    std::string signature("ff72e41634cf372e42cdda9413c1f18308ff9f745326d34af97c4036fb7f927f97e08b12920abd3f16c0ec40615ce8532e2aeea2acaca49326f6acb3c6941e00");

    std::string message("hello world\n");
    size_t message_len = message.size();

    int result = verify_signature(public_key.c_str(), signature.c_str(), reinterpret_cast<const unsigned char*>(message.c_str()), message_len);

    if (result != 0) {
        std::cerr << "Signature verification failed!" << std::endl;
        return 1;
    } else {
        std::cout << "ok" << std::endl;
        return 0;
    }
}
