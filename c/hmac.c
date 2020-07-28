#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "teeny-sha1.h"

#define BLOCKSIZE 64
#define DIGESTSIZE 20

// If compiling for regular computer (like x86 or x86-64 based)
#ifdef REGULAR
void printArray(uint8_t* array, size_t length)
{
    int i;
    printf("0x");
    for (i = 0; i < length; i++)
        printf("%x", array[i]);
    putchar('\n');
}
#endif
// If compiling for TI-84+ CE 
#ifndef REGULAR
#include <tice.h>
static void putChar(char c) {
    static char str[2];
    str[0] = c;
    os_PutStrFull(str);
}
static void putNibHex(unsigned char x) {
    x &= 0xF;
    putChar(x < 10 ? '0' + x : 'A' + x - 10);
}
static void putByteHex(unsigned char x) {
    putNibHex(x >> 4);
    putNibHex(x >> 0);
}

static void printArray(uint8_t* array, size_t length)
{
    int i;
    for (i = 0; i < length; i++)
        putByteHex(array[i]);

}
#endif


int hmac_sha1(uint8_t* digest, uint8_t* key, uint8_t* message, size_t keylen, size_t msglen)
{
    int i;
    uint8_t newkey[BLOCKSIZE] = {0};
    uint8_t o_key_pad[BLOCKSIZE];
    uint8_t i_key_pad[BLOCKSIZE];
    uint8_t tmpmsg[BLOCKSIZE + DIGESTSIZE];
    uint8_t tmpdigeset[DIGESTSIZE]; 
    uint8_t* tmp;

    // If key is longer than blocksize (64), hash the key and make that the new key
    if (keylen > BLOCKSIZE) {
        sha1digest(newkey, key, keylen);
    }
    else {
        // Transfer to newkey array since that has 0s as padding already
        memcpy(newkey, key, keylen);
    }

    // Create o key pad 
    for (i = 0; i < BLOCKSIZE; i++)
    {
        o_key_pad[i] = 0x5c ^ newkey[i];
    }

    // Create i key pad 
    for (i = 0; i < BLOCKSIZE; i++)
    {
        i_key_pad[i] = 0x36 ^ newkey[i];
    }

    tmp = malloc(msglen + BLOCKSIZE);
    
    memcpy(tmp, i_key_pad, BLOCKSIZE);
    memcpy(tmp + BLOCKSIZE, message, msglen); 
    sha1digest(tmpdigeset, tmp, msglen + BLOCKSIZE);

    memcpy(tmpmsg, o_key_pad, BLOCKSIZE);
    memcpy(tmpmsg + BLOCKSIZE, tmpdigeset, DIGESTSIZE);

    sha1digest(digest, tmpmsg, BLOCKSIZE + DIGESTSIZE);
    
    free(tmp);
    
    return 0;
}

int main(void)
{
#ifndef REGULAR
    os_ClrHome();
#endif

    uint8_t digest[20];

    char * msg = "hello";
    char * key = "key";

    hmac_sha1(digest, key, msg, strlen(key), strlen(msg));
    printArray(digest, DIGESTSIZE);
    // The result should be 0xb34ceac4516ff23a143e61d79dfa7a4fbe5f266

#ifndef REGULAR
    while (!os_GetCSC());
#endif
  
}

