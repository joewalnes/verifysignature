================================================
Standalone Ed25519 public-key signature verifier
================================================

This is a standalone portable C implementation of the Ed25519 public key
signature verifier algorithm. It has no dependencies.

See http://ed25519.cr.yp.to/

The signature can only be generated using a secret private key, for which the
corresponding public key is provided. If the message, signature or
public key is tampered with, the verification will fail.

See example.c for complete example of how to verify a message given a public
key and signature. This includes an example public key, signature and message.

See verifysignature.h for the API.

For simplicity, the public key, private key and signature is always represented
as a hex string, allowing it to easily be embedded in code, copy/pasted, emailed,
etc.

The only files that need to be included in your project are verifysignature.h
and verifysignature.c


----------------------
Implementation details
----------------------

This implementation has been extracted from libsodium.
https://github.com/jedisct1/libsodium

Only the absolute minimum code has been extracted, in order to keep the program
small. The C is simple and portable so should run on most processors.


-----------------
Signing a message
-----------------

The included keytool allows you to generate the public key and signature
for a file. To run it you need Python.

First you need a secret key. Let's put it in an environment variable so we can
use it later. This is the key used for the examples:

    $ SECRET_KEY=59e51f2819f774126ae1d3db1411d20019751d5f41cefa98c844271338a1c5b15a47597a67e5a5a18d822d4129eff23669003dba956467fa1eaf65735f32c8d5

Now you need a file to sign. For this example, we'll use the included
'hello-world.txt' file. Note that this file can contain anything, including
binary data.

To sign:

    $ ./keytool sign $SECRET_KEY hello-world.txt

This will output the signature.


-------------------------
Generating a new key pair
-------------------------

To generate a new key pair, first generate a secret key:

    $ ./keytool gen-secret

This will output a new secret key. Keep it safe.

To extract the public key from the secret key:

    $ ./keytool pub-key [YOUR-SECRET-KEY]

Run ./keytool with no args for full usage.



- 2015, Joe Walnes, Sneaky Squid







/* ---------- libsodium license ----------------------------------------------
 * Copyright (c) 2013-2015
 * Frank Denis <j at pureftpd dot org>
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 * ---------------------------------------------------------------------------
 * This is the ISC License: https://en.wikipedia.org/wiki/ISC_license
 */
