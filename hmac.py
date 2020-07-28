#!/usr/bin/env python3

import hashlib

def sha1hash(msg):
    return hashlib.sha1(msg).digest()

def hmac(key, message):
    blocksize = 64

    if (len(key) > blocksize):
        key = sha1hash(key)

    if (len(key) < blocksize):
        key = key + b'\x00'* (blocksize - len(key))

    # print(key)
    o_key_pad = bytearray([elem ^ 0x5c for elem in key])
    # print(o_key_pad.hex())
    i_key_pad = bytearray([elem ^ 0x36 for elem in key])

    return sha1hash(o_key_pad + sha1hash(i_key_pad + message))

print("0x" + hmac(b"key", b"hello").hex())

# The result should be 0xb34ceac4516ff23a143e61d79dfa7a4fbe5f266
