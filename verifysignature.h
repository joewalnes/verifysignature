/* 2015, Joe Walnes, Sneaky Squid */

#pragma once

#include <stddef.h>

/*
 * Verifies the signature provided for a message.
 *
 * The signature can only be generated using a secret private key, for which the
 * corresponding public key is provided. If the message, signature or
 * public key is tampered with, the verification will fail.
 *
 * Therefore, this can be used to guarantee that a message came from an
 * authentic source that possesses the secret private key.
 *
 * The public-key signature verification crypto algorithm is Ed25519.
 *
 * To generate a key-pair and sign the a message, see the accompanying tools.
 *
 * Args:
 *   public_key  : base64 encoded hex string
 *   signature   : base64 encoded hex string
 *   message     : any binary data to verify
 *   message_len : length of message
 *
 * Returns:
 *   If message verifies successufully, returns 0.
 *   If verification failed, returns non-zero.
 */
int verify_signature(const char *public_key_hex,
                     const char *signature_hex,
                     const unsigned char *message,
                     const size_t message_len);
